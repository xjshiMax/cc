//2019/3/18
//使用websock接口实现客户端对接服务端。

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "acdcommon.h"
//#include "../../../../interface/output/third/json-cpp/include/json.h"
using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using namespace std;
using namespace websocketpp;
// pull out the type of messages sent by our config
typedef websocketpp::server<websocketpp::config::asio> wsServer;
typedef wsServer::message_ptr message_ptr;

typedef struct ApAgentInfo
{
	string agentId;          /*坐席工号，并唯一标示一个agentbar连接*/
	string agentDn;         /*座席使用的电话号码*/
	string agentPwd;        /*座席签入的密码*/
	acd::StatusChangeT statusChangetype; /*挂断后状态（自动示闲、自动示忙）*/
	bool autoAnswer; /*挂断后，从示闲或示忙状态到后处理的时间间隔，默认5秒*/
	bool fcSignin; /*坐席已签入，是否强制签出后迁入 */
	string skills; /*技能和技能级别描述*/
	string proxyname; /*保存的proxyname*/
	string proxyname_old;
	int64_t handle;
	int32_t flag;

}t_ApAgentInfo;

enum{
	WSAP_SignIn,WSAP_SignOut,WSAP_SetAgentStatus,WSAP_GetAgentStatus,WSAP_ResetStatuschangetype,WSAP_ResetAutoAnswer,
	WSAP_ResetSkill,
	WSAP_OutboundCall,WSAP_AnswerCall,WSAP_ReleaseCall,WSAP_Hold,WSAP_Retrieve,WSAP_Consult,WSAP_ConsultReconnect,WSAP_ConsultTransfer,WSAP_SingleStepTransfer,WSAP_ConsultConference
	,WSAP_ConferenceJoin,WSAP_SetAssociateData,WSAP_GetAssociateData,WSAP_JumptheQueue,WSAP_ForceSignIn,
	WSAP_ERRORTYPE
};
class WSapserver
{
public:
	WSapserver();
	~WSapserver();
	bool InitApServer(std::string ApListenIp, int32_t ApListenPort, int32_t threadPoolNum);
	bool startServer();
	bool stopServer();
	void on_open(wsServer* s, websocketpp::connection_hdl hdl);
	void on_close(wsServer* s, websocketpp::connection_hdl hdl);
	void on_message(wsServer *s, websocketpp::connection_hdl hdl, message_ptr msg);
	void on_callapclient(wsServer *s, websocketpp::connection_hdl hdl,string applicationcmd);
	int Getcmdvalue(string strcmd);
	int GetcmdType(string cmdfield);
	string Onresponse(int code,string desc);
private:
	std::string m_ApListenIp;
	int32_t m_ApListenPort;
	wsServer* m_server;
	int32_t m_threadPoolNum;
};