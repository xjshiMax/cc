#include "../../interface/output/ims/include/callback.h"
#include "../../interface/output/bgcc/include/bgcc.h"
#include "../../interface/output/bgcc/include/thread.h"
#include <string>
using namespace std;
using namespace bgcc;
using namespace ims;


class Clientcallback:public event_callback
{
public:
	virtual ~Clientcallback() { }

	virtual CcResultT SendCallEvent(
		const CallEventT & event,
		const std::map<std::string, std::string>& ctx);

	virtual CcResultT SendMediaEvent(
		const MediaEventT & event,
		const std::map<std::string, std::string>& ctx);

	virtual CcResultT SendRouteEvent(
		const RouteEventT & event,
		const std::map<std::string, std::string>& ctx);

	virtual CcResultT SendOtherEvent(
		const OtherEventT & event,
		const std::map<std::string, std::string>& ctx);
};

