#include "WS_ApServer.h"
#include "AgentProxy.h"
#include "../../../../interface/third/json-cpp/include/json/json.h"
using websocketpp::lib::bind;

char* CmdType[]={
	"SignIn","SignOut","SetAgentStatus","GetAgentStatus","ResetStatuschangetype","ResetAutoAnswer",
	"ResetSkill","ResetSkill",
	"OutboundCall","AnswerCall","ReleaseCall","Hold","Retrieve","Consult","ConsultReconnect","ConsultTransfer","SingleStepTransfer","ConsultConference"
	,"ConferenceJoin","SetAssociateData","GetAssociateData","JumptheQueue","ForceSignIn",
};
WSapserver::WSapserver()
{

}
WSapserver::~WSapserver()
{

}


bool WSapserver::InitApServer(std::string ApListenIp, int32_t ApListenPort, int32_t threadPoolNum)
{

	bool status = true;

	m_ApListenIp = ApListenIp;
	m_ApListenPort = ApListenPort;
	m_threadPoolNum = threadPoolNum;
	m_server=new wsServer();
	return status;
}

bool WSapserver::startServer()
{
	m_server->init_asio();
	m_server->set_message_handler(bind(&WSapserver::on_message,this,m_server,::_1,::_2));
	m_server->set_open_handler(bind(&WSapserver::on_open,this,m_server,::_1));
	m_server->set_close_handler(bind(&WSapserver::on_close,this,m_server,::_1));
	m_server->set_reuse_addr(true);
	m_server->listen(m_ApListenPort);
	m_server->start_accept();
	m_server->run();
	return true;
}
bool WSapserver::stopServer()
{
	m_server->stop();
	m_server->stop_listening();
	return true;
}
void WSapserver::on_open(wsServer* s, websocketpp::connection_hdl hdl)
{
	//BGCC_TRACE("ap", "on_open called with hdl:%d", hdl.lock().get() );

}

