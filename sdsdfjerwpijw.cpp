#include<iostream>
using namespace std;

class X`
{};

class Y:public X
{};



int main()
{
	try
	{
		throw Y();
	}
	catch(X)
	{
		cout<<"...";
	}
	catch(Y)
	{
		cout<<"int";
	}
	

}
