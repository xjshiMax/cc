#include "../../interface/output/acd/include/acdcallback.h"
#include "../../interface/output/bgcc/include/bgcc.h"
#include "../../interface/output/bgcc/include/thread.h"
#include <string>
using namespace std;
using namespace bgcc;
using namespace acd;


class acdclientCallback:public acdcallback
{
public:
	virtual ~acdclientCallback() { }

	virtual void SendAgentEvent(
		const AgentEventT & event,
		const std::map<std::string, std::string>& ctx)
	{
		//return CcResultT::ResSuccess; 
	}

	virtual void SendMediaEvent(
		const MediaEventT & event,
		const std::map<std::string, std::string>& ctx) 
	{

	}

	virtual void SendQueueEvent(
		const RouteEventT & event,
		const std::map<std::string, std::string>& ctx)
	{

	}

	virtual void SendOtherEvent(
		const OtherEventT & event,
		const std::map<std::string, std::string>& ctx) 
	{

	}
};