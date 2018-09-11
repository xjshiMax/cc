/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef BGCC_SSL_CLIENT_SOCKET_H
#define BGCC_SSL_CLIENT_SOCKET_H

#include <string>
#include <client_socket.h>
#include <bgcc_ssl.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

namespace bgcc {

    class SSLClientSocket : public ClientSocket {
        public:
            SSLClientSocket(const std::string& host, int port) : ClientSocket(host, port), _ssl(NULL) {
            }

            virtual ~SSLClientSocket() { /* empty */ 
                close();
            }

            virtual int32_t open();

            virtual int32_t close();

            virtual int32_t read(void* buffer, int32_t length);

            virtual int32_t write(const void* buffer, int32_t length);

            virtual bool peek() const;

            SSL* ssl() const {
                return _ssl;
            }

        private:
            SSL* _ssl;
    };
}

#endif
