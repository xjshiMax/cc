#include <iostream>
#include <bgcc.h>
#include "math.h"
using namespace bgcc;
using namespace math;

int main()
{
	MathProxy proxy(ServerInfo("localhost",8504));
	int32_t a=24;
	int32_t b=8;
	int32_t sum;
	Result result;

	std::cout<<"Please input a:";
	std::cin>>a;
	std::cout<<"Please input number b:";
	std::cin>>b;
	result = proxy.add(a,b,sum);
	if(proxy.get_errno()!=0)
	{
		std::cout<<"Call proxy.add failed"<<std::endl;
		return 0;
	}
	if(Result::E_OVERLOW==result)
	{
		std::cout<<"Error:overflow\n";
	}
	else if(Result::E_DOWNLOW==result)
	{
		std::cout<<"Error: downflow\n";
	}
	else
	{
		std::cout<<a<<"+"<<b<<"="<<sum<<std::endl;
	}
	return 0;
}