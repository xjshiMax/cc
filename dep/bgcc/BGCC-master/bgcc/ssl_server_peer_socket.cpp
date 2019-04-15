/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <ssl_server_peer_socket.h>
#include <log.h>

namespace bgcc {
    SSLServerPeerSocket::~SSLServerPeerSocket() {
     //   if (_ssl) {
     //       SSL_shutdown(_ssl);
     //       SSL_free(_ssl);
     //       _ssl = NULL;
     //   }
    }

    int32_t SSLServerPeerSocket::read(void* buffer, int32_t length) {
        int32_t nread = 0;
        int32_t xread = 0;

        while (nread < length && *_ssl) {
            xread = SSL_read(*_ssl, (char*)buffer + nread, length - nread);

            switch(SSL_get_error(*_ssl, xread)) {
                case SSL_ERROR_NONE:
                    nread += xread;
                    break;
                case SSL_ERROR_ZERO_RETURN:
                    return -1;
                    break;
                case SSL_ERROR_WANT_READ:
                case SSL_ERROR_WANT_WRITE:
                    continue;
                    break;
                default:
                    return -1;
            }
        }

        if (!*_ssl) {
            return -1;
        }

        return 0;
    }

    int32_t SSLServerPeerSocket::write(const void* buffer, int32_t length)
    {
        int32_t nread = 0;
        int32_t xread = 0;

        while (nread < length && *_ssl) {
            BGCC_DEBUG("bgcc", "Access SSL: %p", _ssl);
            xread = SSL_write(*_ssl, (const char*)buffer + nread, length - nread);

            switch(SSL_get_error(*_ssl, xread)) {
                case SSL_ERROR_NONE:
                    nread += xread;
                    break;
                case SSL_ERROR_ZERO_RETURN:
                    return -1;
                case SSL_ERROR_WANT_READ:
                case SSL_ERROR_WANT_WRITE:
                    continue;
                default:
                    return -1;
            }
        }

        if (!*_ssl) {
            return -1;
        }

        return 0;
    }
}

