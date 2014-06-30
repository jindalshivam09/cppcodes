#include<iostream>
using namespace std;
void func()throw()       // this will restrict rethrowing of exceptions
{
	 try
	 {
		throw 3;
	 }
	 catch(int)
	 {
		cout<<"func int";
//		throw;
	 }
}
main()
{
	int a;
	try
	{
		func();

	}
	catch(int)
	{
		cout<<"main int";
	}
	while(1);
}
