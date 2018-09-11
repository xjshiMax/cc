#include "ivr.h"

namespace ivr {

    const struct ReloadFlagT::desc_t ReloadFlagT::descs[] = {
        {ReloadFlagT::ReloadInBound, "ReloadFlagT::ReloadInBound"},
        {ReloadFlagT::ReloadAutorun, "ReloadFlagT::ReloadAutorun"},
        {ReloadFlagT::ReloadThreadCount, "ReloadFlagT::ReloadThreadCount"},
        {ReloadFlagT::ReloadEslLog, "ReloadFlagT::ReloadEslLog"},
        {ReloadFlagT::ReloadAll, "ReloadFlagT::ReloadAll"},
        {0, NULL}
    };

    ReloadFlagT::ReloadFlagT() : _value(ReloadInBound) {
    }

    ReloadFlagT::ReloadFlagT(int32_t value) : _value(value) {
    }

    int32_t ReloadFlagT::get_value() const {
        return _value;
    }

    std::string ReloadFlagT::get_desc() const {
        const struct desc_t* ptr = ReloadFlagT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool ReloadFlagT::operator==(int32_t value) const {
        return _value == value;
    }

    bool ReloadFlagT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool ReloadFlagT::operator< (int32_t value) const {
        return _value < value;
    }

    bool ReloadFlagT::operator==(const ReloadFlagT& rhs) const {
        return _value == rhs.get_value();
    }

    bool ReloadFlagT::operator!=(const ReloadFlagT& rhs) const {
        return _value != rhs.get_value();
    }

    bool ReloadFlagT::operator< (const ReloadFlagT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const ReloadFlagT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const ReloadFlagT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const ReloadFlagT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const ReloadFlagT& e) {
        o << e.get_value();
        return o;
    }


    const struct IvrResultT::desc_t IvrResultT::descs[] = {
        {IvrResultT::ResSuccess, "IvrResultT::ResSuccess"},
        {IvrResultT::ResFailed, "IvrResultT::ResFailed"},
        {IvrResultT::ResInvalidParam, "IvrResultT::ResInvalidParam"},
        {IvrResultT::ResNoEnoughResource, "IvrResultT::ResNoEnoughResource"},
        {0, NULL}
    };

    IvrResultT::IvrResultT() : _value(ResSuccess) {
    }

    IvrResultT::IvrResultT(int32_t value) : _value(value) {
    }

    int32_t IvrResultT::get_value() const {
        return _value;
    }

    std::string IvrResultT::get_desc() const {
        const struct desc_t* ptr = IvrResultT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool IvrResultT::operator==(int32_t value) const {
        return _value == value;
    }

    bool IvrResultT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool IvrResultT::operator< (int32_t value) const {
        return _value < value;
    }

    bool IvrResultT::operator==(const IvrResultT& rhs) const {
        return _value == rhs.get_value();
    }

    bool IvrResultT::operator!=(const IvrResultT& rhs) const {
        return _value != rhs.get_value();
    }

    bool IvrResultT::operator< (const IvrResultT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const IvrResultT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const IvrResultT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const IvrResultT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const IvrResultT& e) {
        o << e.get_value();
        return o;
    }

    ivrapi_ReloadConfig_args::ivrapi_ReloadConfig_args() {
    }

    ivrapi_ReloadConfig_args::~ivrapi_ReloadConfig_args() {
    }

    bool ivrapi_ReloadConfig_args::operator==(const ivrapi_ReloadConfig_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (type != rhs.type) {
            return false;
        }
        return true;
    }

    bool ivrapi_ReloadConfig_args::operator!=(const ivrapi_ReloadConfig_args& rhs) const {
        return !(*this == rhs);
    }

    bool ivrapi_ReloadConfig_args::operator< (const ivrapi_ReloadConfig_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(type < rhs.type)) {
            return false;
        }
        return true;
    }

    int32_t ivrapi_ReloadConfig_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    int32_t ele_var1;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var1);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    type = ele_var1;
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

    ivrapi_StartFlow_args::ivrapi_StartFlow_args() {
    }

    ivrapi_StartFlow_args::~ivrapi_StartFlow_args() {
    }

    bool ivrapi_StartFlow_args::operator==(const ivrapi_StartFlow_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (flowname != rhs.flowname) {
            return false;
        }
        if (flowvars != rhs.flowvars) {
            return false;
        }
        return true;
    }

    bool ivrapi_StartFlow_args::operator!=(const ivrapi_StartFlow_args& rhs) const {
        return !(*this == rhs);
    }

