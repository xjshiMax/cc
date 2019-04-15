#include <iostream>
#include <deque>
#include <stdlib.h>
#include <string.h>
#include <linenoise.h>
#include <bgcc.h>
using namespace bgcc;
#include <common.h>
#include <talk.h>
#include <callback.h>
using namespace cctalk;
#include "cctalk.h"


static std::deque<std::pair<std::string, std::string> > messageStore;
static Mutex messageStoreMutex;

class CallbackImpl : public Callback {
public:
    virtual ~CallbackImpl() { }

    virtual Result send(
            const std::string & from,
            const std::string & message,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("cctalk", "Before call send");
        messageStoreMutex.lock();
        messageStore.push_back(std::make_pair(from, message));
        messageStoreMutex.unlock();
        BGCC_TRACE("cctalk", "End call send");
        return Result::S_OK;
    }
};

void completion(const char *buf, linenoiseCompletions *lc) {
//    if (buf[0] == 'h') {
//        linenoiseAddCompletion(lc,"hello");
//    }
}

class Command {
public:
    virtual int execute() = 0;
    virtual ~Command() { }
};

class DoIdleCommand : public Command {
public:
    virtual int execute() {
        return 0;
    }

    virtual ~DoIdleCommand() { }
};

class HelpCommand : public Command {
public:
    virtual int execute() {
        std::cout << "help" << std::endl;
        return 0;
    }

    virtual ~HelpCommand() { }
};

TalkerProxy* proxy = NULL;
class LoginCommand : public Command {
public:
    LoginCommand(const std::string& name):_name(name) { }

    virtual int execute() {
        if (proxy) {
            std::string userName;
            std::string password;
            if (parseUserNameAndPassword(userName, password) == 0) {
                Result result = proxy->login(userName, password);
                if (proxy->get_errno() != 0) {
                    std::cerr << "Failed to call login" << std::endl;
                } else if (Result::S_OK == result) {
                    std::cout << "Success to login" << std::endl;
                } else {
                    std::cout << "Failed to login(" << result.get_desc() << ")" << std::endl;
                }
            } else {
                std::cerr << "Failed to parse userName or password from input" << std::endl;
            }
        }
        return 0;
    }

    virtual ~LoginCommand() { }
private:
    int parseUserNameAndPassword(std::string& userName, std::string& password) {
            char buffer[BUFSIZ];
            size_t len = _name.size();

            char* user = (char*)malloc(len + 1);
            if (NULL == user) {
                fprintf(stderr, "Error: %s", strerror_r(errno, buffer, BUFSIZ));
                return -1;
            }

            char* passwd = (char*)malloc(len + 1);
            if (NULL == passwd) {
                fprintf(stderr, "Error: %s", strerror_r(errno, buffer, BUFSIZ));

                free(user);
                return -1;
            }

            int32_t nfield = sscanf(_name.c_str(), LOGIN_PRE"%s%s", user, passwd);

            if (2 != nfield) {
                fprintf(stderr, "Error: parse user or password failed");

                free(user);
                free(passwd);
                return -1;
            }

            userName = std::string(user);
            password = std::string(passwd);
            free(user);
            free(passwd);
            return 0;
    }
private:
    std::string _name;
};

class ListCommand : public Command {
public:
    virtual int execute() {
        if (proxy) {
            std::vector<std::string> users_online;
            Result result = proxy->getOnlineUsers(users_online);
            if (proxy->get_errno() != 0) {
                std::cerr << "Failed to call getOnlineUsers" << std::endl;
            } else if (Result::S_OK == result) {
                if (users_online.empty()) {
                    std::cout << "No user is online" << std::endl;
                } else {
                    std::cout << "online users:\n";
                    std::vector<std::string>::const_iterator citr;
                    for (citr = users_online.begin(); citr != users_online.end(); ++citr) {
                        std::cout << *citr << "\n";
                    }
                    std::cout << std::endl;
                }
            } else {
                std::cout << "Failed to getOnlineUsers(" << result.get_desc() << ")" << std::endl;
            }
        }
        return 0;
    }

    virtual ~ListCommand() { }
};

class TalkCommand : public Command {
public:
    TalkCommand(const std::string& name) : _name(name) { }

    virtual int execute() {
        if (proxy) {
            std::string userName;
            std::string message;
            if (parseUserNameAndMessage(userName, message) == 0) {
                BGCC_TRACE("cctalk", "Before call talk");
                Result result = proxy->talk(userName, message);
                BGCC_TRACE("cctalk", "After call talk");
                if (proxy->get_errno() != 0) {
                    std::cerr << "Failed to call talk" << std::endl;
                } else if (Result::S_OK != result) {
                    std::cout << "Failed to talk(" << result.get_desc() << ")" << std::endl;
                }
            } else {
                std::cerr << "Failed to parse userName or message from input" << std::endl;
            }
        }
        return 0;
    }

