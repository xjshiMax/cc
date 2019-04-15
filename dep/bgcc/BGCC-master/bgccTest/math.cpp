#include "math.h"

namespace math {

    const struct Result::desc_t Result::descs[] = {
        {Result::E_SUCCESS, "Result::E_SUCCESS"},
        {Result::E_OVERLOW, "Result::E_OVERLOW"},
        {Result::E_DOWNLOW, "Result::E_DOWNLOW"},
        {0, NULL}
    };

    Result::Result() : _value(E_SUCCESS) {
    }

    Result::Result(int32_t value) : _value(value) {
    }

    int32_t Result::get_value() const {
        return _value;
    }

    std::string Result::get_desc() const {
        const struct desc_t* ptr = Result::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool Result::operator==(int32_t value) const {
        return _value == value;
    }

    bool Result::operator!=(int32_t value) const {
        return _value != value;
    }

    bool Result::operator< (int32_t value) const {
        return _value < value;
    }

    bool Result::operator==(const Result& rhs) const {
        return _value == rhs.get_value();
    }

    bool Result::operator!=(const Result& rhs) const {
        return _value != rhs.get_value();
    }

    bool Result::operator< (const Result& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const Result& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const Result& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const Result& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const Result& e) {
        o << e.get_value();
        return o;
    }

    Math_add_args::Math_add_args() {
    }

    Math_add_args::~Math_add_args() {
    }

    bool Math_add_args::operator==(const Math_add_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (a != rhs.a) {
            return false;
        }
        if (b != rhs.b) {
            return false;
        }
        return true;
    }

    bool Math_add_args::operator!=(const Math_add_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_add_args::operator< (const Math_add_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(a < rhs.a)) {
            return false;
        }
        if (!(b < rhs.b)) {
            return false;
        }
        return true;
    }

    int32_t Math_add_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, a);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, b);
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

    Math_add_pargs::~Math_add_pargs() {
    }

    int32_t Math_add_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_add_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("a", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(a)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("b", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(b)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_add_result::Math_add_result() {
    }

    Math_add_result::~Math_add_result() {
    }

    bool Math_add_result::operator==(const Math_add_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (sum != rhs.sum) {
            return false;
        }
        return true;
    }

    bool Math_add_result::operator!=(const Math_add_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_add_result::operator< (const Math_add_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(sum < rhs.sum)) {
            return false;
        }
        return true;
    }

    int32_t Math_add_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_add_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sum", bgcc::IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(sum);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_add_presult::~Math_add_presult() {
    }

    int32_t Math_add_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
            case 3:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, (*(sum)));
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

    MathProxy::MathProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.math.Math";
    }

    MathProxy::MathProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.math.Math";
    }

    MathProxy::MathProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::BaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.math.Math";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    Result MathProxy::add(int32_t a, int32_t b, int32_t& sum, bool /*last*/) {
        Result return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_add(a, b, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_add(sum, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_add(const int32_t& a, const int32_t& b, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "add", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_add_pargs pargs;
        pargs.a = &a;
        pargs.b = &b;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Result MathProxy::recv_add(int32_t& sum, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        Result ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_add_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="add"){
            presult.return_value = &ret_val;
            presult.sum = &sum;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    SSLMathProxy::SSLMathProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.math.Math";
    }

    SSLMathProxy::SSLMathProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.math.Math";
    }

    SSLMathProxy::SSLMathProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::SSLBaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.math.Math";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    Result SSLMathProxy::add(int32_t a, int32_t b, int32_t& sum, bool /*last*/) {
        Result return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_add(a, b, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_add(sum, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_add(const int32_t& a, const int32_t& b, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "add", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_add_pargs pargs;
        pargs.a = &a;
        pargs.b = &b;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Result SSLMathProxy::recv_add(int32_t& sum, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        Result ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_add_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="add"){
            presult.return_value = &ret_val;
            presult.sum = &sum;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    MathProcessor::MathProcessor(bgcc::SharedPointer<Math> intf) :
        bgcc::BaseProcessor(), __intf(intf) {
        __fun_map["add"] = &MathProcessor::do_add;
    }

    int32_t MathProcessor::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

    std::string MathProcessor::get_name() const {
        return "global.math.Math";
    }

    int32_t MathProcessor::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, 
        const std::string& fname, int32_t seqid) {
        std::map<std::string, do_function_ptr>::iterator it;
        it = __fun_map.find(fname);
        if (it == __fun_map.end()) {
            return bgcc::BaseProcessor::do_function__(request, request_len, proto, fname, seqid);
        }

        return (this->*(it->second))(request, request_len, proto, seqid);
    }

    int32_t MathProcessor::do_add(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        Math_add_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_add_result result;
        result.return_value = __intf->add(args.a, args.b, result.sum, map);
        ret = proto->writeMessageBegin("global.math.Math", "add", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

}


