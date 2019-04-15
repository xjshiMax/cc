#include "../../interface/output/ims/include/ims.h"
#include "../../interface/output/bgcc/include/bgcc.h"
#include "Clientcallback.h"
#include <string>
using namespace std;
using namespace bgcc;
using namespace ims;

int  main()
{

	SharedPointer<IProcessor> processor(new event_callbackProcessor(SharedPointer<event_callback>(new Clientcallback())));
	ServiceManager sm;
	sm.add_service(processor);


	string strIMSip="192.168.2.100";
	imsapiProxy ClientProxy(ServerInfo(strIMSip.c_str(),9527),5,&sm,1);
	

	ReqIdT myreqid;
	CcResultT result = ClientProxy.Register(ServiceTypeT::ServiceACD,myreqid);
	if(CcResultT::ResSuccess!=result)
	{
		return 0;
	}
	DnTypeT mytype(DnTypeT::IvrANI);
	result = ClientProxy.Assign(myreqid,"user/1006",DnTypeT::AgentDn);
	SessionIdT mysession=123456;

	result = ClientProxy.OutboundCall(myreqid,"user/1006","user/1005","num1","num2",100,CallModeT::Persist,mysession);

	return 0;
}