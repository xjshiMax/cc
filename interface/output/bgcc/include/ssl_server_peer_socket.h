/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef BGCC_SSL_SERVER_PEER_SOCKET_H
#define BGCC_SSL_SERVER_PEER_SOCKET_H

#include <server_peer_socket.h>
#include <openssl/ssl.h>
#include <exception.h>

namespace bgcc {

    class SSLServerPeerSocket : public ServerPeerSocket {
        public:
            SSLServerPeerSocket(SSL** ssl, SOCKET socket) : ServerPeerSocket(socket), _ssl(ssl) {
            }

            ~SSLServerPeerSocket();
            int32_t read(void* buffer, int32_t length);
            int32_t write(const void* buffer, int32_t length);

        private:
            SSL** _ssl;
    };

}

#endif
