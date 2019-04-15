/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SOCKET_UTIL_H_
#define _BGCC2_SOCKET_UTIL_H_

#include "bgcc_common.h"

#include "peer_info.h"

namespace bgcc {
	class SocketTool{
	public:
	    static int32_t getsockdetail(SOCKET sockfd, PeerInfo& peerInfo, bool remote=false); 
		static bool is_interrupt();
		static bool is_wouldblock();
		static int32_t set_tcpnodealy(SOCKET fd, int32_t val);
		static int32_t set_sndbufsize(SOCKET fd, int32_t sz);
		static int32_t set_rcvbufsize(SOCKET fd, int32_t sz);
        static int32_t set_keepalive(SOCKET fd, int32_t val);
        static int32_t set_reuseaddr(SOCKET fd, int32_t val);
		static int32_t set_nonblock(SOCKET fd, int32_t val);
		static int32_t set_sndtimeout(SOCKET fd, int32_t ms);
		static int32_t set_rcvtimeout(SOCKET fd, int32_t ms);
        static bool is_ok(SOCKET sock);
        static int32_t close(SOCKET &fd);
        static int32_t peek(SOCKET fd);
        
		static int32_t init();
        static int32_t uninit();
	public:
		const static int32_t DEF_BUF_SIZE;
	};

#ifdef _WIN32
	class WSAInstance{
		private:
			WSAInstance(){
				(void)SocketTool::init();
			}
			~WSAInstance(){
				(void)SocketTool::uninit();
			}
		public:
			static WSAInstance * Instance(){
				static WSAInstance _inst;
				return &_inst;
			}
	};

	extern WSAInstance *_g;
#endif
}

#endif // _BGCC2_SOCKET_UTIL_H_

