/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "event_callback.h"


#include "log.h"
#include "fake.h"
#include "thread_pool.h"
#include "server_task.h"
#include "service_manager.h"
#include "binary_protocol.h"
#include "connection_manager.h"
#include "server_peer_socket.h"

#ifndef _WIN32
#include "ssl_epoll_server.h"
#include "bgcc_ssl.h"
#include "ssl_server_peer_socket.h"
#include <openssl/err.h>

void bgcc::EventCallback::DataCallback(EventLoop* el, SOCKET fd, void* arg)
{
	int32_t ret=0;
	char *p=NULL;

	bgcc::Mempool* mempool = bgcc::Mempool::get_instance();

	bgcc::ReadItem *pItem=&(Items[fd]);
	reading_item_t& item = pItem->item;
	p = item.head_buf;
	if(S_SIZE_READING == item.state){
		p = item.head_buf;
	}
	else if(S_DATA_READING == item.state){
		p = item.data;
	}

	BGCC_TRACE("bgcc", "Enter DataCallback(fd=%d)", fd);
	while (true){
		ret = recv(fd, p+item.nread, item.nexpected, 0);
		if(ret>0){
			item.nread += ret;
			item.nexpected -= ret;
			if (0 == item.nexpected) {
				if (S_SIZE_READING == item.state) {
					if (item.head_buf[0] != 'b'
							|| item.head_buf[1] != 'g'
							|| item.head_buf[2] != 'c'
							|| item.head_buf[3] != 'P') {
						BGCC_WARN("bgcc", "invalid bgcc header(fd=%d)", fd);
						pItem->err = -1;
						break;
					}
					item.state = S_DATA_READING;
					item.nexpected = BODY_LEN(p);

					if (item.nexpected < 0){
						BGCC_WARN("bgcc", "Message body length=%d too short, remove from epoll",
								item.nexpected);
						break;
					}
					else if(0==item.nexpected){
						BGCC_TRACE("bgcc", "Empty body Package");
						break;
					}

					item.data = (char*)mempool->get_mem_block(item.nexpected);
					p = item.data;
					item.nread = 0;
					continue;
				}
				else if (S_DATA_READING == item.state) {
					pItem->err=0;
					break;
				}
			}
		}
		else if (ret<0) {
			if (SocketTool::is_interrupt()) {
				continue;
			}
			else if (SocketTool::is_wouldblock()) {
				return;
			}
			else {
				pItem->err=BgccSockGetLastError();
				BGCC_WARN("bgcc", "Recv Failed. fd=%d errno=%d", 
						fd, pItem->err);
				break;
			}
		}
		else{
			pItem->err=-1;
			BGCC_TRACE("bgcc", "Recv Return 0. fd=%d ", fd);
			break;
		}
	}

	EpollServer *pArg=(EpollServer*)arg;
	TaskAsso *pT= (pArg?pArg->Tasks+fd:NULL);
	pT->pLoop=el;
	pT->pServer=(EpollServer*)arg;
	pT->pItem=pItem;
	PrepareEvent(pT->event, fd, arg);
	pItem->pTask=pT;

	int32_t todel=1;
	BusizProcessor::Process(pItem, pT, item.nread, &todel);

	if(pItem->err){
		if(pItem->isEnroll){//put_conn call RemoveFD, so here not to call RemoveFD
			if(todel){
				BGCC_WARN("bgcc", "Other Party is Closed Or Protocol Is Invalid, Force To Release fd=%d", fd);
				SharedPointer<BinaryProtocol> proto = SharedPointer<BinaryProtocol>(
					new BinaryProtocol( SharedPointer<ServerPeerSocket>(
							new ServerPeerSocket(fd)
							)));
				SharedPointer<ConnInfo> info=SharedPointer<ConnInfo>(
					new ConnInfo(proto, pItem)
					);
				if(proto.is_valid()&&info.is_valid()){
					bgcc::ConnectionManager::get_instance()->put_connection(pItem->item.memo, info, true);
				}
			}
		}
		else{
			BGCC_WARN("bgcc", "Other Party is Closed Or Protocol Is Invalid, Force To Release fd=%d", fd);
			RemoveFD(el,fd);
		}

	}
	BGCC_TRACE("bgcc", "Leave DataCallback(fd=%d)", fd);
}

