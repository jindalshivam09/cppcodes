#include<iostream>
using namespace std;
namespace user
{
	int a=4;
	void printf()
	{
		cout<<"user defined printf\n";
	}
}
namespace abc
{
	int a=15;
	using namespace user;
	//using namespace abc;
	//std::cout<<a;
}
namespace
{
		int a=6;
		void printf()
		{
			cout<<"unamed namespace";
		}
}
using namespace user;
void fun()
{
	cout<<abc::a<<" ";
	//printf();
}
using abc::a;
main()
{
	int a=100;
	cout<<a<<endl;
	fun();
	//printf();
//	using namespace abc;
	abc::a=5;
	cout<<user::a<<endl;
	abc::printf();
	cout<<abc::a<<" "<<user::a;
	while(1);
}
