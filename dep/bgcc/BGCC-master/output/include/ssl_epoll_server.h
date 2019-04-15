/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef BGCC_SSL_EPOLL_SERVER_H_
#define BGCC_SSL_EPOLL_SERVER_H_

#ifndef _WIN32

#include <epoll_server.h>

namespace bgcc {

    class SSLEpollServer : public EpollServer {
        public:
            SSLEpollServer(ServiceManager* service_manager,
                    ThreadPool* thread_pool,
                    uint16_t port,
                    const std::string& node = "");

            virtual ~SSLEpollServer() { }

            virtual int32_t serve();
    };
}

#endif

#endif
