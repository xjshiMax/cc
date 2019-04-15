/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _WIN32

#include <map>
#include <string>
#include <sstream>

#include "epoll_server.h"
#include "log.h"
#include "bgcc_error.h"
#include "thread_pool.h"
#include "socket_util.h"
#include "event_callback.h"

namespace bgcc {
    EpollServer::EpollServer(ServiceManager* service_manager,
            ThreadPool* thread_pool,
            uint16_t port,
            const std::string & node) :
        _service_manager(service_manager),
        _thread_pool(thread_pool),
        _port(port),
        _state(S_UNINIT),
        _listenfd(-1),
        _node(node) {
        }

    int32_t EpollServer::init() {
        signal(SIGPIPE, SIG_IGN);
        if (S_UNINIT != _state) {
            BGCC_NOTICE("bgcc", "Instance of EpoolServer has already been initialized!\n");
            return E_BGCC_SERVER_ALREADY_INIT;
        }

        if (0 != _loop.create()) {
            return E_BGCC_SERVER_INIT_FAILED;
        }
        _state = S_INIT;
        return 0;
    }

    int32_t EpollServer::serve() {

        int32_t ret;
        if (0 != (ret = init())) {
            return ret;
        }

        if (S_INIT != _state) {
            BGCC_NOTICE("bgcc", "Need to call `init' before `serve' on Instance of EpollServer\n");
            return E_BGCC_SERVER_NEED_INIT;
        }

        _listenfd = socket_init();
        if (INVALID_SOCKET == _listenfd) {
            return E_BGCC_SERVER_CREATE_LISTENFD_FAILED;
        }

        Event e;
		EventCallback::PrepareEvent(e, _listenfd, const_cast<EpollServer*>(this));
        e.read_cb = EventCallback::AcceptCallback;
        _loop.add_event(&e);

        BGCC_NOTICE("bgcc", "fd=%d Is Begin To Wait for accept new client On %s:%d", 
				_listenfd, (_node.empty()?"*":_node.c_str()), _port);
        _state = S_SERVE;
        
		return _loop.loop();
    }

    int32_t EpollServer::stop() {
        if (S_SERVE != _state) {
            return -1;
        }

        _loop.unloop();
        _loop.destroy();

		SocketTool::close(_listenfd);
        
		return 0;
    }

    ServiceManager* EpollServer::get_service_manager() {
        return _service_manager;
    }

    ThreadPool* EpollServer::get_thread_pool() {
        return _thread_pool;
    }

    int32_t EpollServer::socket_init() {
        int32_t ret = 0;
        char buffer[BUFSIZ];
		SOCKET listener=INVALID_SOCKET;

        struct addrinfo hints, *res=NULL, *res0=NULL;
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = PF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        std::stringstream ss;
        std::string port;
        ss << _port;
        ss >> port;

        ret = getaddrinfo(_node.empty() ? NULL : _node.c_str(), port.c_str(), &hints, &res0);
        if (0 != ret) {
			BGCC_WARN("bgcc", "socket_init Failed to getaddrinfo[errno=%d(%s)]",
				BgccSockGetLastError(), 
				bgcc::bgcc_strerror_r(BgccSockGetLastError(), buffer, BUFSIZ));
			return listener;
        }

		for(res=res0; res; res=res->ai_next){
			if ((listener = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
				BGCC_WARN("bgcc", "Failed to socket[errno=%d(%s)]",
					BgccSockGetLastError(),
					bgcc::bgcc_strerror_r(BgccSockGetLastError(), buffer, BUFSIZ));
				continue;
		    } 
			
			SocketTool::set_reuseaddr(listener, 1);
			SocketTool::set_keepalive(listener, 1);
			SocketTool::set_tcpnodealy(listener, 1);

			if (bind(listener, res->ai_addr, res->ai_addrlen) == -1) {
				BGCC_WARN("bgcc", "Failed to bind[errno=%d(%s)]",
					BgccSockGetLastError(), 
					bgcc::bgcc_strerror_r(BgccSockGetLastError(), buffer, BUFSIZ));
				SocketTool::close(listener);
				continue;
		    }

			if (listen(listener, 100) == -1) {
				BGCC_WARN("bgcc", "Failed to listen[errno=%d(%s)]",
					BgccSockGetLastError(), 
					bgcc::bgcc_strerror_r(BgccSockGetLastError(), buffer, BUFSIZ));
				SocketTool::close(listener);
				continue;
		    } 

			break;
		}
		
		if(!res){
			BGCC_FATAL("bgcc", "Failed to init all addr[errno=%d(%s)]",
				BgccSockGetLastError(), 
				bgcc::bgcc_strerror_r(BgccSockGetLastError(), buffer, BUFSIZ));
		}
		else{
			BGCC_NOTICE("bgcc", "Success To listen on %s:%d fd=%d", 
					(_node.empty()?"*":_node.c_str()), _port, listener);
		}

        freeaddrinfo(res0);
        return listener;
    }
}

#endif // _WIN32



