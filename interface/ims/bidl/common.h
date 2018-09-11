#ifndef _BIDL2SL_COMMON_H_
#define _BIDL2SL_COMMON_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

namespace ims {
    typedef int64_t SessionIdT;
    typedef std::string CallIdT;
    typedef std::vector<CallIdT>  CallIdListT;
    typedef std::map<std::string, std::string>  OtherEventDataT;
    typedef int64_t RouteRequestIDT;
    typedef int64_t ReqIdT;
    typedef std::map<std::string, std::string>  AssociateDataT;

    class CcResultT {
    public:
        enum {
            ResSuccess = 0,
            ResFailed = 1,
            ResInvalidParam = 2,
            ResNotSupport = 3,
            ResNoEnoughResource = 4,
            ResSessionNotFound = 5,
            ResInvalidDn = 6,
            ResInvalidState = 7,
            ResInvalidFile = 8,
            ResInvalidReqId = 9,
            ResAccessDenied = 10,
            ResRouteRequestRepeated = 11,
            ResCallSourceNotFound = 12,
            ResNoAgentAssigned = 13
        };

        CcResultT();
        CcResultT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const CcResultT& rhs) const;
        bool operator==(const CcResultT& rhs) const;
        bool operator< (const CcResultT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const CcResultT&);
    bool operator!=(int32_t value, const CcResultT&);
    bool operator< (int32_t value, const CcResultT&);
    std::ostream& operator<<(std::ostream& o, const CcResultT&);


    class CallModeT {
    public:
        enum {
            Normal = 0,
            Persist = 1
        };

        CallModeT();
        CallModeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const CallModeT& rhs) const;
        bool operator==(const CallModeT& rhs) const;
        bool operator< (const CallModeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const CallModeT&);
    bool operator!=(int32_t value, const CallModeT&);
    bool operator< (int32_t value, const CallModeT&);
    std::ostream& operator<<(std::ostream& o, const CallModeT&);


    class SsConferenceTypeT {
    public:
        enum {
            Monitor = 0,
            Intrude = 1,
            MonitorIntrude = 2
        };

        SsConferenceTypeT();
        SsConferenceTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const SsConferenceTypeT& rhs) const;
        bool operator==(const SsConferenceTypeT& rhs) const;
        bool operator< (const SsConferenceTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const SsConferenceTypeT&);
    bool operator!=(int32_t value, const SsConferenceTypeT&);
    bool operator< (int32_t value, const SsConferenceTypeT&);
    std::ostream& operator<<(std::ostream& o, const SsConferenceTypeT&);


    class DnTypeT {
    public:
        enum {
            AgentDn = 0,
            IvrANI = 1
        };

        DnTypeT();
        DnTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const DnTypeT& rhs) const;
        bool operator==(const DnTypeT& rhs) const;
        bool operator< (const DnTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const DnTypeT&);
    bool operator!=(int32_t value, const DnTypeT&);
    bool operator< (int32_t value, const DnTypeT&);
    std::ostream& operator<<(std::ostream& o, const DnTypeT&);

    class SysInfoT {
    public:
        SysInfoT();
        ~SysInfoT();

        int64_t sessionCount;
        float sessionPerSec;
        int64_t sessionSinceStartup;

        bool operator==(const SysInfoT& rhs) const;
        bool operator!=(const SysInfoT& rhs) const;
        bool operator< (const SysInfoT& rhs) const;
        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };


    class ServiceTypeT {
    public:
        enum {
            ServiceNone = 0,
            ServiceIVR = 1,
            ServiceACD = 2,
            ServiceDS = 3
        };

        ServiceTypeT();
        ServiceTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const ServiceTypeT& rhs) const;
        bool operator==(const ServiceTypeT& rhs) const;
        bool operator< (const ServiceTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const ServiceTypeT&);
    bool operator!=(int32_t value, const ServiceTypeT&);
    bool operator< (int32_t value, const ServiceTypeT&);
    std::ostream& operator<<(std::ostream& o, const ServiceTypeT&);


