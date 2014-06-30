#include<iostream>
using namespace std;
union{
	unsigned e;
	int b;
	int a;
	//int  e;
}abc;
main()
{
	cout<<&(abc.a)<<" "<<&(abc.b)<<" "<<&(abc.e)<<" shivam ";
	abc.a=9;
	abc.b=8;
	int e=abc.a+abc.b;
	cout<<" "<<abc.a<<" "<<abc.b<<" "<<e;
	int a;
	cin>>a;
}
