/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "server_info.h"

namespace bgcc {

    ServerInfo::ServerInfo(const std::string& ip, uint16_t port)
    {
        _ip = ip;
        _port = port;
    }

    ServerInfo::ServerInfo(const std::string& ip, int port)
    {
        _ip = ip;
        _port = (uint16_t)port;
    }

    std::string ServerInfo::getIP() const {
        return _ip;
    }

    uint16_t ServerInfo::getPort() const {
        return _port;
    }

    std::string ServerInfo::ip() const {
        return _ip;
    }

    uint16_t ServerInfo::port() const {
        return _port;
    }

    void ServerInfo::ip(const std::string& ip) {
        _ip = ip;
    }

    void ServerInfo::port(uint16_t port) {
        _port = port;
    }

}