    class CallEventTypeT {
    public:
        enum {
            SG_UnKnownEvent = 0,
            SG_InboundCall_InternalCall = 1,
            SG_DestSeized_InternalCall = 2,
            SG_ThisPartyAnswered_InternalCall = 3,
            SG_OtherPartyAnswered_InternalCall = 4,
            SG_ThisPartyDisconnected_InternalCall = 5,
            SG_OtherPartyDisconnected_InternalCall = 6,
            SG_InboundCall_NormalCall = 7,
            SG_DestSeized_NormalCall = 8,
            SG_ThisPartyAnswered_NormalCall = 9,
            SG_OtherPartyAnswered_NormalCall = 10,
            SG_ThisPartyDisconnected_NormalCall = 11,
            SG_OtherPartyDisconnected_NormalCall = 12,
            SG_ThisPartySuspended_NormalCall = 13,
            SG_ThisPartyRetrieved_NormalCall = 14,
            SG_ThisPartyTransferred_NormalCall = 15,
            SG_DestSeized_ConsultCall = 16,
            SG_OtherPartyAnswered_ConsultCall = 17,
            SG_ThisPartyDisconnected_ConsultCall = 18,
            SG_OtherPartyDisconnected_ConsultCall = 19,
            SG_ThisPartyTransferred_ConsultCall = 20,
            SG_OtherPartyTransferred_ConsultCall = 21,
            SG_ThisPartyConferenced_ConferenceCall = 22,
            SG_OtherPartyConferenced_ConferenceCall = 23,
            SG_ThisPartyDisconnect_ConferenceCall = 24,
            SG_OtherPartyDisconnect_ConferenceCall = 25,
            SG_ThisPartyConferenced_MonitorCall = 26,
            SG_OtherPartyConferenced_MonitorCall = 27,
            SG_ThisPartyDisconnect_MonitorCall = 28,
            SG_OtherPartyDisconnect_MonitorCall = 29,
            SG_ThisPartyConferenced_IntrudeCall = 30,
            SG_OtherPartyConferenced_IntrudeCall = 31,
            SG_ThisPartyDisconnect_IntrudeCall = 32,
            SG_OtherPartyDisconnect_IntrudeCall = 33
        };

        CallEventTypeT();
        CallEventTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const CallEventTypeT& rhs) const;
        bool operator==(const CallEventTypeT& rhs) const;
        bool operator< (const CallEventTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const CallEventTypeT&);
    bool operator!=(int32_t value, const CallEventTypeT&);
    bool operator< (int32_t value, const CallEventTypeT&);
    std::ostream& operator<<(std::ostream& o, const CallEventTypeT&);


    class CallStateT {
    public:
        enum {
            SG_UnknownState = 0,
            SG_IdleState = 1,
            SG_AlertingState = 2,
            SG_HalfAlertingState = 3,
            SG_ConnectingState = 4,
            SG_ConnectedState = 5,
            SG_HalfConnectedState = 6,
            SG_SuspendedState = 7,
            SG_ConferenceState = 8,
            SG_MonitorState = 9,
            SG_IntrudeState = 10
        };

        CallStateT();
        CallStateT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const CallStateT& rhs) const;
        bool operator==(const CallStateT& rhs) const;
        bool operator< (const CallStateT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const CallStateT&);
    bool operator!=(int32_t value, const CallStateT&);
    bool operator< (int32_t value, const CallStateT&);
    std::ostream& operator<<(std::ostream& o, const CallStateT&);


    class PartyAttributeT {
    public:
        enum {
            P_Unknown = 0,
            P_Internal = 1,
            P_Normal = 2
        };

        PartyAttributeT();
        PartyAttributeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const PartyAttributeT& rhs) const;
        bool operator==(const PartyAttributeT& rhs) const;
        bool operator< (const PartyAttributeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const PartyAttributeT&);
    bool operator!=(int32_t value, const PartyAttributeT&);
    bool operator< (int32_t value, const PartyAttributeT&);
    std::ostream& operator<<(std::ostream& o, const PartyAttributeT&);


    class CallEventReasonT {
    public:
        enum {
            ReasonSuccess = 0,
            ResaonInvokeComplete = 1,
            ReasonCallDestBusy = 2,
            ReasonCallNoAnswer = 3,
            ReasonCallDestUnknown = 4,
            ReasonCallDestInvalid = 5,
            ReasonCallTimeout = 6
        };

