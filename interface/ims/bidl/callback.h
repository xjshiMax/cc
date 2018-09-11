#ifndef _BIDL2SL_CALLBACK_H_
#define _BIDL2SL_CALLBACK_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

#include "common.h"
namespace ims {
    class event_callback : public bgcc::Shareable {
    public:
        virtual ~event_callback() { }

        virtual CcResultT SendCallEvent(
            const CallEventT & event,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT SendMediaEvent(
            const MediaEventT & event,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT SendRouteEvent(
            const RouteEventT & event,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CcResultT SendOtherEvent(
            const OtherEventT & event,
            const std::map<std::string, std::string>& ctx) = 0;

    };

    class event_callback_SendCallEvent_args {
    public:
        event_callback_SendCallEvent_args();
        virtual ~event_callback_SendCallEvent_args();

        CallEventT event;

        bool operator==(const event_callback_SendCallEvent_args& rhs) const;
        bool operator!=(const event_callback_SendCallEvent_args& rhs) const;
        bool operator< (const event_callback_SendCallEvent_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class event_callback_SendMediaEvent_args {
    public:
        event_callback_SendMediaEvent_args();
        virtual ~event_callback_SendMediaEvent_args();

        MediaEventT event;

        bool operator==(const event_callback_SendMediaEvent_args& rhs) const;
        bool operator!=(const event_callback_SendMediaEvent_args& rhs) const;
        bool operator< (const event_callback_SendMediaEvent_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class event_callback_SendRouteEvent_args {
    public:
        event_callback_SendRouteEvent_args();
        virtual ~event_callback_SendRouteEvent_args();

        RouteEventT event;

        bool operator==(const event_callback_SendRouteEvent_args& rhs) const;
        bool operator!=(const event_callback_SendRouteEvent_args& rhs) const;
        bool operator< (const event_callback_SendRouteEvent_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class event_callback_SendOtherEvent_args {
    public:
        event_callback_SendOtherEvent_args();
        virtual ~event_callback_SendOtherEvent_args();

        OtherEventT event;

        bool operator==(const event_callback_SendOtherEvent_args& rhs) const;
        bool operator!=(const event_callback_SendOtherEvent_args& rhs) const;
        bool operator< (const event_callback_SendOtherEvent_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class event_callback_SendCallEvent_pargs {
    public:
        virtual ~event_callback_SendCallEvent_pargs();

        const CallEventT* event;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendMediaEvent_pargs {
    public:
        virtual ~event_callback_SendMediaEvent_pargs();

        const MediaEventT* event;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendRouteEvent_pargs {
    public:
        virtual ~event_callback_SendRouteEvent_pargs();

        const RouteEventT* event;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendOtherEvent_pargs {
    public:
        virtual ~event_callback_SendOtherEvent_pargs();

        const OtherEventT* event;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendCallEvent_result {
    public:
        event_callback_SendCallEvent_result();
        virtual ~event_callback_SendCallEvent_result();

        CcResultT return_value;

        bool operator==(const event_callback_SendCallEvent_result& rhs) const;
        bool operator!=(const event_callback_SendCallEvent_result& rhs) const;
        bool operator< (const event_callback_SendCallEvent_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendMediaEvent_result {
    public:
        event_callback_SendMediaEvent_result();
        virtual ~event_callback_SendMediaEvent_result();

        CcResultT return_value;

        bool operator==(const event_callback_SendMediaEvent_result& rhs) const;
        bool operator!=(const event_callback_SendMediaEvent_result& rhs) const;
        bool operator< (const event_callback_SendMediaEvent_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendRouteEvent_result {
    public:
        event_callback_SendRouteEvent_result();
        virtual ~event_callback_SendRouteEvent_result();

        CcResultT return_value;

        bool operator==(const event_callback_SendRouteEvent_result& rhs) const;
        bool operator!=(const event_callback_SendRouteEvent_result& rhs) const;
        bool operator< (const event_callback_SendRouteEvent_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendOtherEvent_result {
    public:
        event_callback_SendOtherEvent_result();
        virtual ~event_callback_SendOtherEvent_result();

        CcResultT return_value;

        bool operator==(const event_callback_SendOtherEvent_result& rhs) const;
        bool operator!=(const event_callback_SendOtherEvent_result& rhs) const;
        bool operator< (const event_callback_SendOtherEvent_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendCallEvent_presult {
    public:
        virtual ~event_callback_SendCallEvent_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendMediaEvent_presult {
    public:
        virtual ~event_callback_SendMediaEvent_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendRouteEvent_presult {
    public:
        virtual ~event_callback_SendRouteEvent_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callback_SendOtherEvent_presult {
    public:
        virtual ~event_callback_SendOtherEvent_presult();

        CcResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class event_callbackProxy : public bgcc::BaseProxy {
    public:
        event_callbackProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        event_callbackProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        event_callbackProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CcResultT SendCallEvent(
            const CallEventT& event,
            bool last = false);

        CcResultT SendMediaEvent(
            const MediaEventT& event,
            bool last = false);

        CcResultT SendRouteEvent(
            const RouteEventT& event,
            bool last = false);

        CcResultT SendOtherEvent(
            const OtherEventT& event,
            bool last = false);

    private:
        void send_SendCallEvent(
            const CallEventT& event,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendCallEvent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SendMediaEvent(
            const MediaEventT& event,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendMediaEvent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SendRouteEvent(
            const RouteEventT& event,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendRouteEvent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SendOtherEvent(
            const OtherEventT& event,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendOtherEvent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class SSLevent_callbackProxy : public bgcc::SSLBaseProxy {
    public:
        SSLevent_callbackProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLevent_callbackProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLevent_callbackProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CcResultT SendCallEvent(
            const CallEventT& event,
            bool last = false);

        CcResultT SendMediaEvent(
            const MediaEventT& event,
            bool last = false);

        CcResultT SendRouteEvent(
            const RouteEventT& event,
            bool last = false);

        CcResultT SendOtherEvent(
            const OtherEventT& event,
            bool last = false);

    private:
        void send_SendCallEvent(
            const CallEventT& event,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendCallEvent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SendMediaEvent(
            const MediaEventT& event,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendMediaEvent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SendRouteEvent(
            const RouteEventT& event,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendRouteEvent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_SendOtherEvent(
            const OtherEventT& event,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CcResultT recv_SendOtherEvent(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class event_callbackProcessor : public bgcc::BaseProcessor {
    public:
        event_callbackProcessor(bgcc::SharedPointer<event_callback> intf);

        virtual ~event_callbackProcessor(){ }

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

        bgcc::SharedPointer<event_callback> __intf;

    private:
        int32_t do_SendCallEvent(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_SendMediaEvent(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_SendRouteEvent(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_SendOtherEvent(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        typedef int32_t (event_callbackProcessor::* do_function_ptr)(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        std::map<std::string, do_function_ptr> __fun_map;
    };
}


#endif