void bgcc::EventCallback::ErrCallback(EventLoop* , SOCKET fd, void* )
{
	BGCC_WARN("bgcc","Error Epoll Even( fd=%d )", fd);
}

void bgcc::EventCallback::AcceptCallback(EventLoop* el, SOCKET fd, void* arg)
{
	BGCC_TRACE("bgcc", "Enter AcceptCallback(fd=%d)", fd);
	do{
		SOCKET newfd=INVALID_SOCKET;
		struct sockaddr_in sin;
		socklen_t addrlen = sizeof(struct sockaddr);
		PeerInfo tmp("", 0);

		memset(&sin, 0, addrlen);

		newfd = accept(fd, (struct sockaddr*)&sin, &addrlen);

		if (newfd >= MAXNFD) {
			SocketTool::getsockdetail(newfd, tmp, true);
			BGCC_NOTICE("bgcc", "Accept an Client From %s:%d, fd=%d", 
				tmp.GetHost().c_str(), tmp.GetPort(), newfd);
			
			BGCC_WARN("bgcc", "Too many Client. Reject the new one %s:%d, fd=%d , (max=%d)",
					tmp.GetHost().c_str(), tmp.GetPort(), newfd, MAXNFD);
			
			SocketTool::close(newfd);
			
			BGCC_TRACE("bgcc", "Leave AcceptCallback(fd=%d)", fd);
			return;
		}
	
		if (INVALID_SOCKET != newfd) {
			SocketTool::getsockdetail(newfd, tmp, true);
			BGCC_NOTICE("bgcc", "Accept an Client From %s:%d, fd=%d", 
				tmp.GetHost().c_str(), tmp.GetPort(), newfd);
			
			bgcc::ReadItem *pItem=&(Items[newfd]);
			pItem->Reset();
			pItem->isEnroll=false;
			pItem->pTask=NULL;

			Event e;
			PrepareEvent(e, newfd, arg);

			if(el->add_event(&e)!=0){
				BGCC_WARN("bgcc", "Add fd=%d to epoll failed(errno=%d)", 
					newfd, BgccSockGetLastError());
				SocketTool::close(newfd);
			}
		}
		else{
			if(SocketTool::is_interrupt()){
				continue;
			}
			else{
				break;
			}
		}
	}while(true);
	BGCC_TRACE("bgcc", "Leave AcceptCallback(fd=%d)", fd);
}

void bgcc::EventCallback::RemoveFD(EventLoop *el, SOCKET fd, bool toclose)
{
	Event e;
	PrepareEvent(e, fd);
	if(el&&el->del_event(&e)!=0){
		BGCC_WARN("bgcc", "Del(fd=%d, toclose=%d) From Epoll Failed(%d)", 
				fd, toclose, BgccSockGetLastError());
	}
	else{
		BGCC_TRACE("bgcc", "Del(fd=%d, toclose=%d) From Epoll Success", fd, toclose);
	}

	if(toclose){
		SocketTool::close(fd);
	}
}

void bgcc::EventCallback::PrepareEvent(Event& e, SOCKET sock, void *arg)
{
	e.fd = sock;
	e.mask = DEFAULT_MASK;
	e.read_cb = DataCallback;
	e.read_cb_arg = arg;
	e.error_cb = ErrCallback;
	e.error_cb_arg = arg;
}

bgcc::ReadItem bgcc::EventCallback::Items[MAXNFD];
const uint32_t bgcc::EventCallback::DEFAULT_MASK=EVENT_READ|EVENT_ERROR;

//SSL

