/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "callback_task.h"

#include "fake.h"
#include "bgcc_common.h"
#include "bgcc_error.h"

bgcc::CallBackTask::CallBackTask(const std::string server, int32_t port,
		const std::string proxy, ServiceManager *sm, Selector *selector):
	_server(server), _port(port), _prx(proxy), _sm(sm),
	_pselector(selector){
			_connect = SharedPointer<ClientSocket>(new(std::nothrow) ClientSocket(_server, _port));
			_proto = SharedPointer<BinaryProtocol>(new(std::nothrow) BinaryProtocol(_connect));
			_processor = SharedPointer<IProcessor>(NULL);

			Register();
	}

bgcc::CallBackTask::~CallBackTask(){
}

int32_t bgcc::CallBackTask::operator()(const bool *isstopped, void *)
{
	char *pbody = _buf_body;
	int32_t ret = -1;
	char buffer[MAX_DEFAULT_LEN]={0};

	while (!(*isstopped)) {
		int32_t buffer_size=MAX_DEFAULT_LEN;
		while(((ret=_pselector->Select())==0) && !(*isstopped));
		
		while(ret<0 && !(*isstopped)){
			bgcc::TimeUtil::safe_sleep_ms(200);
			if(Register()){
				while(((ret=_pselector->Select())==0) && !(*isstopped));
				
				if(ret>0){
					break;
				}
			}
		}
		
		if(*isstopped){
			break;
		}
		
		if(pbody && pbody!=_buf_body){
			free(pbody);
			pbody=_buf_body;
		}

		ret = _connect->read(_buf_head, HEAD_SIZE);
		if(0!=ret){
			BGCC_WARN("bgcc", "Read ret %d errno=%d, goto reconnect", ret, BgccSockGetLastError());
			continue;
		}

		int32_t body_len = BODY_LEN(_buf_head);

		if(body_len > MAX_DEFAULT_LEN){
			if( !(pbody=(char*)calloc(1, sizeof(char) * body_len))){
				BGCC_WARN("bgcc", "Malloc failed while receiving. Size: %d", body_len);
			}
		}

		if(pbody&&(ret=_connect->read(pbody, body_len))==0){
			std::string processor_name(PROCESSOR_NAME_PTR(pbody), PROCESSOR_NAME_LEN(pbody));
			_processor=_sm->get_service(processor_name);
			if (_processor.is_valid()) {
				_processor->process(
						pbody,
						body_len,
						_proto);

				continue;
			}
		}
		else if(!pbody){
			pbody=_buf_body;
		}
		else{
			continue;
		}

		_processor = _sm->get_service(DEF_SERVICE);
		if (_processor.is_valid()) {
			if(Fake::fake_default_body(buffer, buffer_size)){
				_processor->process(buffer, buffer_size,_proto);
			}
		}
	}
	
	if(pbody && pbody!=_buf_body){
		free(pbody);
		pbody=_buf_body;
	}

	return 0;
}

bool bgcc::CallBackTask::Register(){
	bool ret=false;
	memset(_buf_head, 0, HEAD_SIZE);
	memset(_buf_body, 0, MAX_DEFAULT_LEN);
	_pselector->Update(INVALID_SOCKET);

	if((ret=(_connect->open()==0))){
		SocketTool::set_sndtimeout(_connect->id(), 3*DEFAULT_HB_TIMEOUT);
		_pselector->Update(_connect->id(), DEFAULT_WAIT_TIMEOUT);

		ret=(_proto->writeMessageBegin(REG_PROCESSOR, REG_FUNC, bgcc::CALL, 0)==0 
			&& _proto->writeString(_prx)==0
			&& _proto->writeMessageEnd()==0);
	}
	else{
		BGCC_WARN("bgcc", "CallBackTask Connect Failed");
	}
	
	return ret;
}

const int32_t bgcc::CallBackTask::DEFAULT_WAIT_TIMEOUT=200;

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