    virtual ~TalkCommand() { }
private:
    int parseUserNameAndMessage(std::string& userName, std::string& message) {
        char buffer[BUFSIZ];
        size_t len = _name.size();

        char* user = (char*)malloc(len + 1);
        if (NULL == user) {
            fprintf(stderr, "Error: %s", strerror_r(errno, buffer, BUFSIZ));
            return -1;
        }

        char* msg = (char*)malloc(len + 1);
        if (NULL == msg) {
            fprintf(stderr, "Error: %s", strerror_r(errno, buffer, BUFSIZ));

            free(user);
            return -1;
        }

        int32_t nfield = sscanf(_name.c_str(), TALK_PRE"%s%s", user, msg);

        if (2 != nfield) {
            fprintf(stderr, "Error: parse user or message failed");

            free(user);
            free(msg);
            return -1;
        }

        const char* cmd_line = _name.c_str();
        while (*cmd_line && !isblank(*cmd_line)) {
            ++cmd_line;
        }
        while (*cmd_line && isblank(*cmd_line)) {
            ++cmd_line;
        }
        while (*cmd_line && !isblank(*cmd_line)) {
            ++cmd_line;
        }
        while (*cmd_line && isblank(*cmd_line)) {
            ++cmd_line;
        }

        userName = std::string(user);
        message = std::string(cmd_line);
        free(user);
        free(msg);
        return 0;
    }
private:
    std::string _name;
};

class UnknownCommand : public Command {
public:
    UnknownCommand(const std::string& name) : _name(name) { }

    virtual int execute() {
        std::cerr << "Unknown command: " << _name << std::endl;
        return 0;
    }

    virtual ~UnknownCommand() { }
private:
    std::string _name;
};

class QuitCommand : public Command {
public:
    virtual int execute() {
        stopped = true;
        return 0;
    }

    virtual ~QuitCommand() { }
};

class LogoutCommand : public Command {
public:
    virtual int execute() {
        if (proxy) {
            Result result = proxy->logout();
            if (proxy->get_errno() != 0) {
                std::cerr << "Failed to call logout" << std::endl;
            } else if (Result::S_OK == result) {
                std::cout << "Success to logout" << std::endl;
            } else {
                std::cout << "Failed to logout(" << result.get_desc() << ")" << std::endl;
            }
        }
        return 0;
    }

    virtual ~LogoutCommand() { }
};

class MessageCommand : public Command {
public:
    virtual int execute() {
        messageStoreMutex.lock();
        if (messageStore.empty()) {
            std::cout << "No message." << std::endl;
        } else {
            while(!messageStore.empty()) {
                std::cout << messageStore.front().first << " said: "
                    << messageStore.front().second << std::endl;
                messageStore.pop_front();
            }
        }
        messageStoreMutex.unlock();
        return 0;
    }

    virtual ~MessageCommand() { }
};

class CommandFactory {
public:
    static Command* make_command(const char* cmd_name) {
        if (NULL == cmd_name) {
            return new DoIdleCommand;
        }
        std::string name(cmd_name);
        if (isDoIdleCommand(name)) {
            return new DoIdleCommand;
        } else if (isQuitCommand(name)) {
            return new QuitCommand;
        } else if (isHelpCommand(name)) {
            return new HelpCommand;
        } else if (isLoginCommand(cmd_name)) {
            return new LoginCommand(name);
        } else if (isLogoutCommand(cmd_name)) {
            return new LogoutCommand;
        } else if (isListCommand(name)) {
            return new ListCommand;
        } else if (isTalkCommand(cmd_name)) {
            return new TalkCommand(name);
        } else if (isMessageCommand(name)) {
            return new MessageCommand;
        } else {
            return new UnknownCommand(name);
        }
    }

private:
    static bool isDoIdleCommand(const std::string& name) {
        return name.empty();
    }

    static bool isQuitCommand(const std::string& name) {
        return QUIT == name || EXIT == name || DOT3 == name;
    }
    
    static bool isLogoutCommand(const std::string& name) {
        return LOGOUT == name;
    }

    static bool isListCommand(const std::string& name) {
        return LIST == name;
    }

    static bool isMessageCommand(const std::string& name) {
        return MESSAGE == name;
    }

    static bool isTalkCommand(const char* cmd_name) {
        return strncmp(TALK_PRE, cmd_name, strlen(TALK_PRE)) == 0;
    }

    static bool isHelpCommand(const std::string& name) {
        return HELP == name || HELP_ == name;
    }

    static bool isLoginCommand(const char* cmd_name) {
        return strncmp(LOGIN_PRE, cmd_name, strlen(LOGIN_PRE)) == 0;
    }
};

static int process_command(char* cmd) {
    int ret;
    Command* pCommand = CommandFactory::make_command(cmd);
    ret = pCommand->execute();
    delete pCommand;
    return ret;
}

volatile bool stopped = false;

int main(void) {
    char* line;

    log_open("bgcc.cfg");

    SharedPointer<IProcessor> xp(
            new CallbackProcessor (
                SharedPointer<Callback>(
                    new CallbackImpl)));
    ServiceManager sm;
    sm.add_service(xp);
    proxy = new TalkerProxy(ServerInfo("localhost", 8509), 1, &sm);

    linenoiseSetCompletionCallback(completion);
    linenoiseHistoryLoad("history.txt");

    while(!stopped && (line = linenoise(CCTALKPROMPT)) != NULL) {
        if (line[0] != '\0') {
            process_command(line);
            linenoiseHistoryAdd(line);
        }
        free(line);
    }

    delete proxy;
    proxy = NULL;
    linenoiseHistorySave("history.txt");
    return 0;
}