void bgcc::SSLEventCallback::DataCallback(EventLoop* el, SOCKET fd, void* arg)
{
	int32_t ret = 0;
	char* p = NULL;

	bgcc::Mempool* mempool = bgcc::Mempool::get_instance();
	struct SSLEventCallbackArg* callbackArg = (struct SSLEventCallbackArg*)arg;

	bgcc::ReadItem* pItem = &(Items[fd]);
	reading_item_t& item = pItem->item;
	p = item.head_buf;
	if (S_SIZE_READING == item.state) {
		p = item.head_buf;
	} else if (S_DATA_READING == item.state) {
		p = item.data;
	}

	BGCC_TRACE("bgcc", "Enter SSL DataCallback(fd=%d)", fd);

	if (!callbackArg->ssl) {
		BGCC_TRACE("bgcc", "callbackArg->ssl is NULL, we should not be here.");
		TimeUtil::safe_sleep_ms(0);
		BGCC_TRACE("bgcc", "Leave SSL DataCallback(fd=%d)", fd);
		return;
	}

	bool do_while = true;

	while (true && do_while) {
		ret = SSL_read(callbackArg->ssl, p + item.nread, item.nexpected);
		switch(SSL_get_error(callbackArg->ssl, ret)) {
			case SSL_ERROR_NONE:
				item.nread += ret;
				item.nexpected -= ret;
				if (0 == item.nexpected) {
					if (S_SIZE_READING == item.state) {
						if (item.head_buf[0] != 'b'
								|| item.head_buf[1] != 'g'
								|| item.head_buf[2] != 'c'
								|| item.head_buf[3] != 'P') {
							BGCC_WARN("bgcc", "invalid bgcc header(fd=%d)", fd);
							pItem->err = -1;
							do_while = false;
							break;
						}
						item.state = S_DATA_READING;
						item.nexpected = BODY_LEN(p);

						if (item.nexpected < 0) {
							BGCC_WARN("bgcc", "Message body length=%d too short, remove from epoll", item.nexpected);
							do_while = false;
							break;
						} else if (0 == item.nexpected) {
							BGCC_TRACE("bgcc", "Empty body Package");
							do_while = false;
							break;
						}

						item.data = (char*)mempool->get_mem_block(item.nexpected);
						p = item.data;
						item.nread = 0;
						continue;
					} else if (S_DATA_READING == item.state) {
						pItem->err = 0;
						do_while = false;
						break;
					}
				}
				continue;
			case SSL_ERROR_WANT_READ:
			case SSL_ERROR_WANT_WRITE:
				return;
			default:
				pItem->err = -1;
				do_while = false;
				break;

		}
	}

	SSLEpollServer* pArg = (SSLEpollServer*)callbackArg->arg;
	TaskAsso* pT = pArg ? pArg->Tasks+fd : NULL;
	pT->pLoop = el;
	pT->pServer = pArg;
	pT->pItem = pItem;
	
	PrepareEvent(pT->event, fd, arg);
	pItem->pTask = pT;

	int32_t todel = 1;
	BusizProcessor::Process(pItem, pT, item.nread, &todel, true, arg);

	if (pItem->err) {
		SSL_shutdown(callbackArg->ssl);
		BGCC_DEBUG("bgcc", "Memory SSL free: %p", callbackArg->ssl);
		SSL_free(callbackArg->ssl);
		callbackArg->ssl = NULL;

		if (pItem->isEnroll) {
			if(todel){
				BGCC_WARN("bgcc", "Other Party is Closed Or Protocol Is Invalid, Force To Release fd=%d", fd);
				SharedPointer<BinaryProtocol> proto = SharedPointer<BinaryProtocol>(
					new BinaryProtocol( SharedPointer<ServerPeerSocket>(
							new ServerPeerSocket(fd)
							)));
				SharedPointer<ConnInfo> info=SharedPointer<ConnInfo>(
					new ConnInfo(proto, pItem)
					);
				if(proto.is_valid()&&info.is_valid()){
					bgcc::ConnectionManager::get_instance()->put_connection(pItem->item.memo, info, true);
				}
			}
		} else {
			BGCC_WARN("bgcc", "Other Party is Closed Or Protocol Is Invalid, Force To Release fd=%d", fd);
			RemoveFD(el,fd);
		}
	}

	BGCC_TRACE("bgcc", "Leave SSL DataCallback(fd=%d)", fd);
}

void bgcc::SSLEventCallback::ErrCallback(EventLoop*, SOCKET fd, void*)
{
	BGCC_WARN("bgcc", "SSL Error Epoll Event(fd=%d)", fd);
}

