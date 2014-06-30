#include<iostream>
using namespace std;

class B1
{};

class B2
{};

class D1:public B1,public B2
{};


int main()
{
	try
	{
		throw &D1();
	}
	
	catch(B1)
	{
		cout<<"Constructor of Base1";
	}

}
