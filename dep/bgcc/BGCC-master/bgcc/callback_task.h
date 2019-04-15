/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef  __CALLBACK_TASK_H_
#define  __CALLBACK_TASK_H_

#include <string>

#include "runnable.h"
#include "selector.h"
#include "client_socket.h"
#include "service_manager.h"
#include "binary_protocol.h"

namespace bgcc{

	class CallBackTask : public Runnable{
		public:
			CallBackTask(const std::string server, int32_t port,
				   const std::string proxy, ServiceManager *sm,
				   Selector *selector);

			~CallBackTask();

			int32_t operator()(const bool *isstopped, void *param=NULL);

		private:
			bool Register();

		private:
			const static int32_t DEFAULT_WAIT_TIMEOUT;
			
			std::string _server;
			int32_t _port;
			std::string _prx;
			ServiceManager *_sm;

			Selector *_pselector;
			
			char _buf_head[HEAD_SIZE];
			char _buf_body[MAX_DEFAULT_LEN];
	
			SharedPointer<ClientSocket> _connect;
			SharedPointer<BinaryProtocol> _proto;
			SharedPointer<IProcessor> _processor;
	};
}


#endif  //__CALLBACK_THREAD_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