void bgcc::SSLEventCallback::SSLAcceptCallback(EventLoop* el, SOCKET fd, void* arg)
{
	int ret;
	Event e;
	SSLEventCallbackArg* newCallbackArg = (SSLEventCallbackArg*)arg;

	BGCC_TRACE("bgcc", "Enter SSL SSLAcceptCallback(fd=%d)", fd);

	ret = SSL_accept(newCallbackArg->ssl);
	switch(SSL_get_error(newCallbackArg->ssl, ret)) {
		case SSL_ERROR_NONE:
			BGCC_TRACE("bgcc", "ERROR NONE");
			PrepareEvent(e, fd, newCallbackArg);

			if (el->add_event(&e) != 0) {
				SSL_shutdown(newCallbackArg->ssl);
				BGCC_DEBUG("bgcc", "Memory SSL free: %p", newCallbackArg->ssl);
				SSL_free(newCallbackArg->ssl);
				newCallbackArg->ssl = NULL;
				RemoveFD(el, fd, true);
				BGCC_TRACE("bgcc", "ssl add_event failed");
			}
			break;
		case SSL_ERROR_WANT_ACCEPT:
		case SSL_ERROR_WANT_READ:
		case SSL_ERROR_WANT_WRITE:
			BGCC_TRACE("bgcc", "WANT ACCPET");
			break;
		default:
			BGCC_TRACE("bgcc", "DEFAULT");
			SSL_shutdown(newCallbackArg->ssl);
			BGCC_DEBUG("bgcc", "Memory SSL free: %p", newCallbackArg->ssl);
			SSL_free(newCallbackArg->ssl);
			newCallbackArg->ssl = NULL;
			RemoveFD(el, fd, true);
			break;
	}

	BGCC_TRACE("bgcc", "Leave SSL SSLAcceptCallback(fd=%d)", fd);
}

void bgcc::SSLEventCallback::AcceptCallback(EventLoop* el, SOCKET fd, void* arg)
{
	BGCC_TRACE("bgcc", "Enter SSL AcceptCallback(fd=%d)", fd);
	do {
		SOCKET newfd = INVALID_SOCKET;
		struct sockaddr_in sin;
		socklen_t addrlen = sizeof(struct sockaddr);
		PeerInfo tmp("", 0);

		memset(&sin, 0, addrlen);

		newfd = accept(fd, (struct sockaddr*)&sin, &addrlen);
		if (INVALID_SOCKET != newfd) {
			SocketTool::getsockdetail(newfd, tmp, true);
			BGCC_NOTICE("bgcc", "Accept an Client From %s:%d, fd=%d",
					tmp.GetHost().c_str(), tmp.GetPort(), newfd);
		} else {
			if (SocketTool::is_interrupt()) {
				continue;
			} else {
				break;
			}
		}

		if (newfd >= MAXNFD) {
			BGCC_WARN("bgcc", "Too many client. Reject client %s:%d, fd=%d, (max=%d)",
					tmp.GetHost().c_str(), tmp.GetPort(), newfd, MAXNFD);
			SocketTool::close(newfd);
			BGCC_TRACE("bgcc", "Leave SSL AcceptCallback(fd=%d)", fd);
			return;
		} else {
			bgcc::ReadItem* pItem = &(Items[newfd]);
			pItem->Reset();
			pItem->isEnroll = false;
			pItem->pTask = NULL;

			SSLEventCallbackArg* callbackArg = (SSLEventCallbackArg*)arg;
			SSLEventCallbackArg* newCallbackArg = &args[newfd];
			newCallbackArg->arg = callbackArg->arg;
			newCallbackArg->ssl = SSL_new(g_ssl_ctx);
			BGCC_DEBUG("bgcc", "Memory new: %p", newCallbackArg->ssl);
			if (!newCallbackArg->ssl) {
				BGCC_WARN("bgcc", "new ssl failed. close fd=%d", newfd);
				SocketTool::close(newfd);
				break;
			}

			SSL_set_fd(newCallbackArg->ssl, newfd);

			Event e;
			PrepareEvent(e, newfd, newCallbackArg);
			e.read_cb = SSLAcceptCallback;

			if (el->add_event(&e) != 0) {
				SSL_shutdown(newCallbackArg->ssl);
				BGCC_DEBUG("bgcc", "Memory SSL free: %p", newCallbackArg->ssl);
				SSL_free(newCallbackArg->ssl);
				newCallbackArg->ssl = NULL;
				SocketTool::close(newfd);
				BGCC_TRACE("bgcc", "ssl add_event failed");
			}
		}
	} while (true);
	BGCC_TRACE("bgcc", "Leave SSL AcceptCallback(fd=%d)", fd);
}

