/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SERVERINFO_H_
#define _BGCC_SERVERINFO_H_

#include <string>

#include "bgcc_common.h"

namespace bgcc {
    
    class ServerInfo {
        public:
            ServerInfo() : _port(0) { }
            ServerInfo(const std::string& ip, uint16_t port); 
            ServerInfo(const std::string& ip, int port); 

            // getIP & getPort was deprecated
            std::string getIP() const;
            uint16_t getPort() const;

            std::string ip() const;
            uint16_t port() const;

            void ip(const std::string& ip);
            void port(uint16_t port);
        private:
            std::string _ip;
            int32_t _port;
    };

}

#endif
