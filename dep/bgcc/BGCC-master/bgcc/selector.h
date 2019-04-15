/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef  __SELECTOR_H_
#define  __SELECTOR_H_

#include "bgcc_common.h"
#include "socket_util.h"

#include <openssl/ssl.h>

namespace bgcc{
class Selector{
	public:
		Selector(int32_t hb_timeout=DEFAULT_HB_TIMEOUT);
		int32_t Create();
		void Destroy();

		int32_t Update(SOCKET fds_r, int32_t timeout=-1);
		int32_t UpdateHBTimeout(int32_t timeout=DEFAULT_HB_TIMEOUT);

		int32_t Select(SSL* ssl = NULL);

	private:
		void init();
		SOCKET _sock;
		int32_t _timeout;
		int32_t _hb_timeout;

#ifdef _WIN32
		struct fd_set _fds;
		struct timeval _tv;
#else
		int32_t _ep;
		struct epoll_event _revents[1];
#endif
};
}
















#endif  //__SELECTOR_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
