#include<iostream>
using namespace std;

//------nested namespaces-----------------
namespace MAIN
{
	int a=9;
	namespace NESTED
	{
		int a=8;
	}
}

///////////////////////////////////////////////

using namespace MAIN;
//using namespace NESTED;
main()
{
	cout<<MAIN::a<<" "<<a<<" ";
	cout<<NESTED::a;
	while(1);
}
