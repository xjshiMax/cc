#include "acdheartbeat.h"

namespace acd {
    acdheartbeat_Heartbeat_args::acdheartbeat_Heartbeat_args() {
    }

    acdheartbeat_Heartbeat_args::~acdheartbeat_Heartbeat_args() {
    }

    bool acdheartbeat_Heartbeat_args::operator==(const acdheartbeat_Heartbeat_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (currentType != rhs.currentType) {
            return false;
        }
        return true;
    }

    bool acdheartbeat_Heartbeat_args::operator!=(const acdheartbeat_Heartbeat_args& rhs) const {
        return !(*this == rhs);
    }

    bool acdheartbeat_Heartbeat_args::operator< (const acdheartbeat_Heartbeat_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(currentType < rhs.currentType)) {
            return false;
        }
        return true;
    }

    int32_t acdheartbeat_Heartbeat_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, currentType);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    acdheartbeat_Heartbeat_pargs::~acdheartbeat_Heartbeat_pargs() {
    }

    int32_t acdheartbeat_Heartbeat_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("acdheartbeat_Heartbeat_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("currentType", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool((*(currentType)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    acdheartbeat_Heartbeat_result::acdheartbeat_Heartbeat_result() {
    }

    acdheartbeat_Heartbeat_result::~acdheartbeat_Heartbeat_result() {
    }

    bool acdheartbeat_Heartbeat_result::operator==(const acdheartbeat_Heartbeat_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (newType != rhs.newType) {
            return false;
        }
        return true;
    }

    bool acdheartbeat_Heartbeat_result::operator!=(const acdheartbeat_Heartbeat_result& rhs) const {
        return !(*this == rhs);
    }

    bool acdheartbeat_Heartbeat_result::operator< (const acdheartbeat_Heartbeat_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(newType < rhs.newType)) {
            return false;
        }
        return true;
    }

    int32_t acdheartbeat_Heartbeat_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("acdheartbeat_Heartbeat_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDBOOL, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeBool(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("newType", bgcc::IDBOOL, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeBool(newType);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    acdheartbeat_Heartbeat_presult::~acdheartbeat_Heartbeat_presult() {
    }

    int32_t acdheartbeat_Heartbeat_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, (*(newType)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    acdheartbeatProxy::acdheartbeatProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.acd.acdheartbeat";
    }

    acdheartbeatProxy::acdheartbeatProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.acd.acdheartbeat";
    }

    acdheartbeatProxy::acdheartbeatProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::BaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.acd.acdheartbeat";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    bool acdheartbeatProxy::Heartbeat(bool currentType, bool& newType, bool /*last*/) {
        bool return_value = false;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Heartbeat(currentType, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Heartbeat(newType, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void acdheartbeatProxy::send_Heartbeat(const bool& currentType, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Heartbeat", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        acdheartbeat_Heartbeat_pargs pargs;
        pargs.currentType = &currentType;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    bool acdheartbeatProxy::recv_Heartbeat(bool& newType, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bool ret_val = false;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        acdheartbeat_Heartbeat_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Heartbeat"){
            presult.return_value = &ret_val;
            presult.newType = &newType;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    SSLacdheartbeatProxy::SSLacdheartbeatProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.acd.acdheartbeat";
    }

    SSLacdheartbeatProxy::SSLacdheartbeatProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.acd.acdheartbeat";
    }

    SSLacdheartbeatProxy::SSLacdheartbeatProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::SSLBaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.acd.acdheartbeat";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    bool SSLacdheartbeatProxy::Heartbeat(bool currentType, bool& newType, bool /*last*/) {
        bool return_value = false;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Heartbeat(currentType, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Heartbeat(newType, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLacdheartbeatProxy::send_Heartbeat(const bool& currentType, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Heartbeat", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        acdheartbeat_Heartbeat_pargs pargs;
        pargs.currentType = &currentType;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    bool SSLacdheartbeatProxy::recv_Heartbeat(bool& newType, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bool ret_val = false;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        acdheartbeat_Heartbeat_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Heartbeat"){
            presult.return_value = &ret_val;
            presult.newType = &newType;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    acdheartbeatProcessor::acdheartbeatProcessor(bgcc::SharedPointer<acdheartbeat> intf) :
        bgcc::BaseProcessor(), __intf(intf) {
        __fun_map["Heartbeat"] = &acdheartbeatProcessor::do_Heartbeat;
    }

    int32_t acdheartbeatProcessor::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0;
        bgcc::MsgTypeID mtype;
        int32_t seqid;
        std::string fname;
        int32_t nread = 0;
        ret = proto->readMessageBegin(&request, request_len, fname, mtype, seqid);
        if (ret < 0) { return ret;}
        nread += ret;
        if (mtype != ::bgcc::CALL){
            return -1;
        }
        return do_function__(OFFSET_PTR(request, nread), request_len-nread, proto, fname, seqid);
    }

    std::string acdheartbeatProcessor::get_name() const {
        return "global.acd.acdheartbeat";
    }

    int32_t acdheartbeatProcessor::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, 
        const std::string& fname, int32_t seqid) {
        std::map<std::string, do_function_ptr>::iterator it;
        it = __fun_map.find(fname);
        if (it == __fun_map.end()) {
            return bgcc::BaseProcessor::do_function__(request, request_len, proto, fname, seqid);
        }

        return (this->*(it->second))(request, request_len, proto, seqid);
    }

    int32_t acdheartbeatProcessor::do_Heartbeat(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        acdheartbeat_Heartbeat_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        acdheartbeat_Heartbeat_result result;
        result.return_value = __intf->Heartbeat(args.currentType, result.newType, map);
        ret = proto->writeMessageBegin("global.acd.acdheartbeat", "Heartbeat", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

}


