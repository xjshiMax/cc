#ifndef _BIDL2SL_IMS_H_
#define _BIDL2SL_IMS_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

#include "common.h"
namespace ims {
    class imsapi : public bgcc::Shareable {
    public:
        virtual ~imsapi() { }

        virtual CcResultT Register(
            const ServiceTypeT & type,
            ReqIdT & reqid,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT UnRegister(
            ReqIdT reqid,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Assign(
            ReqIdT reqid,
            const std::string & devicenumber,
            const DnTypeT & type,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT DeAssign(
            ReqIdT reqid,
            const std::string & devicenumber,
            const DnTypeT & type,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT OutboundCall(
            ReqIdT reqid,
            const std::string & devicenumber,
            const std::string & destUri,
            const std::string & setSrcUri,
            const std::string & setDestUri,
            int32_t timeout,
            const CallModeT & callmode,
            SessionIdT & sessionid,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Answer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Release(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Hold(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Retrieve(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Consult(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::string & destUri,
            const std::string & setDestUri,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Reconnect(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Transfer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Conference(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT SingleStepTransfer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::string & destUri,
            const std::string & dispForCalled,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT SingleStepConference(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::string & destUri,
            const std::string & dispForCalled,
            const SsConferenceTypeT & type,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT SwitchListenAndIntrude(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT SetAssociateData(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & key,
            const std::string & val,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT GetAssociateData(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & key,
            std::string & val,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT RouteRequest(
            ReqIdT reqid,
            SessionIdT sessionid,
            const ServiceTypeT & destService,
            int32_t timeout,
            int32_t valid_time,
            const RouteRequestTypeT & reqType,
            const std::string & reqArgs,
            int32_t level,
            const std::string & caller_uri,
            const std::string & callee_uri,
            const std::string & buffer,
            RouteRequestIDT & requestId,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT CancelRouteRequest(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT RouteRequestRespond(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            const RouteEventReasonT & result,
            const std::string & targetUri,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT CreateSession(
            ReqIdT reqid,
            const std::string & callsource,
            const std::string & channel_id,
            const std::string & oricalled,
            SessionIdT & sessionid,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT TransferAgent(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            const TransferTypeT & transType,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT Record(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::string & filename,
            int32_t maxTime,
            const std::string & interruptKeys,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT SendDTMF(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string & devicenumber,
            const std::string & dtmf,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT DestroySession(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT QuerySession(
            ReqIdT reqid,
            SessionIdT sessionid,
            std::string & originalAni,
            std::string & originalDnis,
            CallIdListT & callidList,
            std::vector<std::string>  & deviceList,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT QueryCall(
            ReqIdT reqid,
            SessionIdT sessionid,
            const CallIdT & callId,
            std::string & deviceAni,
            std::string & deviceDnis,
            std::string & originalAni,
            std::string & originalDnis,
            std::vector<std::string>  & deviceList,
            int32_t & fsid,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT QueryDevice(
            ReqIdT reqid,
            const std::string & device,
            SessionIdT & sessionid,
            CallIdT & callId,
            CallStateT & callstate,
            MediaStateT & mediastate,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT QuerySysInfo(
            ReqIdT reqid,
            SysInfoT & sysinfo,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT ReloadConfig(
            const ConfigTypeT & type,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT HeartBeat(
            ReqIdT reqid,
            const std::string & info,
            const std::map<std::string, std::string>& ctx) = 0;

    };

    class imsapi_Register_args {
    public:
        imsapi_Register_args();
        virtual ~imsapi_Register_args();

        ServiceTypeT type;

        bool operator==(const imsapi_Register_args& rhs) const;
        bool operator!=(const imsapi_Register_args& rhs) const;
        bool operator< (const imsapi_Register_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_UnRegister_args {
    public:
        imsapi_UnRegister_args();
        virtual ~imsapi_UnRegister_args();

        ReqIdT reqid;

        bool operator==(const imsapi_UnRegister_args& rhs) const;
        bool operator!=(const imsapi_UnRegister_args& rhs) const;
        bool operator< (const imsapi_UnRegister_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Assign_args {
    public:
        imsapi_Assign_args();
        virtual ~imsapi_Assign_args();

        ReqIdT reqid;
        std::string devicenumber;
        DnTypeT type;

        bool operator==(const imsapi_Assign_args& rhs) const;
        bool operator!=(const imsapi_Assign_args& rhs) const;
        bool operator< (const imsapi_Assign_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_DeAssign_args {
    public:
        imsapi_DeAssign_args();
        virtual ~imsapi_DeAssign_args();

        ReqIdT reqid;
        std::string devicenumber;
        DnTypeT type;

        bool operator==(const imsapi_DeAssign_args& rhs) const;
        bool operator!=(const imsapi_DeAssign_args& rhs) const;
        bool operator< (const imsapi_DeAssign_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_OutboundCall_args {
    public:
        imsapi_OutboundCall_args();
        virtual ~imsapi_OutboundCall_args();

        ReqIdT reqid;
        std::string devicenumber;
        std::string destUri;
        std::string setSrcUri;
        std::string setDestUri;
        int32_t timeout;
        CallModeT callmode;
        SessionIdT sessionid;

        bool operator==(const imsapi_OutboundCall_args& rhs) const;
        bool operator!=(const imsapi_OutboundCall_args& rhs) const;
        bool operator< (const imsapi_OutboundCall_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Answer_args {
    public:
        imsapi_Answer_args();
        virtual ~imsapi_Answer_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;

        bool operator==(const imsapi_Answer_args& rhs) const;
        bool operator!=(const imsapi_Answer_args& rhs) const;
        bool operator< (const imsapi_Answer_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Release_args {
    public:
        imsapi_Release_args();
        virtual ~imsapi_Release_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;

        bool operator==(const imsapi_Release_args& rhs) const;
        bool operator!=(const imsapi_Release_args& rhs) const;
        bool operator< (const imsapi_Release_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Hold_args {
    public:
        imsapi_Hold_args();
        virtual ~imsapi_Hold_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;

        bool operator==(const imsapi_Hold_args& rhs) const;
        bool operator!=(const imsapi_Hold_args& rhs) const;
        bool operator< (const imsapi_Hold_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Retrieve_args {
    public:
        imsapi_Retrieve_args();
        virtual ~imsapi_Retrieve_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;

        bool operator==(const imsapi_Retrieve_args& rhs) const;
        bool operator!=(const imsapi_Retrieve_args& rhs) const;
        bool operator< (const imsapi_Retrieve_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Consult_args {
    public:
        imsapi_Consult_args();
        virtual ~imsapi_Consult_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;
        std::string destUri;
        std::string setDestUri;

        bool operator==(const imsapi_Consult_args& rhs) const;
        bool operator!=(const imsapi_Consult_args& rhs) const;
        bool operator< (const imsapi_Consult_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Reconnect_args {
    public:
        imsapi_Reconnect_args();
        virtual ~imsapi_Reconnect_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;

        bool operator==(const imsapi_Reconnect_args& rhs) const;
        bool operator!=(const imsapi_Reconnect_args& rhs) const;
        bool operator< (const imsapi_Reconnect_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Transfer_args {
    public:
        imsapi_Transfer_args();
        virtual ~imsapi_Transfer_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;

        bool operator==(const imsapi_Transfer_args& rhs) const;
        bool operator!=(const imsapi_Transfer_args& rhs) const;
        bool operator< (const imsapi_Transfer_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Conference_args {
    public:
        imsapi_Conference_args();
        virtual ~imsapi_Conference_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;

        bool operator==(const imsapi_Conference_args& rhs) const;
        bool operator!=(const imsapi_Conference_args& rhs) const;
        bool operator< (const imsapi_Conference_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_SingleStepTransfer_args {
    public:
        imsapi_SingleStepTransfer_args();
        virtual ~imsapi_SingleStepTransfer_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;
        std::string destUri;
        std::string dispForCalled;

        bool operator==(const imsapi_SingleStepTransfer_args& rhs) const;
        bool operator!=(const imsapi_SingleStepTransfer_args& rhs) const;
        bool operator< (const imsapi_SingleStepTransfer_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_SingleStepConference_args {
    public:
        imsapi_SingleStepConference_args();
        virtual ~imsapi_SingleStepConference_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;
        std::string destUri;
        std::string dispForCalled;
        SsConferenceTypeT type;

        bool operator==(const imsapi_SingleStepConference_args& rhs) const;
        bool operator!=(const imsapi_SingleStepConference_args& rhs) const;
        bool operator< (const imsapi_SingleStepConference_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_SwitchListenAndIntrude_args {
    public:
        imsapi_SwitchListenAndIntrude_args();
        virtual ~imsapi_SwitchListenAndIntrude_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;

        bool operator==(const imsapi_SwitchListenAndIntrude_args& rhs) const;
        bool operator!=(const imsapi_SwitchListenAndIntrude_args& rhs) const;
        bool operator< (const imsapi_SwitchListenAndIntrude_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_SetAssociateData_args {
    public:
        imsapi_SetAssociateData_args();
        virtual ~imsapi_SetAssociateData_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string key;
        std::string val;

        bool operator==(const imsapi_SetAssociateData_args& rhs) const;
        bool operator!=(const imsapi_SetAssociateData_args& rhs) const;
        bool operator< (const imsapi_SetAssociateData_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_GetAssociateData_args {
    public:
        imsapi_GetAssociateData_args();
        virtual ~imsapi_GetAssociateData_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string key;

        bool operator==(const imsapi_GetAssociateData_args& rhs) const;
        bool operator!=(const imsapi_GetAssociateData_args& rhs) const;
        bool operator< (const imsapi_GetAssociateData_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_RouteRequest_args {
    public:
        imsapi_RouteRequest_args();
        virtual ~imsapi_RouteRequest_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        ServiceTypeT destService;
        int32_t timeout;
        int32_t valid_time;
        RouteRequestTypeT reqType;
        std::string reqArgs;
        int32_t level;
        std::string caller_uri;
        std::string callee_uri;
        std::string buffer;

        bool operator==(const imsapi_RouteRequest_args& rhs) const;
        bool operator!=(const imsapi_RouteRequest_args& rhs) const;
        bool operator< (const imsapi_RouteRequest_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_CancelRouteRequest_args {
    public:
        imsapi_CancelRouteRequest_args();
        virtual ~imsapi_CancelRouteRequest_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        RouteRequestIDT requestId;

        bool operator==(const imsapi_CancelRouteRequest_args& rhs) const;
        bool operator!=(const imsapi_CancelRouteRequest_args& rhs) const;
        bool operator< (const imsapi_CancelRouteRequest_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_RouteRequestRespond_args {
    public:
        imsapi_RouteRequestRespond_args();
        virtual ~imsapi_RouteRequestRespond_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        RouteRequestIDT requestId;
        RouteEventReasonT result;
        std::string targetUri;

        bool operator==(const imsapi_RouteRequestRespond_args& rhs) const;
        bool operator!=(const imsapi_RouteRequestRespond_args& rhs) const;
        bool operator< (const imsapi_RouteRequestRespond_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_CreateSession_args {
    public:
        imsapi_CreateSession_args();
        virtual ~imsapi_CreateSession_args();

        ReqIdT reqid;
        std::string callsource;
        std::string channel_id;
        std::string oricalled;

        bool operator==(const imsapi_CreateSession_args& rhs) const;
        bool operator!=(const imsapi_CreateSession_args& rhs) const;
        bool operator< (const imsapi_CreateSession_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_TransferAgent_args {
    public:
        imsapi_TransferAgent_args();
        virtual ~imsapi_TransferAgent_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        RouteRequestIDT requestId;
        TransferTypeT transType;

        bool operator==(const imsapi_TransferAgent_args& rhs) const;
        bool operator!=(const imsapi_TransferAgent_args& rhs) const;
        bool operator< (const imsapi_TransferAgent_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Record_args {
    public:
        imsapi_Record_args();
        virtual ~imsapi_Record_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;
        std::string filename;
        int32_t maxTime;
        std::string interruptKeys;

        bool operator==(const imsapi_Record_args& rhs) const;
        bool operator!=(const imsapi_Record_args& rhs) const;
        bool operator< (const imsapi_Record_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_SendDTMF_args {
    public:
        imsapi_SendDTMF_args();
        virtual ~imsapi_SendDTMF_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        std::string devicenumber;
        std::string dtmf;

        bool operator==(const imsapi_SendDTMF_args& rhs) const;
        bool operator!=(const imsapi_SendDTMF_args& rhs) const;
        bool operator< (const imsapi_SendDTMF_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_DestroySession_args {
    public:
        imsapi_DestroySession_args();
        virtual ~imsapi_DestroySession_args();

        ReqIdT reqid;
        SessionIdT sessionid;

        bool operator==(const imsapi_DestroySession_args& rhs) const;
        bool operator!=(const imsapi_DestroySession_args& rhs) const;
        bool operator< (const imsapi_DestroySession_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_QuerySession_args {
    public:
        imsapi_QuerySession_args();
        virtual ~imsapi_QuerySession_args();

        ReqIdT reqid;
        SessionIdT sessionid;

        bool operator==(const imsapi_QuerySession_args& rhs) const;
        bool operator!=(const imsapi_QuerySession_args& rhs) const;
        bool operator< (const imsapi_QuerySession_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_QueryCall_args {
    public:
        imsapi_QueryCall_args();
        virtual ~imsapi_QueryCall_args();

        ReqIdT reqid;
        SessionIdT sessionid;
        CallIdT callId;

        bool operator==(const imsapi_QueryCall_args& rhs) const;
        bool operator!=(const imsapi_QueryCall_args& rhs) const;
        bool operator< (const imsapi_QueryCall_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_QueryDevice_args {
    public:
        imsapi_QueryDevice_args();
        virtual ~imsapi_QueryDevice_args();

        ReqIdT reqid;
        std::string device;

        bool operator==(const imsapi_QueryDevice_args& rhs) const;
        bool operator!=(const imsapi_QueryDevice_args& rhs) const;
        bool operator< (const imsapi_QueryDevice_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_QuerySysInfo_args {
    public:
        imsapi_QuerySysInfo_args();
        virtual ~imsapi_QuerySysInfo_args();

        ReqIdT reqid;

        bool operator==(const imsapi_QuerySysInfo_args& rhs) const;
        bool operator!=(const imsapi_QuerySysInfo_args& rhs) const;
        bool operator< (const imsapi_QuerySysInfo_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_ReloadConfig_args {
    public:
        imsapi_ReloadConfig_args();
        virtual ~imsapi_ReloadConfig_args();

        ConfigTypeT type;

        bool operator==(const imsapi_ReloadConfig_args& rhs) const;
        bool operator!=(const imsapi_ReloadConfig_args& rhs) const;
        bool operator< (const imsapi_ReloadConfig_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_HeartBeat_args {
    public:
        imsapi_HeartBeat_args();
        virtual ~imsapi_HeartBeat_args();

        ReqIdT reqid;
        std::string info;

        bool operator==(const imsapi_HeartBeat_args& rhs) const;
        bool operator!=(const imsapi_HeartBeat_args& rhs) const;
        bool operator< (const imsapi_HeartBeat_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class imsapi_Register_pargs {
    public:
        virtual ~imsapi_Register_pargs();

        const ServiceTypeT* type;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_UnRegister_pargs {
    public:
        virtual ~imsapi_UnRegister_pargs();

        const ReqIdT* reqid;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Assign_pargs {
    public:
        virtual ~imsapi_Assign_pargs();

        const ReqIdT* reqid;
        const std::string* devicenumber;
        const DnTypeT* type;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_DeAssign_pargs {
    public:
        virtual ~imsapi_DeAssign_pargs();

        const ReqIdT* reqid;
        const std::string* devicenumber;
        const DnTypeT* type;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_OutboundCall_pargs {
    public:
        virtual ~imsapi_OutboundCall_pargs();

        const ReqIdT* reqid;
        const std::string* devicenumber;
        const std::string* destUri;
        const std::string* setSrcUri;
        const std::string* setDestUri;
        const int32_t* timeout;
        const CallModeT* callmode;
        const SessionIdT* sessionid;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Answer_pargs {
    public:
        virtual ~imsapi_Answer_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Release_pargs {
    public:
        virtual ~imsapi_Release_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Hold_pargs {
    public:
        virtual ~imsapi_Hold_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Retrieve_pargs {
    public:
        virtual ~imsapi_Retrieve_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Consult_pargs {
    public:
        virtual ~imsapi_Consult_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;
        const std::string* destUri;
        const std::string* setDestUri;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Reconnect_pargs {
    public:
        virtual ~imsapi_Reconnect_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Transfer_pargs {
    public:
        virtual ~imsapi_Transfer_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Conference_pargs {
    public:
        virtual ~imsapi_Conference_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SingleStepTransfer_pargs {
    public:
        virtual ~imsapi_SingleStepTransfer_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;
        const std::string* destUri;
        const std::string* dispForCalled;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SingleStepConference_pargs {
    public:
        virtual ~imsapi_SingleStepConference_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;
        const std::string* destUri;
        const std::string* dispForCalled;
        const SsConferenceTypeT* type;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SwitchListenAndIntrude_pargs {
    public:
        virtual ~imsapi_SwitchListenAndIntrude_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SetAssociateData_pargs {
    public:
        virtual ~imsapi_SetAssociateData_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* key;
        const std::string* val;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_GetAssociateData_pargs {
    public:
        virtual ~imsapi_GetAssociateData_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* key;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_RouteRequest_pargs {
    public:
        virtual ~imsapi_RouteRequest_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const ServiceTypeT* destService;
        const int32_t* timeout;
        const int32_t* valid_time;
        const RouteRequestTypeT* reqType;
        const std::string* reqArgs;
        const int32_t* level;
        const std::string* caller_uri;
        const std::string* callee_uri;
        const std::string* buffer;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_CancelRouteRequest_pargs {
    public:
        virtual ~imsapi_CancelRouteRequest_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const RouteRequestIDT* requestId;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_RouteRequestRespond_pargs {
    public:
        virtual ~imsapi_RouteRequestRespond_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const RouteRequestIDT* requestId;
        const RouteEventReasonT* result;
        const std::string* targetUri;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_CreateSession_pargs {
    public:
        virtual ~imsapi_CreateSession_pargs();

        const ReqIdT* reqid;
        const std::string* callsource;
        const std::string* channel_id;
        const std::string* oricalled;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_TransferAgent_pargs {
    public:
        virtual ~imsapi_TransferAgent_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const RouteRequestIDT* requestId;
        const TransferTypeT* transType;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Record_pargs {
    public:
        virtual ~imsapi_Record_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;
        const std::string* filename;
        const int32_t* maxTime;
        const std::string* interruptKeys;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SendDTMF_pargs {
    public:
        virtual ~imsapi_SendDTMF_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const std::string* devicenumber;
        const std::string* dtmf;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_DestroySession_pargs {
    public:
        virtual ~imsapi_DestroySession_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QuerySession_pargs {
    public:
        virtual ~imsapi_QuerySession_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QueryCall_pargs {
    public:
        virtual ~imsapi_QueryCall_pargs();

        const ReqIdT* reqid;
        const SessionIdT* sessionid;
        const CallIdT* callId;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QueryDevice_pargs {
    public:
        virtual ~imsapi_QueryDevice_pargs();

        const ReqIdT* reqid;
        const std::string* device;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QuerySysInfo_pargs {
    public:
        virtual ~imsapi_QuerySysInfo_pargs();

        const ReqIdT* reqid;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_ReloadConfig_pargs {
    public:
        virtual ~imsapi_ReloadConfig_pargs();

        const ConfigTypeT* type;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_HeartBeat_pargs {
    public:
        virtual ~imsapi_HeartBeat_pargs();

        const ReqIdT* reqid;
        const std::string* info;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Register_result {
    public:
        imsapi_Register_result();
        virtual ~imsapi_Register_result();

        CcResultT return_value;
        ReqIdT reqid;

        bool operator==(const imsapi_Register_result& rhs) const;
        bool operator!=(const imsapi_Register_result& rhs) const;
        bool operator< (const imsapi_Register_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_UnRegister_result {
    public:
        imsapi_UnRegister_result();
        virtual ~imsapi_UnRegister_result();

        CcResultT return_value;

        bool operator==(const imsapi_UnRegister_result& rhs) const;
        bool operator!=(const imsapi_UnRegister_result& rhs) const;
        bool operator< (const imsapi_UnRegister_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Assign_result {
    public:
        imsapi_Assign_result();
        virtual ~imsapi_Assign_result();

        CcResultT return_value;

        bool operator==(const imsapi_Assign_result& rhs) const;
        bool operator!=(const imsapi_Assign_result& rhs) const;
        bool operator< (const imsapi_Assign_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_DeAssign_result {
    public:
        imsapi_DeAssign_result();
        virtual ~imsapi_DeAssign_result();

        CcResultT return_value;

        bool operator==(const imsapi_DeAssign_result& rhs) const;
        bool operator!=(const imsapi_DeAssign_result& rhs) const;
        bool operator< (const imsapi_DeAssign_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_OutboundCall_result {
    public:
        imsapi_OutboundCall_result();
        virtual ~imsapi_OutboundCall_result();

        CcResultT return_value;
        SessionIdT sessionid;

        bool operator==(const imsapi_OutboundCall_result& rhs) const;
        bool operator!=(const imsapi_OutboundCall_result& rhs) const;
        bool operator< (const imsapi_OutboundCall_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Answer_result {
    public:
        imsapi_Answer_result();
        virtual ~imsapi_Answer_result();

        CcResultT return_value;

        bool operator==(const imsapi_Answer_result& rhs) const;
        bool operator!=(const imsapi_Answer_result& rhs) const;
        bool operator< (const imsapi_Answer_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Release_result {
    public:
        imsapi_Release_result();
        virtual ~imsapi_Release_result();

        CcResultT return_value;

        bool operator==(const imsapi_Release_result& rhs) const;
        bool operator!=(const imsapi_Release_result& rhs) const;
        bool operator< (const imsapi_Release_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Hold_result {
    public:
        imsapi_Hold_result();
        virtual ~imsapi_Hold_result();

        CcResultT return_value;

        bool operator==(const imsapi_Hold_result& rhs) const;
        bool operator!=(const imsapi_Hold_result& rhs) const;
        bool operator< (const imsapi_Hold_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Retrieve_result {
    public:
        imsapi_Retrieve_result();
        virtual ~imsapi_Retrieve_result();

        CcResultT return_value;

        bool operator==(const imsapi_Retrieve_result& rhs) const;
        bool operator!=(const imsapi_Retrieve_result& rhs) const;
        bool operator< (const imsapi_Retrieve_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Consult_result {
    public:
        imsapi_Consult_result();
        virtual ~imsapi_Consult_result();

        CcResultT return_value;

        bool operator==(const imsapi_Consult_result& rhs) const;
        bool operator!=(const imsapi_Consult_result& rhs) const;
        bool operator< (const imsapi_Consult_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Reconnect_result {
    public:
        imsapi_Reconnect_result();
        virtual ~imsapi_Reconnect_result();

        CcResultT return_value;

        bool operator==(const imsapi_Reconnect_result& rhs) const;
        bool operator!=(const imsapi_Reconnect_result& rhs) const;
        bool operator< (const imsapi_Reconnect_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Transfer_result {
    public:
        imsapi_Transfer_result();
        virtual ~imsapi_Transfer_result();

        CcResultT return_value;

        bool operator==(const imsapi_Transfer_result& rhs) const;
        bool operator!=(const imsapi_Transfer_result& rhs) const;
        bool operator< (const imsapi_Transfer_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Conference_result {
    public:
        imsapi_Conference_result();
        virtual ~imsapi_Conference_result();

        CcResultT return_value;

        bool operator==(const imsapi_Conference_result& rhs) const;
        bool operator!=(const imsapi_Conference_result& rhs) const;
        bool operator< (const imsapi_Conference_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SingleStepTransfer_result {
    public:
        imsapi_SingleStepTransfer_result();
        virtual ~imsapi_SingleStepTransfer_result();

        CcResultT return_value;

        bool operator==(const imsapi_SingleStepTransfer_result& rhs) const;
        bool operator!=(const imsapi_SingleStepTransfer_result& rhs) const;
        bool operator< (const imsapi_SingleStepTransfer_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SingleStepConference_result {
    public:
        imsapi_SingleStepConference_result();
        virtual ~imsapi_SingleStepConference_result();

        CcResultT return_value;

        bool operator==(const imsapi_SingleStepConference_result& rhs) const;
        bool operator!=(const imsapi_SingleStepConference_result& rhs) const;
        bool operator< (const imsapi_SingleStepConference_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SwitchListenAndIntrude_result {
    public:
        imsapi_SwitchListenAndIntrude_result();
        virtual ~imsapi_SwitchListenAndIntrude_result();

        CcResultT return_value;

        bool operator==(const imsapi_SwitchListenAndIntrude_result& rhs) const;
        bool operator!=(const imsapi_SwitchListenAndIntrude_result& rhs) const;
        bool operator< (const imsapi_SwitchListenAndIntrude_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SetAssociateData_result {
    public:
        imsapi_SetAssociateData_result();
        virtual ~imsapi_SetAssociateData_result();

        CcResultT return_value;

        bool operator==(const imsapi_SetAssociateData_result& rhs) const;
        bool operator!=(const imsapi_SetAssociateData_result& rhs) const;
        bool operator< (const imsapi_SetAssociateData_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_GetAssociateData_result {
    public:
        imsapi_GetAssociateData_result();
        virtual ~imsapi_GetAssociateData_result();

        CcResultT return_value;
        std::string val;

        bool operator==(const imsapi_GetAssociateData_result& rhs) const;
        bool operator!=(const imsapi_GetAssociateData_result& rhs) const;
        bool operator< (const imsapi_GetAssociateData_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_RouteRequest_result {
    public:
        imsapi_RouteRequest_result();
        virtual ~imsapi_RouteRequest_result();

        CcResultT return_value;
        RouteRequestIDT requestId;

        bool operator==(const imsapi_RouteRequest_result& rhs) const;
        bool operator!=(const imsapi_RouteRequest_result& rhs) const;
        bool operator< (const imsapi_RouteRequest_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_CancelRouteRequest_result {
    public:
        imsapi_CancelRouteRequest_result();
        virtual ~imsapi_CancelRouteRequest_result();

        CcResultT return_value;

        bool operator==(const imsapi_CancelRouteRequest_result& rhs) const;
        bool operator!=(const imsapi_CancelRouteRequest_result& rhs) const;
        bool operator< (const imsapi_CancelRouteRequest_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_RouteRequestRespond_result {
    public:
        imsapi_RouteRequestRespond_result();
        virtual ~imsapi_RouteRequestRespond_result();

        CcResultT return_value;

        bool operator==(const imsapi_RouteRequestRespond_result& rhs) const;
        bool operator!=(const imsapi_RouteRequestRespond_result& rhs) const;
        bool operator< (const imsapi_RouteRequestRespond_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_CreateSession_result {
    public:
        imsapi_CreateSession_result();
        virtual ~imsapi_CreateSession_result();

        CcResultT return_value;
        SessionIdT sessionid;

        bool operator==(const imsapi_CreateSession_result& rhs) const;
        bool operator!=(const imsapi_CreateSession_result& rhs) const;
        bool operator< (const imsapi_CreateSession_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_TransferAgent_result {
    public:
        imsapi_TransferAgent_result();
        virtual ~imsapi_TransferAgent_result();

        CcResultT return_value;

        bool operator==(const imsapi_TransferAgent_result& rhs) const;
        bool operator!=(const imsapi_TransferAgent_result& rhs) const;
        bool operator< (const imsapi_TransferAgent_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Record_result {
    public:
        imsapi_Record_result();
        virtual ~imsapi_Record_result();

        CcResultT return_value;

        bool operator==(const imsapi_Record_result& rhs) const;
        bool operator!=(const imsapi_Record_result& rhs) const;
        bool operator< (const imsapi_Record_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SendDTMF_result {
    public:
        imsapi_SendDTMF_result();
        virtual ~imsapi_SendDTMF_result();

        CcResultT return_value;

        bool operator==(const imsapi_SendDTMF_result& rhs) const;
        bool operator!=(const imsapi_SendDTMF_result& rhs) const;
        bool operator< (const imsapi_SendDTMF_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_DestroySession_result {
    public:
        imsapi_DestroySession_result();
        virtual ~imsapi_DestroySession_result();

        CcResultT return_value;

        bool operator==(const imsapi_DestroySession_result& rhs) const;
        bool operator!=(const imsapi_DestroySession_result& rhs) const;
        bool operator< (const imsapi_DestroySession_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QuerySession_result {
    public:
        imsapi_QuerySession_result();
        virtual ~imsapi_QuerySession_result();

        CcResultT return_value;
        std::string originalAni;
        std::string originalDnis;
        CallIdListT callidList;
        std::vector<std::string>  deviceList;

        bool operator==(const imsapi_QuerySession_result& rhs) const;
        bool operator!=(const imsapi_QuerySession_result& rhs) const;
        bool operator< (const imsapi_QuerySession_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QueryCall_result {
    public:
        imsapi_QueryCall_result();
        virtual ~imsapi_QueryCall_result();

        CcResultT return_value;
        std::string deviceAni;
        std::string deviceDnis;
        std::string originalAni;
        std::string originalDnis;
        std::vector<std::string>  deviceList;
        int32_t fsid;

        bool operator==(const imsapi_QueryCall_result& rhs) const;
        bool operator!=(const imsapi_QueryCall_result& rhs) const;
        bool operator< (const imsapi_QueryCall_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QueryDevice_result {
    public:
        imsapi_QueryDevice_result();
        virtual ~imsapi_QueryDevice_result();

        CcResultT return_value;
        SessionIdT sessionid;
        CallIdT callId;
        CallStateT callstate;
        MediaStateT mediastate;

        bool operator==(const imsapi_QueryDevice_result& rhs) const;
        bool operator!=(const imsapi_QueryDevice_result& rhs) const;
        bool operator< (const imsapi_QueryDevice_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QuerySysInfo_result {
    public:
        imsapi_QuerySysInfo_result();
        virtual ~imsapi_QuerySysInfo_result();

        CcResultT return_value;
        SysInfoT sysinfo;

        bool operator==(const imsapi_QuerySysInfo_result& rhs) const;
        bool operator!=(const imsapi_QuerySysInfo_result& rhs) const;
        bool operator< (const imsapi_QuerySysInfo_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_ReloadConfig_result {
    public:
        imsapi_ReloadConfig_result();
        virtual ~imsapi_ReloadConfig_result();

        CcResultT return_value;

        bool operator==(const imsapi_ReloadConfig_result& rhs) const;
        bool operator!=(const imsapi_ReloadConfig_result& rhs) const;
        bool operator< (const imsapi_ReloadConfig_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_HeartBeat_result {
    public:
        imsapi_HeartBeat_result();
        virtual ~imsapi_HeartBeat_result();

        CcResultT return_value;

        bool operator==(const imsapi_HeartBeat_result& rhs) const;
        bool operator!=(const imsapi_HeartBeat_result& rhs) const;
        bool operator< (const imsapi_HeartBeat_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Register_presult {
    public:
        virtual ~imsapi_Register_presult();

        CcResultT* return_value;
        ReqIdT* reqid;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_UnRegister_presult {
    public:
        virtual ~imsapi_UnRegister_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Assign_presult {
    public:
        virtual ~imsapi_Assign_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_DeAssign_presult {
    public:
        virtual ~imsapi_DeAssign_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_OutboundCall_presult {
    public:
        virtual ~imsapi_OutboundCall_presult();

        CcResultT* return_value;
        SessionIdT* sessionid;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Answer_presult {
    public:
        virtual ~imsapi_Answer_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Release_presult {
    public:
        virtual ~imsapi_Release_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Hold_presult {
    public:
        virtual ~imsapi_Hold_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Retrieve_presult {
    public:
        virtual ~imsapi_Retrieve_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Consult_presult {
    public:
        virtual ~imsapi_Consult_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Reconnect_presult {
    public:
        virtual ~imsapi_Reconnect_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Transfer_presult {
    public:
        virtual ~imsapi_Transfer_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Conference_presult {
    public:
        virtual ~imsapi_Conference_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SingleStepTransfer_presult {
    public:
        virtual ~imsapi_SingleStepTransfer_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SingleStepConference_presult {
    public:
        virtual ~imsapi_SingleStepConference_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SwitchListenAndIntrude_presult {
    public:
        virtual ~imsapi_SwitchListenAndIntrude_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SetAssociateData_presult {
    public:
        virtual ~imsapi_SetAssociateData_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_GetAssociateData_presult {
    public:
        virtual ~imsapi_GetAssociateData_presult();

        CcResultT* return_value;
        std::string* val;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_RouteRequest_presult {
    public:
        virtual ~imsapi_RouteRequest_presult();

        CcResultT* return_value;
        RouteRequestIDT* requestId;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_CancelRouteRequest_presult {
    public:
        virtual ~imsapi_CancelRouteRequest_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_RouteRequestRespond_presult {
    public:
        virtual ~imsapi_RouteRequestRespond_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_CreateSession_presult {
    public:
        virtual ~imsapi_CreateSession_presult();

        CcResultT* return_value;
        SessionIdT* sessionid;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_TransferAgent_presult {
    public:
        virtual ~imsapi_TransferAgent_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_Record_presult {
    public:
        virtual ~imsapi_Record_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_SendDTMF_presult {
    public:
        virtual ~imsapi_SendDTMF_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_DestroySession_presult {
    public:
        virtual ~imsapi_DestroySession_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QuerySession_presult {
    public:
        virtual ~imsapi_QuerySession_presult();

        CcResultT* return_value;
        std::string* originalAni;
        std::string* originalDnis;
        CallIdListT* callidList;
        std::vector<std::string> * deviceList;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QueryCall_presult {
    public:
        virtual ~imsapi_QueryCall_presult();

        CcResultT* return_value;
        std::string* deviceAni;
        std::string* deviceDnis;
        std::string* originalAni;
        std::string* originalDnis;
        std::vector<std::string> * deviceList;
        int32_t* fsid;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QueryDevice_presult {
    public:
        virtual ~imsapi_QueryDevice_presult();

        CcResultT* return_value;
        SessionIdT* sessionid;
        CallIdT* callId;
        CallStateT* callstate;
        MediaStateT* mediastate;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_QuerySysInfo_presult {
    public:
        virtual ~imsapi_QuerySysInfo_presult();

        CcResultT* return_value;
        SysInfoT* sysinfo;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_ReloadConfig_presult {
    public:
        virtual ~imsapi_ReloadConfig_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapi_HeartBeat_presult {
    public:
        virtual ~imsapi_HeartBeat_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class imsapiProxy : public bgcc::BaseProxy {
    public:
        imsapiProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        imsapiProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        imsapiProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CcResultT Register(
            const ServiceTypeT& type,
            ReqIdT& reqid,
            bool last = false);

        CcResultT UnRegister(
            ReqIdT reqid,
            bool last = false);

        CcResultT Assign(
            ReqIdT reqid,
            const std::string& devicenumber,
            const DnTypeT& type,
            bool last = false);

        CcResultT DeAssign(
            ReqIdT reqid,
            const std::string& devicenumber,
            const DnTypeT& type,
            bool last = false);

        CcResultT OutboundCall(
            ReqIdT reqid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& setSrcUri,
            const std::string& setDestUri,
            int32_t timeout,
            const CallModeT& callmode,
            SessionIdT& sessionid,
            bool last = false);

        CcResultT Answer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Release(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Hold(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Retrieve(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Consult(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& setDestUri,
            bool last = false);

        CcResultT Reconnect(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Transfer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Conference(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT SingleStepTransfer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& dispForCalled,
            bool last = false);

        CcResultT SingleStepConference(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& dispForCalled,
            const SsConferenceTypeT& type,
            bool last = false);

        CcResultT SwitchListenAndIntrude(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT SetAssociateData(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& key,
            const std::string& val,
            bool last = false);

        CcResultT GetAssociateData(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& key,
            std::string& val,
            bool last = false);

        CcResultT RouteRequest(
            ReqIdT reqid,
            SessionIdT sessionid,
            const ServiceTypeT& destService,
            int32_t timeout,
            int32_t valid_time,
            const RouteRequestTypeT& reqType,
            const std::string& reqArgs,
            int32_t level,
            const std::string& caller_uri,
            const std::string& callee_uri,
            const std::string& buffer,
            RouteRequestIDT& requestId,
            bool last = false);

        CcResultT CancelRouteRequest(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            bool last = false);

        CcResultT RouteRequestRespond(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            const RouteEventReasonT& result,
            const std::string& targetUri,
            bool last = false);

        CcResultT CreateSession(
            ReqIdT reqid,
            const std::string& callsource,
            const std::string& channel_id,
            const std::string& oricalled,
            SessionIdT& sessionid,
            bool last = false);

        CcResultT TransferAgent(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            const TransferTypeT& transType,
            bool last = false);

        CcResultT Record(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& filename,
            int32_t maxTime,
            const std::string& interruptKeys,
            bool last = false);

        CcResultT SendDTMF(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& dtmf,
            bool last = false);

        CcResultT DestroySession(
            ReqIdT reqid,
            SessionIdT sessionid,
            bool last = false);

        CcResultT QuerySession(
            ReqIdT reqid,
            SessionIdT sessionid,
            std::string& originalAni,
            std::string& originalDnis,
            CallIdListT& callidList,
            std::vector<std::string> & deviceList,
            bool last = false);

        CcResultT QueryCall(
            ReqIdT reqid,
            SessionIdT sessionid,
            const CallIdT& callId,
            std::string& deviceAni,
            std::string& deviceDnis,
            std::string& originalAni,
            std::string& originalDnis,
            std::vector<std::string> & deviceList,
            int32_t& fsid,
            bool last = false);

        CcResultT QueryDevice(
            ReqIdT reqid,
            const std::string& device,
            SessionIdT& sessionid,
            CallIdT& callId,
            CallStateT& callstate,
            MediaStateT& mediastate,
            bool last = false);

        CcResultT QuerySysInfo(
            ReqIdT reqid,
            SysInfoT& sysinfo,
            bool last = false);

        CcResultT ReloadConfig(
            const ConfigTypeT& type,
            bool last = false);

        CcResultT HeartBeat(
            ReqIdT reqid,
            const std::string& info,
            bool last = false);

    private:
        void send_Register(
            const ServiceTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Register(
            ReqIdT& reqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_UnRegister(
            const ReqIdT& reqid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_UnRegister(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Assign(
            const ReqIdT& reqid,
            const std::string& devicenumber,
            const DnTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Assign(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_DeAssign(
            const ReqIdT& reqid,
            const std::string& devicenumber,
            const DnTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_DeAssign(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_OutboundCall(
            const ReqIdT& reqid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& setSrcUri,
            const std::string& setDestUri,
            const int32_t& timeout,
            const CallModeT& callmode,
            const SessionIdT& sessionid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_OutboundCall(
            SessionIdT& sessionid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Answer(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Answer(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Release(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Release(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Hold(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Hold(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Retrieve(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Retrieve(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Consult(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& setDestUri,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Consult(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Reconnect(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Reconnect(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Transfer(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Transfer(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Conference(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Conference(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SingleStepTransfer(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& dispForCalled,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SingleStepTransfer(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SingleStepConference(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& dispForCalled,
            const SsConferenceTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SingleStepConference(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SwitchListenAndIntrude(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SwitchListenAndIntrude(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SetAssociateData(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& key,
            const std::string& val,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SetAssociateData(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_GetAssociateData(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& key,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_GetAssociateData(
            std::string& val,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_RouteRequest(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const ServiceTypeT& destService,
            const int32_t& timeout,
            const int32_t& valid_time,
            const RouteRequestTypeT& reqType,
            const std::string& reqArgs,
            const int32_t& level,
            const std::string& caller_uri,
            const std::string& callee_uri,
            const std::string& buffer,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_RouteRequest(
            RouteRequestIDT& requestId,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_CancelRouteRequest(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const RouteRequestIDT& requestId,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_CancelRouteRequest(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_RouteRequestRespond(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const RouteRequestIDT& requestId,
            const RouteEventReasonT& result,
            const std::string& targetUri,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_RouteRequestRespond(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_CreateSession(
            const ReqIdT& reqid,
            const std::string& callsource,
            const std::string& channel_id,
            const std::string& oricalled,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_CreateSession(
            SessionIdT& sessionid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_TransferAgent(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const RouteRequestIDT& requestId,
            const TransferTypeT& transType,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_TransferAgent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Record(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& filename,
            const int32_t& maxTime,
            const std::string& interruptKeys,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Record(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SendDTMF(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& dtmf,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendDTMF(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_DestroySession(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_DestroySession(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_QuerySession(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_QuerySession(
            std::string& originalAni,
            std::string& originalDnis,
            CallIdListT& callidList,
            std::vector<std::string> & deviceList,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_QueryCall(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const CallIdT& callId,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_QueryCall(
            std::string& deviceAni,
            std::string& deviceDnis,
            std::string& originalAni,
            std::string& originalDnis,
            std::vector<std::string> & deviceList,
            int32_t& fsid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_QueryDevice(
            const ReqIdT& reqid,
            const std::string& device,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_QueryDevice(
            SessionIdT& sessionid,
            CallIdT& callId,
            CallStateT& callstate,
            MediaStateT& mediastate,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_QuerySysInfo(
            const ReqIdT& reqid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_QuerySysInfo(
            SysInfoT& sysinfo,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_ReloadConfig(
            const ConfigTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_ReloadConfig(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_HeartBeat(
            const ReqIdT& reqid,
            const std::string& info,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_HeartBeat(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class SSLimsapiProxy : public bgcc::SSLBaseProxy {
    public:
        SSLimsapiProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLimsapiProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLimsapiProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CcResultT Register(
            const ServiceTypeT& type,
            ReqIdT& reqid,
            bool last = false);

        CcResultT UnRegister(
            ReqIdT reqid,
            bool last = false);

        CcResultT Assign(
            ReqIdT reqid,
            const std::string& devicenumber,
            const DnTypeT& type,
            bool last = false);

        CcResultT DeAssign(
            ReqIdT reqid,
            const std::string& devicenumber,
            const DnTypeT& type,
            bool last = false);

        CcResultT OutboundCall(
            ReqIdT reqid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& setSrcUri,
            const std::string& setDestUri,
            int32_t timeout,
            const CallModeT& callmode,
            SessionIdT& sessionid,
            bool last = false);

        CcResultT Answer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Release(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Hold(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Retrieve(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Consult(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& setDestUri,
            bool last = false);

        CcResultT Reconnect(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Transfer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT Conference(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT SingleStepTransfer(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& dispForCalled,
            bool last = false);

        CcResultT SingleStepConference(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& dispForCalled,
            const SsConferenceTypeT& type,
            bool last = false);

        CcResultT SwitchListenAndIntrude(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            bool last = false);

        CcResultT SetAssociateData(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& key,
            const std::string& val,
            bool last = false);

        CcResultT GetAssociateData(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& key,
            std::string& val,
            bool last = false);

        CcResultT RouteRequest(
            ReqIdT reqid,
            SessionIdT sessionid,
            const ServiceTypeT& destService,
            int32_t timeout,
            int32_t valid_time,
            const RouteRequestTypeT& reqType,
            const std::string& reqArgs,
            int32_t level,
            const std::string& caller_uri,
            const std::string& callee_uri,
            const std::string& buffer,
            RouteRequestIDT& requestId,
            bool last = false);

        CcResultT CancelRouteRequest(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            bool last = false);

        CcResultT RouteRequestRespond(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            const RouteEventReasonT& result,
            const std::string& targetUri,
            bool last = false);

        CcResultT CreateSession(
            ReqIdT reqid,
            const std::string& callsource,
            const std::string& channel_id,
            const std::string& oricalled,
            SessionIdT& sessionid,
            bool last = false);

        CcResultT TransferAgent(
            ReqIdT reqid,
            SessionIdT sessionid,
            RouteRequestIDT requestId,
            const TransferTypeT& transType,
            bool last = false);

        CcResultT Record(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& filename,
            int32_t maxTime,
            const std::string& interruptKeys,
            bool last = false);

        CcResultT SendDTMF(
            ReqIdT reqid,
            SessionIdT sessionid,
            const std::string& devicenumber,
            const std::string& dtmf,
            bool last = false);

        CcResultT DestroySession(
            ReqIdT reqid,
            SessionIdT sessionid,
            bool last = false);

        CcResultT QuerySession(
            ReqIdT reqid,
            SessionIdT sessionid,
            std::string& originalAni,
            std::string& originalDnis,
            CallIdListT& callidList,
            std::vector<std::string> & deviceList,
            bool last = false);

        CcResultT QueryCall(
            ReqIdT reqid,
            SessionIdT sessionid,
            const CallIdT& callId,
            std::string& deviceAni,
            std::string& deviceDnis,
            std::string& originalAni,
            std::string& originalDnis,
            std::vector<std::string> & deviceList,
            int32_t& fsid,
            bool last = false);

        CcResultT QueryDevice(
            ReqIdT reqid,
            const std::string& device,
            SessionIdT& sessionid,
            CallIdT& callId,
            CallStateT& callstate,
            MediaStateT& mediastate,
            bool last = false);

        CcResultT QuerySysInfo(
            ReqIdT reqid,
            SysInfoT& sysinfo,
            bool last = false);

        CcResultT ReloadConfig(
            const ConfigTypeT& type,
            bool last = false);

        CcResultT HeartBeat(
            ReqIdT reqid,
            const std::string& info,
            bool last = false);

    private:
        void send_Register(
            const ServiceTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Register(
            ReqIdT& reqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_UnRegister(
            const ReqIdT& reqid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_UnRegister(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Assign(
            const ReqIdT& reqid,
            const std::string& devicenumber,
            const DnTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Assign(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_DeAssign(
            const ReqIdT& reqid,
            const std::string& devicenumber,
            const DnTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_DeAssign(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_OutboundCall(
            const ReqIdT& reqid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& setSrcUri,
            const std::string& setDestUri,
            const int32_t& timeout,
            const CallModeT& callmode,
            const SessionIdT& sessionid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_OutboundCall(
            SessionIdT& sessionid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Answer(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Answer(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Release(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Release(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Hold(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Hold(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Retrieve(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Retrieve(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Consult(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& setDestUri,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Consult(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Reconnect(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Reconnect(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Transfer(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Transfer(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Conference(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Conference(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SingleStepTransfer(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& dispForCalled,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SingleStepTransfer(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SingleStepConference(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& destUri,
            const std::string& dispForCalled,
            const SsConferenceTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SingleStepConference(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SwitchListenAndIntrude(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SwitchListenAndIntrude(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SetAssociateData(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& key,
            const std::string& val,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SetAssociateData(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_GetAssociateData(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& key,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_GetAssociateData(
            std::string& val,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_RouteRequest(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const ServiceTypeT& destService,
            const int32_t& timeout,
            const int32_t& valid_time,
            const RouteRequestTypeT& reqType,
            const std::string& reqArgs,
            const int32_t& level,
            const std::string& caller_uri,
            const std::string& callee_uri,
            const std::string& buffer,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_RouteRequest(
            RouteRequestIDT& requestId,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_CancelRouteRequest(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const RouteRequestIDT& requestId,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_CancelRouteRequest(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_RouteRequestRespond(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const RouteRequestIDT& requestId,
            const RouteEventReasonT& result,
            const std::string& targetUri,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_RouteRequestRespond(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_CreateSession(
            const ReqIdT& reqid,
            const std::string& callsource,
            const std::string& channel_id,
            const std::string& oricalled,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_CreateSession(
            SessionIdT& sessionid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_TransferAgent(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const RouteRequestIDT& requestId,
            const TransferTypeT& transType,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_TransferAgent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Record(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& filename,
            const int32_t& maxTime,
            const std::string& interruptKeys,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_Record(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SendDTMF(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const std::string& devicenumber,
            const std::string& dtmf,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendDTMF(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_DestroySession(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_DestroySession(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_QuerySession(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_QuerySession(
            std::string& originalAni,
            std::string& originalDnis,
            CallIdListT& callidList,
            std::vector<std::string> & deviceList,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_QueryCall(
            const ReqIdT& reqid,
            const SessionIdT& sessionid,
            const CallIdT& callId,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_QueryCall(
            std::string& deviceAni,
            std::string& deviceDnis,
            std::string& originalAni,
            std::string& originalDnis,
            std::vector<std::string> & deviceList,
            int32_t& fsid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_QueryDevice(
            const ReqIdT& reqid,
            const std::string& device,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_QueryDevice(
            SessionIdT& sessionid,
            CallIdT& callId,
            CallStateT& callstate,
            MediaStateT& mediastate,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_QuerySysInfo(
            const ReqIdT& reqid,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_QuerySysInfo(
            SysInfoT& sysinfo,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_ReloadConfig(
            const ConfigTypeT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_ReloadConfig(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_HeartBeat(
            const ReqIdT& reqid,
            const std::string& info,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_HeartBeat(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class imsapiProcessor : public bgcc::BaseProcessor {
    public:
        imsapiProcessor(bgcc::SharedPointer<imsapi> intf);

        virtual ~imsapiProcessor(){ }

        virtual int32_t process(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        virtual std::string get_name() const;

    protected:
        virtual int32_t do_function__(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            const std::string& fname, int32_t seqid);

        bgcc::SharedPointer<imsapi> __intf;

    private:
        int32_t do_Register(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_UnRegister(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Assign(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_DeAssign(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_OutboundCall(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Answer(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Release(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Hold(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Retrieve(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Consult(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Reconnect(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Transfer(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Conference(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_SingleStepTransfer(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_SingleStepConference(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_SwitchListenAndIntrude(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_SetAssociateData(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_GetAssociateData(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_RouteRequest(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_CancelRouteRequest(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_RouteRequestRespond(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_CreateSession(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_TransferAgent(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Record(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_SendDTMF(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_DestroySession(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_QuerySession(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_QueryCall(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_QueryDevice(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_QuerySysInfo(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_ReloadConfig(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_HeartBeat(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        typedef int32_t (imsapiProcessor::* do_function_ptr)(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        std::map<std::string, do_function_ptr> __fun_map;
    };
}


#endif
