#ifndef _BIDL2SL_ACDHEARTBEAT_H_
#define _BIDL2SL_ACDHEARTBEAT_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

namespace acd {
    class acdheartbeat : public bgcc::Shareable {
    public:
        virtual ~acdheartbeat() { }

        virtual bool Heartbeat(
            bool currentType,
            bool & newType,
            const std::map<std::string, std::string>& ctx) = 0;

    };

    class acdheartbeat_Heartbeat_args {
    public:
        acdheartbeat_Heartbeat_args();
        virtual ~acdheartbeat_Heartbeat_args();

        bool currentType;

        bool operator==(const acdheartbeat_Heartbeat_args& rhs) const;
        bool operator!=(const acdheartbeat_Heartbeat_args& rhs) const;
        bool operator< (const acdheartbeat_Heartbeat_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class acdheartbeat_Heartbeat_pargs {
    public:
        virtual ~acdheartbeat_Heartbeat_pargs();

        const bool* currentType;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class acdheartbeat_Heartbeat_result {
    public:
        acdheartbeat_Heartbeat_result();
        virtual ~acdheartbeat_Heartbeat_result();

        bool return_value;
        bool newType;

        bool operator==(const acdheartbeat_Heartbeat_result& rhs) const;
        bool operator!=(const acdheartbeat_Heartbeat_result& rhs) const;
        bool operator< (const acdheartbeat_Heartbeat_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class acdheartbeat_Heartbeat_presult {
    public:
        virtual ~acdheartbeat_Heartbeat_presult();

        bool* return_value;
        bool* newType;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class acdheartbeatProxy : public bgcc::BaseProxy {
    public:
        acdheartbeatProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        acdheartbeatProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        acdheartbeatProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        bool Heartbeat(
            bool currentType,
            bool& newType,
            bool last = false);

    private:
        void send_Heartbeat(
            const bool& currentType,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        bool recv_Heartbeat(
            bool& newType,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class SSLacdheartbeatProxy : public bgcc::SSLBaseProxy {
    public:
        SSLacdheartbeatProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLacdheartbeatProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLacdheartbeatProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        bool Heartbeat(
            bool currentType,
            bool& newType,
            bool last = false);

    private:
        void send_Heartbeat(
            const bool& currentType,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        bool recv_Heartbeat(
            bool& newType,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class acdheartbeatProcessor : public bgcc::BaseProcessor {
    public:
        acdheartbeatProcessor(bgcc::SharedPointer<acdheartbeat> intf);

        virtual ~acdheartbeatProcessor(){ }

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

        bgcc::SharedPointer<acdheartbeat> __intf;

    private:
        int32_t do_Heartbeat(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        typedef int32_t (acdheartbeatProcessor::* do_function_ptr)(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        std::map<std::string, do_function_ptr> __fun_map;
    };
}


#endif
