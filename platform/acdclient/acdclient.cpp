#include "../../interface/output/acd/include/acdcallback.h"
#include "../../interface/output/acd/include/acd.h"
#include "../../interface/output/bgcc/include/bgcc.h"
#include "acdclientCallback.h"
#include <string>
using namespace  std;
using namespace bgcc;
using namespace acd;
int main()
{
	SharedPointer<IProcessor> processor(new acdcallbackProcessor(SharedPointer<acdcallback>(new acdclientCallback())));
	ServiceManager sm;
	sm.add_service(processor);

	string strACDip="192.168.2.100";
	acdapiProxy acdClientproxy(ServerInfo(strACDip.c_str(),8123),5,&sm,1);
	const std::string agentId="1234";
	const std::string agentDn="user/1006";
	const std::string agentPwd="123123";
	const StatusChangeT statusChangetype=StatusChangeT::ScReady;
	bool autoAnswer=false;
	bool fcSignin=true;
	const std::string skill="high";
	int64_t handle=0;
	//	bool last = false
	AcdResultT result = acdClientproxy.SignIn(agentId,agentDn,agentPwd,statusChangetype,autoAnswer,
		fcSignin,skill,handle);
	printf("rsult:%d",result);
	result = acdClientproxy.OutboundCall(handle,agentId,"user/1006","user/1005","me","you",
		100,CallModeT::CmOffhook,CallTypeT::CtOut);
	printf("rsult:%d",result);
	return 0;
}