void WSapserver::on_close(wsServer* s, websocketpp::connection_hdl hdl)
{
	//BGCC_TRACE("ap", "on_close called with hdl:%d", hdl.lock().get() );

}
void WSapserver::on_message(wsServer *s, websocketpp::connection_hdl hdl, message_ptr msg)
{
	//BGCC_TRACE("ap", "recv message:%s.", msg->get_payload().c_str());
	printf("recv message:%s.\n",msg->get_payload().c_str());
	// check for a special command to instruct the server to stop listening so
	// it can be cleanly exited.
	if (msg->get_payload() == "stop-listening")
	{
		s->stop_listening();
		return;
	}
	try
	{
		s->send(hdl, msg->get_payload(), msg->get_opcode());
		if(msg->get_payload()!="")
			on_callapclient(s,  hdl,msg->get_payload());
		wsServer::connection_ptr clientconn=	s->get_con_from_hdl(hdl);
		string strhost=clientconn->get_host();
		uri_ptr uri_ = clientconn->get_uri();
		string remoteinfo = clientconn->get_remote_endpoint();
		string anhost = uri_->get_host();
		printf("host:%s\n",strhost.c_str());

	}
	catch (websocketpp::exception const &e)
	{
		//BGCC_WARN("ap", "Echo failed because: %s", e.what());
	}

}
int WSapserver::Getcmdvalue(string strcmd)
{

}
int WSapserver::GetcmdType(string cmdfield)
{
	//CmdType[]
	int size=sizeof(CmdType);
	for(int i=0;i<size;i++)
	{
		if(CmdType[i]==cmdfield)
		{
			return i;
		}
	}
	return WSAP_ERRORTYPE;

	
}
void WSapserver::on_callapclient(wsServer *s, websocketpp::connection_hdl hdl,string applicationcmd)
{
	Json::Reader reader;
	Json::Value root;
	if(!reader.parse(applicationcmd.c_str(),root))
	{
		return;
	}
	if(root["cmd"].isNull())
		return;
	int cmdNUM=GetcmdType(root["cmd"].asString());
	acd::AcdResultT ret;
	switch (cmdNUM)
	{
	case WSAP_SignIn:
		{
			Json::Value jsonparam;
			jsonparam=root["param"];
			if(jsonparam.isNull())
				return;
			string agentId = jsonparam["agentId"].asString();
			string agentDn = jsonparam["agentDn"].asString();
			string agentPwd = jsonparam["agentPwd"].asString();
			acd::StatusChangeT statusChangetype = jsonparam["agentId"].asInt();
			bool autoAnswer = jsonparam["autoAnswer"].asBool();
			bool fcSignin = jsonparam["fcSignin"].asBool();
			string skills = jsonparam["skills"].asString();
			int64_t handle = jsonparam["handle"].asInt64();
				BGCC_TRACE("ap",
				"SignIn AgentId = %s,AgentDn = %s,AgentPwd = %s,statusChangetype = %d,autoAnswer = %d,fcSignin = %d,skill = %s.",
				agentId.c_str(), agentDn.c_str(), agentPwd.c_str(), statusChangetype.get_value(), autoAnswer,
				fcSignin, skills.c_str());
			uint64_t time_rcv = TimeUtil::get_timestamp_ms();
			AgentProxy *agentProxy = AgentProxy::Instance();
			//acd::AcdResultT ret;
			const std::map<std::string, std::string> ctx;
			//acd::StatusChangeT statusChangetype=_status ;
			ret = agentProxy->SignIn(agentId, agentDn, agentPwd, statusChangetype, autoAnswer, fcSignin, skills,
				handle, ctx, time_rcv);
		}
		break;
	case WSAP_SignOut:
		{
			Json::Value jsonparam;
			jsonparam=root["param"];
			if(jsonparam.isNull())
				return;
			string agentId = jsonparam["agentId"].asString();
			int64_t handle = jsonparam["handle"].asInt64();
			BGCC_TRACE("ap", "SignOut AgentId = %s,handle = %" int64ld ".", agentId.c_str(), handle);
			uint64_t time_rcv = TimeUtil::get_timestamp_ms();
			AgentProxy *agentProxy = AgentProxy::Instance();
			AcdResultT ret;
			const std::map<std::string, std::string> ctx;
			ret = agentProxy->SignOut(handle, agentId, ctx, time_rcv);
		}
		break;
	case WSAP_SetAgentStatus:
		{
			Json::Value jsonparam;
			jsonparam=root["param"];
			if(jsonparam.isNull())
				return;
			string agentId = jsonparam["agentId"].asString();
			int64_t handle = jsonparam["handle"].asInt64();
			string restReason = jsonparam["restReason"].asString();
			AgentStatusT agentStatus=jsonparam["agentStatus"].asInt();
			BGCC_TRACE("ap",
				"SetAgentStatus AgentId = %s,handle = %" int64ld ",agentStatus = %d,restReason = %s.",
				agentId.c_str(), handle, agentStatus.get_value(), restReason.c_str());
			uint64_t time_rcv = TimeUtil::get_timestamp_ms();
			AgentProxy *agentProxy = AgentProxy::Instance();
			AcdResultT ret;
			AgentData agentinfo;
			const std::map<std::string, std::string> ctx;
			ret = agentProxy->SetAgentStatus(handle, agentId, agentStatus, restReason, ctx, time_rcv);
		}
		break;
	case WSAP_GetAgentStatus:
		{
			Json::Value jsonparam;
			jsonparam=root["param"];
			if(jsonparam.isNull())
				return;
			string agentId = jsonparam["agentId"].asString();
			int64_t handle = jsonparam["handle"].asInt64();
			AgentStatusT agentStatus=jsonparam["agentStatus"].asInt();
			BGCC_TRACE("ap", "GetAgentStatus AgentId = %s,handle = %" int64ld ",agentStatus = %d.",
				agentId.c_str(), handle, agentStatus.get_value());
			uint64_t time_rcv = TimeUtil::get_timestamp_ms();
			AgentProxy *agentProxy = AgentProxy::Instance();
			AcdResultT ret;
			const std::map<std::string, std::string> ctx;
			ret = agentProxy->GetAgentStatus(handle, agentId, agentStatus, ctx, time_rcv);
		}
		break;
	case WSAP_ResetStatuschangetype:
		{
			Json::Value jsonparam;
			jsonparam=root["param"];
			if(jsonparam.isNull())
				return;
			string agentId = jsonparam["agentId"].asString();
			int64_t handle = jsonparam["handle"].asInt64();
			acd::StatusChangeT statusChangetype = jsonparam["agentId"].asInt();
			BGCC_TRACE("ap", "ResetStatuschangetype AgentId = %s,handle = %" int64ld ",statusChangetype = %d.",
				agentId.c_str(), handle, statusChangetype.get_value());
			uint64_t time_rcv = TimeUtil::get_timestamp_ms();
			AgentProxy *agentProxy = AgentProxy::Instance();
			AcdResultT ret;
			const std::map<std::string, std::string> ctx;
			ret = agentProxy->ResetStatuschangetype(handle, agentId, statusChangetype, ctx, time_rcv);
		}
		break;
	case WSAP_ResetAutoAnswer:
		{
			Json::Value jsonparam;
			jsonparam=root["param"];
			if(jsonparam.isNull())
				return;
			string agentId = jsonparam["agentId"].asString();
			int64_t handle = jsonparam["handle"].asInt64();
			bool autoAnswer = jsonparam["autoAnswer"].asBool();
			BGCC_TRACE("ap", "ResetAutoAnswer AgentId = %s,handle = %" int64ld ",autoAnswer = %d.",
				agentId.c_str(), handle, autoAnswer);
			uint64_t time_rcv = TimeUtil::get_timestamp_ms();
			AgentProxy *agentProxy = AgentProxy::Instance();
			AcdResultT ret;
			const std::map<std::string, std::string> ctx;
			ret = agentProxy->ResetAutoAnswer(handle, agentId, autoAnswer, ctx, time_rcv);
		}
		break;
	case WSAP_OutboundCall:
		{
			Json::Value jsonparam;
			jsonparam=root["param"];
			if(jsonparam.isNull())
				return;
			string agentId = jsonparam["agentId"].asString();
			int64_t handle = jsonparam["handle"].asInt64();
			bool autoAnswer = jsonparam["autoAnswer"].asBool();
			string callerId = jsonparam["callerId"].asString();
			string destId = jsonparam["destId"].asString();
			string forCallerDispNum = jsonparam["forCallerDispNum"].asString();
			string forCalleeDispNum = jsonparam["forCalleeDispNum"].asString();
			const CallModeT callMode =  jsonparam["callMode"].asInt();
			const CallTypeT callType =  jsonparam["callType"].asInt();
			int Timeout = jsonparam["timeout"].asInt();
			BGCC_TRACE("ap",
				"OutboundCall AgentId = %s,handle = %" int64ld ",callerId = %s,destId = %s,forCallerDispNum = %s,forCalleeDispNum = %s,timeout = %d,callMode = %d,callType = %d.",
				agentId.c_str(), handle, callerId.c_str(), destId.c_str(), forCallerDispNum.c_str(),
				forCalleeDispNum.c_str(),
				Timeout, callMode.get_value(), callType.get_value());
			uint64_t time_rcv = TimeUtil::get_timestamp_ms();
			AgentProxy *agentProxy = AgentProxy::Instance();
			AcdResultT ret;
			const std::map<std::string, std::string> ctx;
			ret = agentProxy->OutboundCall(handle, agentId, callerId, destId, forCallerDispNum,
				forCalleeDispNum, Timeout, callMode, callType, ctx, time_rcv);
		}
		break;
	default:
		{

		}
		break;
	}
	string respmsg=Onresponse(ret.get_value(),"ok");
	s->send(hdl,respmsg.c_str(), respmsg.length(),frame::opcode::text);

}
string WSapserver::Onresponse(int code,string desc)
{

	Json::Value respjosn;
	Json::Value jsoncontent;
	Json::Value jsonvalue;
	Json::Value jsondesc;
	jsonvalue["value"]=0;
	jsonvalue["desc"]=desc;
	jsoncontent.append(jsonvalue);
	jsoncontent.append(jsondesc);
	respjosn["code"]=code;
	respjosn["content"]=jsoncontent;
	respjosn.toStyledString();
	return  respjosn.toStyledString();
}