/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  *
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_EXCEPTION_INTERNAL_H_
#define _BGCC_EXCEPTION_INTERNAL_H_

#include "bgcc_common.h"
#include "bgcc_error.h"

#include <exception>
#include <string>
#include <sstream>

#define SOCKBUFSIZE 1024

namespace bgcc {

enum {
    OPERSUCCESS = 0,
    BUFFERISNULL = -1,
    SOCKETNOTOPEN = -2,
    SETSOCKOPTFAIL = -3,
    PEEREXCEPTION = -4,
    CREATESOCKETFAIL = -5,
    WRITEEXCEPTION = -6,
    READEXCEPTION = -7,
    CONNECTSERVERFAIL = -8,
    GETADDRFAIL = -9,
    PORTINVALID = -10,
    BINDSOCKETFAIL = -11,
    LISTENFAIL = -12,
    SOCKETINVALID = -13,
    GETPEERNAMEFAIL = -14,
    CLOSESOCKETFAIL = -15,
    SOCKETINTERRUPT = -16,
    CREATEINTERSOCKFAIL = -17,

    /*以下错误码为windows下专用*/
    WSACLEANUPERROR = -18,
    WSASTARTUPERROR = -19,

};

class Exception {
public:
    void set_errno(int32_t e) {
        //BgccGetLastError() = e;
        errno = e;
    }

    int32_t get_errno() {
        //return BgccGetLastError();
        return errno;
    }

    virtual ~Exception() {}

    const char* get_err_msg() {
        return "error";
    }
};

class ConfigurationException : public std::exception {
public:
    ConfigurationException(const std::string& msg): _msg("ConfigurationException> " + msg) {
    }

    ~ConfigurationException() throw() {
    }

    virtual const char * what() const throw() {
        return _msg.c_str();
    }

private:
    std::string _msg;
};

class SSLException : public std::exception {
    public:
        SSLException(const std::string& msg) : _msg("SSLException> " + msg) {
        }

        ~SSLException() throw() {
        }

        virtual const char* what() const throw() {
            return _msg.c_str();
        }
    private:
        std::string _msg;
};

}

#endif
