/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "socket_base.h"
#include "bgcc_error.h"
#include "log.h"

namespace bgcc {

    Socket::~Socket() {
		//close();
    }

    int32_t Socket::open() {
        return 0;
    }
	
	int32_t Socket::close(){
		return SocketTool::close(_socket);
	}

        int32_t Socket::read(void* buffer, int32_t length)
        {
            char logbuffer[BUFSIZ];
            int32_t nread = 0;
            int32_t err = 0;

            if(!buffer){
                BGCC_WARN("bgcc", "Param buf is NULL. Please check.");
                return E_BGCC_NULL_POINTER;
            }

            while( nread < length) {
				int32_t xread = recv(_socket, (char*)buffer + nread, length - nread, 0);
                
				if(SOCKET_ERROR == xread && SocketTool::is_interrupt()) {
					continue;
				}
#ifdef _WIN32
				else if (SocketTool::is_wouldblock()) {
					continue;
				}
#endif
				else if(xread <= 0){
					if(xread==0){
						BGCC_WARN("bgcc", "[SYS] read peer closed, fd=%d", _socket);
					}
					else{
	                    err = BgccSockGetLastError();
		                BGCC_WARN("bgcc", "[SYS] read errno=%d(%s) fd=%d", err, bgcc::bgcc_strerror_r(err, logbuffer, BUFSIZ), _socket);
					}
                    return E_BGCC_SYSERROR;
                }
                
                nread += xread;
            }
            return 0;
        }

        int32_t Socket::write(const void* buffer, int32_t length) {
            int32_t nwrite = 0;
            int32_t xwrite = 0;
            int32_t errno_cp = 0;
            char logbuffer[BUFSIZ];
            
			if (!buffer) {
                BGCC_WARN("bgcc", "write Param buf is NULL. Please check.");
                return E_BGCC_NULL_POINTER;
            }

            while(nwrite < length) {
                xwrite = send(_socket, (const char*)buffer + nwrite, length - nwrite, 0);
                if (SOCKET_ERROR == xwrite && SocketTool::is_interrupt()) {
					continue;
				}
				else if(xwrite <= 0){
                    errno_cp = BgccSockGetLastError();
					BGCC_WARN("bgcc", "[SYS] write errno=%d(%s) fd=%d", 
                            errno_cp, bgcc::bgcc_strerror_r(errno_cp, logbuffer, BUFSIZ), _socket);
                    return E_BGCC_SYSERROR;
				}
				
				nwrite += xwrite;
   			}

			return 0;
		}

        bool Socket::is_open() const {
            return true;
        }

        bool Socket::peek() const {
			return SocketTool::peek(_socket) > 0;
        }

        Socket::Socket()
            :_socket(INVALID_SOCKET)
        {
        }
}