void bgcc::SSLEventCallback::RemoveFD(EventLoop* el, SOCKET fd, bool toclose)
{
	Event e;
	PrepareEvent(e, fd);
	if (el && el->del_event(&e) != 0) {
		BGCC_WARN("bgcc", "Del(fd=%d, toclose=%d) From Epoll Failed(%d)", 
				fd, toclose, BgccSockGetLastError());
	} else {
		BGCC_TRACE("bgcc", "Del(fd=%d, toclose=%d) From Epoll Success", fd, toclose);
	}

	if (toclose) {
		SocketTool::close(fd);
	}
}

void bgcc::SSLEventCallback::PrepareEvent(Event& e, SOCKET sock, void *arg)
{
	e.fd = sock;
	e.mask = DEFAULT_MASK;
	e.read_cb = DataCallback;
	e.read_cb_arg = arg;
	e.error_cb = ErrCallback;
	e.error_cb_arg = arg;
}

bgcc::ReadItem bgcc::SSLEventCallback::Items[MAXNFD];
bgcc::SSLEventCallbackArg bgcc::SSLEventCallback::args[MAXNFD];
const uint32_t bgcc::SSLEventCallback::DEFAULT_MASK=EVENT_READ|EVENT_ERROR;
#endif

void bgcc::BusizProcessor::Process(ReadItem *pItem, void *param, int32_t body_len, int32_t *todel, bool ssl, void* arg)
{
	//if(!pItem || pItem->err){
	if(!pItem){ // if err must callback; otherwise, todel will have no effect
		return;
	}

	char *p=pItem->item.data;
	std::string prc_name;
	if(!pItem->err&&p){
		if (PROCESSOR_NAME_LEN(p) > body_len - 4) {
			pItem->err = -1;
			return;
		}
		prc_name=std::string(PROCESSOR_NAME_PTR(p), PROCESSOR_NAME_LEN(p));
	}

	if (!pItem->err&&Fake::is_reg_proc(prc_name)) {
		ProcessEnroll(pItem, param, ssl, arg);	
	}
	else if(pItem->isEnroll){	//callbck(enroll fd))
		if(ISHB(pItem->item.head_buf)){
			ProcessHB(pItem, ssl, arg);
		}
		else{
			ProcessServerCallback(pItem, param, todel, ssl, arg);
		}
	}
	else if(!pItem->err){
		ProcessUser(pItem, prc_name, param, ssl, arg);
	}
}

void bgcc::BusizProcessor::ProcessEnroll(ReadItem *pItem, void *param, bool ssl, void* arg)
{
	BGCC_TRACE("bgcc", "...Enter Enroll Process");
	char *p= pItem->item.data;
	SOCKET sock=INVALID_SOCKET;

#ifndef _WIN32
	TaskAsso *pT=(TaskAsso*)param;
	sock=pT->event.fd;
#endif
	
	pItem->item.memo=std::string(PROXY_NAME_PTR(p), PROXY_NAME_LEN(p));
	bgcc::ConnectionManager::get_instance()->enroll(pItem->item.memo, sock, pItem, ssl, arg);
	SocketTool::set_sndtimeout(sock, DEFAULT_SERVER_TIMEOUT);
	SocketTool::set_rcvtimeout(sock, DEFAULT_SERVER_TIMEOUT);
	pItem->isEnroll=true;

#ifndef _WIN32
	if(pT&&pT->pLoop){
		if (ssl) {
			pT->event.read_cb = SSLEventCallback::DataCallback;
		} else {
			pT->event.read_cb = EventCallback::DataCallback;
		}
		if(pT->pLoop->add_event(&(pT->event))!=0){
			SocketTool::close(sock);
		}
		pItem->pTask=pT;
	}
#endif
	
	pItem->Reset();
	BGCC_TRACE("bgcc", "...Leave Enroll Process");
}

