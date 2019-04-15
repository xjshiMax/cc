/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "server_peer_socket.h"
#include "socket_util.h"
#include "bgcc_error.h"

namespace bgcc {

	ServerPeerSocket::ServerPeerSocket(SOCKET socket) {
        
		_socket = socket;
		InitPeerInfo();
	}
    
    typedef SharedPointer<PeerInfo> PeerInfoSharedPointer;
    int32_t ServerPeerSocket::InitPeerInfo(){

        if(_socket<0){
            return -1;
        }

        PeerInfo tmp("", 0);
        int32_t ret = SocketTool::getsockdetail(_socket, tmp, true);
        if (ret != 0) {
            return ret;
        }
        _peerinfo = SharedPointer<PeerInfo>(new PeerInfo(tmp.GetHost(), tmp.GetPort()));
 
        return 0;
    }
    
    SharedPointer<PeerInfo> ServerPeerSocket::GetPeerInfo(){
        return _peerinfo;
    }
}
