/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "socket_util.h"
#include "server_peer_socket.h"
#include "log.h"

namespace bgcc {
    int32_t SocketTool::getsockdetail(SOCKET sockfd, PeerInfo& peerInfo, bool remote) {
        struct sockaddr_in addr;

        memset(&addr,0,sizeof addr);

        int len = sizeof addr;
        int ret = 0;
		
		if(remote){
			ret=getpeername(sockfd,(struct sockaddr*)&addr,(socklen_t*)&len);
		}
		else{
			ret=getsockname(sockfd,(struct sockaddr*)&addr,(socklen_t*)&len);
		}
        
		if(ret != 0){
            return -1;
        }

        peerInfo.SetHost(inet_ntoa(addr.sin_addr));
        peerInfo.SetPort(ntohs(addr.sin_port));
        return 0;
    }

	bool SocketTool::is_interrupt(){
#ifdef _WIN32
		return WSAGetLastError()==WSAEINTR;
#else
		return EINTR==errno;
#endif
	}

	bool SocketTool::is_wouldblock(){
#ifdef _WIN32
		int32_t error = WSAGetLastError();
		return (WSAEWOULDBLOCK==error 
				|| WSA_IO_PENDING==error 
				|| ERROR_IO_PENDING==error);
#else
		return (EAGAIN==errno || EWOULDBLOCK==errno);
#endif
	}

	int32_t SocketTool::set_tcpnodealy(SOCKET fd, int32_t val){
		return setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (char*)&val, (int32_t)sizeof(int32_t));
	}

	int32_t SocketTool::set_sndbufsize( SOCKET fd, int32_t sz ){
		return setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char*)&sz, (int32_t)sizeof(int32_t));
	}

	int32_t SocketTool::set_rcvbufsize( SOCKET fd, int32_t sz){
		return setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char*)&sz, (int32_t)sizeof(int32_t));
	}
        
	int32_t SocketTool::set_keepalive(SOCKET fd, int32_t val){
		return setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (char*)&val, int(sizeof(int32_t)));
    }
	
	int32_t SocketTool::set_reuseaddr(SOCKET fd, int32_t val){
		return setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char*)&val, int(sizeof(int32_t)));
    }

	int32_t SocketTool::set_nonblock(SOCKET fd, int32_t val){
#ifdef _WIN32
		unsigned long v=val;
		return ioctlsocket(fd, FIONBIO, &v);
#else
		int32_t flags = fcntl(fd, F_GETFL, 0);
		if(val){
			flags |= (O_NONBLOCK);
		}
		else{
			flags &= (~O_NONBLOCK);
		}
		return fcntl(fd, F_SETFL, flags);
#endif
	}

	int32_t SocketTool::set_sndtimeout(SOCKET fd, int32_t ms){
#ifdef _WIN32
		int32_t timeout=ms;
#else
		struct timeval timeout;
		timeout.tv_sec=ms/1000;
		timeout.tv_usec=ms%1000 * 1000;
#endif
		return setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, (char*)(&timeout), sizeof(timeout));
	}

	int32_t SocketTool::set_rcvtimeout(SOCKET fd, int32_t ms){
#ifdef _WIN32
		int32_t timeout=ms;
#else
		struct timeval timeout;
		timeout.tv_sec=ms/1000;
		timeout.tv_usec=ms%1000 * 1000;
#endif
		return setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (char*)(&timeout), sizeof(timeout));
	}

        int32_t SocketTool::init() {
            int32_t ret = 0;
#ifdef _WIN32
			WSADATA info;
			memset(&info, 0, sizeof(info));
			ret=WSAStartup(MAKEWORD(2, 0), &info);
#endif
            return ret;
        }

        int32_t SocketTool::uninit() {
			int32_t ret=0;
#ifdef _WIN32
			ret=WSACleanup();
#endif
            return ret;
        }
		
		int32_t SocketTool::close( SOCKET& sock ) {
            int32_t ret = 0;

            if (INVALID_SOCKET != sock) {
#ifdef _WIN32 
                ret = (shutdown(sock, SD_BOTH), ::closesocket(sock));
#else
                ret = (shutdown(sock, SHUT_RDWR), ::close(sock));
#endif	
				BGCC_DEBUG("bgcc", "fd=%d Closed", sock);
                sock = INVALID_SOCKET;
            }
            
		    return ret;
        }

        int32_t SocketTool::peek(SOCKET fd){
            char buffer[1];
#ifdef _WIN32
            return recv(fd, buffer, 1, MSG_PEEK);
#else
			return recv(fd, buffer, 1, MSG_PEEK|MSG_DONTWAIT);
#endif
        }    
        
    	bool SocketTool::is_ok(SOCKET sock){
            if(INVALID_SOCKET==sock){
                return false;
            }
            else{
#ifdef _WIN32
                int32_t optval=0, optlen=sizeof(int32_t); 
                if(getsockopt(sock, SOL_SOCKET, SO_ERROR, (char*)&optval, &optlen)==0){
                    return (optval == 0);
                }
#else
                struct tcp_info info;
                int32_t len = sizeof(info);
                memset(&info, 0, len);
                if(getsockopt(sock, IPPROTO_TCP, TCP_INFO, &info, (socklen_t*)&len)==0){
                    return (info.tcpi_state == TCP_ESTABLISHED);
                }
#endif
            }

            return true;//getsockopt error, cannot judge
        }

		const int32_t SocketTool::DEF_BUF_SIZE= 128*1024;

#ifdef _WIN32
	WSAInstance *_g= WSAInstance::Instance();
#endif
}

