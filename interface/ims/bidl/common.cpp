#include "common.h"

namespace ims {

    const struct CcResultT::desc_t CcResultT::descs[] = {
        {CcResultT::ResSuccess, "CcResultT::ResSuccess"},
        {CcResultT::ResFailed, "CcResultT::ResFailed"},
        {CcResultT::ResInvalidParam, "CcResultT::ResInvalidParam"},
        {CcResultT::ResNotSupport, "CcResultT::ResNotSupport"},
        {CcResultT::ResNoEnoughResource, "CcResultT::ResNoEnoughResource"},
        {CcResultT::ResSessionNotFound, "CcResultT::ResSessionNotFound"},
        {CcResultT::ResInvalidDn, "CcResultT::ResInvalidDn"},
        {CcResultT::ResInvalidState, "CcResultT::ResInvalidState"},
        {CcResultT::ResInvalidFile, "CcResultT::ResInvalidFile"},
        {CcResultT::ResInvalidReqId, "CcResultT::ResInvalidReqId"},
        {CcResultT::ResAccessDenied, "CcResultT::ResAccessDenied"},
        {CcResultT::ResRouteRequestRepeated, "CcResultT::ResRouteRequestRepeated"},
        {CcResultT::ResCallSourceNotFound, "CcResultT::ResCallSourceNotFound"},
        {CcResultT::ResNoAgentAssigned, "CcResultT::ResNoAgentAssigned"},
        {0, NULL}
    };

    CcResultT::CcResultT() : _value(ResSuccess) {
    }

    CcResultT::CcResultT(int32_t value) : _value(value) {
    }

    int32_t CcResultT::get_value() const {
        return _value;
    }

