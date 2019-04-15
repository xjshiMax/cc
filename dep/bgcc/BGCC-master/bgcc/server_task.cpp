/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <iostream>

#include "server_task.h"
#include "mempool.h"
#include "log.h"
#include "binary_protocol.h"
#include "socket_util.h"
#include "service_framework.h"

namespace bgcc {

    ServerTask::ServerTask(
            SharedPointer<IProcessor> processor, void* request, int32_t request_len, 
			SharedPointer<IProtocol> out, void *asso
            ) : _processor(processor), _request(request), _request_len(request_len), 
				_out(out), _asso(asso)
			{}

    int32_t ServerTask::operator()(const bool* , void* ) {
        int32_t ret = _processor->process(
                (char*)_request, 
                _request_len,
                _out);

#ifndef _WIN32
		TaskAsso *pT= (TaskAsso*)_asso;
        if(pT){
			if(pT->pItem){
				pT->pItem->Reset();
			}

			//after add_event, epoll may recv msg if pT->Reset after add_event, may 
			//result destroy datacallback logic.
			//so save pT' data before add_event, and do pT->Reset before add_event 
			Event e=pT->event;
			EventLoop *l=pT->pLoop;
			pT->Reset();

			if(!l || l->add_event(&e)!=0){
				BGCC_WARN("bgcc", "After Process Add(fd=%d) To Epoll Faild", e.fd);
				SocketTool::close(e.fd);
			}
			else{
				BGCC_TRACE("bgcc", "After Process Add(fd=%d) To Epoll Success", e.fd);
			}
		}
#endif
        return ret;
    }
}
