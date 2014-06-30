//----------Program Name:----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date:------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
void fun() throw(double)
{
	float f=3.4;
		try{
			throw 3.4 ;
		}
		catch(float a)
		{
			cout<<"throw\n";
			//throw;
		}
		catch(...) {
			cout << "double";
			throw;
		}
}
main()
{
	try{
		fun();
	}
	catch(int a)
	{
		cout<<a<<" ";
		cout<<"rethrow\n";
	}
	catch(...) {
		cout << "rethrow2";
	}
	cin.get();
    return 0;
}
