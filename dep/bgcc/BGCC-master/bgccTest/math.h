#ifndef _BIDL2SL_MATH_H_
#define _BIDL2SL_MATH_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

namespace math {

    class Result {
    public:
        enum {
            E_SUCCESS = 0,
            E_OVERLOW = 1,
            E_DOWNLOW = 2
        };

        Result();
        Result(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const Result& rhs) const;
        bool operator==(const Result& rhs) const;
        bool operator< (const Result& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const Result&);
    bool operator!=(int32_t value, const Result&);
    bool operator< (int32_t value, const Result&);
    std::ostream& operator<<(std::ostream& o, const Result&);

    class Math : public bgcc::Shareable {
    public:
        virtual ~Math() { }

        virtual Result add(
            int32_t a,
            int32_t b,
            int32_t & sum,
            const std::map<std::string, std::string>& ctx) = 0;

    };

    class Math_add_args {
    public:
        Math_add_args();
        virtual ~Math_add_args();

        int32_t a;
        int32_t b;

        bool operator==(const Math_add_args& rhs) const;
        bool operator!=(const Math_add_args& rhs) const;
        bool operator< (const Math_add_args& rhs) const;
        int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);
    };

    class Math_add_pargs {
    public:
        virtual ~Math_add_pargs();

        const int32_t* a;
        const int32_t* b;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_add_result {
    public:
        Math_add_result();
        virtual ~Math_add_result();

        Result return_value;
        int32_t sum;

        bool operator==(const Math_add_result& rhs) const;
        bool operator!=(const Math_add_result& rhs) const;
        bool operator< (const Math_add_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_add_presult {
    public:
        virtual ~Math_add_presult();

        Result* return_value;
        int32_t* sum;

        int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class MathProxy : public bgcc::BaseProxy {
    public:
        MathProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        MathProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        MathProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        Result add(
            int32_t a,
            int32_t b,
            int32_t& sum,
            bool last = false);

    private:
        void send_add(
            const int32_t& a,
            const int32_t& b,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        Result recv_add(
            int32_t& sum,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class SSLMathProxy : public bgcc::SSLBaseProxy {
    public:
        SSLMathProxy(
            bgcc::ServerInfo serverinfo,
            int32_t maxConn,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLMathProxy(
            bgcc::ServerInfo serverinfo,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        SSLMathProxy(
            const std::string& proxy_name,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        Result add(
            int32_t a,
            int32_t b,
            int32_t& sum,
            bool last = false);

    private:
        void send_add(
            const int32_t& a,
            const int32_t& b,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

        Result recv_add(
            int32_t& sum,
            bgcc::SharedPointer<bgcc::ConnInfo> conn);

    };

    class MathProcessor : public bgcc::BaseProcessor {
    public:
        MathProcessor(bgcc::SharedPointer<Math> intf);

        virtual ~MathProcessor(){ }

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

        bgcc::SharedPointer<Math> __intf;

    private:
        int32_t do_add(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        typedef int32_t (MathProcessor::* do_function_ptr)(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        std::map<std::string, do_function_ptr> __fun_map;
    };
}


#endif