void bgcc::BusizProcessor::ProcessUser(ReadItem *pItem, const std::string &name, void *param, bool ssl, void* arg)
{
	BGCC_TRACE("bgcc", "...Enter User Process");
	char *p= pItem->item.data;
	static char buffer[MAX_DEFAULT_LEN]={0};
	int32_t buffer_size=MAX_DEFAULT_LEN;
	bgcc::ServiceManager* service_manager = NULL;
	bgcc::ThreadPool* thread_pool = NULL;
	SOCKET sock=INVALID_SOCKET;	

#ifndef _WIN32
	TaskAsso *pT=(TaskAsso*)param;
	EpollServer* pServer=(EpollServer*)pT->pServer;
	service_manager = pServer->get_service_manager();
	thread_pool = pServer->get_thread_pool();
	sock=pT->event.fd;
#endif

	SharedPointer<IProcessor> processor = service_manager->get_service(name);
	if(!processor.is_valid()){
		processor = service_manager->get_service(DEF_SERVICE);
		if(processor.is_valid()){
			p=NULL;
			if(Fake::fake_default_body(buffer, buffer_size)){
				p=buffer;
			
				BGCC_WARN("bgcc", "...Cannot find processor %s to use default service", 
					name.c_str());
			}
		}
	}

	if (processor.is_valid() && p) {
#ifndef _WIN32
		if (ssl) {
			SSLEventCallback::RemoveFD(pT->pLoop, sock, false);
		} else {
			EventCallback::RemoveFD(pT->pLoop, sock, false);
		}
#endif
		ServerPeerSocket* server_peer_socket = NULL;
		
		if (ssl) {
#ifndef _WIN32
            SSLEventCallbackArg* callbackArg = (SSLEventCallbackArg*)arg;
			server_peer_socket = new SSLServerPeerSocket(&(callbackArg->ssl), sock);
#endif
		} else {
			server_peer_socket = new ServerPeerSocket(sock);
		}
		SharedPointer<ITransport> trans(server_peer_socket);
		SharedPointer<IProtocol> proto(new BinaryProtocol(trans));
		SharedPointer<Runnable> task(new ServerTask(processor, p, 
					(p==pItem->item.data?pItem->item.nread:buffer_size), proto, param));

		if(!thread_pool->addTask(task)){
			BGCC_WARN("bgcc", "...Add Task Failed(fd=%d, processor=%s)", sock, name.c_str());
		}
	}
	else{
		BGCC_WARN("bgcc", "...Cannot find Any Processor do nothing");
	}
	BGCC_TRACE("bgcc", "...Leave User Process");
}

void bgcc::BusizProcessor::ProcessServerCallback(ReadItem *pItem, void *param, int32_t *todel, bool ssl, void* /*arg*/)
{
#ifndef _WIN32
	BGCC_TRACE("bgcc", "...Enter ServerCallback Process");
	//if(pItem->item.data)
	if(pItem->isWait){	//have wait(read message)
		TaskAsso *pT=(TaskAsso*)param;
		SOCKET sock=pT->event.fd;
		if(!pItem->err){	// err DataCallback deal
			if (ssl) {
				SSLEventCallback::RemoveFD(pT->pLoop, sock, false);
			} else {
				EventCallback::RemoveFD(pT->pLoop, sock, false);
			}
		}
		else{
			if(todel){
				*todel=0;
			}
		}
		pItem->psem->signal();
	}
	//pItem->psem->signal();	//default to signal
	BGCC_TRACE("bgcc", "...Leave ServerCallback Process(delete=%d)", (*todel));
#endif
}

void bgcc::BusizProcessor::ProcessHB(ReadItem *pItem, bool /*ssl*/, void* /*arg*/)
{
	BGCC_TRACE("bgcc", "...HB Process");
	if(pItem){
		//pItem->Reset();
		pItem->item.reset();
	}
	return;
} 

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
