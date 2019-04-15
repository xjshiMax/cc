#include <bgcc.h>
#include "math.h"
using namespace bgcc;
using namespace math;
class MathImpl: public Math
{
public:
	virtual ~MathImpl(){}
	virtual Result add(int32_t a, int32_t b, int32_t & sum, const std::map<std::string, std::string>& ctx)
	{
		Result result=Result::E_SUCCESS;
		int32_t tmp = a+b;
		if(a>0&&b>0 && tmp<=0)
		{
			result=Result::E_DOWNLOW;
		}
		else if(a<0 && b<0 &&tmp >=0)
		{
			result = Result::E_DOWNLOW;
		}
		else
		{
			sum=tmp;
		}
		return result;
	}
};

int main()
{
	SharedPointer<IProcessor> processor(new MathProcessor(SharedPointer<Math>(new MathImpl)));
	ServiceManager sm;
	sm.add_service(processor);
	ThreadPool tp;
	tp.init(10);

	Server server(&sm,&tp,8504);
	if(0!=server.serve())
	{
		return 0;
	}
	return 0;
}