#ifndef _BIDL2SL_CALLBACK_H_
#define _BIDL2SL_CALLBACK_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

namespace demo {

    class CallbackResult {
    public:
        enum {
            R_SUCC = 0,
            R_FAIL = 1
        };

        CallbackResult();
        CallbackResult(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const CallbackResult& rhs) const;
        bool operator==(const CallbackResult& rhs) const;
        bool operator< (const CallbackResult& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const CallbackResult&);
    bool operator!=(int32_t value, const CallbackResult&);
    bool operator< (int32_t value, const CallbackResult&);
    std::ostream& operator<<(std::ostream& o, const CallbackResult&);

    class CallbackRecver : public bgcc::Shareable {
    public:
        virtual ~CallbackRecver() { }

        virtual CallbackResult Callback(
            int32_t val,
            const std::map<std::string, std::string>& ctx) = 0;

    };

    class CallbackRecver_Callback_args {
    public:
        CallbackRecver_Callback_args();
        virtual ~CallbackRecver_Callback_args();

        int32_t val;

        bool operator==(const CallbackRecver_Callback_args& rhs) const;
        bool operator!=(const CallbackRecver_Callback_args& rhs) const;
        bool operator< (const CallbackRecver_Callback_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class CallbackRecver_Callback_pargs {
    public:
        virtual ~CallbackRecver_Callback_pargs();

        const int32_t* val;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackRecver_Callback_result {
    public:
        CallbackRecver_Callback_result();
        virtual ~CallbackRecver_Callback_result();

        CallbackResult return_value;

        bool operator==(const CallbackRecver_Callback_result& rhs) const;
        bool operator!=(const CallbackRecver_Callback_result& rhs) const;
        bool operator< (const CallbackRecver_Callback_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackRecver_Callback_presult {
    public:
        virtual ~CallbackRecver_Callback_presult();

        CallbackResult* return_value;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackRecverProxy : public bgcc::BaseProxy {
    public:
        CallbackRecverProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CallbackRecverProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CallbackRecverProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CallbackResult Callback(
            int32_t val,
            bool last = false);

    private:
        void send_Callback(
            const int32_t& val,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CallbackResult recv_Callback(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class SSLCallbackRecverProxy : public bgcc::SSLBaseProxy {
    public:
        SSLCallbackRecverProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLCallbackRecverProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLCallbackRecverProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CallbackResult Callback(
            int32_t val,
            bool last = false);

    private:
        void send_Callback(
            const int32_t& val,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CallbackResult recv_Callback(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class CallbackRecverProcessor : public bgcc::BaseProcessor {
    public:
        CallbackRecverProcessor(bgcc::SharedPointer<CallbackRecver> intf);

        virtual ~CallbackRecverProcessor(){ }

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

        bgcc::SharedPointer<CallbackRecver> __intf;

    private:
        int32_t do_Callback(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        typedef int32_t (CallbackRecverProcessor::* do_function_ptr)(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        std::map<std::string, do_function_ptr> __fun_map;
    };
    class CallbackSender : public bgcc::Shareable {
    public:
        virtual ~CallbackSender() { }

        virtual CallbackResult AddClient(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual CallbackResult DelClient(
            const std::map<std::string, std::string>& ctx) = 0;

    };

    class CallbackSender_AddClient_args {
    public:
        CallbackSender_AddClient_args();
        virtual ~CallbackSender_AddClient_args();

        bool operator==(const CallbackSender_AddClient_args& rhs) const;
        bool operator!=(const CallbackSender_AddClient_args& rhs) const;
        bool operator< (const CallbackSender_AddClient_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class CallbackSender_DelClient_args {
    public:
        CallbackSender_DelClient_args();
        virtual ~CallbackSender_DelClient_args();

        bool operator==(const CallbackSender_DelClient_args& rhs) const;
        bool operator!=(const CallbackSender_DelClient_args& rhs) const;
        bool operator< (const CallbackSender_DelClient_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class CallbackSender_AddClient_pargs {
    public:
        virtual ~CallbackSender_AddClient_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackSender_DelClient_pargs {
    public:
        virtual ~CallbackSender_DelClient_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackSender_AddClient_result {
    public:
        CallbackSender_AddClient_result();
        virtual ~CallbackSender_AddClient_result();

        CallbackResult return_value;
        bool operator==(const CallbackSender_AddClient_result& rhs) const;
        bool operator!=(const CallbackSender_AddClient_result& rhs) const;
        bool operator< (const CallbackSender_AddClient_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackSender_DelClient_result {
    public:
        CallbackSender_DelClient_result();
        virtual ~CallbackSender_DelClient_result();

        CallbackResult return_value;
        bool operator==(const CallbackSender_DelClient_result& rhs) const;
        bool operator!=(const CallbackSender_DelClient_result& rhs) const;
        bool operator< (const CallbackSender_DelClient_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackSender_AddClient_presult {
    public:
        virtual ~CallbackSender_AddClient_presult();

        CallbackResult* return_value;
        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackSender_DelClient_presult {
    public:
        virtual ~CallbackSender_DelClient_presult();

        CallbackResult* return_value;
        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class CallbackSenderProxy : public bgcc::BaseProxy {
    public:
        CallbackSenderProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CallbackSenderProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CallbackSenderProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CallbackResult AddClient(
            bool last = false);

        CallbackResult DelClient(
            bool last = false);

    private:
        void send_AddClient(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CallbackResult recv_AddClient(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_DelClient(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CallbackResult recv_DelClient(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class SSLCallbackSenderProxy : public bgcc::SSLBaseProxy {
    public:
        SSLCallbackSenderProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLCallbackSenderProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLCallbackSenderProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        CallbackResult AddClient(
            bool last = false);

        CallbackResult DelClient(
            bool last = false);

    private:
        void send_AddClient(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CallbackResult recv_AddClient(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        void send_DelClient(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        CallbackResult recv_DelClient(
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class CallbackSenderProcessor : public bgcc::BaseProcessor {
    public:
        CallbackSenderProcessor(bgcc::SharedPointer<CallbackSender> intf);

        virtual ~CallbackSenderProcessor(){ }

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

        bgcc::SharedPointer<CallbackSender> __intf;

    private:
        int32_t do_AddClient(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_DelClient(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        typedef int32_t (CallbackSenderProcessor::* do_function_ptr)(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        std::map<std::string, do_function_ptr> __fun_map;
    };
}


#endif