        CallEventReasonT();
        CallEventReasonT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const CallEventReasonT& rhs) const;
        bool operator==(const CallEventReasonT& rhs) const;
        bool operator< (const CallEventReasonT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const CallEventReasonT&);
    bool operator!=(int32_t value, const CallEventReasonT&);
    bool operator< (int32_t value, const CallEventReasonT&);
    std::ostream& operator<<(std::ostream& o, const CallEventReasonT&);

    class CallEventT {
    public:
        CallEventT();
        ~CallEventT();

        SessionIdT sessionid;
        CallIdT callid;
        std::string device;
        CallEventTypeT eventType;
        CallStateT state;
        CallIdT originalCallid;
        int32_t partyNum;
        std::string otherDevice;
        PartyAttributeT otherAttr;
        std::string originatingParty;
        std::string originalAni;
        std::string originalDnis;
        CallEventReasonT reason;
        int64_t timestamp;

        bool operator==(const CallEventT& rhs) const;
        bool operator!=(const CallEventT& rhs) const;
        bool operator< (const CallEventT& rhs) const;
        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };


    class MediaEventTypeT {
    public:
        enum {
            MG_UnknownEvent = 0,
            MG_TP_Record_Started = 1,
            MG_OP_Record_Started = 2,
            MG_TP_Record_Done = 3,
            MG_OP_Record_Done = 4
        };

        MediaEventTypeT();
        MediaEventTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const MediaEventTypeT& rhs) const;
        bool operator==(const MediaEventTypeT& rhs) const;
        bool operator< (const MediaEventTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const MediaEventTypeT&);
    bool operator!=(int32_t value, const MediaEventTypeT&);
    bool operator< (int32_t value, const MediaEventTypeT&);
    std::ostream& operator<<(std::ostream& o, const MediaEventTypeT&);


    class MediaStateT {
    public:
        enum {
            MG_UnknownState = 0,
            MG_IdleState = 1,
            MG_RecordingState = 2
        };

        MediaStateT();
        MediaStateT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const MediaStateT& rhs) const;
        bool operator==(const MediaStateT& rhs) const;
        bool operator< (const MediaStateT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const MediaStateT&);
    bool operator!=(int32_t value, const MediaStateT&);
    bool operator< (int32_t value, const MediaStateT&);
    std::ostream& operator<<(std::ostream& o, const MediaStateT&);


    class MediaEventReasonT {
    public:
        enum {
            ReasonMediaUnknown = 0,
            ReasonMediaEnd = 1,
            ReasonMediaOther = 2
        };

        MediaEventReasonT();
        MediaEventReasonT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const MediaEventReasonT& rhs) const;
        bool operator==(const MediaEventReasonT& rhs) const;
        bool operator< (const MediaEventReasonT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const MediaEventReasonT&);
    bool operator!=(int32_t value, const MediaEventReasonT&);
    bool operator< (int32_t value, const MediaEventReasonT&);
    std::ostream& operator<<(std::ostream& o, const MediaEventReasonT&);

    class MediaEventT {
    public:
        MediaEventT();
        ~MediaEventT();

        SessionIdT sessionid;
        CallIdT callid;
        std::string device;
        MediaEventTypeT eventType;
        MediaStateT state;
        MediaEventReasonT reason;
        std::string otherDevice;
        std::string mediaBuffer;
        int64_t timestamp;

        bool operator==(const MediaEventT& rhs) const;
        bool operator!=(const MediaEventT& rhs) const;
        bool operator< (const MediaEventT& rhs) const;
        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };


    class RouteEventTypeT {
    public:
        enum {
            RT_RouteUnknown = 0,
            RT_RouteRequest = 1,
            RT_RouteRespond = 2,
            RT_RouteRequestCancel = 3
        };

        RouteEventTypeT();
        RouteEventTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const RouteEventTypeT& rhs) const;
        bool operator==(const RouteEventTypeT& rhs) const;
        bool operator< (const RouteEventTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const RouteEventTypeT&);
    bool operator!=(int32_t value, const RouteEventTypeT&);
    bool operator< (int32_t value, const RouteEventTypeT&);
    std::ostream& operator<<(std::ostream& o, const RouteEventTypeT&);


    class RouteRequestTypeT {
    public:
        enum {
            RR_TypeUnknown = 0,
            RR_TypeSkill = 1,
            RR_TypePrivate = 2,
            RR_TypePrivateList = 3
        };

