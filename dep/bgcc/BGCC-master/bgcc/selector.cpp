/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "selector.h"
#include "log.h"
#include "bgcc_error.h"
#include "socket_util.h"
#include "binary_protocol.h"

bgcc::Selector::Selector(int32_t hb_timeout):_hb_timeout(hb_timeout){
	init();
}

void bgcc::Selector::init(){
	_sock=INVALID_SOCKET;
	_timeout=-1;
#ifdef _WIN32
	memset(&_fds, 0, sizeof(struct fd_set));
	memset(&_tv, 0, sizeof(struct timeval));
#else
	_ep=INVALID_SOCKET;
	memset(_revents, 0, sizeof(struct epoll_event));
#endif
}

int32_t bgcc::Selector::Create(){
	int32_t ret=0;

#ifdef _WIN32
	FD_ZERO(&_fds);
#else
	ret= ((_ep=epoll_create(1))>0?0:-1);
#endif

	return ret;
}

void bgcc::Selector::Destroy(){
#ifndef _WIN32
	if(INVALID_SOCKET!=_ep){
		SocketTool::close(_ep);
	}
#endif
}

int32_t bgcc::Selector::Update(SOCKET fds_r, int32_t timeout){
	int32_t ret=0;
#ifndef _WIN32
	struct epoll_event ee;
	memset(&ee, 0, sizeof(struct epoll_event));
	if(INVALID_SOCKET==_ep){
		ret=-1;
		goto END;
	}
#endif

	if(INVALID_SOCKET!=_sock){
#ifdef _WIN32
		FD_ZERO(&_fds);
		_sock=INVALID_SOCKET;
#else
		ret=epoll_ctl(_ep, EPOLL_CTL_DEL, _sock, &ee);
		if(0!=ret){
			goto END;
		}
		else{
			_sock=INVALID_SOCKET;
		}
#endif
	}

	if(INVALID_SOCKET!=fds_r){
#ifdef _WIN32
		FD_ZERO(&_fds);
		FD_SET(fds_r, &_fds);
#else
		ee.data.fd=fds_r;
		ee.events=EPOLLIN;
		ret=epoll_ctl(_ep, EPOLL_CTL_ADD, fds_r, &ee);
#endif
	}

	if(0==ret){
		_sock=fds_r;
		_timeout=timeout;
#ifdef _WIN32
		_tv.tv_sec = _timeout/1000;
		_tv.tv_usec = _timeout%1000 *1000;
#endif
	}

#ifndef _WIN32
END:
#endif
	return ret;
}

int32_t bgcc::Selector::UpdateHBTimeout(int32_t timeout)
{
	if(timeout>DEFAULT_HB_TIMEOUT){
		_hb_timeout=timeout;
	}

	return _hb_timeout;
}

int32_t bgcc::Selector::Select(SSL* ssl){
	int32_t ret=0;
	static int64_t last_deal=TimeUtil::get_timestamp_ms(); //no need threadsafe

	if(INVALID_SOCKET==_sock){
		return -1;
	}

#ifdef _WIN32
	struct timeval *ptv=NULL;
	if(_timeout>=0){
		ptv=&_tv;
	}
	struct fd_set fds_copy=_fds;
	ret=select((int32_t)_sock+1, &fds_copy, NULL, NULL, ptv);
#else
	memset(_revents, 0, sizeof(struct epoll_event));
	while((ret=epoll_wait(_ep, _revents, 1, _timeout))==SOCKET_ERROR&&SocketTool::is_interrupt());
#endif

	if(0==ret){
		if(TimeUtil::get_timestamp_ms()-last_deal>=_hb_timeout){
			BGCC_TRACE("bgcc", "%ds not Recv Data, Try To HeartBeat Send fd=%d",_hb_timeout/1000, _sock);
		
			//trick.....	
			//in order to judge quickly, reduce the sndbuf size , then the third send will EAGAIN when
			//network is unable to connect to server

			if (!ssl) {
				SocketTool::set_sndbufsize(_sock, HEAD_SIZE*2);
				int32_t r=send(_sock, (const char*)bp_hb_hdr, HEAD_SIZE, 0);
				last_deal=TimeUtil::get_timestamp_ms();

				if(0==r||(SOCKET_ERROR==r&&!SocketTool::is_interrupt())){
					ret=-1;
					BGCC_WARN("bgcc", "HeartBeat Send fd=%d, ret=%d, errno=%d", _sock, r, BgccSockGetLastError());
				}
				else{
					BGCC_TRACE("bgcc", "HeartBeat Send fd=%d, ret=%d", _sock, r);
				}
			} else {
				int nwritten = 0;
				int xwritten = 0;

				while (nwritten < HEAD_SIZE) {
					if (-1 == ret) {
						break;
					}

					xwritten = SSL_write(ssl, (const char*)bp_hb_hdr + nwritten, HEAD_SIZE - nwritten);

					switch(SSL_get_error(ssl, xwritten)) {
						case SSL_ERROR_NONE:
							nwritten += xwritten;
							break;
						case SSL_ERROR_ZERO_RETURN:
							ret = -1;
							break;
						case SSL_ERROR_WANT_READ:
						case SSL_ERROR_WANT_WRITE:
							continue;
							break;
						default:
							ret = -1;
					}
				}
			}
		}
	}
	else if(ret>0){
		SocketTool::set_sndbufsize(_sock, SocketTool::DEF_BUF_SIZE);
		last_deal=TimeUtil::get_timestamp_ms();
		if(SocketTool::peek(_sock)<=0){
			ret=-1;
		}
	}

	return ret;
}













/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
