/***********************************************************************
 * Copyright (c) 2012, Baidu Inc. All rights reserved.
 * 
 * Licensed under the BSD License
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      license.txt
 *********************************************************************/

#include "connection_manager.h"
#include "guard.h"
#include "time_util.h"
#include "log.h"

#include "event_callback.h"
#include "server_task.h"
#include "ssl_server_peer_socket.h"

namespace bgcc {
	int32_t ConnectionNode::put(SharedPointer<ConnInfo>& info, bool toclose)
	{
		int32_t ret=E_BGCC_SYSERROR;

		if(!info.is_valid()||!info->proto->getTransport().is_valid()){
            if (!info.is_valid()) {
                BGCC_WARN("bgcc", "info.is_valid: %d", info.is_valid());
            } else {
                BGCC_WARN("bgcc", "info->proto->getTransport().is_valid: %d", info->proto->getTransport().is_valid());
            }

			return ret;
		}

		if(_info.is_valid()){
			SharedPointer<ITransport> trans=_info->proto->getTransport();
			if(trans.is_valid()&&info->proto->getTransport()->id()==trans->id()){//curr conn to put
				if(!toclose&&_isused){
					_isused=false;
					_info=info;

					ret=0;
#ifndef _WIN32	
					TaskAsso *pTask=(TaskAsso*)info->param->pTask;
					if(!pTask
							||!pTask->pLoop 
							||pTask->pLoop->add_event(&(pTask->event))!=0){
						BGCC_WARN("bgcc", "ConnInNode put(fd=%d) To Epoll Failed", pTask->event.fd);
						SocketTool::close(pTask->event.fd);
					}
#endif

					if(_info->param){
						ReadItem *pItem=(ReadItem*)(info->param);
						pItem->Reset();
					}
					BGCC_TRACE("bgcc","ConnectionNode put, ret=%d, fd=%d",
							ret, _info->proto->getTransport()->id());
				}
				else if(toclose){
#ifndef _WIN32
					if(info->param){
						TaskAsso *pTask=(TaskAsso*)info->param->pTask;
						EventCallback::RemoveFD(pTask->pLoop, pTask->event.fd);
					}
#endif
					if(_info->param){
						ReadItem *pItem=(ReadItem*)(_info->param);
						pItem->Reset();
					}
					
					BGCC_WARN("bgcc", "ConnectionNode put, invalid fd=%d", trans->id());
					_info=SharedPointer<ConnInfo>(NULL);
					ret=0;
				}
			}
			else if(trans.is_valid()){// old conn to put
				if(info->param){
					ReadItem *pItem=(ReadItem*)(info->param);
					pItem->Reset();
				}
				BGCC_WARN("bgcc", "ConnectionNode put, invalid fd=%d (but now is fd=%d)", 
						info->proto->getTransport()->id(), _info->proto->getTransport()->id());
				ret=-1;
			}
		} else {
            BGCC_TRACE("bgcc", "_info.is_valid: %d", _info.is_valid());
        }

#ifndef _WIN32
        if(0 != ret && info->param){
            TaskAsso *pTask=(TaskAsso*)info->param->pTask;
            EventCallback::RemoveFD(pTask->pLoop, pTask->event.fd);
        }
#endif

		return ret;
	}

	int32_t ConnectionNode::get(SharedPointer<ConnInfo>& info)
	{
		int32_t ret=( _isused ? E_BGCC_SYSERROR : 0 );

		if(0==ret){
			info=_info;
			_isused=true;
#ifndef _WIN32
			TaskAsso *pTask=(TaskAsso*)info->param->pTask;
			if(pTask&&pTask->pLoop){
				EventCallback::RemoveFD(pTask->pLoop, pTask->event.fd, false);
			}
#endif

			BGCC_TRACE("bgcc","ConnectionNode get ret=%d, fd=%d",
					ret, info->proto->getTransport()->id());
		}
		else{
			BGCC_WARN("bgcc","ConnectionNode get ret=%d, fd=%d",
					ret, _info->proto->getTransport()->id());
		}

		return ret;
	}

