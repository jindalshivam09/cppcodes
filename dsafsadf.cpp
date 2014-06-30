#include<iostream>
using namespace std;

class X
{
	public:
		~X()
		{
			throw 7;
		}

};

int func()
{
	X ob;
	throw 5;
}

int main()
{
	try
	{
	try
	{
		func();
	}catch(int x)
	{
		cout<<x;
	}
	}catch(int x)
	{
		cout<<x;
	}	

}
