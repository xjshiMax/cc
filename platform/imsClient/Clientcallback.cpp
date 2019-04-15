#include "Clientcallback.h"

 CcResultT Clientcallback::SendCallEvent(
	const CallEventT & event,
	const std::map<std::string, std::string>& ctx)
{
	return CcResultT::ResSuccess;
}

 CcResultT Clientcallback::SendMediaEvent(
	const MediaEventT & event,
	const std::map<std::string, std::string>& ctx)
{
	return CcResultT::ResSuccess;
}

 CcResultT Clientcallback::SendRouteEvent(
	const RouteEventT & event,
	const std::map<std::string, std::string>& ctx)
{
	return CcResultT::ResSuccess;
}

 CcResultT Clientcallback::SendOtherEvent(
	const OtherEventT & event,
	const std::map<std::string, std::string>& ctx)
{
	return CcResultT::ResSuccess;
}