	int32_t ConnectionNode::insert(SharedPointer<ConnInfo> &info)
	{
		BGCC_NOTICE("bgcc","ConnectionNode insert, fd-old=%d, fd-new=%d",
				_info->proto->getTransport()->id(), info->proto->getTransport()->id());

		if(_info.get()!=info.get()){
			_info=info;
		}

		_isused=false;

		return 0;
	}
	SharedPointer<BinaryProtocol> ConnectionNode::get_socketname()
	{
		return _info->proto;
	}

	ConnectionManager::ConnectionManager() {
	}

	ConnectionManager::~ConnectionManager() {
	}

	int32_t ConnectionManager::enroll(const std::string& proxy_name, SOCKET fd, ReadItem *param, bool ssl, void* arg) {
		Guard<Mutex> guard(&_mutex);
		std::map<std::string, SharedPointer<ConnectionNode> >::iterator itr;
		itr = _proxy_name2connections.find(proxy_name);

        BinaryProtocol* binary_protocol = NULL;
        if (ssl) {
#ifndef _WIN32
            struct SSLEventCallbackArg* callbackArg = (struct SSLEventCallbackArg*)arg;
            binary_protocol = new BinaryProtocol(SharedPointer<SSLServerPeerSocket>(new SSLServerPeerSocket(
                            &(callbackArg->ssl), fd)));
#endif
        } else {
            binary_protocol = new BinaryProtocol(SharedPointer<ServerPeerSocket>(new ServerPeerSocket(fd)));
        }

		SharedPointer<BinaryProtocol> proto =SharedPointer<BinaryProtocol>(binary_protocol);
		SharedPointer<ConnInfo> info=SharedPointer<ConnInfo>(new ConnInfo(proto, param));

		if (itr == _proxy_name2connections.end()) {
			SharedPointer<ConnectionNode> sp(new ConnectionNode(info));
			itr = _proxy_name2connections.insert(std::make_pair(proxy_name, sp)).first;
		}
		else{
			itr->second->insert(info);
		}

		if(_proxy_name2connections.find(proxy_name)!=_proxy_name2connections.end()){
			BGCC_NOTICE("bgcc", "enroll fd=%d for proxy_name: %s Success", fd, proxy_name.c_str());
		}
		else{
			BGCC_WARN("bgcc", "enroll fd=%d for proxy_name: %s Failed", fd, proxy_name.c_str());
		}
		return 0;
	}

	int32_t ConnectionManager::put_connection(const std::string& proxy_name, SharedPointer<ConnInfo> info, bool toclose)
	{
		Guard<Mutex> guard(&_mutex);
		std::map<std::string, SharedPointer<ConnectionNode> >::iterator itr;
		itr = _proxy_name2connections.find(proxy_name);

		if (itr != _proxy_name2connections.end())
		{
			if( itr->second->put(info, toclose)==0 && toclose ){
				_proxy_name2connections.erase(itr);
			}
		} else {
            BGCC_TRACE("bgcc", "connections for proxy_name %s not exist yet", proxy_name.c_str());

#ifndef _WIN32
            if(info->param){
                TaskAsso *pTask=(TaskAsso*)info->param->pTask;
                EventCallback::RemoveFD(pTask->pLoop, pTask->event.fd);
            }
#endif
        }
		return 0;
	}
	SharedPointer<ConnInfo>
		ConnectionManager::get_connection(const std::string& proxy_name) {
            int32_t trycount=1;
		    SharedPointer<ConnInfo> info=SharedPointer<ConnInfo>(NULL);
            do{
                {
    			    Guard<Mutex> guard(&_mutex);
    	    		std::map<std::string, SharedPointer<ConnectionNode> >::iterator itr;
	    	    	itr = _proxy_name2connections.find(proxy_name);

		    	    if (itr!=_proxy_name2connections.end()){
	    		    	itr->second->get(info);
			        }
                    else{
	    	    		BGCC_WARN("bgcc", "no conn in for proxy=%s", proxy_name.c_str());
                    }
                }
                
                if(!info.is_valid()&&(--trycount)>0){
                    TimeUtil::safe_sleep_ms(1500);
                }
                else{
                    break;
                }
	    	}while(true);

            return info;
        }

    void ConnectionManager::clear_connection(const std::string& proxy_name)
    {
        Guard<Mutex> guard(&_mutex);
        _proxy_name2connections.clear();
    }
}

