/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "base_processor.h"
#include "processor.h"
#include "bgcc_error.h"
#include "protocol.h"
#include "transaction.h"
#include "thread_util.h"
#include "bgcc_error.h"
#include "fake.h"

namespace bgcc {

    BaseProcessor::BaseProcessor() {
        __fun_map[TICKET_FUNC] = &BaseProcessor::do___get_ticket_id;
        __fun_map[DEF_FUNC] = &BaseProcessor::do___service_not_found;
    }

    int32_t BaseProcessor::process(
            char* request,
            int32_t request_len,
            SharedPointer<IProtocol> proto) {
        int32_t ret = 0;
        MsgTypeID mtype;
        int32_t seqid;
        std::string fname;
        int32_t nread = 0;

        ret = proto->readMessageBegin(&request, request_len, fname, mtype, seqid);
        if(ret < 0) { return ret;}
        nread += ret;

        if(mtype != bgcc::CALL) {
            return -1;
        }

        return do_function__(request + nread, request_len - nread, proto, fname, seqid);
    }

    int32_t BaseProcessor::do_function__(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            const std::string& fname,
            int32_t seqid) {
        std::map<std::string, do_function_ptr>::iterator itr;

        itr = __fun_map.find(fname);
        if (itr == __fun_map.end()) {
            return -1;
        }
        return (this->*(itr->second))(request, request_len, proto, seqid);
    }

    int32_t BaseProcessor::do___get_ticket_id(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t ) {
        int32_t ret = 0;
        int32_t nread = 0;
        int32_t thr_id = (int32_t)bgcc::ThreadUtil::self_id();
        bool belast = false;
        std::string fname;

        ret = proto->readInt32(request + nread, request_len - nread, thr_id);
        if (ret < 0) { return ret;}
        nread += ret;

        ret = proto->readString(request + nread, request_len - nread, fname);
        if (ret < 0) { return ret;}
        nread += ret;

        ret = proto->readBool(request + nread, request_len - nread, belast);
        if (ret < 0) { return ret;}
        nread += ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret;}
        nread += ret;

        int32_t tid;

        if (belast) {
            tid = Transaction::get_instance()->getCurrentTicketId(proto, thr_id, fname);
        } else {
            tid = Transaction::get_instance()->getTicketId(proto, thr_id, fname);
        }   

        ret = proto->writeMessageBegin(TICKET_PROC, TICKET_FUNC, bgcc::REPLY, 0); 
        if (ret < 0) { return ret;}
        ret = proto->writeInt32(tid);
        if (ret < 0) { return ret;}
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t BaseProcessor::do___service_not_found(
            char* ,
            int32_t ,
            SharedPointer<IProtocol> proto,
            int32_t seqid) {
        int32_t ret;
        ret = proto->writeMessageBegin("","", ::bgcc::EXCEPTION, seqid);
        if (ret < 0) { return ret;}
        ret = proto->writeInt32(E_BGCC_SERVICE_NOT_FOUND);
        if (ret < 0) { return ret;}
        ret = proto->writeMessageEnd();
        return ret;
    }

    std::string BaseProcessor::get_name() const {
        return DEF_SERVICE;
    }

	const char * BaseProcessor::PROXY_NAME="ProxyName";
	const char * BaseProcessor::PEER_IP="PeerIP";
	const char * BaseProcessor::PEER_PORT="PeerPort";

} // namespace