    std::string CcResultT::get_desc() const {
        const struct desc_t* ptr = CcResultT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool CcResultT::operator==(int32_t value) const {
        return _value == value;
    }

    bool CcResultT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool CcResultT::operator< (int32_t value) const {
        return _value < value;
    }

    bool CcResultT::operator==(const CcResultT& rhs) const {
        return _value == rhs.get_value();
    }

    bool CcResultT::operator!=(const CcResultT& rhs) const {
        return _value != rhs.get_value();
    }

    bool CcResultT::operator< (const CcResultT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const CcResultT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const CcResultT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const CcResultT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const CcResultT& e) {
        o << e.get_value();
        return o;
    }


    const struct CallModeT::desc_t CallModeT::descs[] = {
        {CallModeT::Normal, "CallModeT::Normal"},
        {CallModeT::Persist, "CallModeT::Persist"},
        {0, NULL}
    };

    CallModeT::CallModeT() : _value(Normal) {
    }

    CallModeT::CallModeT(int32_t value) : _value(value) {
    }

    int32_t CallModeT::get_value() const {
        return _value;
    }

    std::string CallModeT::get_desc() const {
        const struct desc_t* ptr = CallModeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool CallModeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool CallModeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool CallModeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool CallModeT::operator==(const CallModeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool CallModeT::operator!=(const CallModeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool CallModeT::operator< (const CallModeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const CallModeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const CallModeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const CallModeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const CallModeT& e) {
        o << e.get_value();
        return o;
    }


    const struct SsConferenceTypeT::desc_t SsConferenceTypeT::descs[] = {
        {SsConferenceTypeT::Monitor, "SsConferenceTypeT::Monitor"},
        {SsConferenceTypeT::Intrude, "SsConferenceTypeT::Intrude"},
        {SsConferenceTypeT::MonitorIntrude, "SsConferenceTypeT::MonitorIntrude"},
        {0, NULL}
    };

    SsConferenceTypeT::SsConferenceTypeT() : _value(Monitor) {
    }

    SsConferenceTypeT::SsConferenceTypeT(int32_t value) : _value(value) {
    }

    int32_t SsConferenceTypeT::get_value() const {
        return _value;
    }

    std::string SsConferenceTypeT::get_desc() const {
        const struct desc_t* ptr = SsConferenceTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool SsConferenceTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool SsConferenceTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool SsConferenceTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool SsConferenceTypeT::operator==(const SsConferenceTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool SsConferenceTypeT::operator!=(const SsConferenceTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool SsConferenceTypeT::operator< (const SsConferenceTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const SsConferenceTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const SsConferenceTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const SsConferenceTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const SsConferenceTypeT& e) {
        o << e.get_value();
        return o;
    }


    const struct DnTypeT::desc_t DnTypeT::descs[] = {
        {DnTypeT::AgentDn, "DnTypeT::AgentDn"},
        {DnTypeT::IvrANI, "DnTypeT::IvrANI"},
        {0, NULL}
    };

    DnTypeT::DnTypeT() : _value(AgentDn) {
    }

    DnTypeT::DnTypeT(int32_t value) : _value(value) {
    }

    int32_t DnTypeT::get_value() const {
        return _value;
    }

    std::string DnTypeT::get_desc() const {
        const struct desc_t* ptr = DnTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool DnTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool DnTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool DnTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool DnTypeT::operator==(const DnTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool DnTypeT::operator!=(const DnTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool DnTypeT::operator< (const DnTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const DnTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const DnTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const DnTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const DnTypeT& e) {
        o << e.get_value();
        return o;
    }

    SysInfoT::SysInfoT() {
    }

    SysInfoT::~SysInfoT() {
    }

    bool SysInfoT::operator==(const SysInfoT& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (sessionCount != rhs.sessionCount) {
            return false;
        }
        if (sessionPerSec != rhs.sessionPerSec) {
            return false;
        }
        if (sessionSinceStartup != rhs.sessionSinceStartup) {
            return false;
        }
        return true;
    }

    bool SysInfoT::operator!=(const SysInfoT& rhs) const {
        return !(*this == rhs);
    }

    bool SysInfoT::operator< (const SysInfoT& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (sessionCount < rhs.sessionCount) {
            return true;
        }
        else if (rhs.sessionCount < sessionCount) {
            return false;
        }

        if (sessionPerSec < rhs.sessionPerSec) {
            return true;
        }
        else if (rhs.sessionPerSec < sessionPerSec) {
            return false;
        }

        if (sessionSinceStartup < rhs.sessionSinceStartup) {
            return true;
        }
        else if (rhs.sessionSinceStartup < sessionSinceStartup) {
            return false;
        }

        return false;
    }

    int32_t SysInfoT::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto){
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionCount);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readFloat(OFFSET_PTR(request, nread), request_len - nread, sessionPerSec);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionSinceStartup);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t SysInfoT::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("SysInfoT");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionCount", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionCount);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionPerSec", bgcc::IDFLOAT, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat(sessionPerSec);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionSinceStartup", bgcc::IDINT64, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionSinceStartup);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct ServiceTypeT::desc_t ServiceTypeT::descs[] = {
        {ServiceTypeT::ServiceNone, "ServiceTypeT::ServiceNone"},
        {ServiceTypeT::ServiceIVR, "ServiceTypeT::ServiceIVR"},
        {ServiceTypeT::ServiceACD, "ServiceTypeT::ServiceACD"},
        {ServiceTypeT::ServiceDS, "ServiceTypeT::ServiceDS"},
        {0, NULL}
    };

    ServiceTypeT::ServiceTypeT() : _value(ServiceNone) {
    }

    ServiceTypeT::ServiceTypeT(int32_t value) : _value(value) {
    }

    int32_t ServiceTypeT::get_value() const {
        return _value;
    }

    std::string ServiceTypeT::get_desc() const {
        const struct desc_t* ptr = ServiceTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool ServiceTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool ServiceTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool ServiceTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool ServiceTypeT::operator==(const ServiceTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool ServiceTypeT::operator!=(const ServiceTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool ServiceTypeT::operator< (const ServiceTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const ServiceTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const ServiceTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const ServiceTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const ServiceTypeT& e) {
        o << e.get_value();
        return o;
    }


    const struct CallEventTypeT::desc_t CallEventTypeT::descs[] = {
        {CallEventTypeT::SG_UnKnownEvent, "CallEventTypeT::SG_UnKnownEvent"},
        {CallEventTypeT::SG_InboundCall_InternalCall, "CallEventTypeT::SG_InboundCall_InternalCall"},
        {CallEventTypeT::SG_DestSeized_InternalCall, "CallEventTypeT::SG_DestSeized_InternalCall"},
        {CallEventTypeT::SG_ThisPartyAnswered_InternalCall, "CallEventTypeT::SG_ThisPartyAnswered_InternalCall"},
        {CallEventTypeT::SG_OtherPartyAnswered_InternalCall, "CallEventTypeT::SG_OtherPartyAnswered_InternalCall"},
        {CallEventTypeT::SG_ThisPartyDisconnected_InternalCall, "CallEventTypeT::SG_ThisPartyDisconnected_InternalCall"},
        {CallEventTypeT::SG_OtherPartyDisconnected_InternalCall, "CallEventTypeT::SG_OtherPartyDisconnected_InternalCall"},
        {CallEventTypeT::SG_InboundCall_NormalCall, "CallEventTypeT::SG_InboundCall_NormalCall"},
        {CallEventTypeT::SG_DestSeized_NormalCall, "CallEventTypeT::SG_DestSeized_NormalCall"},
        {CallEventTypeT::SG_ThisPartyAnswered_NormalCall, "CallEventTypeT::SG_ThisPartyAnswered_NormalCall"},
        {CallEventTypeT::SG_OtherPartyAnswered_NormalCall, "CallEventTypeT::SG_OtherPartyAnswered_NormalCall"},
        {CallEventTypeT::SG_ThisPartyDisconnected_NormalCall, "CallEventTypeT::SG_ThisPartyDisconnected_NormalCall"},
        {CallEventTypeT::SG_OtherPartyDisconnected_NormalCall, "CallEventTypeT::SG_OtherPartyDisconnected_NormalCall"},
        {CallEventTypeT::SG_ThisPartySuspended_NormalCall, "CallEventTypeT::SG_ThisPartySuspended_NormalCall"},
        {CallEventTypeT::SG_ThisPartyRetrieved_NormalCall, "CallEventTypeT::SG_ThisPartyRetrieved_NormalCall"},
        {CallEventTypeT::SG_ThisPartyTransferred_NormalCall, "CallEventTypeT::SG_ThisPartyTransferred_NormalCall"},
        {CallEventTypeT::SG_DestSeized_ConsultCall, "CallEventTypeT::SG_DestSeized_ConsultCall"},
        {CallEventTypeT::SG_OtherPartyAnswered_ConsultCall, "CallEventTypeT::SG_OtherPartyAnswered_ConsultCall"},
        {CallEventTypeT::SG_ThisPartyDisconnected_ConsultCall, "CallEventTypeT::SG_ThisPartyDisconnected_ConsultCall"},
        {CallEventTypeT::SG_OtherPartyDisconnected_ConsultCall, "CallEventTypeT::SG_OtherPartyDisconnected_ConsultCall"},
        {CallEventTypeT::SG_ThisPartyTransferred_ConsultCall, "CallEventTypeT::SG_ThisPartyTransferred_ConsultCall"},
        {CallEventTypeT::SG_OtherPartyTransferred_ConsultCall, "CallEventTypeT::SG_OtherPartyTransferred_ConsultCall"},
        {CallEventTypeT::SG_ThisPartyConferenced_ConferenceCall, "CallEventTypeT::SG_ThisPartyConferenced_ConferenceCall"},
        {CallEventTypeT::SG_OtherPartyConferenced_ConferenceCall, "CallEventTypeT::SG_OtherPartyConferenced_ConferenceCall"},
        {CallEventTypeT::SG_ThisPartyDisconnect_ConferenceCall, "CallEventTypeT::SG_ThisPartyDisconnect_ConferenceCall"},
        {CallEventTypeT::SG_OtherPartyDisconnect_ConferenceCall, "CallEventTypeT::SG_OtherPartyDisconnect_ConferenceCall"},
        {CallEventTypeT::SG_ThisPartyConferenced_MonitorCall, "CallEventTypeT::SG_ThisPartyConferenced_MonitorCall"},
        {CallEventTypeT::SG_OtherPartyConferenced_MonitorCall, "CallEventTypeT::SG_OtherPartyConferenced_MonitorCall"},
        {CallEventTypeT::SG_ThisPartyDisconnect_MonitorCall, "CallEventTypeT::SG_ThisPartyDisconnect_MonitorCall"},
        {CallEventTypeT::SG_OtherPartyDisconnect_MonitorCall, "CallEventTypeT::SG_OtherPartyDisconnect_MonitorCall"},
        {CallEventTypeT::SG_ThisPartyConferenced_IntrudeCall, "CallEventTypeT::SG_ThisPartyConferenced_IntrudeCall"},
        {CallEventTypeT::SG_OtherPartyConferenced_IntrudeCall, "CallEventTypeT::SG_OtherPartyConferenced_IntrudeCall"},
        {CallEventTypeT::SG_ThisPartyDisconnect_IntrudeCall, "CallEventTypeT::SG_ThisPartyDisconnect_IntrudeCall"},
        {CallEventTypeT::SG_OtherPartyDisconnect_IntrudeCall, "CallEventTypeT::SG_OtherPartyDisconnect_IntrudeCall"},
        {0, NULL}
    };

    CallEventTypeT::CallEventTypeT() : _value(SG_UnKnownEvent) {
    }

    CallEventTypeT::CallEventTypeT(int32_t value) : _value(value) {
    }

    int32_t CallEventTypeT::get_value() const {
        return _value;
    }

    std::string CallEventTypeT::get_desc() const {
        const struct desc_t* ptr = CallEventTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool CallEventTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool CallEventTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool CallEventTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool CallEventTypeT::operator==(const CallEventTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool CallEventTypeT::operator!=(const CallEventTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool CallEventTypeT::operator< (const CallEventTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const CallEventTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const CallEventTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const CallEventTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const CallEventTypeT& e) {
        o << e.get_value();
        return o;
    }


    const struct CallStateT::desc_t CallStateT::descs[] = {
        {CallStateT::SG_UnknownState, "CallStateT::SG_UnknownState"},
        {CallStateT::SG_IdleState, "CallStateT::SG_IdleState"},
        {CallStateT::SG_AlertingState, "CallStateT::SG_AlertingState"},
        {CallStateT::SG_HalfAlertingState, "CallStateT::SG_HalfAlertingState"},
        {CallStateT::SG_ConnectingState, "CallStateT::SG_ConnectingState"},
        {CallStateT::SG_ConnectedState, "CallStateT::SG_ConnectedState"},
        {CallStateT::SG_HalfConnectedState, "CallStateT::SG_HalfConnectedState"},
        {CallStateT::SG_SuspendedState, "CallStateT::SG_SuspendedState"},
        {CallStateT::SG_ConferenceState, "CallStateT::SG_ConferenceState"},
        {CallStateT::SG_MonitorState, "CallStateT::SG_MonitorState"},
        {CallStateT::SG_IntrudeState, "CallStateT::SG_IntrudeState"},
        {0, NULL}
    };

    CallStateT::CallStateT() : _value(SG_UnknownState) {
    }

    CallStateT::CallStateT(int32_t value) : _value(value) {
    }

    int32_t CallStateT::get_value() const {
        return _value;
    }

    std::string CallStateT::get_desc() const {
        const struct desc_t* ptr = CallStateT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool CallStateT::operator==(int32_t value) const {
        return _value == value;
    }

    bool CallStateT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool CallStateT::operator< (int32_t value) const {
        return _value < value;
    }

    bool CallStateT::operator==(const CallStateT& rhs) const {
        return _value == rhs.get_value();
    }

    bool CallStateT::operator!=(const CallStateT& rhs) const {
        return _value != rhs.get_value();
    }

    bool CallStateT::operator< (const CallStateT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const CallStateT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const CallStateT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const CallStateT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const CallStateT& e) {
        o << e.get_value();
        return o;
    }


    const struct PartyAttributeT::desc_t PartyAttributeT::descs[] = {
        {PartyAttributeT::P_Unknown, "PartyAttributeT::P_Unknown"},
        {PartyAttributeT::P_Internal, "PartyAttributeT::P_Internal"},
        {PartyAttributeT::P_Normal, "PartyAttributeT::P_Normal"},
        {0, NULL}
    };

    PartyAttributeT::PartyAttributeT() : _value(P_Unknown) {
    }

    PartyAttributeT::PartyAttributeT(int32_t value) : _value(value) {
    }

    int32_t PartyAttributeT::get_value() const {
        return _value;
    }

    std::string PartyAttributeT::get_desc() const {
        const struct desc_t* ptr = PartyAttributeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool PartyAttributeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool PartyAttributeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool PartyAttributeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool PartyAttributeT::operator==(const PartyAttributeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool PartyAttributeT::operator!=(const PartyAttributeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool PartyAttributeT::operator< (const PartyAttributeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const PartyAttributeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const PartyAttributeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const PartyAttributeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const PartyAttributeT& e) {
        o << e.get_value();
        return o;
    }


    const struct CallEventReasonT::desc_t CallEventReasonT::descs[] = {
        {CallEventReasonT::ReasonSuccess, "CallEventReasonT::ReasonSuccess"},
        {CallEventReasonT::ResaonInvokeComplete, "CallEventReasonT::ResaonInvokeComplete"},
        {CallEventReasonT::ReasonCallDestBusy, "CallEventReasonT::ReasonCallDestBusy"},
        {CallEventReasonT::ReasonCallNoAnswer, "CallEventReasonT::ReasonCallNoAnswer"},
        {CallEventReasonT::ReasonCallDestUnknown, "CallEventReasonT::ReasonCallDestUnknown"},
        {CallEventReasonT::ReasonCallDestInvalid, "CallEventReasonT::ReasonCallDestInvalid"},
        {CallEventReasonT::ReasonCallTimeout, "CallEventReasonT::ReasonCallTimeout"},
        {0, NULL}
    };

    CallEventReasonT::CallEventReasonT() : _value(ReasonSuccess) {
    }

    CallEventReasonT::CallEventReasonT(int32_t value) : _value(value) {
    }

    int32_t CallEventReasonT::get_value() const {
        return _value;
    }

    std::string CallEventReasonT::get_desc() const {
        const struct desc_t* ptr = CallEventReasonT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool CallEventReasonT::operator==(int32_t value) const {
        return _value == value;
    }

    bool CallEventReasonT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool CallEventReasonT::operator< (int32_t value) const {
        return _value < value;
    }

    bool CallEventReasonT::operator==(const CallEventReasonT& rhs) const {
        return _value == rhs.get_value();
    }

    bool CallEventReasonT::operator!=(const CallEventReasonT& rhs) const {
        return _value != rhs.get_value();
    }

    bool CallEventReasonT::operator< (const CallEventReasonT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const CallEventReasonT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const CallEventReasonT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const CallEventReasonT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const CallEventReasonT& e) {
        o << e.get_value();
        return o;
    }

    CallEventT::CallEventT() {
    }

    CallEventT::~CallEventT() {
    }

    bool CallEventT::operator==(const CallEventT& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (callid != rhs.callid) {
            return false;
        }
        if (device != rhs.device) {
            return false;
        }
        if (eventType != rhs.eventType) {
            return false;
        }
        if (state != rhs.state) {
            return false;
        }
        if (originalCallid != rhs.originalCallid) {
            return false;
        }
        if (partyNum != rhs.partyNum) {
            return false;
        }
        if (otherDevice != rhs.otherDevice) {
            return false;
        }
        if (otherAttr != rhs.otherAttr) {
            return false;
        }
        if (originatingParty != rhs.originatingParty) {
            return false;
        }
        if (originalAni != rhs.originalAni) {
            return false;
        }
        if (originalDnis != rhs.originalDnis) {
            return false;
        }
        if (reason != rhs.reason) {
            return false;
        }
        if (timestamp != rhs.timestamp) {
            return false;
        }
        return true;
    }

    bool CallEventT::operator!=(const CallEventT& rhs) const {
        return !(*this == rhs);
    }

    bool CallEventT::operator< (const CallEventT& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (sessionid < rhs.sessionid) {
            return true;
        }
        else if (rhs.sessionid < sessionid) {
            return false;
        }

        if (callid < rhs.callid) {
            return true;
        }
        else if (rhs.callid < callid) {
            return false;
        }

        if (device < rhs.device) {
            return true;
        }
        else if (rhs.device < device) {
            return false;
        }

        if (eventType < rhs.eventType) {
            return true;
        }
        else if (rhs.eventType < eventType) {
            return false;
        }

        if (state < rhs.state) {
            return true;
        }
        else if (rhs.state < state) {
            return false;
        }

        if (originalCallid < rhs.originalCallid) {
            return true;
        }
        else if (rhs.originalCallid < originalCallid) {
            return false;
        }

        if (partyNum < rhs.partyNum) {
            return true;
        }
        else if (rhs.partyNum < partyNum) {
            return false;
        }

        if (otherDevice < rhs.otherDevice) {
            return true;
        }
        else if (rhs.otherDevice < otherDevice) {
            return false;
        }

        if (otherAttr < rhs.otherAttr) {
            return true;
        }
        else if (rhs.otherAttr < otherAttr) {
            return false;
        }

        if (originatingParty < rhs.originatingParty) {
            return true;
        }
        else if (rhs.originatingParty < originatingParty) {
            return false;
        }

        if (originalAni < rhs.originalAni) {
            return true;
        }
        else if (rhs.originalAni < originalAni) {
            return false;
        }

        if (originalDnis < rhs.originalDnis) {
            return true;
        }
        else if (rhs.originalDnis < originalDnis) {
            return false;
        }

        if (reason < rhs.reason) {
            return true;
        }
        else if (rhs.reason < reason) {
            return false;
        }

        if (timestamp < rhs.timestamp) {
            return true;
        }
        else if (rhs.timestamp < timestamp) {
            return false;
        }

        return false;
    }

    int32_t CallEventT::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto){
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, callid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, device);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 4:
                int32_t ele_var1;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var1);
                if (ret < 0) { return ret; }
                nread += ret;
                eventType = ele_var1;
                break;
            case 5:
                int32_t ele_var2;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var2);
                if (ret < 0) { return ret; }
                nread += ret;
                state = ele_var2;
                break;
            case 6:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, originalCallid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 7:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, partyNum);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 8:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, otherDevice);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 9:
                int32_t ele_var3;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var3);
                if (ret < 0) { return ret; }
                nread += ret;
                otherAttr = ele_var3;
                break;
            case 10:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, originatingParty);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 11:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, originalAni);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 12:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, originalDnis);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 13:
                int32_t ele_var4;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var4);
                if (ret < 0) { return ret; }
                nread += ret;
                reason = ele_var4;
                break;
            case 14:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, timestamp);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t CallEventT::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("CallEventT");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callid", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString(callid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("device", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString(device);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("eventType", bgcc::IDINT32, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(eventType.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("state", bgcc::IDINT32, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(state.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("originalCallid", bgcc::IDSTR, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeString(originalCallid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("partyNum", bgcc::IDINT32, 7);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(partyNum);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("otherDevice", bgcc::IDSTR, 8);
        if (ret < 0) { return ret; }
        ret = proto->writeString(otherDevice);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("otherAttr", bgcc::IDINT32, 9);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(otherAttr.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("originatingParty", bgcc::IDSTR, 10);
        if (ret < 0) { return ret; }
        ret = proto->writeString(originatingParty);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("originalAni", bgcc::IDSTR, 11);
        if (ret < 0) { return ret; }
        ret = proto->writeString(originalAni);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("originalDnis", bgcc::IDSTR, 12);
        if (ret < 0) { return ret; }
        ret = proto->writeString(originalDnis);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reason", bgcc::IDINT32, 13);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(reason.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("timestamp", bgcc::IDINT64, 14);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(timestamp);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct MediaEventTypeT::desc_t MediaEventTypeT::descs[] = {
        {MediaEventTypeT::MG_UnknownEvent, "MediaEventTypeT::MG_UnknownEvent"},
        {MediaEventTypeT::MG_TP_Record_Started, "MediaEventTypeT::MG_TP_Record_Started"},
        {MediaEventTypeT::MG_OP_Record_Started, "MediaEventTypeT::MG_OP_Record_Started"},
        {MediaEventTypeT::MG_TP_Record_Done, "MediaEventTypeT::MG_TP_Record_Done"},
        {MediaEventTypeT::MG_OP_Record_Done, "MediaEventTypeT::MG_OP_Record_Done"},
        {0, NULL}
    };

    MediaEventTypeT::MediaEventTypeT() : _value(MG_UnknownEvent) {
    }

    MediaEventTypeT::MediaEventTypeT(int32_t value) : _value(value) {
    }

    int32_t MediaEventTypeT::get_value() const {
        return _value;
    }

    std::string MediaEventTypeT::get_desc() const {
        const struct desc_t* ptr = MediaEventTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool MediaEventTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool MediaEventTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool MediaEventTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool MediaEventTypeT::operator==(const MediaEventTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool MediaEventTypeT::operator!=(const MediaEventTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool MediaEventTypeT::operator< (const MediaEventTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const MediaEventTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const MediaEventTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const MediaEventTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const MediaEventTypeT& e) {
        o << e.get_value();
        return o;
    }


    const struct MediaStateT::desc_t MediaStateT::descs[] = {
        {MediaStateT::MG_UnknownState, "MediaStateT::MG_UnknownState"},
        {MediaStateT::MG_IdleState, "MediaStateT::MG_IdleState"},
        {MediaStateT::MG_RecordingState, "MediaStateT::MG_RecordingState"},
        {0, NULL}
    };

    MediaStateT::MediaStateT() : _value(MG_UnknownState) {
    }

    MediaStateT::MediaStateT(int32_t value) : _value(value) {
    }

    int32_t MediaStateT::get_value() const {
        return _value;
    }

    std::string MediaStateT::get_desc() const {
        const struct desc_t* ptr = MediaStateT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool MediaStateT::operator==(int32_t value) const {
        return _value == value;
    }

    bool MediaStateT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool MediaStateT::operator< (int32_t value) const {
        return _value < value;
    }

    bool MediaStateT::operator==(const MediaStateT& rhs) const {
        return _value == rhs.get_value();
    }

    bool MediaStateT::operator!=(const MediaStateT& rhs) const {
        return _value != rhs.get_value();
    }

    bool MediaStateT::operator< (const MediaStateT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const MediaStateT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const MediaStateT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const MediaStateT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const MediaStateT& e) {
        o << e.get_value();
        return o;
    }


    const struct MediaEventReasonT::desc_t MediaEventReasonT::descs[] = {
        {MediaEventReasonT::ReasonMediaUnknown, "MediaEventReasonT::ReasonMediaUnknown"},
        {MediaEventReasonT::ReasonMediaEnd, "MediaEventReasonT::ReasonMediaEnd"},
        {MediaEventReasonT::ReasonMediaOther, "MediaEventReasonT::ReasonMediaOther"},
        {0, NULL}
    };

    MediaEventReasonT::MediaEventReasonT() : _value(ReasonMediaUnknown) {
    }

    MediaEventReasonT::MediaEventReasonT(int32_t value) : _value(value) {
    }

    int32_t MediaEventReasonT::get_value() const {
        return _value;
    }

    std::string MediaEventReasonT::get_desc() const {
        const struct desc_t* ptr = MediaEventReasonT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool MediaEventReasonT::operator==(int32_t value) const {
        return _value == value;
    }

    bool MediaEventReasonT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool MediaEventReasonT::operator< (int32_t value) const {
        return _value < value;
    }

    bool MediaEventReasonT::operator==(const MediaEventReasonT& rhs) const {
        return _value == rhs.get_value();
    }

    bool MediaEventReasonT::operator!=(const MediaEventReasonT& rhs) const {
        return _value != rhs.get_value();
    }

    bool MediaEventReasonT::operator< (const MediaEventReasonT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const MediaEventReasonT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const MediaEventReasonT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const MediaEventReasonT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const MediaEventReasonT& e) {
        o << e.get_value();
        return o;
    }

    MediaEventT::MediaEventT() {
    }

    MediaEventT::~MediaEventT() {
    }

    bool MediaEventT::operator==(const MediaEventT& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (callid != rhs.callid) {
            return false;
        }
        if (device != rhs.device) {
            return false;
        }
        if (eventType != rhs.eventType) {
            return false;
        }
        if (state != rhs.state) {
            return false;
        }
        if (reason != rhs.reason) {
            return false;
        }
        if (otherDevice != rhs.otherDevice) {
            return false;
        }
        if (mediaBuffer != rhs.mediaBuffer) {
            return false;
        }
        if (timestamp != rhs.timestamp) {
            return false;
        }
        return true;
    }

    bool MediaEventT::operator!=(const MediaEventT& rhs) const {
        return !(*this == rhs);
    }

    bool MediaEventT::operator< (const MediaEventT& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (sessionid < rhs.sessionid) {
            return true;
        }
        else if (rhs.sessionid < sessionid) {
            return false;
        }

        if (callid < rhs.callid) {
            return true;
        }
        else if (rhs.callid < callid) {
            return false;
        }

        if (device < rhs.device) {
            return true;
        }
        else if (rhs.device < device) {
            return false;
        }

        if (eventType < rhs.eventType) {
            return true;
        }
        else if (rhs.eventType < eventType) {
            return false;
        }

        if (state < rhs.state) {
            return true;
        }
        else if (rhs.state < state) {
            return false;
        }

        if (reason < rhs.reason) {
            return true;
        }
        else if (rhs.reason < reason) {
            return false;
        }

        if (otherDevice < rhs.otherDevice) {
            return true;
        }
        else if (rhs.otherDevice < otherDevice) {
            return false;
        }

        if (mediaBuffer < rhs.mediaBuffer) {
            return true;
        }
        else if (rhs.mediaBuffer < mediaBuffer) {
            return false;
        }

        if (timestamp < rhs.timestamp) {
            return true;
        }
        else if (rhs.timestamp < timestamp) {
            return false;
        }

        return false;
    }

    int32_t MediaEventT::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto){
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, callid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, device);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 4:
                int32_t ele_var5;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var5);
                if (ret < 0) { return ret; }
                nread += ret;
                eventType = ele_var5;
                break;
            case 5:
                int32_t ele_var6;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var6);
                if (ret < 0) { return ret; }
                nread += ret;
                state = ele_var6;
                break;
            case 6:
                int32_t ele_var7;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var7);
                if (ret < 0) { return ret; }
                nread += ret;
                reason = ele_var7;
                break;
            case 7:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, otherDevice);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 8:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, mediaBuffer);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 9:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, timestamp);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t MediaEventT::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("MediaEventT");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callid", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString(callid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("device", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString(device);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("eventType", bgcc::IDINT32, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(eventType.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("state", bgcc::IDINT32, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(state.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reason", bgcc::IDINT32, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(reason.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("otherDevice", bgcc::IDSTR, 7);
        if (ret < 0) { return ret; }
        ret = proto->writeString(otherDevice);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("mediaBuffer", bgcc::IDSTR, 8);
        if (ret < 0) { return ret; }
        ret = proto->writeString(mediaBuffer);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("timestamp", bgcc::IDINT64, 9);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(timestamp);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct RouteEventTypeT::desc_t RouteEventTypeT::descs[] = {
        {RouteEventTypeT::RT_RouteUnknown, "RouteEventTypeT::RT_RouteUnknown"},
        {RouteEventTypeT::RT_RouteRequest, "RouteEventTypeT::RT_RouteRequest"},
        {RouteEventTypeT::RT_RouteRespond, "RouteEventTypeT::RT_RouteRespond"},
        {RouteEventTypeT::RT_RouteRequestCancel, "RouteEventTypeT::RT_RouteRequestCancel"},
        {0, NULL}
    };

    RouteEventTypeT::RouteEventTypeT() : _value(RT_RouteUnknown) {
    }

    RouteEventTypeT::RouteEventTypeT(int32_t value) : _value(value) {
    }

    int32_t RouteEventTypeT::get_value() const {
        return _value;
    }

    std::string RouteEventTypeT::get_desc() const {
        const struct desc_t* ptr = RouteEventTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool RouteEventTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool RouteEventTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool RouteEventTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool RouteEventTypeT::operator==(const RouteEventTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool RouteEventTypeT::operator!=(const RouteEventTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool RouteEventTypeT::operator< (const RouteEventTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const RouteEventTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const RouteEventTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const RouteEventTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const RouteEventTypeT& e) {
        o << e.get_value();
        return o;
    }


    const struct RouteRequestTypeT::desc_t RouteRequestTypeT::descs[] = {
        {RouteRequestTypeT::RR_TypeUnknown, "RouteRequestTypeT::RR_TypeUnknown"},
        {RouteRequestTypeT::RR_TypeSkill, "RouteRequestTypeT::RR_TypeSkill"},
        {RouteRequestTypeT::RR_TypePrivate, "RouteRequestTypeT::RR_TypePrivate"},
        {RouteRequestTypeT::RR_TypePrivateList, "RouteRequestTypeT::RR_TypePrivateList"},
        {0, NULL}
    };

    RouteRequestTypeT::RouteRequestTypeT() : _value(RR_TypeUnknown) {
    }

    RouteRequestTypeT::RouteRequestTypeT(int32_t value) : _value(value) {
    }

    int32_t RouteRequestTypeT::get_value() const {
        return _value;
    }

    std::string RouteRequestTypeT::get_desc() const {
        const struct desc_t* ptr = RouteRequestTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool RouteRequestTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool RouteRequestTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool RouteRequestTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool RouteRequestTypeT::operator==(const RouteRequestTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool RouteRequestTypeT::operator!=(const RouteRequestTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool RouteRequestTypeT::operator< (const RouteRequestTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const RouteRequestTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const RouteRequestTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const RouteRequestTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const RouteRequestTypeT& e) {
        o << e.get_value();
        return o;
    }


    const struct RouteEventReasonT::desc_t RouteEventReasonT::descs[] = {
        {RouteEventReasonT::RouteReasonSuccess, "RouteEventReasonT::RouteReasonSuccess"},
        {RouteEventReasonT::RouteReasonBusy, "RouteEventReasonT::RouteReasonBusy"},
        {RouteEventReasonT::RouteReasonPrivateBusy, "RouteEventReasonT::RouteReasonPrivateBusy"},
        {RouteEventReasonT::RouteReasonWrongSkill, "RouteEventReasonT::RouteReasonWrongSkill"},
        {RouteEventReasonT::RouteReasonNotAssigned, "RouteEventReasonT::RouteReasonNotAssigned"},
        {RouteEventReasonT::RouteReasonError, "RouteEventReasonT::RouteReasonError"},
        {RouteEventReasonT::RouteReasonIVRCancel, "RouteEventReasonT::RouteReasonIVRCancel"},
        {RouteEventReasonT::RouteReasonClientHangup, "RouteEventReasonT::RouteReasonClientHangup"},
        {RouteEventReasonT::RouteReasonOther, "RouteEventReasonT::RouteReasonOther"},
        {0, NULL}
    };

    RouteEventReasonT::RouteEventReasonT() : _value(RouteReasonSuccess) {
    }

    RouteEventReasonT::RouteEventReasonT(int32_t value) : _value(value) {
    }

    int32_t RouteEventReasonT::get_value() const {
        return _value;
    }

    std::string RouteEventReasonT::get_desc() const {
        const struct desc_t* ptr = RouteEventReasonT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool RouteEventReasonT::operator==(int32_t value) const {
        return _value == value;
    }

    bool RouteEventReasonT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool RouteEventReasonT::operator< (int32_t value) const {
        return _value < value;
    }

    bool RouteEventReasonT::operator==(const RouteEventReasonT& rhs) const {
        return _value == rhs.get_value();
    }

    bool RouteEventReasonT::operator!=(const RouteEventReasonT& rhs) const {
        return _value != rhs.get_value();
    }

    bool RouteEventReasonT::operator< (const RouteEventReasonT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const RouteEventReasonT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const RouteEventReasonT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const RouteEventReasonT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const RouteEventReasonT& e) {
        o << e.get_value();
        return o;
    }

    RouteEventT::RouteEventT() {
    }

    RouteEventT::~RouteEventT() {
    }

    bool RouteEventT::operator==(const RouteEventT& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (callid != rhs.callid) {
            return false;
        }
        if (device != rhs.device) {
            return false;
        }
        if (eventType != rhs.eventType) {
            return false;
        }
        if (reason != rhs.reason) {
            return false;
        }
        if (requstid != rhs.requstid) {
            return false;
        }
        if (targetDevice != rhs.targetDevice) {
            return false;
        }
        if (destService != rhs.destService) {
            return false;
        }
        if (requestType != rhs.requestType) {
            return false;
        }
        if (requestArgs != rhs.requestArgs) {
            return false;
        }
        if (level != rhs.level) {
            return false;
        }
        if (callerDn != rhs.callerDn) {
            return false;
        }
        if (calleeDn != rhs.calleeDn) {
            return false;
        }
        if (validtime != rhs.validtime) {
            return false;
        }
        if (timeout != rhs.timeout) {
            return false;
        }
        if (buffer != rhs.buffer) {
            return false;
        }
        if (timestamp != rhs.timestamp) {
            return false;
        }
        return true;
    }

    bool RouteEventT::operator!=(const RouteEventT& rhs) const {
        return !(*this == rhs);
    }

    bool RouteEventT::operator< (const RouteEventT& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (sessionid < rhs.sessionid) {
            return true;
        }
        else if (rhs.sessionid < sessionid) {
            return false;
        }

        if (callid < rhs.callid) {
            return true;
        }
        else if (rhs.callid < callid) {
            return false;
        }

        if (device < rhs.device) {
            return true;
        }
        else if (rhs.device < device) {
            return false;
        }

        if (eventType < rhs.eventType) {
            return true;
        }
        else if (rhs.eventType < eventType) {
            return false;
        }

        if (reason < rhs.reason) {
            return true;
        }
        else if (rhs.reason < reason) {
            return false;
        }

        if (requstid < rhs.requstid) {
            return true;
        }
        else if (rhs.requstid < requstid) {
            return false;
        }

        if (targetDevice < rhs.targetDevice) {
            return true;
        }
        else if (rhs.targetDevice < targetDevice) {
            return false;
        }

        if (destService < rhs.destService) {
            return true;
        }
        else if (rhs.destService < destService) {
            return false;
        }

        if (requestType < rhs.requestType) {
            return true;
        }
        else if (rhs.requestType < requestType) {
            return false;
        }

        if (requestArgs < rhs.requestArgs) {
            return true;
        }
        else if (rhs.requestArgs < requestArgs) {
            return false;
        }

        if (level < rhs.level) {
            return true;
        }
        else if (rhs.level < level) {
            return false;
        }

        if (callerDn < rhs.callerDn) {
            return true;
        }
        else if (rhs.callerDn < callerDn) {
            return false;
        }

        if (calleeDn < rhs.calleeDn) {
            return true;
        }
        else if (rhs.calleeDn < calleeDn) {
            return false;
        }

        if (validtime < rhs.validtime) {
            return true;
        }
        else if (rhs.validtime < validtime) {
            return false;
        }

        if (timeout < rhs.timeout) {
            return true;
        }
        else if (rhs.timeout < timeout) {
            return false;
        }

        if (buffer < rhs.buffer) {
            return true;
        }
        else if (rhs.buffer < buffer) {
            return false;
        }

        if (timestamp < rhs.timestamp) {
            return true;
        }
        else if (rhs.timestamp < timestamp) {
            return false;
        }

        return false;
    }

    int32_t RouteEventT::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto){
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, callid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, device);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 4:
                int32_t ele_var8;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var8);
                if (ret < 0) { return ret; }
                nread += ret;
                eventType = ele_var8;
                break;
            case 5:
                int32_t ele_var9;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var9);
                if (ret < 0) { return ret; }
                nread += ret;
                reason = ele_var9;
                break;
            case 6:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, requstid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 7:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, targetDevice);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 8:
                int32_t ele_var10;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var10);
                if (ret < 0) { return ret; }
                nread += ret;
                destService = ele_var10;
                break;
            case 9:
                int32_t ele_var11;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var11);
                if (ret < 0) { return ret; }
                nread += ret;
                requestType = ele_var11;
                break;
            case 10:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, requestArgs);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 11:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, level);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 12:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, callerDn);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 13:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, calleeDn);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 14:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, validtime);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 15:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, timeout);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 16:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, buffer);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 17:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, timestamp);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t RouteEventT::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("RouteEventT");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callid", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString(callid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("device", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString(device);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("eventType", bgcc::IDINT32, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(eventType.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("reason", bgcc::IDINT32, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(reason.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("requstid", bgcc::IDINT64, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(requstid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("targetDevice", bgcc::IDSTR, 7);
        if (ret < 0) { return ret; }
        ret = proto->writeString(targetDevice);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("destService", bgcc::IDINT32, 8);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(destService.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("requestType", bgcc::IDINT32, 9);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(requestType.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("requestArgs", bgcc::IDSTR, 10);
        if (ret < 0) { return ret; }
        ret = proto->writeString(requestArgs);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("level", bgcc::IDINT32, 11);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(level);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callerDn", bgcc::IDSTR, 12);
        if (ret < 0) { return ret; }
        ret = proto->writeString(callerDn);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("calleeDn", bgcc::IDSTR, 13);
        if (ret < 0) { return ret; }
        ret = proto->writeString(calleeDn);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("validtime", bgcc::IDINT32, 14);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(validtime);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("timeout", bgcc::IDINT32, 15);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(timeout);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("buffer", bgcc::IDSTR, 16);
        if (ret < 0) { return ret; }
        ret = proto->writeString(buffer);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("timestamp", bgcc::IDINT64, 17);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(timestamp);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct OtherEventTypeT::desc_t OtherEventTypeT::descs[] = {
        {OtherEventTypeT::OG_HeartBeat, "OtherEventTypeT::OG_HeartBeat"},
        {OtherEventTypeT::OG_SessionCreate, "OtherEventTypeT::OG_SessionCreate"},
        {OtherEventTypeT::OG_OperationFailed, "OtherEventTypeT::OG_OperationFailed"},
        {0, NULL}
    };

    OtherEventTypeT::OtherEventTypeT() : _value(OG_HeartBeat) {
    }

    OtherEventTypeT::OtherEventTypeT(int32_t value) : _value(value) {
    }

    int32_t OtherEventTypeT::get_value() const {
        return _value;
    }

    std::string OtherEventTypeT::get_desc() const {
        const struct desc_t* ptr = OtherEventTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool OtherEventTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool OtherEventTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool OtherEventTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool OtherEventTypeT::operator==(const OtherEventTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool OtherEventTypeT::operator!=(const OtherEventTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool OtherEventTypeT::operator< (const OtherEventTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const OtherEventTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const OtherEventTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const OtherEventTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const OtherEventTypeT& e) {
        o << e.get_value();
        return o;
    }

    OtherEventT::OtherEventT() {
    }

    OtherEventT::~OtherEventT() {
    }

    bool OtherEventT::operator==(const OtherEventT& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (sessionid != rhs.sessionid) {
            return false;
        }
        if (callid != rhs.callid) {
            return false;
        }
        if (device != rhs.device) {
            return false;
        }
        if (eventType != rhs.eventType) {
            return false;
        }
        if (timestamp != rhs.timestamp) {
            return false;
        }
        if (data != rhs.data) {
            return false;
        }
        return true;
    }

    bool OtherEventT::operator!=(const OtherEventT& rhs) const {
        return !(*this == rhs);
    }

    bool OtherEventT::operator< (const OtherEventT& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (sessionid < rhs.sessionid) {
            return true;
        }
        else if (rhs.sessionid < sessionid) {
            return false;
        }

        if (callid < rhs.callid) {
            return true;
        }
        else if (rhs.callid < callid) {
            return false;
        }

        if (device < rhs.device) {
            return true;
        }
        else if (rhs.device < device) {
            return false;
        }

        if (eventType < rhs.eventType) {
            return true;
        }
        else if (rhs.eventType < eventType) {
            return false;
        }

        if (timestamp < rhs.timestamp) {
            return true;
        }
        else if (rhs.timestamp < timestamp) {
            return false;
        }

        if (data < rhs.data) {
            return true;
        }
        else if (rhs.data < data) {
            return false;
        }

        return false;
    }

    int32_t OtherEventT::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto){
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, sessionid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, callid);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, device);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 4:
                int32_t ele_var12;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var12);
                if (ret < 0) { return ret; }
                nread += ret;
                eventType = ele_var12;
                break;
            case 5:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, timestamp);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 6:
                data.clear();

                int32_t size_var13;
                bgcc::DataTypeID ktype_var14;
                bgcc::DataTypeID vtype_var15;

                ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var14, vtype_var15, size_var13);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var13; ++i) {
                    std::string key_var16;

                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, key_var16);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    std::string& value_var17 = data[key_var16];
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value_var17);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t OtherEventT::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("OtherEventT");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sessionid", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(sessionid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("callid", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString(callid);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("device", bgcc::IDSTR, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeString(device);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("eventType", bgcc::IDINT32, 4);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(eventType.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("timestamp", bgcc::IDINT64, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(timestamp);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("data", bgcc::IDMAP, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDSTR, bgcc::IDSTR, data.size());
        if (ret < 0) { return ret; }
        std::map<std::string, std::string> ::const_iterator citr_var18;
        for (citr_var18 = data.begin(); citr_var18 != data.end(); ++citr_var18) {
            ret = proto->writeString(citr_var18->first);
            if (ret < 0) { return ret; }
            ret = proto->writeString(citr_var18->second);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct ConfigTypeT::desc_t ConfigTypeT::descs[] = {
        {ConfigTypeT::CT_All, "ConfigTypeT::CT_All"},
        {0, NULL}
    };

    ConfigTypeT::ConfigTypeT() : _value(CT_All) {
    }

    ConfigTypeT::ConfigTypeT(int32_t value) : _value(value) {
    }

    int32_t ConfigTypeT::get_value() const {
        return _value;
    }

    std::string ConfigTypeT::get_desc() const {
        const struct desc_t* ptr = ConfigTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool ConfigTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool ConfigTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool ConfigTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool ConfigTypeT::operator==(const ConfigTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool ConfigTypeT::operator!=(const ConfigTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool ConfigTypeT::operator< (const ConfigTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const ConfigTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const ConfigTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const ConfigTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const ConfigTypeT& e) {
        o << e.get_value();
        return o;
    }


    const struct TransferTypeT::desc_t TransferTypeT::descs[] = {
        {TransferTypeT::TT_UNKONWN, "TransferTypeT::TT_UNKONWN"},
        {TransferTypeT::TT_INSTANT, "TransferTypeT::TT_INSTANT"},
        {TransferTypeT::TT_RING, "TransferTypeT::TT_RING"},
        {TransferTypeT::TT_ANSWER, "TransferTypeT::TT_ANSWER"},
        {0, NULL}
    };

    TransferTypeT::TransferTypeT() : _value(TT_UNKONWN) {
    }

    TransferTypeT::TransferTypeT(int32_t value) : _value(value) {
    }

    int32_t TransferTypeT::get_value() const {
        return _value;
    }

    std::string TransferTypeT::get_desc() const {
        const struct desc_t* ptr = TransferTypeT::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool TransferTypeT::operator==(int32_t value) const {
        return _value == value;
    }

    bool TransferTypeT::operator!=(int32_t value) const {
        return _value != value;
    }

    bool TransferTypeT::operator< (int32_t value) const {
        return _value < value;
    }

    bool TransferTypeT::operator==(const TransferTypeT& rhs) const {
        return _value == rhs.get_value();
    }

    bool TransferTypeT::operator!=(const TransferTypeT& rhs) const {
        return _value != rhs.get_value();
    }

    bool TransferTypeT::operator< (const TransferTypeT& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const TransferTypeT& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const TransferTypeT& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const TransferTypeT& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const TransferTypeT& e) {
        o << e.get_value();
        return o;
    }

}


