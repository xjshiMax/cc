/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_CONNECTION_MANAGER_H_
#define _BGCC2_CONNECTION_MANAGER_H_

#include <map>
#include <string>

#include "bgcc_common.h"
#include "sync_vector.h"
#include "shared_pointer.h"
#include "mutex.h"
#include "thread.h"

#include "server_peer_socket.h"
#include "binary_protocol.h"

namespace bgcc {

	class ConnInfo : public Shareable{
		public:
			ConnInfo(SharedPointer<BinaryProtocol> p, ReadItem *pm=NULL):proto(p),param(pm){}
			SharedPointer<BinaryProtocol> proto;
			ReadItem* param;
	};

    class ConnectionNode : public Shareable 
    {
    public:
        ConnectionNode(SharedPointer<ConnInfo> info) : _info(info),_isused(false){
        }
        ~ConnectionNode(){
        }

        int32_t put(SharedPointer<ConnInfo>& conn, bool toclose);
        int32_t get(SharedPointer<ConnInfo>& conn);
        int32_t insert(SharedPointer<ConnInfo> &conn);
        SharedPointer<BinaryProtocol> get_socketname();
    private:
        SharedPointer<ConnInfo> _info ;
		volatile bool _isused;
    };

    class ConnectionManager {
    public:
        static ConnectionManager* get_instance() {
            static ConnectionManager cm;
            return &cm;
        }

        int32_t enroll(const std::string& proxy_name, SOCKET fd, ReadItem* param=NULL, bool ssl = false, void* arg = NULL);
        int32_t put_connection(const std::string& proxy_name, SharedPointer<ConnInfo> info, bool toclose=false);

        SharedPointer<ConnInfo>
            get_connection(const std::string& proxy_name);

        void clear_connection(const std::string& proxy_name);

        ~ConnectionManager();
    private:
        ConnectionManager();
        ConnectionManager(const ConnectionManager&);
        ConnectionManager& operator=(const ConnectionManager&);

    private:
        std::map<std::string, SharedPointer<ConnectionNode> > _proxy_name2connections;
        Mutex _mutex;

    };
}
#endif // _BGCC2_CONNECTION_MANAGER_H_

