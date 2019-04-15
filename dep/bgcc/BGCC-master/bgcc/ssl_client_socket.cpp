/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <ssl_client_socket.h>
#include <bgcc_ssl.h>
#include <log.h>

namespace bgcc {

    int32_t SSLClientSocket::open() {
        int32_t ret;

        if ((ret = ClientSocket::open()) != 0) {
            return ret;
        }

        if ((_ssl = SSL_new(g_ssl_ctx)) == NULL) {
            BGCC_DEBUG("bgcc", "Memory SSL: %p", _ssl);
            return 1;
        }

        SSL_set_fd(_ssl, id());

        if (SSL_connect(_ssl) == -1) {
            return 1;
        }

        return 0;
    }

    int32_t SSLClientSocket::close() {
        if (_ssl) {
            SSL_shutdown(_ssl);
            BGCC_DEBUG("bgcc", "Memory SSL free: %p", _ssl);
            SSL_free(_ssl);
            _ssl = NULL;
        }
        return 0;
    }
    
    int32_t SSLClientSocket::read(void* buffer, int32_t length) {
        int32_t nread = 0;
        int32_t xread = 0;

        while (nread < length) {
            xread = SSL_read(_ssl, (char*)buffer + nread, length - nread);

            switch(SSL_get_error(_ssl, xread)) {
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

        return 0;
    }

    int32_t SSLClientSocket::write(const void* buffer, int32_t length)
    {
        int32_t nread = 0;
        int32_t xread = 0;

        while (nread < length) {
            xread = SSL_write(_ssl, (const char*)buffer + nread, length - nread);

            switch(SSL_get_error(_ssl, xread)) {
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

        return 0;
    }

    bool SSLClientSocket::peek() const {
        return true;
    }

}

