#include <bgcc.h>
using namespace bgcc;
#include <talk.h>
#include <callback.h>
using namespace cctalk;

class TalkerImpl : public Talker {
public:
    TalkerImpl(const std::string& userFileName) : _userFileName(userFileName) {
        ConfUnit* root = ConfLoader::load_conf(_userFileName.c_str());
        if (NULL == root) {
            std::cerr << "ConfLoader::load_conf return a NULL ConfUnit pointer" << std::endl;
            exit(0);
        }

        ConfUnit* users = (*root)["user"];

        if (NULL == users) {
            std::cerr << "Not find user section" << std::endl;
            exit(0);
        }

        if (ConfUnit::UT_ARRAY != users->get_type()) {
            std::cerr << "user is not an array" << std::endl;
            exit(0);
        }

        ConfUnit::const_iterator citr;
        int32_t i;
        for (citr = users->begin(), i = 1; citr != users->end(); ++citr, ++i) {
            ConfUnit* user = *citr;
            if (NULL == user || ConfUnit::UT_GROUP != user->get_type()) {
                continue;
            }

            ConfUnit* name = (*user)["name"];
            if (NULL == name || ConfUnit::UT_STRING != name->get_type()) {
                continue;
            }
            std::string name_valstr = name->to_string();

            ConfUnit* password = (*user)["password"];
            if (NULL == password || ConfUnit::UT_STRING != password->get_type()) {
                continue;
            }
            std::string password_valstr = password->to_string();

            _userName2password.insert(std::make_pair(name_valstr, password_valstr));
        }
    }

    virtual ~TalkerImpl() { }

    virtual Result login(
            const std::string & name,
            const std::string & password,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("cctalk", "Enter login[name: %s, password: %s]",
                name.c_str(), password.c_str());
        Result result(Result::S_OK);

        std::string proxyName = getProxyName(ctx);
        if (proxyName.empty()) {
            result = Result::E_MISS_PROXYNAME;
            BGCC_TRACE("cctalk", "login failed--E_MISS_PROXYNAME");
        } else {
            bool valid = false;
            std::map<std::string, std::string>::const_iterator citr;
            citr = _userName2password.find(name);
            if (citr != _userName2password.end() &&
                    password == citr->second) {
                valid = true;
            }

            _mutex.lock();
            if (isLoggedIn(proxyName)) {
                result = Result::E_ALREADY_LOGIN;
            } else {
                if (valid) {
                    _name2proxyname.erase(name);
                    _name2proxyname.insert(std::make_pair(name, proxyName));
                    _proxyname2name.erase(proxyName);
                    _proxyname2name.insert(std::make_pair(proxyName, name));
                } else {
                    result = Result::E_WRONGNAMEORPASSWORD;
                }
            }
            _mutex.unlock();
        }

        BGCC_TRACE("cctalk", "Leave login[result: %s]", result.get_desc().c_str());
        return result; 
    }

    virtual Result talk(
            const std::string & peer,
            const std::string & message,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("cctalk", "server before call talk");
        Result result(Result::S_OK);

        std::string proxyName = getProxyName(ctx);
        std::string from;
        std::string toProxyName;

        _mutex.lock();
        if (isLoggedIn(proxyName)) {
            from = _proxyname2name[proxyName];
            toProxyName = _name2proxyname[peer];
            if(toProxyName.empty()) {
                _name2proxyname.erase(peer);
            }
        } else {
            result = Result::E_NOT_LOGIN;
        }
        _mutex.unlock();

        if (Result::S_OK == result) {
            if (toProxyName.empty()) {
                result = Result::E_USERNOTEXIST;
            } else {
                CallbackProxy callbackProxy(toProxyName);
                BGCC_TRACE("cctalk", "server before call send by proxy");
                Result cbResult = callbackProxy.send(from, message);
                BGCC_TRACE("cctalk", "server after call send by proxy");
                if (callbackProxy.get_errno() != 0) {
                    result = Result::E_NETWORK;
                }
            }
        }
        BGCC_TRACE("cctalk", "server after call talk");
        return result;
    }

    virtual Result getOnlineUsers(
            std::vector<std::string>  & onlineUsers,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("cctalk", "Enter getOnlineUsers");
        Result result(Result::S_OK);
        std::string proxyName = getProxyName(ctx);
        std::map<std::string, std::string>::const_iterator citr;

        _mutex.lock();
        if (isLoggedIn(proxyName)) {
            for (citr = _name2proxyname.begin(); citr != _name2proxyname.end(); ++citr) {
                onlineUsers.push_back(citr->first);
            }
        } else {
            result = Result::E_NOT_LOGIN;
        }
        _mutex.unlock();

        BGCC_TRACE("cctalk", "Leave getOnlineUsers[result: %s]",
                result.get_desc().c_str());
        return result;
    }

    virtual Result logout(
            const std::map<std::string, std::string>& ctx) {
        Result result(Result::S_OK);
        BGCC_TRACE("cctalk", "Enter logout");

        std::string proxyName = getProxyName(ctx);
        _mutex.lock();
        if (isLoggedIn(proxyName)) {
            _name2proxyname.erase(_proxyname2name[proxyName]);
            _proxyname2name.erase(proxyName);
        } else {
            result = Result::E_NOT_LOGIN;
        }
        _mutex.unlock();

        BGCC_TRACE("cctalk", "Leave logout");
        return result; 
    }

private:
    std::string getProxyName(const std::map<std::string, std::string>& ctx) {
        std::string proxyName;
        std::map<std::string, std::string>::const_iterator citr;

        citr = ctx.find("ProxyName");
        if (citr != ctx.end()) {
            proxyName = citr->second;
        }
        return proxyName;
    }

    bool isLoggedIn(const std::string& proxyName) {
        return _proxyname2name.find(proxyName) != _proxyname2name.end();
    }

private:
    std::string _userFileName;
    std::map<std::string, std::string> _userName2password;
    Mutex _mutex;
    std::map<std::string, std::string> _name2proxyname;
    std::map<std::string, std::string> _proxyname2name;
};

Server* server;

void* server_func(void*) {
    SharedPointer<IProcessor> xp(
            new TalkerProcessor(
                SharedPointer<Talker>(
                    new TalkerImpl("user.list"))));

    ServiceManager sm;
    sm.add_service(xp);

    ThreadPool tp;
    tp.init(10);
    server = new Server(&sm, &tp, 8509);
    if (0 != server->serve()) {
        return 0;
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    log_open("bgcc.cfg");
    Thread t(server_func);
    t.start();

    return 0;
}
