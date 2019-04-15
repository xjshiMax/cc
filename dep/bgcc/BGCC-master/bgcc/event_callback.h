/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef  __EVENT_CALLBACK_H_
#define  __EVENT_CALLBACK_H_

#include <map>

#include "sema.h"
#include "socket_util.h"
#include "service_framework.h"

#ifndef _WIN32
#include "event_poll.h"
#include <openssl/ssl.h>

namespace bgcc{
   /**
	* @brief Epoll callback deal
	*
	* WARNING: not thread safe
	*  
	*/
	class EventCallback{
		public:
			static void DataCallback  (EventLoop *el, SOCKET fd, void* arg);
			static void StatCallback  (EventLoop *el, SOCKET fd, void* arg);
			static void ErrCallback   (EventLoop *el, SOCKET fd, void* arg);
			static void AcceptCallback(EventLoop *el, SOCKET fd, void* arg);
			static void RemoveFD      (EventLoop *el, SOCKET fd, bool toclose=true);

			static void PrepareEvent(Event& e, SOCKET sock, void* arg=NULL);

		public:
			const static uint32_t DEFAULT_MASK;
			static ReadItem Items[MAXNFD];
	};

	struct SSLEventCallbackArg {
		void* arg;
		SSL* ssl;
	};

	class SSLEventCallback{
		public:
			static void DataCallback  (EventLoop *el, SOCKET fd, void* arg);
			static void StatCallback  (EventLoop *el, SOCKET fd, void* arg);
			static void ErrCallback   (EventLoop *el, SOCKET fd, void* arg);
			static void AcceptCallback(EventLoop *el, SOCKET fd, void* arg);
			static void SSLAcceptCallback(EventLoop *el, SOCKET fd, void* arg);
			static void RemoveFD      (EventLoop *el, SOCKET fd, bool toclose=true);

			static void PrepareEvent(Event& e, SOCKET sock, void* arg=NULL);

		public:
			const static uint32_t DEFAULT_MASK;
			static ReadItem Items[MAXNFD];
			static SSLEventCallbackArg args[MAXNFD];
	};

}

#endif

namespace bgcc{
   /**
	* @brief Business logic deal
	*
	* WARNING: interface support windows, but imp dont support 
	*  
	*/
	class BusizProcessor{
		public:
			static void Process(ReadItem *pItem, void *param, int32_t body_len, int32_t *todel=NULL, bool ssl = false, void* arg = NULL);
		private:
			static void ProcessHB(ReadItem *pItem, bool ssl = false, void* arg = NULL);
			static void ProcessEnroll(ReadItem *pItem, void *param, bool ssl = false, void* arg = NULL);
			static void ProcessServerCallback(ReadItem *pItem, void *param, int32_t *todel, bool ssl = false, void* arg = NULL);
			static void ProcessUser(ReadItem *pItem, const std::string &name, void *param, bool ssl = false, void* arg = NULL);

	};
}

#endif  //__EVENT_CALLBACK_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
