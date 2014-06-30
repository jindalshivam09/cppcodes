#include<iostream>
using namespace std;

class base
{
	public:
		virtual void func()
		{
			cout<<"Base error";
		}

};

class d1:public base
{
	const char *op;
	
	public:
		d1(const char *p)
		{
			op=p;
		}
		void func()
		{
			cout<<"D1 handler"<<"Error"<<op;
		}
};

int main()
{

	try
	{
		throw d1("shobhit");
	}catch(base &ob)
	{
		ob.func();
	}+
}
