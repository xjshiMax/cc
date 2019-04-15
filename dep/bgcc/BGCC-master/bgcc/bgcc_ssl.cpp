/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <errno.h>
#include <stdio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <bgcc_ssl.h>

namespace bgcc {

    SSL_CTX* g_ssl_ctx;

    int ssl_init(const struct ssl_init* init)
    {
        int type;
        int ver;
        const SSL_METHOD* method = NULL;

        if (!init) {
            return 1;
        }

        type = init->type;
        ver = init->version;
        if (type != SSL_SERVER && type != SSL_CLIENT) {
            return 1;
        }

        SSL_library_init();
        OpenSSL_add_all_algorithms();
        SSL_load_error_strings();

        if (ver == SSLv2 && type == SSL_SERVER) {
            method = SSLv2_server_method();
        } else if (ver == SSLv3 && type == SSL_SERVER) {
            method = SSLv3_server_method();
        } else if (ver == TLSv1 && type == SSL_SERVER) {
            method = TLSv1_server_method();
        } else if (ver == SSLv23 && type == SSL_SERVER) {
            method = SSLv23_server_method();
        } else if (ver == SSLv2 && type == SSL_CLIENT) {
            method = SSLv2_client_method();
        } else if (ver == SSLv3 && type == SSL_CLIENT) {
            method = SSLv3_client_method();
        } else if (ver == TLSv1 && type == SSL_CLIENT) {
            method = TLSv1_client_method();
        } else if (ver == SSLv23 && type == SSL_CLIENT) {
            method = SSLv23_client_method();
        } else {
            return 1;
        }

        g_ssl_ctx = SSL_CTX_new(const_cast<SSL_METHOD*>(method));
        if (g_ssl_ctx == NULL) {
            ERR_print_errors_fp(stderr);
            return 1;
        }

        if (init->cert_file) {
            if (SSL_CTX_use_certificate_file(g_ssl_ctx, init->cert_file, SSL_FILETYPE_PEM) <= 0) {
                ERR_print_errors_fp(stderr);
                return 1;
            }
        }

        if (init->pkey_file) {
            if (SSL_CTX_use_PrivateKey_file(g_ssl_ctx, init->pkey_file, SSL_FILETYPE_PEM) <= 0) {
                ERR_print_errors_fp(stderr);
                return 1;
            }
        }

        if (init->cert_file && init->pkey_file) {
            if (!SSL_CTX_check_private_key(g_ssl_ctx)) {
                ERR_print_errors_fp(stderr);
                return 1;
            }
        }

        return 0;
    }

    int ssl_uninit()
    {
        SSL_CTX_free(g_ssl_ctx);
        return 0;
    }

}

