//----------Program Name:exception handling through classes----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date:  april 2013------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
class handler
{
		int a;
		public:
			handler(int b=0)
			{
				cout<<"constructor\n";
				a=b;
			}
			handler( handler &x)
			{
				a=x.a;
				cout<<a;
				cout<<" copy constructor\n";
			}
			
};
main()
{
	int a;
	handler x(1);
	try
	{
     	throw x;
	}
	catch(handler x)
	{
		cout<<"exception";
	}
	cin.get();
    return 0;
}