    bool ivrapi_StartFlow_args::operator< (const ivrapi_StartFlow_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(flowname < rhs.flowname)) {
            return false;
        }
        if (!(flowvars < rhs.flowvars)) {
            return false;
        }
        return true;
    }

    int32_t ivrapi_StartFlow_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, flowname);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, flowvars);
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

    ivrapi_Heartbeat_args::ivrapi_Heartbeat_args() {
    }

    ivrapi_Heartbeat_args::~ivrapi_Heartbeat_args() {
    }

    bool ivrapi_Heartbeat_args::operator==(const ivrapi_Heartbeat_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool ivrapi_Heartbeat_args::operator!=(const ivrapi_Heartbeat_args& rhs) const {
        return !(*this == rhs);
    }

    bool ivrapi_Heartbeat_args::operator< (const ivrapi_Heartbeat_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t ivrapi_Heartbeat_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

    ivrapi_ReloadConfig_pargs::~ivrapi_ReloadConfig_pargs() {
    }

    int32_t ivrapi_ReloadConfig_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("ivrapi_ReloadConfig_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("type", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(type)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    ivrapi_StartFlow_pargs::~ivrapi_StartFlow_pargs() {
    }

    int32_t ivrapi_StartFlow_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("ivrapi_StartFlow_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("flowname", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(flowname)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("flowvars", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(flowvars)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    ivrapi_Heartbeat_pargs::~ivrapi_Heartbeat_pargs() {
    }

    int32_t ivrapi_Heartbeat_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("ivrapi_Heartbeat_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    ivrapi_ReloadConfig_result::ivrapi_ReloadConfig_result() {
    }

    ivrapi_ReloadConfig_result::~ivrapi_ReloadConfig_result() {
    }

    bool ivrapi_ReloadConfig_result::operator==(const ivrapi_ReloadConfig_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool ivrapi_ReloadConfig_result::operator!=(const ivrapi_ReloadConfig_result& rhs) const {
        return !(*this == rhs);
    }

    bool ivrapi_ReloadConfig_result::operator< (const ivrapi_ReloadConfig_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t ivrapi_ReloadConfig_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("ivrapi_ReloadConfig_result");
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

    ivrapi_StartFlow_result::ivrapi_StartFlow_result() {
    }

    ivrapi_StartFlow_result::~ivrapi_StartFlow_result() {
    }

    bool ivrapi_StartFlow_result::operator==(const ivrapi_StartFlow_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool ivrapi_StartFlow_result::operator!=(const ivrapi_StartFlow_result& rhs) const {
        return !(*this == rhs);
    }

    bool ivrapi_StartFlow_result::operator< (const ivrapi_StartFlow_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t ivrapi_StartFlow_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("ivrapi_StartFlow_result");
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

    ivrapi_Heartbeat_result::ivrapi_Heartbeat_result() {
    }

    ivrapi_Heartbeat_result::~ivrapi_Heartbeat_result() {
    }

    bool ivrapi_Heartbeat_result::operator==(const ivrapi_Heartbeat_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (ivrinfo != rhs.ivrinfo) {
            return false;
        }
        return true;
    }

    bool ivrapi_Heartbeat_result::operator!=(const ivrapi_Heartbeat_result& rhs) const {
        return !(*this == rhs);
    }

    bool ivrapi_Heartbeat_result::operator< (const ivrapi_Heartbeat_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(ivrinfo < rhs.ivrinfo)) {
            return false;
        }
        return true;
    }

    int32_t ivrapi_Heartbeat_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("ivrapi_Heartbeat_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("ivrinfo", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(ivrinfo);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    ivrapi_ReloadConfig_presult::~ivrapi_ReloadConfig_presult() {
    }

    int32_t ivrapi_ReloadConfig_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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

    ivrapi_StartFlow_presult::~ivrapi_StartFlow_presult() {
    }

    int32_t ivrapi_StartFlow_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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

    ivrapi_Heartbeat_presult::~ivrapi_Heartbeat_presult() {
    }

    int32_t ivrapi_Heartbeat_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var4;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var4);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var4;
                break;
            case 1:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(ivrinfo)));
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

    ivrapiProxy::ivrapiProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.ivr.ivrapi";
    }

    ivrapiProxy::ivrapiProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.ivr.ivrapi";
    }

    ivrapiProxy::ivrapiProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::BaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.ivr.ivrapi";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    IvrResultT ivrapiProxy::ReloadConfig(const ReloadFlagT& type, bool /*last*/) {
        IvrResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_ReloadConfig(type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_ReloadConfig(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void ivrapiProxy::send_ReloadConfig(const ReloadFlagT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "ReloadConfig", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        ivrapi_ReloadConfig_pargs pargs;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    IvrResultT ivrapiProxy::recv_ReloadConfig(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        IvrResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        ivrapi_ReloadConfig_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="ReloadConfig"){
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

    IvrResultT ivrapiProxy::StartFlow(const std::string& flowname, const std::string& flowvars, bool /*last*/) {
        IvrResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_StartFlow(flowname, flowvars, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_StartFlow(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void ivrapiProxy::send_StartFlow(const std::string& flowname, const std::string& flowvars, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "StartFlow", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        ivrapi_StartFlow_pargs pargs;
        pargs.flowname = &flowname;
        pargs.flowvars = &flowvars;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    IvrResultT ivrapiProxy::recv_StartFlow(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        IvrResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        ivrapi_StartFlow_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="StartFlow"){
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

    IvrResultT ivrapiProxy::Heartbeat(std::string& ivrinfo, bool /*last*/) {
        IvrResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Heartbeat(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Heartbeat(ivrinfo, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void ivrapiProxy::send_Heartbeat(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Heartbeat", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        ivrapi_Heartbeat_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    IvrResultT ivrapiProxy::recv_Heartbeat(std::string& ivrinfo, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        IvrResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        ivrapi_Heartbeat_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Heartbeat"){
            presult.return_value = &ret_val;
            presult.ivrinfo = &ivrinfo;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    SSLivrapiProxy::SSLivrapiProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.ivr.ivrapi";
    }

    SSLivrapiProxy::SSLivrapiProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.ivr.ivrapi";
    }

    SSLivrapiProxy::SSLivrapiProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::SSLBaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.ivr.ivrapi";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    IvrResultT SSLivrapiProxy::ReloadConfig(const ReloadFlagT& type, bool /*last*/) {
        IvrResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_ReloadConfig(type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_ReloadConfig(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLivrapiProxy::send_ReloadConfig(const ReloadFlagT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "ReloadConfig", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        ivrapi_ReloadConfig_pargs pargs;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    IvrResultT SSLivrapiProxy::recv_ReloadConfig(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        IvrResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        ivrapi_ReloadConfig_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="ReloadConfig"){
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

    IvrResultT SSLivrapiProxy::StartFlow(const std::string& flowname, const std::string& flowvars, bool /*last*/) {
        IvrResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_StartFlow(flowname, flowvars, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_StartFlow(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLivrapiProxy::send_StartFlow(const std::string& flowname, const std::string& flowvars, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "StartFlow", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        ivrapi_StartFlow_pargs pargs;
        pargs.flowname = &flowname;
        pargs.flowvars = &flowvars;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    IvrResultT SSLivrapiProxy::recv_StartFlow(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        IvrResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        ivrapi_StartFlow_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="StartFlow"){
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

    IvrResultT SSLivrapiProxy::Heartbeat(std::string& ivrinfo, bool /*last*/) {
        IvrResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Heartbeat(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Heartbeat(ivrinfo, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLivrapiProxy::send_Heartbeat(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Heartbeat", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        ivrapi_Heartbeat_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    IvrResultT SSLivrapiProxy::recv_Heartbeat(std::string& ivrinfo, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        IvrResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        ivrapi_Heartbeat_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Heartbeat"){
            presult.return_value = &ret_val;
            presult.ivrinfo = &ivrinfo;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    ivrapiProcessor::ivrapiProcessor(bgcc::SharedPointer<ivrapi> intf) :
        bgcc::BaseProcessor(), __intf(intf) {
        __fun_map["ReloadConfig"] = &ivrapiProcessor::do_ReloadConfig;
        __fun_map["StartFlow"] = &ivrapiProcessor::do_StartFlow;
        __fun_map["Heartbeat"] = &ivrapiProcessor::do_Heartbeat;
    }

    int32_t ivrapiProcessor::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

    std::string ivrapiProcessor::get_name() const {
        return "global.ivr.ivrapi";
    }

    int32_t ivrapiProcessor::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, 
        const std::string& fname, int32_t seqid) {
        std::map<std::string, do_function_ptr>::iterator it;
        it = __fun_map.find(fname);
        if (it == __fun_map.end()) {
            return bgcc::BaseProcessor::do_function__(request, request_len, proto, fname, seqid);
        }

        return (this->*(it->second))(request, request_len, proto, seqid);
    }

    int32_t ivrapiProcessor::do_ReloadConfig(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        ivrapi_ReloadConfig_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        ivrapi_ReloadConfig_result result;
        result.return_value = __intf->ReloadConfig(args.type, map);
        ret = proto->writeMessageBegin("global.ivr.ivrapi", "ReloadConfig", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t ivrapiProcessor::do_StartFlow(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        ivrapi_StartFlow_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        ivrapi_StartFlow_result result;
        result.return_value = __intf->StartFlow(args.flowname, args.flowvars, map);
        ret = proto->writeMessageBegin("global.ivr.ivrapi", "StartFlow", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t ivrapiProcessor::do_Heartbeat(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        ivrapi_Heartbeat_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        ivrapi_Heartbeat_result result;
        result.return_value = __intf->Heartbeat(result.ivrinfo, map);
        ret = proto->writeMessageBegin("global.ivr.ivrapi", "Heartbeat", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

}


