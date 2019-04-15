/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _WIN32

#include <ssl_epoll_server.h>

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
    SSLEpollServer::SSLEpollServer(ServiceManager* service_manager,
            ThreadPool* thread_pool,
            uint16_t port,
            const std::string& node) :
        EpollServer(service_manager, thread_pool, port, node) { }

    int32_t SSLEpollServer::serve() {
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

        SSLEventCallbackArg* callbackArg = &SSLEventCallback::args[_listenfd];
        callbackArg->ssl = NULL;
        callbackArg->arg = const_cast<SSLEpollServer*>(this);
        Event e;
        SSLEventCallback::PrepareEvent(e, _listenfd, callbackArg);
        e.read_cb = SSLEventCallback::AcceptCallback;
        _loop.add_event(&e);

        BGCC_NOTICE("bgcc", "fd=%d Is Begin To Wait for accept new client On %s:%d", 
                _listenfd, (_node.empty()?"*":_node.c_str()), _port);
        _state = S_SERVE;

        return _loop.loop();
    }
}

#endif