        RouteRequestTypeT();
        RouteRequestTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const RouteRequestTypeT& rhs) const;
        bool operator==(const RouteRequestTypeT& rhs) const;
        bool operator< (const RouteRequestTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const RouteRequestTypeT&);
    bool operator!=(int32_t value, const RouteRequestTypeT&);
    bool operator< (int32_t value, const RouteRequestTypeT&);
    std::ostream& operator<<(std::ostream& o, const RouteRequestTypeT&);


    class RouteEventReasonT {
    public:
        enum {
            RouteReasonSuccess = 0,
            RouteReasonBusy = 1,
            RouteReasonPrivateBusy = 2,
            RouteReasonWrongSkill = 3,
            RouteReasonNotAssigned = 4,
            RouteReasonError = 5,
            RouteReasonIVRCancel = 6,
            RouteReasonClientHangup = 7,
            RouteReasonOther = 8
        };

        RouteEventReasonT();
        RouteEventReasonT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const RouteEventReasonT& rhs) const;
        bool operator==(const RouteEventReasonT& rhs) const;
        bool operator< (const RouteEventReasonT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const RouteEventReasonT&);
    bool operator!=(int32_t value, const RouteEventReasonT&);
    bool operator< (int32_t value, const RouteEventReasonT&);
    std::ostream& operator<<(std::ostream& o, const RouteEventReasonT&);

    class RouteEventT {
    public:
        RouteEventT();
        ~RouteEventT();

        SessionIdT sessionid;
        CallIdT callid;
        std::string device;
        RouteEventTypeT eventType;
        RouteEventReasonT reason;
        RouteRequestIDT requstid;
        std::string targetDevice;
        ServiceTypeT destService;
        RouteRequestTypeT requestType;
        std::string requestArgs;
        int32_t level;
        std::string callerDn;
        std::string calleeDn;
        int32_t validtime;
        int32_t timeout;
        std::string buffer;
        int64_t timestamp;

        bool operator==(const RouteEventT& rhs) const;
        bool operator!=(const RouteEventT& rhs) const;
        bool operator< (const RouteEventT& rhs) const;
        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };


    class OtherEventTypeT {
    public:
        enum {
            OG_HeartBeat = 0,
            OG_SessionCreate = 1,
            OG_OperationFailed = 2
        };

        OtherEventTypeT();
        OtherEventTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const OtherEventTypeT& rhs) const;
        bool operator==(const OtherEventTypeT& rhs) const;
        bool operator< (const OtherEventTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const OtherEventTypeT&);
    bool operator!=(int32_t value, const OtherEventTypeT&);
    bool operator< (int32_t value, const OtherEventTypeT&);
    std::ostream& operator<<(std::ostream& o, const OtherEventTypeT&);

    class OtherEventT {
    public:
        OtherEventT();
        ~OtherEventT();

        SessionIdT sessionid;
        CallIdT callid;
        std::string device;
        OtherEventTypeT eventType;
        int64_t timestamp;
        OtherEventDataT data;

        bool operator==(const OtherEventT& rhs) const;
        bool operator!=(const OtherEventT& rhs) const;
        bool operator< (const OtherEventT& rhs) const;
        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };


    class ConfigTypeT {
    public:
        enum {
            CT_All = 0
        };

        ConfigTypeT();
        ConfigTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const ConfigTypeT& rhs) const;
        bool operator==(const ConfigTypeT& rhs) const;
        bool operator< (const ConfigTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const ConfigTypeT&);
    bool operator!=(int32_t value, const ConfigTypeT&);
    bool operator< (int32_t value, const ConfigTypeT&);
    std::ostream& operator<<(std::ostream& o, const ConfigTypeT&);


    class TransferTypeT {
    public:
        enum {
            TT_UNKONWN = 0,
            TT_INSTANT = 1,
            TT_RING = 2,
            TT_ANSWER = 3
        };

        TransferTypeT();
        TransferTypeT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const TransferTypeT& rhs) const;
        bool operator==(const TransferTypeT& rhs) const;
        bool operator< (const TransferTypeT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const TransferTypeT&);
    bool operator!=(int32_t value, const TransferTypeT&);
    bool operator< (int32_t value, const TransferTypeT&);
    std::ostream& operator<<(std::ostream& o, const TransferTypeT&);

}


#endif
