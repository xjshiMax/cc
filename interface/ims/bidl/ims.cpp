#include "ims.h"

namespace ims {
    imsapi_Register_args::imsapi_Register_args() {
    }

    imsapi_Register_args::~imsapi_Register_args() {
    }

    bool imsapi_Register_args::operator==(const imsapi_Register_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (type != rhs.type) {
            return false;
        }
        return true;
    }

    bool imsapi_Register_args::operator!=(const imsapi_Register_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Register_args::operator< (const imsapi_Register_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(type < rhs.type)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Register_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

    imsapi_UnRegister_args::imsapi_UnRegister_args() {
    }

    imsapi_UnRegister_args::~imsapi_UnRegister_args() {
    }

    bool imsapi_UnRegister_args::operator==(const imsapi_UnRegister_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        return true;
    }

    bool imsapi_UnRegister_args::operator!=(const imsapi_UnRegister_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_UnRegister_args::operator< (const imsapi_UnRegister_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_UnRegister_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
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

    imsapi_Assign_args::imsapi_Assign_args() {
    }

    imsapi_Assign_args::~imsapi_Assign_args() {
    }

    bool imsapi_Assign_args::operator==(const imsapi_Assign_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        if (type != rhs.type) {
            return false;
        }
        return true;
    }

    bool imsapi_Assign_args::operator!=(const imsapi_Assign_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Assign_args::operator< (const imsapi_Assign_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        if (!(type < rhs.type)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Assign_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    int32_t ele_var2;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var2);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    type = ele_var2;
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

    imsapi_DeAssign_args::imsapi_DeAssign_args() {
    }

    imsapi_DeAssign_args::~imsapi_DeAssign_args() {
    }

    bool imsapi_DeAssign_args::operator==(const imsapi_DeAssign_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        if (type != rhs.type) {
            return false;
        }
        return true;
    }

    bool imsapi_DeAssign_args::operator!=(const imsapi_DeAssign_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_DeAssign_args::operator< (const imsapi_DeAssign_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        if (!(type < rhs.type)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_DeAssign_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    int32_t ele_var3;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var3);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    type = ele_var3;
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

    imsapi_OutboundCall_args::imsapi_OutboundCall_args() {
    }

    imsapi_OutboundCall_args::~imsapi_OutboundCall_args() {
    }

    bool imsapi_OutboundCall_args::operator==(const imsapi_OutboundCall_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        if (destUri != rhs.destUri) {
            return false;
        }
        if (setSrcUri != rhs.setSrcUri) {
            return false;
        }
        if (setDestUri != rhs.setDestUri) {
            return false;
        }
        if (timeout != rhs.timeout) {
            return false;
        }
        if (callmode != rhs.callmode) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        return true;
    }

    bool imsapi_OutboundCall_args::operator!=(const imsapi_OutboundCall_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_OutboundCall_args::operator< (const imsapi_OutboundCall_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        if (!(destUri < rhs.destUri)) {
            return false;
        }
        if (!(setSrcUri < rhs.setSrcUri)) {
            return false;
        }
        if (!(setDestUri < rhs.setDestUri)) {
            return false;
        }
        if (!(timeout < rhs.timeout)) {
            return false;
        }
        if (!(callmode < rhs.callmode)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_OutboundCall_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, destUri);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, setSrcUri);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 5:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, setDestUri);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 6:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, timeout);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 7:
                {
                    int32_t ele_var4;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var4);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    callmode = ele_var4;
                }
                break;
            case 8:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
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

    imsapi_Answer_args::imsapi_Answer_args() {
    }

    imsapi_Answer_args::~imsapi_Answer_args() {
    }

    bool imsapi_Answer_args::operator==(const imsapi_Answer_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        return true;
    }

    bool imsapi_Answer_args::operator!=(const imsapi_Answer_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Answer_args::operator< (const imsapi_Answer_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Answer_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
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

    imsapi_Release_args::imsapi_Release_args() {
    }

    imsapi_Release_args::~imsapi_Release_args() {
    }

    bool imsapi_Release_args::operator==(const imsapi_Release_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        return true;
    }

    bool imsapi_Release_args::operator!=(const imsapi_Release_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Release_args::operator< (const imsapi_Release_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Release_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
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

    imsapi_Hold_args::imsapi_Hold_args() {
    }

    imsapi_Hold_args::~imsapi_Hold_args() {
    }

    bool imsapi_Hold_args::operator==(const imsapi_Hold_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        return true;
    }

    bool imsapi_Hold_args::operator!=(const imsapi_Hold_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Hold_args::operator< (const imsapi_Hold_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Hold_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
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

    imsapi_Retrieve_args::imsapi_Retrieve_args() {
    }

    imsapi_Retrieve_args::~imsapi_Retrieve_args() {
    }

    bool imsapi_Retrieve_args::operator==(const imsapi_Retrieve_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        return true;
    }

    bool imsapi_Retrieve_args::operator!=(const imsapi_Retrieve_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Retrieve_args::operator< (const imsapi_Retrieve_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Retrieve_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
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

    imsapi_Consult_args::imsapi_Consult_args() {
    }

    imsapi_Consult_args::~imsapi_Consult_args() {
    }

    bool imsapi_Consult_args::operator==(const imsapi_Consult_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        if (destUri != rhs.destUri) {
            return false;
        }
        if (setDestUri != rhs.setDestUri) {
            return false;
        }
        return true;
    }

    bool imsapi_Consult_args::operator!=(const imsapi_Consult_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Consult_args::operator< (const imsapi_Consult_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        if (!(destUri < rhs.destUri)) {
            return false;
        }
        if (!(setDestUri < rhs.setDestUri)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Consult_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, destUri);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 5:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, setDestUri);
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

    imsapi_Reconnect_args::imsapi_Reconnect_args() {
    }

    imsapi_Reconnect_args::~imsapi_Reconnect_args() {
    }

    bool imsapi_Reconnect_args::operator==(const imsapi_Reconnect_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        return true;
    }

    bool imsapi_Reconnect_args::operator!=(const imsapi_Reconnect_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Reconnect_args::operator< (const imsapi_Reconnect_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Reconnect_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
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

    imsapi_Transfer_args::imsapi_Transfer_args() {
    }

    imsapi_Transfer_args::~imsapi_Transfer_args() {
    }

    bool imsapi_Transfer_args::operator==(const imsapi_Transfer_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        return true;
    }

    bool imsapi_Transfer_args::operator!=(const imsapi_Transfer_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Transfer_args::operator< (const imsapi_Transfer_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Transfer_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
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

    imsapi_Conference_args::imsapi_Conference_args() {
    }

    imsapi_Conference_args::~imsapi_Conference_args() {
    }

    bool imsapi_Conference_args::operator==(const imsapi_Conference_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        return true;
    }

    bool imsapi_Conference_args::operator!=(const imsapi_Conference_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Conference_args::operator< (const imsapi_Conference_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Conference_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
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

    imsapi_SingleStepTransfer_args::imsapi_SingleStepTransfer_args() {
    }

    imsapi_SingleStepTransfer_args::~imsapi_SingleStepTransfer_args() {
    }

    bool imsapi_SingleStepTransfer_args::operator==(const imsapi_SingleStepTransfer_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        if (destUri != rhs.destUri) {
            return false;
        }
        if (dispForCalled != rhs.dispForCalled) {
            return false;
        }
        return true;
    }

    bool imsapi_SingleStepTransfer_args::operator!=(const imsapi_SingleStepTransfer_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SingleStepTransfer_args::operator< (const imsapi_SingleStepTransfer_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        if (!(destUri < rhs.destUri)) {
            return false;
        }
        if (!(dispForCalled < rhs.dispForCalled)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SingleStepTransfer_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, destUri);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 5:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, dispForCalled);
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

    imsapi_SingleStepConference_args::imsapi_SingleStepConference_args() {
    }

    imsapi_SingleStepConference_args::~imsapi_SingleStepConference_args() {
    }

    bool imsapi_SingleStepConference_args::operator==(const imsapi_SingleStepConference_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        if (destUri != rhs.destUri) {
            return false;
        }
        if (dispForCalled != rhs.dispForCalled) {
            return false;
        }
        if (type != rhs.type) {
            return false;
        }
        return true;
    }

    bool imsapi_SingleStepConference_args::operator!=(const imsapi_SingleStepConference_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SingleStepConference_args::operator< (const imsapi_SingleStepConference_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        if (!(destUri < rhs.destUri)) {
            return false;
        }
        if (!(dispForCalled < rhs.dispForCalled)) {
            return false;
        }
        if (!(type < rhs.type)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SingleStepConference_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, destUri);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 5:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, dispForCalled);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 6:
                {
                    int32_t ele_var5;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var5);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    type = ele_var5;
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

    imsapi_SwitchListenAndIntrude_args::imsapi_SwitchListenAndIntrude_args() {
    }

    imsapi_SwitchListenAndIntrude_args::~imsapi_SwitchListenAndIntrude_args() {
    }

    bool imsapi_SwitchListenAndIntrude_args::operator==(const imsapi_SwitchListenAndIntrude_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        return true;
    }

    bool imsapi_SwitchListenAndIntrude_args::operator!=(const imsapi_SwitchListenAndIntrude_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SwitchListenAndIntrude_args::operator< (const imsapi_SwitchListenAndIntrude_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SwitchListenAndIntrude_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
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

    imsapi_SetAssociateData_args::imsapi_SetAssociateData_args() {
    }

    imsapi_SetAssociateData_args::~imsapi_SetAssociateData_args() {
    }

    bool imsapi_SetAssociateData_args::operator==(const imsapi_SetAssociateData_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (key != rhs.key) {
            return false;
        }
        if (val != rhs.val) {
            return false;
        }
        return true;
    }

    bool imsapi_SetAssociateData_args::operator!=(const imsapi_SetAssociateData_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SetAssociateData_args::operator< (const imsapi_SetAssociateData_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(key < rhs.key)) {
            return false;
        }
        if (!(val < rhs.val)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SetAssociateData_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, key);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, val);
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

    imsapi_GetAssociateData_args::imsapi_GetAssociateData_args() {
    }

    imsapi_GetAssociateData_args::~imsapi_GetAssociateData_args() {
    }

    bool imsapi_GetAssociateData_args::operator==(const imsapi_GetAssociateData_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (key != rhs.key) {
            return false;
        }
        return true;
    }

    bool imsapi_GetAssociateData_args::operator!=(const imsapi_GetAssociateData_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_GetAssociateData_args::operator< (const imsapi_GetAssociateData_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(key < rhs.key)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_GetAssociateData_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, key);
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

    imsapi_RouteRequest_args::imsapi_RouteRequest_args() {
    }

    imsapi_RouteRequest_args::~imsapi_RouteRequest_args() {
    }

    bool imsapi_RouteRequest_args::operator==(const imsapi_RouteRequest_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (destService != rhs.destService) {
            return false;
        }
        if (timeout != rhs.timeout) {
            return false;
        }
        if (valid_time != rhs.valid_time) {
            return false;
        }
        if (reqType != rhs.reqType) {
            return false;
        }
        if (reqArgs != rhs.reqArgs) {
            return false;
        }
        if (level != rhs.level) {
            return false;
        }
        if (caller_uri != rhs.caller_uri) {
            return false;
        }
        if (callee_uri != rhs.callee_uri) {
            return false;
        }
        if (buffer != rhs.buffer) {
            return false;
        }
        return true;
    }

    bool imsapi_RouteRequest_args::operator!=(const imsapi_RouteRequest_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_RouteRequest_args::operator< (const imsapi_RouteRequest_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(destService < rhs.destService)) {
            return false;
        }
        if (!(timeout < rhs.timeout)) {
            return false;
        }
        if (!(valid_time < rhs.valid_time)) {
            return false;
        }
        if (!(reqType < rhs.reqType)) {
            return false;
        }
        if (!(reqArgs < rhs.reqArgs)) {
            return false;
        }
        if (!(level < rhs.level)) {
            return false;
        }
        if (!(caller_uri < rhs.caller_uri)) {
            return false;
        }
        if (!(callee_uri < rhs.callee_uri)) {
            return false;
        }
        if (!(buffer < rhs.buffer)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_RouteRequest_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    int32_t ele_var6;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var6);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    destService = ele_var6;
                }
                break;
            case 4:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, timeout);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 5:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, valid_time);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 6:
                {
                    int32_t ele_var7;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var7);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    reqType = ele_var7;
                }
                break;
            case 7:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, reqArgs);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 8:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, level);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 9:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, caller_uri);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 10:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, callee_uri);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 11:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, buffer);
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

    imsapi_CancelRouteRequest_args::imsapi_CancelRouteRequest_args() {
    }

    imsapi_CancelRouteRequest_args::~imsapi_CancelRouteRequest_args() {
    }

    bool imsapi_CancelRouteRequest_args::operator==(const imsapi_CancelRouteRequest_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (requestId != rhs.requestId) {
            return false;
        }
        return true;
    }

    bool imsapi_CancelRouteRequest_args::operator!=(const imsapi_CancelRouteRequest_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_CancelRouteRequest_args::operator< (const imsapi_CancelRouteRequest_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(requestId < rhs.requestId)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_CancelRouteRequest_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, requestId);
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

    imsapi_RouteRequestRespond_args::imsapi_RouteRequestRespond_args() {
    }

    imsapi_RouteRequestRespond_args::~imsapi_RouteRequestRespond_args() {
    }

    bool imsapi_RouteRequestRespond_args::operator==(const imsapi_RouteRequestRespond_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (requestId != rhs.requestId) {
            return false;
        }
        if (result != rhs.result) {
            return false;
        }
        if (targetUri != rhs.targetUri) {
            return false;
        }
        return true;
    }

    bool imsapi_RouteRequestRespond_args::operator!=(const imsapi_RouteRequestRespond_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_RouteRequestRespond_args::operator< (const imsapi_RouteRequestRespond_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(requestId < rhs.requestId)) {
            return false;
        }
        if (!(result < rhs.result)) {
            return false;
        }
        if (!(targetUri < rhs.targetUri)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_RouteRequestRespond_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, requestId);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    int32_t ele_var8;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var8);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    result = ele_var8;
                }
                break;
            case 5:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, targetUri);
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

    imsapi_CreateSession_args::imsapi_CreateSession_args() {
    }

    imsapi_CreateSession_args::~imsapi_CreateSession_args() {
    }

    bool imsapi_CreateSession_args::operator==(const imsapi_CreateSession_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (callsource != rhs.callsource) {
            return false;
        }
        if (channel_id != rhs.channel_id) {
            return false;
        }
        if (oricalled != rhs.oricalled) {
            return false;
        }
        return true;
    }

    bool imsapi_CreateSession_args::operator!=(const imsapi_CreateSession_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_CreateSession_args::operator< (const imsapi_CreateSession_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(callsource < rhs.callsource)) {
            return false;
        }
        if (!(channel_id < rhs.channel_id)) {
            return false;
        }
        if (!(oricalled < rhs.oricalled)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_CreateSession_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, callsource);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, channel_id);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, oricalled);
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

    imsapi_TransferAgent_args::imsapi_TransferAgent_args() {
    }

    imsapi_TransferAgent_args::~imsapi_TransferAgent_args() {
    }

    bool imsapi_TransferAgent_args::operator==(const imsapi_TransferAgent_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (requestId != rhs.requestId) {
            return false;
        }
        if (transType != rhs.transType) {
            return false;
        }
        return true;
    }

    bool imsapi_TransferAgent_args::operator!=(const imsapi_TransferAgent_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_TransferAgent_args::operator< (const imsapi_TransferAgent_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(requestId < rhs.requestId)) {
            return false;
        }
        if (!(transType < rhs.transType)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_TransferAgent_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, requestId);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    int32_t ele_var9;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var9);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    transType = ele_var9;
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

    imsapi_Record_args::imsapi_Record_args() {
    }

    imsapi_Record_args::~imsapi_Record_args() {
    }

    bool imsapi_Record_args::operator==(const imsapi_Record_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        if (filename != rhs.filename) {
            return false;
        }
        if (maxTime != rhs.maxTime) {
            return false;
        }
        if (interruptKeys != rhs.interruptKeys) {
            return false;
        }
        return true;
    }

    bool imsapi_Record_args::operator!=(const imsapi_Record_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Record_args::operator< (const imsapi_Record_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        if (!(filename < rhs.filename)) {
            return false;
        }
        if (!(maxTime < rhs.maxTime)) {
            return false;
        }
        if (!(interruptKeys < rhs.interruptKeys)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Record_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, filename);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 5:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, maxTime);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 6:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, interruptKeys);
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

    imsapi_SendDTMF_args::imsapi_SendDTMF_args() {
    }

    imsapi_SendDTMF_args::~imsapi_SendDTMF_args() {
    }

    bool imsapi_SendDTMF_args::operator==(const imsapi_SendDTMF_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (devicenumber != rhs.devicenumber) {
            return false;
        }
        if (dtmf != rhs.dtmf) {
            return false;
        }
        return true;
    }

    bool imsapi_SendDTMF_args::operator!=(const imsapi_SendDTMF_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SendDTMF_args::operator< (const imsapi_SendDTMF_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(devicenumber < rhs.devicenumber)) {
            return false;
        }
        if (!(dtmf < rhs.dtmf)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SendDTMF_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, devicenumber);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 4:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, dtmf);
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

    imsapi_DestroySession_args::imsapi_DestroySession_args() {
    }

    imsapi_DestroySession_args::~imsapi_DestroySession_args() {
    }

    bool imsapi_DestroySession_args::operator==(const imsapi_DestroySession_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        return true;
    }

    bool imsapi_DestroySession_args::operator!=(const imsapi_DestroySession_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_DestroySession_args::operator< (const imsapi_DestroySession_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_DestroySession_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
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

    imsapi_QuerySession_args::imsapi_QuerySession_args() {
    }

    imsapi_QuerySession_args::~imsapi_QuerySession_args() {
    }

    bool imsapi_QuerySession_args::operator==(const imsapi_QuerySession_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        return true;
    }

    bool imsapi_QuerySession_args::operator!=(const imsapi_QuerySession_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_QuerySession_args::operator< (const imsapi_QuerySession_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_QuerySession_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
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

    imsapi_QueryCall_args::imsapi_QueryCall_args() {
    }

    imsapi_QueryCall_args::~imsapi_QueryCall_args() {
    }

    bool imsapi_QueryCall_args::operator==(const imsapi_QueryCall_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (callId != rhs.callId) {
            return false;
        }
        return true;
    }

    bool imsapi_QueryCall_args::operator!=(const imsapi_QueryCall_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_QueryCall_args::operator< (const imsapi_QueryCall_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(callId < rhs.callId)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_QueryCall_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, callId);
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

    imsapi_QueryDevice_args::imsapi_QueryDevice_args() {
    }

    imsapi_QueryDevice_args::~imsapi_QueryDevice_args() {
    }

    bool imsapi_QueryDevice_args::operator==(const imsapi_QueryDevice_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (device != rhs.device) {
            return false;
        }
        return true;
    }

    bool imsapi_QueryDevice_args::operator!=(const imsapi_QueryDevice_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_QueryDevice_args::operator< (const imsapi_QueryDevice_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(device < rhs.device)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_QueryDevice_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, device);
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

    imsapi_QuerySysInfo_args::imsapi_QuerySysInfo_args() {
    }

    imsapi_QuerySysInfo_args::~imsapi_QuerySysInfo_args() {
    }

    bool imsapi_QuerySysInfo_args::operator==(const imsapi_QuerySysInfo_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        return true;
    }

    bool imsapi_QuerySysInfo_args::operator!=(const imsapi_QuerySysInfo_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_QuerySysInfo_args::operator< (const imsapi_QuerySysInfo_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_QuerySysInfo_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
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

    imsapi_ReloadConfig_args::imsapi_ReloadConfig_args() {
    }

    imsapi_ReloadConfig_args::~imsapi_ReloadConfig_args() {
    }

    bool imsapi_ReloadConfig_args::operator==(const imsapi_ReloadConfig_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (type != rhs.type) {
            return false;
        }
        return true;
    }

    bool imsapi_ReloadConfig_args::operator!=(const imsapi_ReloadConfig_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_ReloadConfig_args::operator< (const imsapi_ReloadConfig_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(type < rhs.type)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_ReloadConfig_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    int32_t ele_var10;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var10);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    type = ele_var10;
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

    imsapi_HeartBeat_args::imsapi_HeartBeat_args() {
    }

    imsapi_HeartBeat_args::~imsapi_HeartBeat_args() {
    }

    bool imsapi_HeartBeat_args::operator==(const imsapi_HeartBeat_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        if (info != rhs.info) {
            return false;
        }
        return true;
    }

    bool imsapi_HeartBeat_args::operator!=(const imsapi_HeartBeat_args& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_HeartBeat_args::operator< (const imsapi_HeartBeat_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        if (!(info < rhs.info)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_HeartBeat_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, reqid);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, info);
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

    imsapi_Register_pargs::~imsapi_Register_pargs() {
    }

    int32_t imsapi_Register_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Register_pargs");
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

    imsapi_UnRegister_pargs::~imsapi_UnRegister_pargs() {
    }

    int32_t imsapi_UnRegister_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_UnRegister_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Assign_pargs::~imsapi_Assign_pargs() {
    }

    int32_t imsapi_Assign_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Assign_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("type", bgcc::IDINT32, 3);
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

    imsapi_DeAssign_pargs::~imsapi_DeAssign_pargs() {
    }

    int32_t imsapi_DeAssign_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_DeAssign_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("type", bgcc::IDINT32, 3);
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

    imsapi_OutboundCall_pargs::~imsapi_OutboundCall_pargs() {
    }

    int32_t imsapi_OutboundCall_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_OutboundCall_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("destUri", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(destUri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("setSrcUri", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(setSrcUri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("setDestUri", bgcc::IDSTR, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(setDestUri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("timeout", bgcc::IDINT32, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(timeout)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callmode", bgcc::IDINT32, 7);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(callmode)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 8);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Answer_pargs::~imsapi_Answer_pargs() {
    }

    int32_t imsapi_Answer_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Answer_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Release_pargs::~imsapi_Release_pargs() {
    }

    int32_t imsapi_Release_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Release_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Hold_pargs::~imsapi_Hold_pargs() {
    }

    int32_t imsapi_Hold_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Hold_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Retrieve_pargs::~imsapi_Retrieve_pargs() {
    }

    int32_t imsapi_Retrieve_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Retrieve_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Consult_pargs::~imsapi_Consult_pargs() {
    }

    int32_t imsapi_Consult_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Consult_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("destUri", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(destUri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("setDestUri", bgcc::IDSTR, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(setDestUri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Reconnect_pargs::~imsapi_Reconnect_pargs() {
    }

    int32_t imsapi_Reconnect_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Reconnect_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Transfer_pargs::~imsapi_Transfer_pargs() {
    }

    int32_t imsapi_Transfer_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Transfer_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Conference_pargs::~imsapi_Conference_pargs() {
    }

    int32_t imsapi_Conference_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Conference_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_SingleStepTransfer_pargs::~imsapi_SingleStepTransfer_pargs() {
    }

    int32_t imsapi_SingleStepTransfer_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SingleStepTransfer_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("destUri", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(destUri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("dispForCalled", bgcc::IDSTR, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(dispForCalled)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_SingleStepConference_pargs::~imsapi_SingleStepConference_pargs() {
    }

    int32_t imsapi_SingleStepConference_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SingleStepConference_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("destUri", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(destUri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("dispForCalled", bgcc::IDSTR, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(dispForCalled)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("type", bgcc::IDINT32, 6);
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

    imsapi_SwitchListenAndIntrude_pargs::~imsapi_SwitchListenAndIntrude_pargs() {
    }

    int32_t imsapi_SwitchListenAndIntrude_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SwitchListenAndIntrude_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_SetAssociateData_pargs::~imsapi_SetAssociateData_pargs() {
    }

    int32_t imsapi_SetAssociateData_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SetAssociateData_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("key", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(key)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("val", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(val)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_GetAssociateData_pargs::~imsapi_GetAssociateData_pargs() {
    }

    int32_t imsapi_GetAssociateData_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_GetAssociateData_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("key", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(key)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_RouteRequest_pargs::~imsapi_RouteRequest_pargs() {
    }

    int32_t imsapi_RouteRequest_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_RouteRequest_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("destService", bgcc::IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(destService)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("timeout", bgcc::IDINT32, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(timeout)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("valid_time", bgcc::IDINT32, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(valid_time)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqType", bgcc::IDINT32, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(reqType)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqArgs", bgcc::IDSTR, 7);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(reqArgs)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("level", bgcc::IDINT32, 8);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(level)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("caller_uri", bgcc::IDSTR, 9);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(caller_uri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callee_uri", bgcc::IDSTR, 10);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(callee_uri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("buffer", bgcc::IDSTR, 11);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(buffer)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_CancelRouteRequest_pargs::~imsapi_CancelRouteRequest_pargs() {
    }

    int32_t imsapi_CancelRouteRequest_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_CancelRouteRequest_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("requestId", bgcc::IDINT64, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(requestId)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_RouteRequestRespond_pargs::~imsapi_RouteRequestRespond_pargs() {
    }

    int32_t imsapi_RouteRequestRespond_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_RouteRequestRespond_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("requestId", bgcc::IDINT64, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(requestId)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("result", bgcc::IDINT32, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(result)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("targetUri", bgcc::IDSTR, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(targetUri)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_CreateSession_pargs::~imsapi_CreateSession_pargs() {
    }

    int32_t imsapi_CreateSession_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_CreateSession_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callsource", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(callsource)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("channel_id", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(channel_id)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("oricalled", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(oricalled)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_TransferAgent_pargs::~imsapi_TransferAgent_pargs() {
    }

    int32_t imsapi_TransferAgent_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_TransferAgent_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("requestId", bgcc::IDINT64, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(requestId)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("transType", bgcc::IDINT32, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(transType)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Record_pargs::~imsapi_Record_pargs() {
    }

    int32_t imsapi_Record_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Record_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("filename", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(filename)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("maxTime", bgcc::IDINT32, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(maxTime)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("interruptKeys", bgcc::IDSTR, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(interruptKeys)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_SendDTMF_pargs::~imsapi_SendDTMF_pargs() {
    }

    int32_t imsapi_SendDTMF_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SendDTMF_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("devicenumber", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(devicenumber)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("dtmf", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(dtmf)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_DestroySession_pargs::~imsapi_DestroySession_pargs() {
    }

    int32_t imsapi_DestroySession_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_DestroySession_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_QuerySession_pargs::~imsapi_QuerySession_pargs() {
    }

    int32_t imsapi_QuerySession_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_QuerySession_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_QueryCall_pargs::~imsapi_QueryCall_pargs() {
    }

    int32_t imsapi_QueryCall_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_QueryCall_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(sessionid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callId", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(callId)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_QueryDevice_pargs::~imsapi_QueryDevice_pargs() {
    }

    int32_t imsapi_QueryDevice_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_QueryDevice_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("device", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(device)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_QuerySysInfo_pargs::~imsapi_QuerySysInfo_pargs() {
    }

    int32_t imsapi_QuerySysInfo_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_QuerySysInfo_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_ReloadConfig_pargs::~imsapi_ReloadConfig_pargs() {
    }

    int32_t imsapi_ReloadConfig_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_ReloadConfig_pargs");
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

    imsapi_HeartBeat_pargs::~imsapi_HeartBeat_pargs() {
    }

    int32_t imsapi_HeartBeat_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_HeartBeat_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(reqid)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("info", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(info)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    imsapi_Register_result::imsapi_Register_result() {
    }

    imsapi_Register_result::~imsapi_Register_result() {
    }

    bool imsapi_Register_result::operator==(const imsapi_Register_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (reqid != rhs.reqid) {
            return false;
        }
        return true;
    }

    bool imsapi_Register_result::operator!=(const imsapi_Register_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Register_result::operator< (const imsapi_Register_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(reqid < rhs.reqid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Register_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Register_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reqid", bgcc::IDINT64, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(reqid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_UnRegister_result::imsapi_UnRegister_result() {
    }

    imsapi_UnRegister_result::~imsapi_UnRegister_result() {
    }

    bool imsapi_UnRegister_result::operator==(const imsapi_UnRegister_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_UnRegister_result::operator!=(const imsapi_UnRegister_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_UnRegister_result::operator< (const imsapi_UnRegister_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_UnRegister_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_UnRegister_result");
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

    imsapi_Assign_result::imsapi_Assign_result() {
    }

    imsapi_Assign_result::~imsapi_Assign_result() {
    }

    bool imsapi_Assign_result::operator==(const imsapi_Assign_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Assign_result::operator!=(const imsapi_Assign_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Assign_result::operator< (const imsapi_Assign_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Assign_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Assign_result");
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

    imsapi_DeAssign_result::imsapi_DeAssign_result() {
    }

    imsapi_DeAssign_result::~imsapi_DeAssign_result() {
    }

    bool imsapi_DeAssign_result::operator==(const imsapi_DeAssign_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_DeAssign_result::operator!=(const imsapi_DeAssign_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_DeAssign_result::operator< (const imsapi_DeAssign_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_DeAssign_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_DeAssign_result");
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

    imsapi_OutboundCall_result::imsapi_OutboundCall_result() {
    }

    imsapi_OutboundCall_result::~imsapi_OutboundCall_result() {
    }

    bool imsapi_OutboundCall_result::operator==(const imsapi_OutboundCall_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        return true;
    }

    bool imsapi_OutboundCall_result::operator!=(const imsapi_OutboundCall_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_OutboundCall_result::operator< (const imsapi_OutboundCall_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_OutboundCall_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_OutboundCall_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 8);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_Answer_result::imsapi_Answer_result() {
    }

    imsapi_Answer_result::~imsapi_Answer_result() {
    }

    bool imsapi_Answer_result::operator==(const imsapi_Answer_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Answer_result::operator!=(const imsapi_Answer_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Answer_result::operator< (const imsapi_Answer_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Answer_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Answer_result");
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

    imsapi_Release_result::imsapi_Release_result() {
    }

    imsapi_Release_result::~imsapi_Release_result() {
    }

    bool imsapi_Release_result::operator==(const imsapi_Release_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Release_result::operator!=(const imsapi_Release_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Release_result::operator< (const imsapi_Release_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Release_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Release_result");
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

    imsapi_Hold_result::imsapi_Hold_result() {
    }

    imsapi_Hold_result::~imsapi_Hold_result() {
    }

    bool imsapi_Hold_result::operator==(const imsapi_Hold_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Hold_result::operator!=(const imsapi_Hold_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Hold_result::operator< (const imsapi_Hold_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Hold_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Hold_result");
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

    imsapi_Retrieve_result::imsapi_Retrieve_result() {
    }

    imsapi_Retrieve_result::~imsapi_Retrieve_result() {
    }

    bool imsapi_Retrieve_result::operator==(const imsapi_Retrieve_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Retrieve_result::operator!=(const imsapi_Retrieve_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Retrieve_result::operator< (const imsapi_Retrieve_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Retrieve_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Retrieve_result");
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

    imsapi_Consult_result::imsapi_Consult_result() {
    }

    imsapi_Consult_result::~imsapi_Consult_result() {
    }

    bool imsapi_Consult_result::operator==(const imsapi_Consult_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Consult_result::operator!=(const imsapi_Consult_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Consult_result::operator< (const imsapi_Consult_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Consult_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Consult_result");
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

    imsapi_Reconnect_result::imsapi_Reconnect_result() {
    }

    imsapi_Reconnect_result::~imsapi_Reconnect_result() {
    }

    bool imsapi_Reconnect_result::operator==(const imsapi_Reconnect_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Reconnect_result::operator!=(const imsapi_Reconnect_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Reconnect_result::operator< (const imsapi_Reconnect_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Reconnect_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Reconnect_result");
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

    imsapi_Transfer_result::imsapi_Transfer_result() {
    }

    imsapi_Transfer_result::~imsapi_Transfer_result() {
    }

    bool imsapi_Transfer_result::operator==(const imsapi_Transfer_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Transfer_result::operator!=(const imsapi_Transfer_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Transfer_result::operator< (const imsapi_Transfer_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Transfer_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Transfer_result");
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

    imsapi_Conference_result::imsapi_Conference_result() {
    }

    imsapi_Conference_result::~imsapi_Conference_result() {
    }

    bool imsapi_Conference_result::operator==(const imsapi_Conference_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Conference_result::operator!=(const imsapi_Conference_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Conference_result::operator< (const imsapi_Conference_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Conference_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Conference_result");
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

    imsapi_SingleStepTransfer_result::imsapi_SingleStepTransfer_result() {
    }

    imsapi_SingleStepTransfer_result::~imsapi_SingleStepTransfer_result() {
    }

    bool imsapi_SingleStepTransfer_result::operator==(const imsapi_SingleStepTransfer_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_SingleStepTransfer_result::operator!=(const imsapi_SingleStepTransfer_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SingleStepTransfer_result::operator< (const imsapi_SingleStepTransfer_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SingleStepTransfer_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SingleStepTransfer_result");
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

    imsapi_SingleStepConference_result::imsapi_SingleStepConference_result() {
    }

    imsapi_SingleStepConference_result::~imsapi_SingleStepConference_result() {
    }

    bool imsapi_SingleStepConference_result::operator==(const imsapi_SingleStepConference_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_SingleStepConference_result::operator!=(const imsapi_SingleStepConference_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SingleStepConference_result::operator< (const imsapi_SingleStepConference_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SingleStepConference_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SingleStepConference_result");
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

    imsapi_SwitchListenAndIntrude_result::imsapi_SwitchListenAndIntrude_result() {
    }

    imsapi_SwitchListenAndIntrude_result::~imsapi_SwitchListenAndIntrude_result() {
    }

    bool imsapi_SwitchListenAndIntrude_result::operator==(const imsapi_SwitchListenAndIntrude_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_SwitchListenAndIntrude_result::operator!=(const imsapi_SwitchListenAndIntrude_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SwitchListenAndIntrude_result::operator< (const imsapi_SwitchListenAndIntrude_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SwitchListenAndIntrude_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SwitchListenAndIntrude_result");
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

    imsapi_SetAssociateData_result::imsapi_SetAssociateData_result() {
    }

    imsapi_SetAssociateData_result::~imsapi_SetAssociateData_result() {
    }

    bool imsapi_SetAssociateData_result::operator==(const imsapi_SetAssociateData_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_SetAssociateData_result::operator!=(const imsapi_SetAssociateData_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SetAssociateData_result::operator< (const imsapi_SetAssociateData_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SetAssociateData_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SetAssociateData_result");
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

    imsapi_GetAssociateData_result::imsapi_GetAssociateData_result() {
    }

    imsapi_GetAssociateData_result::~imsapi_GetAssociateData_result() {
    }

    bool imsapi_GetAssociateData_result::operator==(const imsapi_GetAssociateData_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (val != rhs.val) {
            return false;
        }
        return true;
    }

    bool imsapi_GetAssociateData_result::operator!=(const imsapi_GetAssociateData_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_GetAssociateData_result::operator< (const imsapi_GetAssociateData_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(val < rhs.val)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_GetAssociateData_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_GetAssociateData_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("val", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString(val);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_RouteRequest_result::imsapi_RouteRequest_result() {
    }

    imsapi_RouteRequest_result::~imsapi_RouteRequest_result() {
    }

    bool imsapi_RouteRequest_result::operator==(const imsapi_RouteRequest_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (requestId != rhs.requestId) {
            return false;
        }
        return true;
    }

    bool imsapi_RouteRequest_result::operator!=(const imsapi_RouteRequest_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_RouteRequest_result::operator< (const imsapi_RouteRequest_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(requestId < rhs.requestId)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_RouteRequest_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_RouteRequest_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("requestId", bgcc::IDINT64, 12);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(requestId);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_CancelRouteRequest_result::imsapi_CancelRouteRequest_result() {
    }

    imsapi_CancelRouteRequest_result::~imsapi_CancelRouteRequest_result() {
    }

    bool imsapi_CancelRouteRequest_result::operator==(const imsapi_CancelRouteRequest_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_CancelRouteRequest_result::operator!=(const imsapi_CancelRouteRequest_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_CancelRouteRequest_result::operator< (const imsapi_CancelRouteRequest_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_CancelRouteRequest_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_CancelRouteRequest_result");
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

    imsapi_RouteRequestRespond_result::imsapi_RouteRequestRespond_result() {
    }

    imsapi_RouteRequestRespond_result::~imsapi_RouteRequestRespond_result() {
    }

    bool imsapi_RouteRequestRespond_result::operator==(const imsapi_RouteRequestRespond_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_RouteRequestRespond_result::operator!=(const imsapi_RouteRequestRespond_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_RouteRequestRespond_result::operator< (const imsapi_RouteRequestRespond_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_RouteRequestRespond_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_RouteRequestRespond_result");
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

    imsapi_CreateSession_result::imsapi_CreateSession_result() {
    }

    imsapi_CreateSession_result::~imsapi_CreateSession_result() {
    }

    bool imsapi_CreateSession_result::operator==(const imsapi_CreateSession_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        return true;
    }

    bool imsapi_CreateSession_result::operator!=(const imsapi_CreateSession_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_CreateSession_result::operator< (const imsapi_CreateSession_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_CreateSession_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_CreateSession_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_TransferAgent_result::imsapi_TransferAgent_result() {
    }

    imsapi_TransferAgent_result::~imsapi_TransferAgent_result() {
    }

    bool imsapi_TransferAgent_result::operator==(const imsapi_TransferAgent_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_TransferAgent_result::operator!=(const imsapi_TransferAgent_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_TransferAgent_result::operator< (const imsapi_TransferAgent_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_TransferAgent_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_TransferAgent_result");
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

    imsapi_Record_result::imsapi_Record_result() {
    }

    imsapi_Record_result::~imsapi_Record_result() {
    }

    bool imsapi_Record_result::operator==(const imsapi_Record_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_Record_result::operator!=(const imsapi_Record_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_Record_result::operator< (const imsapi_Record_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_Record_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_Record_result");
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

    imsapi_SendDTMF_result::imsapi_SendDTMF_result() {
    }

    imsapi_SendDTMF_result::~imsapi_SendDTMF_result() {
    }

    bool imsapi_SendDTMF_result::operator==(const imsapi_SendDTMF_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_SendDTMF_result::operator!=(const imsapi_SendDTMF_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_SendDTMF_result::operator< (const imsapi_SendDTMF_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_SendDTMF_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_SendDTMF_result");
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

    imsapi_DestroySession_result::imsapi_DestroySession_result() {
    }

    imsapi_DestroySession_result::~imsapi_DestroySession_result() {
    }

    bool imsapi_DestroySession_result::operator==(const imsapi_DestroySession_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_DestroySession_result::operator!=(const imsapi_DestroySession_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_DestroySession_result::operator< (const imsapi_DestroySession_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_DestroySession_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_DestroySession_result");
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

    imsapi_QuerySession_result::imsapi_QuerySession_result() {
    }

    imsapi_QuerySession_result::~imsapi_QuerySession_result() {
    }

    bool imsapi_QuerySession_result::operator==(const imsapi_QuerySession_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (originalAni != rhs.originalAni) {
            return false;
        }
        if (originalDnis != rhs.originalDnis) {
            return false;
        }
        if (callidList != rhs.callidList) {
            return false;
        }
        if (deviceList != rhs.deviceList) {
            return false;
        }
        return true;
    }

    bool imsapi_QuerySession_result::operator!=(const imsapi_QuerySession_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_QuerySession_result::operator< (const imsapi_QuerySession_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(originalAni < rhs.originalAni)) {
            return false;
        }
        if (!(originalDnis < rhs.originalDnis)) {
            return false;
        }
        if (!(callidList < rhs.callidList)) {
            return false;
        }
        if (!(deviceList < rhs.deviceList)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_QuerySession_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_QuerySession_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("originalAni", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString(originalAni);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("originalDnis", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString(originalDnis);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callidList", bgcc::IDLIST, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTR, callidList.size());
        if (ret < 0) { return ret; }
        std::vector<CallIdT> ::const_iterator citr_var11;
        for (citr_var11 = callidList.begin(); citr_var11 != callidList.end(); ++citr_var11) {
            ret = proto->writeString((*citr_var11));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("deviceList", bgcc::IDLIST, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTR, deviceList.size());
        if (ret < 0) { return ret; }
        std::vector<std::string> ::const_iterator citr_var12;
        for (citr_var12 = deviceList.begin(); citr_var12 != deviceList.end(); ++citr_var12) {
            ret = proto->writeString((*citr_var12));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_QueryCall_result::imsapi_QueryCall_result() {
    }

    imsapi_QueryCall_result::~imsapi_QueryCall_result() {
    }

    bool imsapi_QueryCall_result::operator==(const imsapi_QueryCall_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (deviceAni != rhs.deviceAni) {
            return false;
        }
        if (deviceDnis != rhs.deviceDnis) {
            return false;
        }
        if (originalAni != rhs.originalAni) {
            return false;
        }
        if (originalDnis != rhs.originalDnis) {
            return false;
        }
        if (deviceList != rhs.deviceList) {
            return false;
        }
        if (fsid != rhs.fsid) {
            return false;
        }
        return true;
    }

    bool imsapi_QueryCall_result::operator!=(const imsapi_QueryCall_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_QueryCall_result::operator< (const imsapi_QueryCall_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(deviceAni < rhs.deviceAni)) {
            return false;
        }
        if (!(deviceDnis < rhs.deviceDnis)) {
            return false;
        }
        if (!(originalAni < rhs.originalAni)) {
            return false;
        }
        if (!(originalDnis < rhs.originalDnis)) {
            return false;
        }
        if (!(deviceList < rhs.deviceList)) {
            return false;
        }
        if (!(fsid < rhs.fsid)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_QueryCall_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_QueryCall_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("deviceAni", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString(deviceAni);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("deviceDnis", bgcc::IDSTR, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeString(deviceDnis);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("originalAni", bgcc::IDSTR, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeString(originalAni);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("originalDnis", bgcc::IDSTR, 7);
        if (ret < 0) { return ret; }
        ret = proto->writeString(originalDnis);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("deviceList", bgcc::IDLIST, 8);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTR, deviceList.size());
        if (ret < 0) { return ret; }
        std::vector<std::string> ::const_iterator citr_var13;
        for (citr_var13 = deviceList.begin(); citr_var13 != deviceList.end(); ++citr_var13) {
            ret = proto->writeString((*citr_var13));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("fsid", bgcc::IDINT32, 9);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(fsid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_QueryDevice_result::imsapi_QueryDevice_result() {
    }

    imsapi_QueryDevice_result::~imsapi_QueryDevice_result() {
    }

    bool imsapi_QueryDevice_result::operator==(const imsapi_QueryDevice_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (callId != rhs.callId) {
            return false;
        }
        if (callstate != rhs.callstate) {
            return false;
        }
        if (mediastate != rhs.mediastate) {
            return false;
        }
        return true;
    }

    bool imsapi_QueryDevice_result::operator!=(const imsapi_QueryDevice_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_QueryDevice_result::operator< (const imsapi_QueryDevice_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(sessionid < rhs.sessionid)) {
            return false;
        }
        if (!(callId < rhs.callId)) {
            return false;
        }
        if (!(callstate < rhs.callstate)) {
            return false;
        }
        if (!(mediastate < rhs.mediastate)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_QueryDevice_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_QueryDevice_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callId", bgcc::IDSTR, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeString(callId);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callstate", bgcc::IDINT32, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(callstate.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("mediastate", bgcc::IDINT32, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(mediastate.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_QuerySysInfo_result::imsapi_QuerySysInfo_result() {
    }

    imsapi_QuerySysInfo_result::~imsapi_QuerySysInfo_result() {
    }

    bool imsapi_QuerySysInfo_result::operator==(const imsapi_QuerySysInfo_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (sysinfo != rhs.sysinfo) {
            return false;
        }
        return true;
    }

    bool imsapi_QuerySysInfo_result::operator!=(const imsapi_QuerySysInfo_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_QuerySysInfo_result::operator< (const imsapi_QuerySysInfo_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(sysinfo < rhs.sysinfo)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_QuerySysInfo_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_QuerySysInfo_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sysinfo", bgcc::IDSTRUCT, 2);
        if (ret < 0) { return ret; }
        ret = sysinfo.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    imsapi_ReloadConfig_result::imsapi_ReloadConfig_result() {
    }

    imsapi_ReloadConfig_result::~imsapi_ReloadConfig_result() {
    }

    bool imsapi_ReloadConfig_result::operator==(const imsapi_ReloadConfig_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_ReloadConfig_result::operator!=(const imsapi_ReloadConfig_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_ReloadConfig_result::operator< (const imsapi_ReloadConfig_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_ReloadConfig_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_ReloadConfig_result");
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

    imsapi_HeartBeat_result::imsapi_HeartBeat_result() {
    }

    imsapi_HeartBeat_result::~imsapi_HeartBeat_result() {
    }

    bool imsapi_HeartBeat_result::operator==(const imsapi_HeartBeat_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool imsapi_HeartBeat_result::operator!=(const imsapi_HeartBeat_result& rhs) const {
        return !(*this == rhs);
    }

    bool imsapi_HeartBeat_result::operator< (const imsapi_HeartBeat_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t imsapi_HeartBeat_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("imsapi_HeartBeat_result");
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

    imsapi_Register_presult::~imsapi_Register_presult() {
    }

    int32_t imsapi_Register_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var14;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var14);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var14;
                break;
            case 2:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, (*(reqid)));
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

    imsapi_UnRegister_presult::~imsapi_UnRegister_presult() {
    }

    int32_t imsapi_UnRegister_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var15;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var15);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var15;
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

    imsapi_Assign_presult::~imsapi_Assign_presult() {
    }

    int32_t imsapi_Assign_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var16;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var16);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var16;
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

    imsapi_DeAssign_presult::~imsapi_DeAssign_presult() {
    }

    int32_t imsapi_DeAssign_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var17;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var17);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var17;
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

    imsapi_OutboundCall_presult::~imsapi_OutboundCall_presult() {
    }

    int32_t imsapi_OutboundCall_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var18;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var18);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var18;
                break;
            case 8:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, (*(sessionid)));
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

    imsapi_Answer_presult::~imsapi_Answer_presult() {
    }

    int32_t imsapi_Answer_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var19;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var19);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var19;
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

    imsapi_Release_presult::~imsapi_Release_presult() {
    }

    int32_t imsapi_Release_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var20;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var20);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var20;
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

    imsapi_Hold_presult::~imsapi_Hold_presult() {
    }

    int32_t imsapi_Hold_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var21;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var21);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var21;
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

    imsapi_Retrieve_presult::~imsapi_Retrieve_presult() {
    }

    int32_t imsapi_Retrieve_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var22;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var22);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var22;
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

    imsapi_Consult_presult::~imsapi_Consult_presult() {
    }

    int32_t imsapi_Consult_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var23;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var23);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var23;
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

    imsapi_Reconnect_presult::~imsapi_Reconnect_presult() {
    }

    int32_t imsapi_Reconnect_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var24;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var24);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var24;
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

    imsapi_Transfer_presult::~imsapi_Transfer_presult() {
    }

    int32_t imsapi_Transfer_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var25;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var25);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var25;
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

    imsapi_Conference_presult::~imsapi_Conference_presult() {
    }

    int32_t imsapi_Conference_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var26;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var26);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var26;
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

    imsapi_SingleStepTransfer_presult::~imsapi_SingleStepTransfer_presult() {
    }

    int32_t imsapi_SingleStepTransfer_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var27;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var27);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var27;
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

    imsapi_SingleStepConference_presult::~imsapi_SingleStepConference_presult() {
    }

    int32_t imsapi_SingleStepConference_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var28;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var28);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var28;
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

    imsapi_SwitchListenAndIntrude_presult::~imsapi_SwitchListenAndIntrude_presult() {
    }

    int32_t imsapi_SwitchListenAndIntrude_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var29;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var29);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var29;
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

    imsapi_SetAssociateData_presult::~imsapi_SetAssociateData_presult() {
    }

    int32_t imsapi_SetAssociateData_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var30;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var30);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var30;
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

    imsapi_GetAssociateData_presult::~imsapi_GetAssociateData_presult() {
    }

    int32_t imsapi_GetAssociateData_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var31;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var31);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var31;
                break;
            case 4:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(val)));
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

    imsapi_RouteRequest_presult::~imsapi_RouteRequest_presult() {
    }

    int32_t imsapi_RouteRequest_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var32;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var32);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var32;
                break;
            case 12:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, (*(requestId)));
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

    imsapi_CancelRouteRequest_presult::~imsapi_CancelRouteRequest_presult() {
    }

    int32_t imsapi_CancelRouteRequest_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var33;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var33);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var33;
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

    imsapi_RouteRequestRespond_presult::~imsapi_RouteRequestRespond_presult() {
    }

    int32_t imsapi_RouteRequestRespond_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var34;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var34);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var34;
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

    imsapi_CreateSession_presult::~imsapi_CreateSession_presult() {
    }

    int32_t imsapi_CreateSession_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var35;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var35);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var35;
                break;
            case 5:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, (*(sessionid)));
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

    imsapi_TransferAgent_presult::~imsapi_TransferAgent_presult() {
    }

    int32_t imsapi_TransferAgent_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var36;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var36);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var36;
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

    imsapi_Record_presult::~imsapi_Record_presult() {
    }

    int32_t imsapi_Record_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var37;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var37);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var37;
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

    imsapi_SendDTMF_presult::~imsapi_SendDTMF_presult() {
    }

    int32_t imsapi_SendDTMF_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var38;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var38);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var38;
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

    imsapi_DestroySession_presult::~imsapi_DestroySession_presult() {
    }

    int32_t imsapi_DestroySession_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var39;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var39);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var39;
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

    imsapi_QuerySession_presult::~imsapi_QuerySession_presult() {
    }

    int32_t imsapi_QuerySession_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var40;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var40);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var40;
                break;
            case 3:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(originalAni)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 4:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(originalDnis)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 5:
                (*(callidList)).clear();

                int32_t size_var41;
                bgcc::DataTypeID etype_var42;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var42, size_var41);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(callidList)).reserve(size_var41);
                for(int32_t i = 0; i < size_var41; ++i) {
                    CallIdT value_var43;
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value_var43);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(callidList)).push_back(value_var43);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 6:
                (*(deviceList)).clear();

                int32_t size_var44;
                bgcc::DataTypeID etype_var45;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var45, size_var44);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(deviceList)).reserve(size_var44);
                for(int32_t i = 0; i < size_var44; ++i) {
                    std::string value_var46;
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value_var46);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(deviceList)).push_back(value_var46);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
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

    imsapi_QueryCall_presult::~imsapi_QueryCall_presult() {
    }

    int32_t imsapi_QueryCall_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var47;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var47);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var47;
                break;
            case 4:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(deviceAni)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 5:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(deviceDnis)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 6:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(originalAni)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 7:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(originalDnis)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 8:
                (*(deviceList)).clear();

                int32_t size_var48;
                bgcc::DataTypeID etype_var49;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var49, size_var48);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(deviceList)).reserve(size_var48);
                for(int32_t i = 0; i < size_var48; ++i) {
                    std::string value_var50;
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value_var50);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(deviceList)).push_back(value_var50);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 9:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, (*(fsid)));
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

    imsapi_QueryDevice_presult::~imsapi_QueryDevice_presult() {
    }

    int32_t imsapi_QueryDevice_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var51;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var51);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var51;
                break;
            case 3:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, (*(sessionid)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 4:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(callId)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 5:
                int32_t ele_var52;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var52);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(callstate)) = ele_var52;
                break;
            case 6:
                int32_t ele_var53;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var53);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(mediastate)) = ele_var53;
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

    imsapi_QuerySysInfo_presult::~imsapi_QuerySysInfo_presult() {
    }

    int32_t imsapi_QuerySysInfo_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var54;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var54);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var54;
                break;
            case 2:
                ret = (*(sysinfo)).read(OFFSET_PTR(request, nread), request_len - nread, proto);
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

    imsapi_ReloadConfig_presult::~imsapi_ReloadConfig_presult() {
    }

    int32_t imsapi_ReloadConfig_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var55;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var55);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var55;
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

    imsapi_HeartBeat_presult::~imsapi_HeartBeat_presult() {
    }

    int32_t imsapi_HeartBeat_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
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
                int32_t ele_var56;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var56);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var56;
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

    imsapiProxy::imsapiProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.ims.imsapi";
    }

    imsapiProxy::imsapiProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.ims.imsapi";
    }

    imsapiProxy::imsapiProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::BaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.ims.imsapi";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    CcResultT imsapiProxy::Register(const ServiceTypeT& type, ReqIdT& reqid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Register(type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Register(reqid, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Register(const ServiceTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Register", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Register_pargs pargs;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Register(ReqIdT& reqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Register_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Register"){
            presult.return_value = &ret_val;
            presult.reqid = &reqid;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::UnRegister(ReqIdT reqid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_UnRegister(reqid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_UnRegister(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_UnRegister(const ReqIdT& reqid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "UnRegister", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_UnRegister_pargs pargs;
        pargs.reqid = &reqid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_UnRegister(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_UnRegister_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="UnRegister"){
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

    CcResultT imsapiProxy::Assign(ReqIdT reqid, const std::string& devicenumber, const DnTypeT& type, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Assign(reqid, devicenumber, type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Assign(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Assign(const ReqIdT& reqid, const std::string& devicenumber, const DnTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Assign", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Assign_pargs pargs;
        pargs.reqid = &reqid;
        pargs.devicenumber = &devicenumber;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Assign(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Assign_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Assign"){
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

    CcResultT imsapiProxy::DeAssign(ReqIdT reqid, const std::string& devicenumber, const DnTypeT& type, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_DeAssign(reqid, devicenumber, type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_DeAssign(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_DeAssign(const ReqIdT& reqid, const std::string& devicenumber, const DnTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "DeAssign", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_DeAssign_pargs pargs;
        pargs.reqid = &reqid;
        pargs.devicenumber = &devicenumber;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_DeAssign(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_DeAssign_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="DeAssign"){
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

    CcResultT imsapiProxy::OutboundCall(ReqIdT reqid, const std::string& devicenumber, const std::string& destUri, const std::string& setSrcUri, const std::string& setDestUri, int32_t timeout, const CallModeT& callmode, SessionIdT& sessionid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_OutboundCall(reqid, devicenumber, destUri, setSrcUri, setDestUri, timeout, callmode, sessionid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_OutboundCall(sessionid, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_OutboundCall(const ReqIdT& reqid, const std::string& devicenumber, const std::string& destUri, const std::string& setSrcUri, const std::string& setDestUri, const int32_t& timeout, const CallModeT& callmode, const SessionIdT& sessionid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "OutboundCall", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_OutboundCall_pargs pargs;
        pargs.reqid = &reqid;
        pargs.devicenumber = &devicenumber;
        pargs.destUri = &destUri;
        pargs.setSrcUri = &setSrcUri;
        pargs.setDestUri = &setDestUri;
        pargs.timeout = &timeout;
        pargs.callmode = &callmode;
        pargs.sessionid = &sessionid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_OutboundCall(SessionIdT& sessionid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_OutboundCall_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="OutboundCall"){
            presult.return_value = &ret_val;
            presult.sessionid = &sessionid;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::Answer(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Answer(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Answer(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Answer(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Answer", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Answer_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Answer(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Answer_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Answer"){
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

    CcResultT imsapiProxy::Release(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Release(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Release(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Release(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Release", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Release_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Release(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Release_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Release"){
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

    CcResultT imsapiProxy::Hold(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Hold(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Hold(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Hold(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Hold", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Hold_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Hold(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Hold_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Hold"){
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

    CcResultT imsapiProxy::Retrieve(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Retrieve(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Retrieve(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Retrieve(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Retrieve", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Retrieve_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Retrieve(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Retrieve_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Retrieve"){
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

    CcResultT imsapiProxy::Consult(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& setDestUri, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Consult(reqid, sessionid, devicenumber, destUri, setDestUri, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Consult(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Consult(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& setDestUri, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Consult", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Consult_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.destUri = &destUri;
        pargs.setDestUri = &setDestUri;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Consult(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Consult_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Consult"){
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

    CcResultT imsapiProxy::Reconnect(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Reconnect(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Reconnect(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Reconnect(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Reconnect", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Reconnect_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Reconnect(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Reconnect_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Reconnect"){
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

    CcResultT imsapiProxy::Transfer(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Transfer(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Transfer(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Transfer(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Transfer", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Transfer_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Transfer(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Transfer_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Transfer"){
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

    CcResultT imsapiProxy::Conference(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Conference(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Conference(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Conference(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Conference", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Conference_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Conference(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Conference_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Conference"){
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

    CcResultT imsapiProxy::SingleStepTransfer(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& dispForCalled, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SingleStepTransfer(reqid, sessionid, devicenumber, destUri, dispForCalled, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SingleStepTransfer(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_SingleStepTransfer(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& dispForCalled, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SingleStepTransfer", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SingleStepTransfer_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.destUri = &destUri;
        pargs.dispForCalled = &dispForCalled;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_SingleStepTransfer(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SingleStepTransfer_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SingleStepTransfer"){
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

    CcResultT imsapiProxy::SingleStepConference(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& dispForCalled, const SsConferenceTypeT& type, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SingleStepConference(reqid, sessionid, devicenumber, destUri, dispForCalled, type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SingleStepConference(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_SingleStepConference(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& dispForCalled, const SsConferenceTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SingleStepConference", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SingleStepConference_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.destUri = &destUri;
        pargs.dispForCalled = &dispForCalled;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_SingleStepConference(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SingleStepConference_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SingleStepConference"){
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

    CcResultT imsapiProxy::SwitchListenAndIntrude(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SwitchListenAndIntrude(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SwitchListenAndIntrude(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_SwitchListenAndIntrude(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SwitchListenAndIntrude", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SwitchListenAndIntrude_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_SwitchListenAndIntrude(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SwitchListenAndIntrude_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SwitchListenAndIntrude"){
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

    CcResultT imsapiProxy::SetAssociateData(ReqIdT reqid, SessionIdT sessionid, const std::string& key, const std::string& val, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SetAssociateData(reqid, sessionid, key, val, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SetAssociateData(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_SetAssociateData(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& key, const std::string& val, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SetAssociateData", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SetAssociateData_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.key = &key;
        pargs.val = &val;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_SetAssociateData(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SetAssociateData_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SetAssociateData"){
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

    CcResultT imsapiProxy::GetAssociateData(ReqIdT reqid, SessionIdT sessionid, const std::string& key, std::string& val, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_GetAssociateData(reqid, sessionid, key, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_GetAssociateData(val, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_GetAssociateData(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& key, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "GetAssociateData", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_GetAssociateData_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.key = &key;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_GetAssociateData(std::string& val, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_GetAssociateData_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="GetAssociateData"){
            presult.return_value = &ret_val;
            presult.val = &val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::RouteRequest(ReqIdT reqid, SessionIdT sessionid, const ServiceTypeT& destService, int32_t timeout, int32_t valid_time, const RouteRequestTypeT& reqType, const std::string& reqArgs, int32_t level, const std::string& caller_uri, const std::string& callee_uri, const std::string& buffer, RouteRequestIDT& requestId, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_RouteRequest(reqid, sessionid, destService, timeout, valid_time, reqType, reqArgs, level, caller_uri, callee_uri, buffer, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_RouteRequest(requestId, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_RouteRequest(const ReqIdT& reqid, const SessionIdT& sessionid, const ServiceTypeT& destService, const int32_t& timeout, const int32_t& valid_time, const RouteRequestTypeT& reqType, const std::string& reqArgs, const int32_t& level, const std::string& caller_uri, const std::string& callee_uri, const std::string& buffer, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "RouteRequest", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_RouteRequest_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.destService = &destService;
        pargs.timeout = &timeout;
        pargs.valid_time = &valid_time;
        pargs.reqType = &reqType;
        pargs.reqArgs = &reqArgs;
        pargs.level = &level;
        pargs.caller_uri = &caller_uri;
        pargs.callee_uri = &callee_uri;
        pargs.buffer = &buffer;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_RouteRequest(RouteRequestIDT& requestId, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_RouteRequest_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="RouteRequest"){
            presult.return_value = &ret_val;
            presult.requestId = &requestId;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::CancelRouteRequest(ReqIdT reqid, SessionIdT sessionid, RouteRequestIDT requestId, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_CancelRouteRequest(reqid, sessionid, requestId, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_CancelRouteRequest(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_CancelRouteRequest(const ReqIdT& reqid, const SessionIdT& sessionid, const RouteRequestIDT& requestId, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "CancelRouteRequest", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_CancelRouteRequest_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.requestId = &requestId;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_CancelRouteRequest(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_CancelRouteRequest_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="CancelRouteRequest"){
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

    CcResultT imsapiProxy::RouteRequestRespond(ReqIdT reqid, SessionIdT sessionid, RouteRequestIDT requestId, const RouteEventReasonT& result, const std::string& targetUri, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_RouteRequestRespond(reqid, sessionid, requestId, result, targetUri, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_RouteRequestRespond(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_RouteRequestRespond(const ReqIdT& reqid, const SessionIdT& sessionid, const RouteRequestIDT& requestId, const RouteEventReasonT& result, const std::string& targetUri, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "RouteRequestRespond", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_RouteRequestRespond_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.requestId = &requestId;
        pargs.result = &result;
        pargs.targetUri = &targetUri;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_RouteRequestRespond(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_RouteRequestRespond_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="RouteRequestRespond"){
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

    CcResultT imsapiProxy::CreateSession(ReqIdT reqid, const std::string& callsource, const std::string& channel_id, const std::string& oricalled, SessionIdT& sessionid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_CreateSession(reqid, callsource, channel_id, oricalled, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_CreateSession(sessionid, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_CreateSession(const ReqIdT& reqid, const std::string& callsource, const std::string& channel_id, const std::string& oricalled, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "CreateSession", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_CreateSession_pargs pargs;
        pargs.reqid = &reqid;
        pargs.callsource = &callsource;
        pargs.channel_id = &channel_id;
        pargs.oricalled = &oricalled;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_CreateSession(SessionIdT& sessionid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_CreateSession_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="CreateSession"){
            presult.return_value = &ret_val;
            presult.sessionid = &sessionid;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::TransferAgent(ReqIdT reqid, SessionIdT sessionid, RouteRequestIDT requestId, const TransferTypeT& transType, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_TransferAgent(reqid, sessionid, requestId, transType, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_TransferAgent(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_TransferAgent(const ReqIdT& reqid, const SessionIdT& sessionid, const RouteRequestIDT& requestId, const TransferTypeT& transType, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "TransferAgent", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_TransferAgent_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.requestId = &requestId;
        pargs.transType = &transType;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_TransferAgent(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_TransferAgent_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="TransferAgent"){
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

    CcResultT imsapiProxy::Record(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& filename, int32_t maxTime, const std::string& interruptKeys, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Record(reqid, sessionid, devicenumber, filename, maxTime, interruptKeys, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Record(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_Record(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& filename, const int32_t& maxTime, const std::string& interruptKeys, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Record", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Record_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.filename = &filename;
        pargs.maxTime = &maxTime;
        pargs.interruptKeys = &interruptKeys;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_Record(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Record_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Record"){
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

    CcResultT imsapiProxy::SendDTMF(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& dtmf, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SendDTMF(reqid, sessionid, devicenumber, dtmf, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SendDTMF(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_SendDTMF(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& dtmf, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SendDTMF", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SendDTMF_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.dtmf = &dtmf;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_SendDTMF(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SendDTMF_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SendDTMF"){
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

    CcResultT imsapiProxy::DestroySession(ReqIdT reqid, SessionIdT sessionid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_DestroySession(reqid, sessionid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_DestroySession(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_DestroySession(const ReqIdT& reqid, const SessionIdT& sessionid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "DestroySession", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_DestroySession_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_DestroySession(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_DestroySession_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="DestroySession"){
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

    CcResultT imsapiProxy::QuerySession(ReqIdT reqid, SessionIdT sessionid, std::string& originalAni, std::string& originalDnis, CallIdListT& callidList, std::vector<std::string> & deviceList, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_QuerySession(reqid, sessionid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_QuerySession(originalAni, originalDnis, callidList, deviceList, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_QuerySession(const ReqIdT& reqid, const SessionIdT& sessionid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "QuerySession", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_QuerySession_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_QuerySession(std::string& originalAni, std::string& originalDnis, CallIdListT& callidList, std::vector<std::string> & deviceList, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_QuerySession_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="QuerySession"){
            presult.return_value = &ret_val;
            presult.originalAni = &originalAni;
            presult.originalDnis = &originalDnis;
            presult.callidList = &callidList;
            presult.deviceList = &deviceList;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::QueryCall(ReqIdT reqid, SessionIdT sessionid, const CallIdT& callId, std::string& deviceAni, std::string& deviceDnis, std::string& originalAni, std::string& originalDnis, std::vector<std::string> & deviceList, int32_t& fsid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_QueryCall(reqid, sessionid, callId, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_QueryCall(deviceAni, deviceDnis, originalAni, originalDnis, deviceList, fsid, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_QueryCall(const ReqIdT& reqid, const SessionIdT& sessionid, const CallIdT& callId, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "QueryCall", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_QueryCall_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.callId = &callId;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_QueryCall(std::string& deviceAni, std::string& deviceDnis, std::string& originalAni, std::string& originalDnis, std::vector<std::string> & deviceList, int32_t& fsid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_QueryCall_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="QueryCall"){
            presult.return_value = &ret_val;
            presult.deviceAni = &deviceAni;
            presult.deviceDnis = &deviceDnis;
            presult.originalAni = &originalAni;
            presult.originalDnis = &originalDnis;
            presult.deviceList = &deviceList;
            presult.fsid = &fsid;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::QueryDevice(ReqIdT reqid, const std::string& device, SessionIdT& sessionid, CallIdT& callId, CallStateT& callstate, MediaStateT& mediastate, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_QueryDevice(reqid, device, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_QueryDevice(sessionid, callId, callstate, mediastate, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_QueryDevice(const ReqIdT& reqid, const std::string& device, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "QueryDevice", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_QueryDevice_pargs pargs;
        pargs.reqid = &reqid;
        pargs.device = &device;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_QueryDevice(SessionIdT& sessionid, CallIdT& callId, CallStateT& callstate, MediaStateT& mediastate, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_QueryDevice_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="QueryDevice"){
            presult.return_value = &ret_val;
            presult.sessionid = &sessionid;
            presult.callId = &callId;
            presult.callstate = &callstate;
            presult.mediastate = &mediastate;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::QuerySysInfo(ReqIdT reqid, SysInfoT& sysinfo, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_QuerySysInfo(reqid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_QuerySysInfo(sysinfo, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_QuerySysInfo(const ReqIdT& reqid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "QuerySysInfo", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_QuerySysInfo_pargs pargs;
        pargs.reqid = &reqid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_QuerySysInfo(SysInfoT& sysinfo, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_QuerySysInfo_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="QuerySysInfo"){
            presult.return_value = &ret_val;
            presult.sysinfo = &sysinfo;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT imsapiProxy::ReloadConfig(const ConfigTypeT& type, bool /*last*/) {
        CcResultT return_value;
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

    void imsapiProxy::send_ReloadConfig(const ConfigTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "ReloadConfig", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_ReloadConfig_pargs pargs;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_ReloadConfig(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_ReloadConfig_presult presult;
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

    CcResultT imsapiProxy::HeartBeat(ReqIdT reqid, const std::string& info, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_HeartBeat(reqid, info, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_HeartBeat(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void imsapiProxy::send_HeartBeat(const ReqIdT& reqid, const std::string& info, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "HeartBeat", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_HeartBeat_pargs pargs;
        pargs.reqid = &reqid;
        pargs.info = &info;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT imsapiProxy::recv_HeartBeat(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_HeartBeat_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="HeartBeat"){
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

    SSLimsapiProxy::SSLimsapiProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.ims.imsapi";
    }

    SSLimsapiProxy::SSLimsapiProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.ims.imsapi";
    }

    SSLimsapiProxy::SSLimsapiProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::SSLBaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.ims.imsapi";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    CcResultT SSLimsapiProxy::Register(const ServiceTypeT& type, ReqIdT& reqid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Register(type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Register(reqid, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Register(const ServiceTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Register", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Register_pargs pargs;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Register(ReqIdT& reqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Register_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Register"){
            presult.return_value = &ret_val;
            presult.reqid = &reqid;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::UnRegister(ReqIdT reqid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_UnRegister(reqid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_UnRegister(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_UnRegister(const ReqIdT& reqid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "UnRegister", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_UnRegister_pargs pargs;
        pargs.reqid = &reqid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_UnRegister(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_UnRegister_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="UnRegister"){
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

    CcResultT SSLimsapiProxy::Assign(ReqIdT reqid, const std::string& devicenumber, const DnTypeT& type, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Assign(reqid, devicenumber, type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Assign(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Assign(const ReqIdT& reqid, const std::string& devicenumber, const DnTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Assign", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Assign_pargs pargs;
        pargs.reqid = &reqid;
        pargs.devicenumber = &devicenumber;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Assign(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Assign_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Assign"){
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

    CcResultT SSLimsapiProxy::DeAssign(ReqIdT reqid, const std::string& devicenumber, const DnTypeT& type, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_DeAssign(reqid, devicenumber, type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_DeAssign(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_DeAssign(const ReqIdT& reqid, const std::string& devicenumber, const DnTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "DeAssign", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_DeAssign_pargs pargs;
        pargs.reqid = &reqid;
        pargs.devicenumber = &devicenumber;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_DeAssign(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_DeAssign_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="DeAssign"){
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

    CcResultT SSLimsapiProxy::OutboundCall(ReqIdT reqid, const std::string& devicenumber, const std::string& destUri, const std::string& setSrcUri, const std::string& setDestUri, int32_t timeout, const CallModeT& callmode, SessionIdT& sessionid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_OutboundCall(reqid, devicenumber, destUri, setSrcUri, setDestUri, timeout, callmode, sessionid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_OutboundCall(sessionid, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_OutboundCall(const ReqIdT& reqid, const std::string& devicenumber, const std::string& destUri, const std::string& setSrcUri, const std::string& setDestUri, const int32_t& timeout, const CallModeT& callmode, const SessionIdT& sessionid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "OutboundCall", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_OutboundCall_pargs pargs;
        pargs.reqid = &reqid;
        pargs.devicenumber = &devicenumber;
        pargs.destUri = &destUri;
        pargs.setSrcUri = &setSrcUri;
        pargs.setDestUri = &setDestUri;
        pargs.timeout = &timeout;
        pargs.callmode = &callmode;
        pargs.sessionid = &sessionid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_OutboundCall(SessionIdT& sessionid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_OutboundCall_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="OutboundCall"){
            presult.return_value = &ret_val;
            presult.sessionid = &sessionid;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::Answer(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Answer(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Answer(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Answer(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Answer", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Answer_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Answer(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Answer_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Answer"){
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

    CcResultT SSLimsapiProxy::Release(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Release(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Release(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Release(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Release", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Release_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Release(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Release_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Release"){
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

    CcResultT SSLimsapiProxy::Hold(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Hold(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Hold(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Hold(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Hold", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Hold_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Hold(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Hold_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Hold"){
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

    CcResultT SSLimsapiProxy::Retrieve(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Retrieve(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Retrieve(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Retrieve(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Retrieve", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Retrieve_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Retrieve(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Retrieve_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Retrieve"){
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

    CcResultT SSLimsapiProxy::Consult(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& setDestUri, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Consult(reqid, sessionid, devicenumber, destUri, setDestUri, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Consult(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Consult(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& setDestUri, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Consult", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Consult_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.destUri = &destUri;
        pargs.setDestUri = &setDestUri;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Consult(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Consult_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Consult"){
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

    CcResultT SSLimsapiProxy::Reconnect(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Reconnect(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Reconnect(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Reconnect(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Reconnect", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Reconnect_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Reconnect(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Reconnect_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Reconnect"){
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

    CcResultT SSLimsapiProxy::Transfer(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Transfer(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Transfer(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Transfer(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Transfer", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Transfer_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Transfer(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Transfer_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Transfer"){
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

    CcResultT SSLimsapiProxy::Conference(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Conference(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Conference(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Conference(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Conference", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Conference_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Conference(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Conference_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Conference"){
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

    CcResultT SSLimsapiProxy::SingleStepTransfer(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& dispForCalled, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SingleStepTransfer(reqid, sessionid, devicenumber, destUri, dispForCalled, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SingleStepTransfer(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_SingleStepTransfer(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& dispForCalled, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SingleStepTransfer", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SingleStepTransfer_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.destUri = &destUri;
        pargs.dispForCalled = &dispForCalled;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_SingleStepTransfer(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SingleStepTransfer_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SingleStepTransfer"){
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

    CcResultT SSLimsapiProxy::SingleStepConference(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& dispForCalled, const SsConferenceTypeT& type, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SingleStepConference(reqid, sessionid, devicenumber, destUri, dispForCalled, type, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SingleStepConference(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_SingleStepConference(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& destUri, const std::string& dispForCalled, const SsConferenceTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SingleStepConference", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SingleStepConference_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.destUri = &destUri;
        pargs.dispForCalled = &dispForCalled;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_SingleStepConference(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SingleStepConference_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SingleStepConference"){
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

    CcResultT SSLimsapiProxy::SwitchListenAndIntrude(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SwitchListenAndIntrude(reqid, sessionid, devicenumber, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SwitchListenAndIntrude(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_SwitchListenAndIntrude(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SwitchListenAndIntrude", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SwitchListenAndIntrude_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_SwitchListenAndIntrude(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SwitchListenAndIntrude_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SwitchListenAndIntrude"){
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

    CcResultT SSLimsapiProxy::SetAssociateData(ReqIdT reqid, SessionIdT sessionid, const std::string& key, const std::string& val, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SetAssociateData(reqid, sessionid, key, val, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SetAssociateData(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_SetAssociateData(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& key, const std::string& val, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SetAssociateData", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SetAssociateData_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.key = &key;
        pargs.val = &val;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_SetAssociateData(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SetAssociateData_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SetAssociateData"){
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

    CcResultT SSLimsapiProxy::GetAssociateData(ReqIdT reqid, SessionIdT sessionid, const std::string& key, std::string& val, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_GetAssociateData(reqid, sessionid, key, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_GetAssociateData(val, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_GetAssociateData(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& key, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "GetAssociateData", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_GetAssociateData_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.key = &key;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_GetAssociateData(std::string& val, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_GetAssociateData_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="GetAssociateData"){
            presult.return_value = &ret_val;
            presult.val = &val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::RouteRequest(ReqIdT reqid, SessionIdT sessionid, const ServiceTypeT& destService, int32_t timeout, int32_t valid_time, const RouteRequestTypeT& reqType, const std::string& reqArgs, int32_t level, const std::string& caller_uri, const std::string& callee_uri, const std::string& buffer, RouteRequestIDT& requestId, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_RouteRequest(reqid, sessionid, destService, timeout, valid_time, reqType, reqArgs, level, caller_uri, callee_uri, buffer, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_RouteRequest(requestId, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_RouteRequest(const ReqIdT& reqid, const SessionIdT& sessionid, const ServiceTypeT& destService, const int32_t& timeout, const int32_t& valid_time, const RouteRequestTypeT& reqType, const std::string& reqArgs, const int32_t& level, const std::string& caller_uri, const std::string& callee_uri, const std::string& buffer, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "RouteRequest", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_RouteRequest_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.destService = &destService;
        pargs.timeout = &timeout;
        pargs.valid_time = &valid_time;
        pargs.reqType = &reqType;
        pargs.reqArgs = &reqArgs;
        pargs.level = &level;
        pargs.caller_uri = &caller_uri;
        pargs.callee_uri = &callee_uri;
        pargs.buffer = &buffer;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_RouteRequest(RouteRequestIDT& requestId, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_RouteRequest_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="RouteRequest"){
            presult.return_value = &ret_val;
            presult.requestId = &requestId;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::CancelRouteRequest(ReqIdT reqid, SessionIdT sessionid, RouteRequestIDT requestId, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_CancelRouteRequest(reqid, sessionid, requestId, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_CancelRouteRequest(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_CancelRouteRequest(const ReqIdT& reqid, const SessionIdT& sessionid, const RouteRequestIDT& requestId, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "CancelRouteRequest", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_CancelRouteRequest_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.requestId = &requestId;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_CancelRouteRequest(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_CancelRouteRequest_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="CancelRouteRequest"){
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

    CcResultT SSLimsapiProxy::RouteRequestRespond(ReqIdT reqid, SessionIdT sessionid, RouteRequestIDT requestId, const RouteEventReasonT& result, const std::string& targetUri, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_RouteRequestRespond(reqid, sessionid, requestId, result, targetUri, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_RouteRequestRespond(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_RouteRequestRespond(const ReqIdT& reqid, const SessionIdT& sessionid, const RouteRequestIDT& requestId, const RouteEventReasonT& result, const std::string& targetUri, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "RouteRequestRespond", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_RouteRequestRespond_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.requestId = &requestId;
        pargs.result = &result;
        pargs.targetUri = &targetUri;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_RouteRequestRespond(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_RouteRequestRespond_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="RouteRequestRespond"){
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

    CcResultT SSLimsapiProxy::CreateSession(ReqIdT reqid, const std::string& callsource, const std::string& channel_id, const std::string& oricalled, SessionIdT& sessionid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_CreateSession(reqid, callsource, channel_id, oricalled, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_CreateSession(sessionid, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_CreateSession(const ReqIdT& reqid, const std::string& callsource, const std::string& channel_id, const std::string& oricalled, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "CreateSession", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_CreateSession_pargs pargs;
        pargs.reqid = &reqid;
        pargs.callsource = &callsource;
        pargs.channel_id = &channel_id;
        pargs.oricalled = &oricalled;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_CreateSession(SessionIdT& sessionid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_CreateSession_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="CreateSession"){
            presult.return_value = &ret_val;
            presult.sessionid = &sessionid;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::TransferAgent(ReqIdT reqid, SessionIdT sessionid, RouteRequestIDT requestId, const TransferTypeT& transType, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_TransferAgent(reqid, sessionid, requestId, transType, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_TransferAgent(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_TransferAgent(const ReqIdT& reqid, const SessionIdT& sessionid, const RouteRequestIDT& requestId, const TransferTypeT& transType, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "TransferAgent", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_TransferAgent_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.requestId = &requestId;
        pargs.transType = &transType;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_TransferAgent(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_TransferAgent_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="TransferAgent"){
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

    CcResultT SSLimsapiProxy::Record(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& filename, int32_t maxTime, const std::string& interruptKeys, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_Record(reqid, sessionid, devicenumber, filename, maxTime, interruptKeys, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_Record(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_Record(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& filename, const int32_t& maxTime, const std::string& interruptKeys, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "Record", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_Record_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.filename = &filename;
        pargs.maxTime = &maxTime;
        pargs.interruptKeys = &interruptKeys;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_Record(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_Record_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="Record"){
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

    CcResultT SSLimsapiProxy::SendDTMF(ReqIdT reqid, SessionIdT sessionid, const std::string& devicenumber, const std::string& dtmf, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_SendDTMF(reqid, sessionid, devicenumber, dtmf, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_SendDTMF(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_SendDTMF(const ReqIdT& reqid, const SessionIdT& sessionid, const std::string& devicenumber, const std::string& dtmf, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "SendDTMF", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_SendDTMF_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.devicenumber = &devicenumber;
        pargs.dtmf = &dtmf;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_SendDTMF(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_SendDTMF_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="SendDTMF"){
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

    CcResultT SSLimsapiProxy::DestroySession(ReqIdT reqid, SessionIdT sessionid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_DestroySession(reqid, sessionid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_DestroySession(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_DestroySession(const ReqIdT& reqid, const SessionIdT& sessionid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "DestroySession", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_DestroySession_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_DestroySession(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_DestroySession_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="DestroySession"){
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

    CcResultT SSLimsapiProxy::QuerySession(ReqIdT reqid, SessionIdT sessionid, std::string& originalAni, std::string& originalDnis, CallIdListT& callidList, std::vector<std::string> & deviceList, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_QuerySession(reqid, sessionid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_QuerySession(originalAni, originalDnis, callidList, deviceList, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_QuerySession(const ReqIdT& reqid, const SessionIdT& sessionid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "QuerySession", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_QuerySession_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_QuerySession(std::string& originalAni, std::string& originalDnis, CallIdListT& callidList, std::vector<std::string> & deviceList, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_QuerySession_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="QuerySession"){
            presult.return_value = &ret_val;
            presult.originalAni = &originalAni;
            presult.originalDnis = &originalDnis;
            presult.callidList = &callidList;
            presult.deviceList = &deviceList;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::QueryCall(ReqIdT reqid, SessionIdT sessionid, const CallIdT& callId, std::string& deviceAni, std::string& deviceDnis, std::string& originalAni, std::string& originalDnis, std::vector<std::string> & deviceList, int32_t& fsid, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_QueryCall(reqid, sessionid, callId, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_QueryCall(deviceAni, deviceDnis, originalAni, originalDnis, deviceList, fsid, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_QueryCall(const ReqIdT& reqid, const SessionIdT& sessionid, const CallIdT& callId, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "QueryCall", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_QueryCall_pargs pargs;
        pargs.reqid = &reqid;
        pargs.sessionid = &sessionid;
        pargs.callId = &callId;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_QueryCall(std::string& deviceAni, std::string& deviceDnis, std::string& originalAni, std::string& originalDnis, std::vector<std::string> & deviceList, int32_t& fsid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_QueryCall_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="QueryCall"){
            presult.return_value = &ret_val;
            presult.deviceAni = &deviceAni;
            presult.deviceDnis = &deviceDnis;
            presult.originalAni = &originalAni;
            presult.originalDnis = &originalDnis;
            presult.deviceList = &deviceList;
            presult.fsid = &fsid;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::QueryDevice(ReqIdT reqid, const std::string& device, SessionIdT& sessionid, CallIdT& callId, CallStateT& callstate, MediaStateT& mediastate, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_QueryDevice(reqid, device, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_QueryDevice(sessionid, callId, callstate, mediastate, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_QueryDevice(const ReqIdT& reqid, const std::string& device, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "QueryDevice", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_QueryDevice_pargs pargs;
        pargs.reqid = &reqid;
        pargs.device = &device;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_QueryDevice(SessionIdT& sessionid, CallIdT& callId, CallStateT& callstate, MediaStateT& mediastate, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_QueryDevice_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="QueryDevice"){
            presult.return_value = &ret_val;
            presult.sessionid = &sessionid;
            presult.callId = &callId;
            presult.callstate = &callstate;
            presult.mediastate = &mediastate;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::QuerySysInfo(ReqIdT reqid, SysInfoT& sysinfo, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_QuerySysInfo(reqid, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_QuerySysInfo(sysinfo, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_QuerySysInfo(const ReqIdT& reqid, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "QuerySysInfo", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_QuerySysInfo_pargs pargs;
        pargs.reqid = &reqid;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_QuerySysInfo(SysInfoT& sysinfo, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_QuerySysInfo_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="QuerySysInfo"){
            presult.return_value = &ret_val;
            presult.sysinfo = &sysinfo;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    CcResultT SSLimsapiProxy::ReloadConfig(const ConfigTypeT& type, bool /*last*/) {
        CcResultT return_value;
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

    void SSLimsapiProxy::send_ReloadConfig(const ConfigTypeT& type, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "ReloadConfig", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_ReloadConfig_pargs pargs;
        pargs.type = &type;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_ReloadConfig(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_ReloadConfig_presult presult;
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

    CcResultT SSLimsapiProxy::HeartBeat(ReqIdT reqid, const std::string& info, bool /*last*/) {
        CcResultT return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_HeartBeat(reqid, info, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_HeartBeat(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLimsapiProxy::send_HeartBeat(const ReqIdT& reqid, const std::string& info, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "HeartBeat", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        imsapi_HeartBeat_pargs pargs;
        pargs.reqid = &reqid;
        pargs.info = &info;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    CcResultT SSLimsapiProxy::recv_HeartBeat(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        CcResultT ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        imsapi_HeartBeat_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="HeartBeat"){
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

    imsapiProcessor::imsapiProcessor(bgcc::SharedPointer<imsapi> intf) :
        bgcc::BaseProcessor(), __intf(intf) {
        __fun_map["Register"] = &imsapiProcessor::do_Register;
        __fun_map["UnRegister"] = &imsapiProcessor::do_UnRegister;
        __fun_map["Assign"] = &imsapiProcessor::do_Assign;
        __fun_map["DeAssign"] = &imsapiProcessor::do_DeAssign;
        __fun_map["OutboundCall"] = &imsapiProcessor::do_OutboundCall;
        __fun_map["Answer"] = &imsapiProcessor::do_Answer;
        __fun_map["Release"] = &imsapiProcessor::do_Release;
        __fun_map["Hold"] = &imsapiProcessor::do_Hold;
        __fun_map["Retrieve"] = &imsapiProcessor::do_Retrieve;
        __fun_map["Consult"] = &imsapiProcessor::do_Consult;
        __fun_map["Reconnect"] = &imsapiProcessor::do_Reconnect;
        __fun_map["Transfer"] = &imsapiProcessor::do_Transfer;
        __fun_map["Conference"] = &imsapiProcessor::do_Conference;
        __fun_map["SingleStepTransfer"] = &imsapiProcessor::do_SingleStepTransfer;
        __fun_map["SingleStepConference"] = &imsapiProcessor::do_SingleStepConference;
        __fun_map["SwitchListenAndIntrude"] = &imsapiProcessor::do_SwitchListenAndIntrude;
        __fun_map["SetAssociateData"] = &imsapiProcessor::do_SetAssociateData;
        __fun_map["GetAssociateData"] = &imsapiProcessor::do_GetAssociateData;
        __fun_map["RouteRequest"] = &imsapiProcessor::do_RouteRequest;
        __fun_map["CancelRouteRequest"] = &imsapiProcessor::do_CancelRouteRequest;
        __fun_map["RouteRequestRespond"] = &imsapiProcessor::do_RouteRequestRespond;
        __fun_map["CreateSession"] = &imsapiProcessor::do_CreateSession;
        __fun_map["TransferAgent"] = &imsapiProcessor::do_TransferAgent;
        __fun_map["Record"] = &imsapiProcessor::do_Record;
        __fun_map["SendDTMF"] = &imsapiProcessor::do_SendDTMF;
        __fun_map["DestroySession"] = &imsapiProcessor::do_DestroySession;
        __fun_map["QuerySession"] = &imsapiProcessor::do_QuerySession;
        __fun_map["QueryCall"] = &imsapiProcessor::do_QueryCall;
        __fun_map["QueryDevice"] = &imsapiProcessor::do_QueryDevice;
        __fun_map["QuerySysInfo"] = &imsapiProcessor::do_QuerySysInfo;
        __fun_map["ReloadConfig"] = &imsapiProcessor::do_ReloadConfig;
        __fun_map["HeartBeat"] = &imsapiProcessor::do_HeartBeat;
    }

    int32_t imsapiProcessor::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
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

    std::string imsapiProcessor::get_name() const {
        return "global.ims.imsapi";
    }

    int32_t imsapiProcessor::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, 
        const std::string& fname, int32_t seqid) {
        std::map<std::string, do_function_ptr>::iterator it;
        it = __fun_map.find(fname);
        if (it == __fun_map.end()) {
            return bgcc::BaseProcessor::do_function__(request, request_len, proto, fname, seqid);
        }

        return (this->*(it->second))(request, request_len, proto, seqid);
    }

    int32_t imsapiProcessor::do_Register(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Register_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Register_result result;
        result.return_value = __intf->Register(args.type, result.reqid, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Register", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_UnRegister(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_UnRegister_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_UnRegister_result result;
        result.return_value = __intf->UnRegister(args.reqid, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "UnRegister", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Assign(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Assign_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Assign_result result;
        result.return_value = __intf->Assign(args.reqid, args.devicenumber, args.type, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Assign", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_DeAssign(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_DeAssign_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_DeAssign_result result;
        result.return_value = __intf->DeAssign(args.reqid, args.devicenumber, args.type, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "DeAssign", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_OutboundCall(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_OutboundCall_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_OutboundCall_result result;
        result.return_value = __intf->OutboundCall(args.reqid, args.devicenumber, args.destUri, args.setSrcUri, args.setDestUri, args.timeout, args.callmode, args.sessionid, map);
        result.sessionid = args.sessionid;
        ret = proto->writeMessageBegin("global.ims.imsapi", "OutboundCall", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Answer(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Answer_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Answer_result result;
        result.return_value = __intf->Answer(args.reqid, args.sessionid, args.devicenumber, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Answer", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Release(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Release_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Release_result result;
        result.return_value = __intf->Release(args.reqid, args.sessionid, args.devicenumber, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Release", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Hold(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Hold_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Hold_result result;
        result.return_value = __intf->Hold(args.reqid, args.sessionid, args.devicenumber, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Hold", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Retrieve(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Retrieve_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Retrieve_result result;
        result.return_value = __intf->Retrieve(args.reqid, args.sessionid, args.devicenumber, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Retrieve", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Consult(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Consult_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Consult_result result;
        result.return_value = __intf->Consult(args.reqid, args.sessionid, args.devicenumber, args.destUri, args.setDestUri, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Consult", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Reconnect(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Reconnect_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Reconnect_result result;
        result.return_value = __intf->Reconnect(args.reqid, args.sessionid, args.devicenumber, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Reconnect", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Transfer(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Transfer_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Transfer_result result;
        result.return_value = __intf->Transfer(args.reqid, args.sessionid, args.devicenumber, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Transfer", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Conference(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Conference_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Conference_result result;
        result.return_value = __intf->Conference(args.reqid, args.sessionid, args.devicenumber, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Conference", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_SingleStepTransfer(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_SingleStepTransfer_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_SingleStepTransfer_result result;
        result.return_value = __intf->SingleStepTransfer(args.reqid, args.sessionid, args.devicenumber, args.destUri, args.dispForCalled, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "SingleStepTransfer", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_SingleStepConference(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_SingleStepConference_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_SingleStepConference_result result;
        result.return_value = __intf->SingleStepConference(args.reqid, args.sessionid, args.devicenumber, args.destUri, args.dispForCalled, args.type, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "SingleStepConference", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_SwitchListenAndIntrude(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_SwitchListenAndIntrude_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_SwitchListenAndIntrude_result result;
        result.return_value = __intf->SwitchListenAndIntrude(args.reqid, args.sessionid, args.devicenumber, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "SwitchListenAndIntrude", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_SetAssociateData(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_SetAssociateData_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_SetAssociateData_result result;
        result.return_value = __intf->SetAssociateData(args.reqid, args.sessionid, args.key, args.val, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "SetAssociateData", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_GetAssociateData(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_GetAssociateData_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_GetAssociateData_result result;
        result.return_value = __intf->GetAssociateData(args.reqid, args.sessionid, args.key, result.val, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "GetAssociateData", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_RouteRequest(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_RouteRequest_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_RouteRequest_result result;
        result.return_value = __intf->RouteRequest(args.reqid, args.sessionid, args.destService, args.timeout, args.valid_time, args.reqType, args.reqArgs, args.level, args.caller_uri, args.callee_uri, args.buffer, result.requestId, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "RouteRequest", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_CancelRouteRequest(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_CancelRouteRequest_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_CancelRouteRequest_result result;
        result.return_value = __intf->CancelRouteRequest(args.reqid, args.sessionid, args.requestId, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "CancelRouteRequest", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_RouteRequestRespond(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_RouteRequestRespond_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_RouteRequestRespond_result result;
        result.return_value = __intf->RouteRequestRespond(args.reqid, args.sessionid, args.requestId, args.result, args.targetUri, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "RouteRequestRespond", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_CreateSession(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_CreateSession_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_CreateSession_result result;
        result.return_value = __intf->CreateSession(args.reqid, args.callsource, args.channel_id, args.oricalled, result.sessionid, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "CreateSession", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_TransferAgent(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_TransferAgent_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_TransferAgent_result result;
        result.return_value = __intf->TransferAgent(args.reqid, args.sessionid, args.requestId, args.transType, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "TransferAgent", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_Record(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_Record_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_Record_result result;
        result.return_value = __intf->Record(args.reqid, args.sessionid, args.devicenumber, args.filename, args.maxTime, args.interruptKeys, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "Record", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_SendDTMF(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_SendDTMF_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_SendDTMF_result result;
        result.return_value = __intf->SendDTMF(args.reqid, args.sessionid, args.devicenumber, args.dtmf, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "SendDTMF", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_DestroySession(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_DestroySession_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_DestroySession_result result;
        result.return_value = __intf->DestroySession(args.reqid, args.sessionid, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "DestroySession", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_QuerySession(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_QuerySession_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_QuerySession_result result;
        result.return_value = __intf->QuerySession(args.reqid, args.sessionid, result.originalAni, result.originalDnis, result.callidList, result.deviceList, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "QuerySession", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_QueryCall(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_QueryCall_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_QueryCall_result result;
        result.return_value = __intf->QueryCall(args.reqid, args.sessionid, args.callId, result.deviceAni, result.deviceDnis, result.originalAni, result.originalDnis, result.deviceList, result.fsid, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "QueryCall", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_QueryDevice(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_QueryDevice_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_QueryDevice_result result;
        result.return_value = __intf->QueryDevice(args.reqid, args.device, result.sessionid, result.callId, result.callstate, result.mediastate, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "QueryDevice", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_QuerySysInfo(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_QuerySysInfo_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_QuerySysInfo_result result;
        result.return_value = __intf->QuerySysInfo(args.reqid, result.sysinfo, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "QuerySysInfo", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_ReloadConfig(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_ReloadConfig_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_ReloadConfig_result result;
        result.return_value = __intf->ReloadConfig(args.type, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "ReloadConfig", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t imsapiProcessor::do_HeartBeat(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
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

        imsapi_HeartBeat_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        imsapi_HeartBeat_result result;
        result.return_value = __intf->HeartBeat(args.reqid, args.info, map);
        ret = proto->writeMessageBegin("global.ims.imsapi", "HeartBeat", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

}


