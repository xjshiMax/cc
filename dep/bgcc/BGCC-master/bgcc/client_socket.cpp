/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "client_socket.h"
#include "transport.h"
#include "exception.h"
#include "bgcc_error.h"
#include "string_util.h"

namespace bgcc {
    bool ClientSocket::is_open() const {
        return SocketTool::is_ok(_socket);
    }

    int32_t ClientSocket::open_impl(struct addrinfo *res) {
        if (!res) {
            return E_BGCC_NULL_POINTER;
        }

        //create a socket
        _socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (INVALID_SOCKET == _socket) {
		    BGCC_WARN("bgcc", "Client Connect To %s:%d Failed , fd=%d , ERR:%d", 
                    _host.c_str(), _port, _socket, BgccSockGetLastError());
            return -1;
        }

        //connect to server
        int32_t ret = connect(_socket, res->ai_addr, (int32_t)res->ai_addrlen);
        if (0 != ret) {
		    BGCC_WARN("bgcc", "Client Connect To %s:%d Failed , fd=%d , ERR:%d", 
                    _host.c_str(), _port, _socket, BgccSockGetLastError());
			close();
            return -1;
        }

		PeerInfo tmp("", 0);
		SocketTool::getsockdetail(_socket, tmp, false);
		BGCC_NOTICE("bgcc", "Client Connect (%s:%d-->%s:%d) Success, fd=%d", 
				tmp.GetHost().c_str(), tmp.GetPort(),
				_host.c_str(), _port, 
				_socket);

		SocketTool::set_sndbufsize(_socket, SocketTool::DEF_BUF_SIZE);
		SocketTool::set_rcvbufsize(_socket, SocketTool::DEF_BUF_SIZE);

		SocketTool::set_tcpnodealy(_socket, 1);

        return 0;
    }
    int32_t ClientSocket::get_address_list(struct addrinfo **ppres) {		

        struct addrinfo hints;
        memset((void*)&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        std::stringstream ss;
        ss << _port;
        std::string port;
        ss >> port;

        return (getaddrinfo(_host.empty() ? NULL: _host.c_str(), port.c_str(), &hints, ppres) == 0 ? 0 : -1);
    }


    int32_t ClientSocket::open() {
		close();

        int32_t ret = 0;
        struct addrinfo *res, *res0;
        ret = get_address_list(&res0);
        if (0 != ret) {
            return ret;
        }

        for (res = res0; NULL != res; res = res->ai_next) {
            ret = open_impl(res);
            if (0 == ret) {
				SocketTool::set_sndtimeout(_socket, DEFAULT_CLIENT_TIMEOUT);
				SocketTool::set_rcvtimeout(_socket, DEFAULT_CLIENT_TIMEOUT);
                break;
            } 
        }   

        freeaddrinfo(res0);
		return ret;
    }
}

