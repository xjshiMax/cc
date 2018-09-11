#ifndef _BIDL2SL_IVR_H_
#define _BIDL2SL_IVR_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

namespace ivr {

    class ReloadFlagT {
    public:
        enum {
            ReloadInBound = 0,
            ReloadAutorun = 1,
            ReloadThreadCount = 2,
            ReloadEslLog = 3,
            ReloadAll = 4
        };

        ReloadFlagT();
        ReloadFlagT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const ReloadFlagT& rhs) const;
        bool operator==(const ReloadFlagT& rhs) const;
        bool operator< (const ReloadFlagT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const ReloadFlagT&);
    bool operator!=(int32_t value, const ReloadFlagT&);
    bool operator< (int32_t value, const ReloadFlagT&);
    std::ostream& operator<<(std::ostream& o, const ReloadFlagT&);


    class IvrResultT {
    public:
        enum {
            ResSuccess = 0,
            ResFailed = 1,
            ResInvalidParam = 2,
            ResNoEnoughResource = 3
        };

        IvrResultT();
        IvrResultT(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const IvrResultT& rhs) const;
        bool operator==(const IvrResultT& rhs) const;
        bool operator< (const IvrResultT& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const IvrResultT&);
    bool operator!=(int32_t value, const IvrResultT&);
    bool operator< (int32_t value, const IvrResultT&);
    std::ostream& operator<<(std::ostream& o, const IvrResultT&);

    class ivrapi : public bgcc::Shareable {
    public:
        virtual ~ivrapi() { }

        virtual IvrResultT ReloadConfig(
            const ReloadFlagT & type,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual IvrResultT StartFlow(
            const std::string & flowname,
            const std::string & flowvars,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual IvrResultT Heartbeat(
            std::string & ivrinfo,
            const std::map<std::string, std::string>& ctx) = 0;

    };

    class ivrapi_ReloadConfig_args {
    public:
        ivrapi_ReloadConfig_args();
        virtual ~ivrapi_ReloadConfig_args();

        ReloadFlagT type;

        bool operator==(const ivrapi_ReloadConfig_args& rhs) const;
        bool operator!=(const ivrapi_ReloadConfig_args& rhs) const;
        bool operator< (const ivrapi_ReloadConfig_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class ivrapi_StartFlow_args {
    public:
        ivrapi_StartFlow_args();
        virtual ~ivrapi_StartFlow_args();

        std::string flowname;
        std::string flowvars;

        bool operator==(const ivrapi_StartFlow_args& rhs) const;
        bool operator!=(const ivrapi_StartFlow_args& rhs) const;
        bool operator< (const ivrapi_StartFlow_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class ivrapi_Heartbeat_args {
    public:
        ivrapi_Heartbeat_args();
        virtual ~ivrapi_Heartbeat_args();


        bool operator==(const ivrapi_Heartbeat_args& rhs) const;
        bool operator!=(const ivrapi_Heartbeat_args& rhs) const;
        bool operator< (const ivrapi_Heartbeat_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class ivrapi_ReloadConfig_pargs {
    public:
        virtual ~ivrapi_ReloadConfig_pargs();

        const ReloadFlagT* type;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapi_StartFlow_pargs {
    public:
        virtual ~ivrapi_StartFlow_pargs();

        const std::string* flowname;
        const std::string* flowvars;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapi_Heartbeat_pargs {
    public:
        virtual ~ivrapi_Heartbeat_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapi_ReloadConfig_result {
    public:
        ivrapi_ReloadConfig_result();
        virtual ~ivrapi_ReloadConfig_result();

        IvrResultT return_value;

        bool operator==(const ivrapi_ReloadConfig_result& rhs) const;
        bool operator!=(const ivrapi_ReloadConfig_result& rhs) const;
        bool operator< (const ivrapi_ReloadConfig_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapi_StartFlow_result {
    public:
        ivrapi_StartFlow_result();
        virtual ~ivrapi_StartFlow_result();

        IvrResultT return_value;

        bool operator==(const ivrapi_StartFlow_result& rhs) const;
        bool operator!=(const ivrapi_StartFlow_result& rhs) const;
        bool operator< (const ivrapi_StartFlow_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapi_Heartbeat_result {
    public:
        ivrapi_Heartbeat_result();
        virtual ~ivrapi_Heartbeat_result();

        IvrResultT return_value;
        std::string ivrinfo;

        bool operator==(const ivrapi_Heartbeat_result& rhs) const;
        bool operator!=(const ivrapi_Heartbeat_result& rhs) const;
        bool operator< (const ivrapi_Heartbeat_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapi_ReloadConfig_presult {
    public:
        virtual ~ivrapi_ReloadConfig_presult();

        IvrResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapi_StartFlow_presult {
    public:
        virtual ~ivrapi_StartFlow_presult();

        IvrResultT* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapi_Heartbeat_presult {
    public:
        virtual ~ivrapi_Heartbeat_presult();

        IvrResultT* return_value;
        std::string* ivrinfo;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class ivrapiProxy : public bgcc::BaseProxy {
    public:
        ivrapiProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        ivrapiProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        ivrapiProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        IvrResultT ReloadConfig(
            const ReloadFlagT& type,
            bool last = false);

        IvrResultT StartFlow(
            const std::string& flowname,
            const std::string& flowvars,
            bool last = false);

        IvrResultT Heartbeat(
            std::string& ivrinfo,
            bool last = false);

    private:
        void send_ReloadConfig(
            const ReloadFlagT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        IvrResultT recv_ReloadConfig(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_StartFlow(
            const std::string& flowname,
            const std::string& flowvars,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        IvrResultT recv_StartFlow(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Heartbeat(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        IvrResultT recv_Heartbeat(
            std::string& ivrinfo,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class SSLivrapiProxy : public bgcc::SSLBaseProxy {
    public:
        SSLivrapiProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLivrapiProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLivrapiProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        IvrResultT ReloadConfig(
            const ReloadFlagT& type,
            bool last = false);

        IvrResultT StartFlow(
            const std::string& flowname,
            const std::string& flowvars,
            bool last = false);

        IvrResultT Heartbeat(
            std::string& ivrinfo,
            bool last = false);

    private:
        void send_ReloadConfig(
            const ReloadFlagT& type,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        IvrResultT recv_ReloadConfig(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_StartFlow(
            const std::string& flowname,
            const std::string& flowvars,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        IvrResultT recv_StartFlow(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_Heartbeat(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        IvrResultT recv_Heartbeat(
            std::string& ivrinfo,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class ivrapiProcessor : public bgcc::BaseProcessor {
    public:
        ivrapiProcessor(bgcc::SharedPointer<ivrapi> intf);

        virtual ~ivrapiProcessor(){ }

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

        bgcc::SharedPointer<ivrapi> __intf;

    private:
        int32_t do_ReloadConfig(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_StartFlow(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_Heartbeat(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        typedef int32_t (ivrapiProcessor::* do_function_ptr)(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        std::map<std::string, do_function_ptr> __fun_map;
    };
}


#endif
