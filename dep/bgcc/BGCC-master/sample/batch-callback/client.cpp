/***************************************************************************
 * 
 * Copyright (c) 2012 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/



/**
 * @file client.cpp
 * @author chenyuzhen(chenyuzhen@baidu.com)
 * @date 2012/11/13 16:21:10
 * @version 1.0.0 
 * @brief 
 *  
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bgcc.h>

#include "output-cpp/callback.h"
#include "callback_recv_impl.h"

#include "string_util.h"

using namespace bgcc;

#define SERVER_PORT 8878
//#define SERVER_IP "10.26.78.49"
#define SERVER_IP "127.0.0.1"

#define POOL_SIZE 1
#define CLIENT_COUNT POOL_SIZE
#define PER_CLIENT_EXECUTE 1000

class UUIDTask : public Runnable{
	public:
		int32_t operator()(const bool *isstopped, void *param=NULL){
			for(int32_t i=0; i<PER_CLIENT_EXECUTE; ++i) {
				BGCC_TRACE("client", "%s", StringUtil::generate_uuid().c_str()) ;
			}

			return 0;
		}
};

void menu();
class ClientTask : public Runnable {
	public:
		ClientTask():_prx(NULL){}
		virtual int32_t operator()(const bool* isstopped, void* param = NULL){
			SharedPointer<IProcessor> proc_recv (
					new demo::CallbackRecverProcessor(
						SharedPointer<callback_recv_impl_t> (new callback_recv_impl_t) ));

//			TimeUtil::safe_sleep_s(bgcc::ThreadUtil::self_id()%10);
			ServiceManager mgr;
			mgr.add_service(proc_recv);
			ServerInfo si(SERVER_IP, SERVER_PORT);

			for(int32_t i=0; i<PER_CLIENT_EXECUTE; ++i) {
				_prx = new(std::nothrow)demo::CallbackSenderProxy(si, &mgr, 0, 0);
				//_prx = new(std::nothrow)demo::CallbackSenderProxy(si, NULL, 0, 0);
				if(!_prx){
					BGCC_TRACE("client", "prx create failed");
					return -1;
				}
				BGCC_TRACE("client", "Proxy Name is %s", _prx->get_name().c_str());
				_prx->set_property(bgcc::BaseProxy::PROXY_RECV_TIMEOUT, 3000);
				demo::CallbackResult result=_prx->AddClient();
				if(_prx->get_errno()==0&&result==demo::CallbackResult::R_SUCC){
					BGCC_TRACE("client", "AddClient %s Success", _prx->get_name().c_str());
//					TimeUtil::safe_sleep_s(1);
					result = _prx->DelClient();
					if(_prx->get_errno()!=0||result!=demo::CallbackResult::R_SUCC){
						BGCC_WARN("client", "DelClient %s Failed, errno=%d, result=%d", 
								_prx->get_name().c_str(), _prx->get_errno(), result.get_value());
					}
					else{
						BGCC_TRACE("client", "DelClient %s Success", _prx->get_name().c_str());
					}
				}
				else{
					BGCC_WARN("client", "AddClient %s Failed, errno=%d, result=%d", 
							_prx->get_name().c_str(), _prx->get_errno(), result.get_value());
				}

				if(_prx){
					delete _prx;
					_prx=NULL;
				}

				//TimeUtil::safe_sleep_s(10);
			}

			TimeUtil::safe_sleep_s(10);
			return 0;
		}
	private:
		demo::CallbackSenderProxy *_prx;
};

int main( int argc, char **argv ){
	log_open("client.cfg");
	
	ThreadPool pool;
	pool.init(POOL_SIZE);

	for(int32_t i=0; i<CLIENT_COUNT; ++i){
		pool.addTask( SharedPointer<ClientTask>(new (std::nothrow)ClientTask));
		//pool.addTask( SharedPointer<UUIDTask>(new (std::nothrow)UUIDTask));
	}

	pool.terminate();
	pool.join();
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
