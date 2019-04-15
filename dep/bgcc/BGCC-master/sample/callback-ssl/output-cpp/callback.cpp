#include "callback.h"

namespace demo {

    const struct CallbackResult::desc_t CallbackResult::descs[] = {
        {CallbackResult::R_SUCC, "CallbackResult::R_SUCC"},
        {CallbackResult::R_FAIL, "CallbackResult::R_FAIL"},
        {0, NULL}
    };

    CallbackResult::CallbackResult() : _value(R_SUCC) {
    }

    CallbackResult::CallbackResult(int32_t value) : _value(value) {
    }

    int32_t CallbackResult::get_value() const {
        return _value;
    }

    std::string CallbackResult::get_desc() const {
        const struct desc_t* ptr = CallbackResult::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool CallbackResult::operator==(int32_t value) const {
        return _value == value;
    }

    bool CallbackResult::operator!=(int32_t value) const {
        return _value != value;
    }

    bool CallbackResult::operator< (int32_t value) const {
        return _value < value;
    }

    bool CallbackResult::operator==(const CallbackResult& rhs) const {
        return _value == rhs.get_value();
    }

    bool CallbackResult::operator!=(const CallbackResult& rhs) const {
        return _value != rhs.get_value();
    }

    bool CallbackResult::operator< (const CallbackResult& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const CallbackResult& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const CallbackResult& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const CallbackResult& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const CallbackResult& e) {
        o << e.get_value();
        return o;
    }

    CallbackRecver_Callback_args::CallbackRecver_Callback_args() {
    }

    CallbackRecver_Callback_args::~CallbackRecver_Callback_args() {
    }

    bool CallbackRecver_Callback_args::operator==(const CallbackRecver_Callback_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (val != rhs.val) {
            return false;
        }
        return true;
    }

    bool CallbackRecver_Callback_args::operator!=(const CallbackRecver_Callback_args& rhs) const {
        return !(*this == rhs);
    }

    bool CallbackRecver_Callback_args::operator< (const CallbackRecver_Callback_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(val < rhs.val)) {
            return false;
        }
        return true;
    }

    int32_t CallbackRecver_Callback_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, val);
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

    CallbackRecver_Callback_pargs::~CallbackRecver_Callback_pargs() {
    }

    int32_t CallbackRecver_Callback_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("CallbackRecver_Callback_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("val", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(val)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    CallbackRecver_Callback_result::CallbackRecver_Callback_result() {
    }

    CallbackRecver_Callback_result::~CallbackRecver_Callback_result() {
    }

    bool CallbackRecver_Callback_result::operator==(const CallbackRecver_Callback_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool CallbackRecver_Callback_result::operator!=(const CallbackRecver_Callback_result& rhs) const {
        return !(*this == rhs);
    }

    bool CallbackRecver_Callback_result::operator< (const CallbackRecver_Callback_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t CallbackRecver_Callback_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("CallbackRecver_Callback_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    CallbackRecver_Callback_presult::~CallbackRecver_Callback_presult() {
    }

    int32_t CallbackRecver_Callback_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var1;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var1);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var1;
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

    CallbackRecverProxy::CallbackRecverProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.demo.CallbackRecver";
    }

    CallbackRecverProxy::CallbackRecverProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.demo.CallbackRecver";
    }

    CallbackRecverProxy::CallbackRecverProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::BaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.demo.CallbackRecver";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    CallbackResult CallbackRecverProxy::Callback(int32_t val, bool /*last*/) {
        CallbackResult return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Callback(val, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Callback(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void CallbackRecverProxy::send_Callback(const int32_t& val, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Callback", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        CallbackRecver_Callback_pargs pargs;
        pargs.val = &val;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CallbackResult CallbackRecverProxy::recv_Callback(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CallbackResult ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        CallbackRecver_Callback_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Callback"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    SSLCallbackRecverProxy::SSLCallbackRecverProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.demo.CallbackRecver";
    }

    SSLCallbackRecverProxy::SSLCallbackRecverProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.demo.CallbackRecver";
    }

    SSLCallbackRecverProxy::SSLCallbackRecverProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::SSLBaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.demo.CallbackRecver";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    CallbackResult SSLCallbackRecverProxy::Callback(int32_t val, bool /*last*/) {
        CallbackResult return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Callback(val, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Callback(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLCallbackRecverProxy::send_Callback(const int32_t& val, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Callback", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        CallbackRecver_Callback_pargs pargs;
        pargs.val = &val;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CallbackResult SSLCallbackRecverProxy::recv_Callback(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CallbackResult ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        CallbackRecver_Callback_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Callback"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CallbackRecverProcessor::CallbackRecverProcessor(bgcc::SharedPointer<CallbackRecver> intf) :
        bgcc::BaseProcessor(), __intf(intf) {
        __fun_map["Callback"] = &CallbackRecverProcessor::do_Callback;
    }

    int32_t CallbackRecverProcessor::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

    std::string CallbackRecverProcessor::get_name() const {
        return "global.demo.CallbackRecver";
    }

    int32_t CallbackRecverProcessor::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, 
        const std::string& fname, int32_t seqid) {
        std::map<std::string, do_function_ptr>::iterator it;
        it = __fun_map.find(fname);
        if (it == __fun_map.end()) {
            return bgcc::BaseProcessor::do_function__(request, request_len, proto, fname, seqid);
        }

        return (this->*(it->second))(request, request_len, proto, seqid);
    }

    int32_t CallbackRecverProcessor::do_Callback(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        CallbackRecver_Callback_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        CallbackRecver_Callback_result result;
        result.return_value = __intf->Callback(args.val, map);
        ret = proto->writeMessageBegin("global.demo.CallbackRecver", "Callback", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    CallbackSender_AddClient_args::CallbackSender_AddClient_args() {
    }

    CallbackSender_AddClient_args::~CallbackSender_AddClient_args() {
    }

    bool CallbackSender_AddClient_args::operator==(const CallbackSender_AddClient_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool CallbackSender_AddClient_args::operator!=(const CallbackSender_AddClient_args& rhs) const {
        return !(*this == rhs);
    }

    bool CallbackSender_AddClient_args::operator< (const CallbackSender_AddClient_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t CallbackSender_AddClient_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    CallbackSender_DelClient_args::CallbackSender_DelClient_args() {
    }

    CallbackSender_DelClient_args::~CallbackSender_DelClient_args() {
    }

    bool CallbackSender_DelClient_args::operator==(const CallbackSender_DelClient_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool CallbackSender_DelClient_args::operator!=(const CallbackSender_DelClient_args& rhs) const {
        return !(*this == rhs);
    }

    bool CallbackSender_DelClient_args::operator< (const CallbackSender_DelClient_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t CallbackSender_DelClient_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    CallbackSender_AddClient_pargs::~CallbackSender_AddClient_pargs() {
    }

    int32_t CallbackSender_AddClient_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("CallbackSender_AddClient_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    CallbackSender_DelClient_pargs::~CallbackSender_DelClient_pargs() {
    }

    int32_t CallbackSender_DelClient_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("CallbackSender_DelClient_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    CallbackSender_AddClient_result::CallbackSender_AddClient_result() {
    }

    CallbackSender_AddClient_result::~CallbackSender_AddClient_result() {
    }

    bool CallbackSender_AddClient_result::operator==(const CallbackSender_AddClient_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool CallbackSender_AddClient_result::operator!=(const CallbackSender_AddClient_result& rhs) const {
        return !(*this == rhs);
    }

    bool CallbackSender_AddClient_result::operator< (const CallbackSender_AddClient_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t CallbackSender_AddClient_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("CallbackSender_AddClient_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    CallbackSender_DelClient_result::CallbackSender_DelClient_result() {
    }

    CallbackSender_DelClient_result::~CallbackSender_DelClient_result() {
    }

    bool CallbackSender_DelClient_result::operator==(const CallbackSender_DelClient_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool CallbackSender_DelClient_result::operator!=(const CallbackSender_DelClient_result& rhs) const {
        return !(*this == rhs);
    }

    bool CallbackSender_DelClient_result::operator< (const CallbackSender_DelClient_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t CallbackSender_DelClient_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("CallbackSender_DelClient_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    CallbackSender_AddClient_presult::~CallbackSender_AddClient_presult() {
    }

    int32_t CallbackSender_AddClient_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var2;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var2);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var2;
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

    CallbackSender_DelClient_presult::~CallbackSender_DelClient_presult() {
    }

    int32_t CallbackSender_DelClient_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var3;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var3);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var3;
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

    CallbackSenderProxy::CallbackSenderProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.demo.CallbackSender";
    }

    CallbackSenderProxy::CallbackSenderProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.demo.CallbackSender";
    }

    CallbackSenderProxy::CallbackSenderProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::BaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.demo.CallbackSender";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    CallbackResult CallbackSenderProxy::AddClient(bool /*last*/) {
        CallbackResult return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_AddClient(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_AddClient(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void CallbackSenderProxy::send_AddClient(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "AddClient", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        CallbackSender_AddClient_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CallbackResult CallbackSenderProxy::recv_AddClient(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CallbackResult ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        CallbackSender_AddClient_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="AddClient"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CallbackResult CallbackSenderProxy::DelClient(bool /*last*/) {
        CallbackResult return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_DelClient(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_DelClient(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void CallbackSenderProxy::send_DelClient(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "DelClient", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        CallbackSender_DelClient_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CallbackResult CallbackSenderProxy::recv_DelClient(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CallbackResult ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        CallbackSender_DelClient_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="DelClient"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    SSLCallbackSenderProxy::SSLCallbackSenderProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.demo.CallbackSender";
    }

    SSLCallbackSenderProxy::SSLCallbackSenderProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.demo.CallbackSender";
    }

    SSLCallbackSenderProxy::SSLCallbackSenderProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::SSLBaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.demo.CallbackSender";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    CallbackResult SSLCallbackSenderProxy::AddClient(bool /*last*/) {
        CallbackResult return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_AddClient(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_AddClient(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLCallbackSenderProxy::send_AddClient(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "AddClient", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        CallbackSender_AddClient_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CallbackResult SSLCallbackSenderProxy::recv_AddClient(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CallbackResult ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        CallbackSender_AddClient_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="AddClient"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CallbackResult SSLCallbackSenderProxy::DelClient(bool /*last*/) {
        CallbackResult return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_DelClient(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_DelClient(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLCallbackSenderProxy::send_DelClient(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "DelClient", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        CallbackSender_DelClient_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CallbackResult SSLCallbackSenderProxy::recv_DelClient(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CallbackResult ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        CallbackSender_DelClient_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="DelClient"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CallbackSenderProcessor::CallbackSenderProcessor(bgcc::SharedPointer<CallbackSender> intf) :
        bgcc::BaseProcessor(), __intf(intf) {
        __fun_map["AddClient"] = &CallbackSenderProcessor::do_AddClient;
        __fun_map["DelClient"] = &CallbackSenderProcessor::do_DelClient;
    }

    int32_t CallbackSenderProcessor::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

    std::string CallbackSenderProcessor::get_name() const {
        return "global.demo.CallbackSender";
    }

    int32_t CallbackSenderProcessor::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, 
        const std::string& fname, int32_t seqid) {
        std::map<std::string, do_function_ptr>::iterator it;
        it = __fun_map.find(fname);
        if (it == __fun_map.end()) {
            return bgcc::BaseProcessor::do_function__(request, request_len, proto, fname, seqid);
        }

        return (this->*(it->second))(request, request_len, proto, seqid);
    }

    int32_t CallbackSenderProcessor::do_AddClient(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        CallbackSender_AddClient_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        CallbackSender_AddClient_result result;
        result.return_value = __intf->AddClient(map);
        ret = proto->writeMessageBegin("global.demo.CallbackSender", "AddClient", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t CallbackSenderProcessor::do_DelClient(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        CallbackSender_DelClient_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        CallbackSender_DelClient_result result;
        result.return_value = __intf->DelClient(map);
        ret = proto->writeMessageBegin("global.demo.CallbackSender", "DelClient", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

}


