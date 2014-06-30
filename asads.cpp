#include<iostream>
using namespace std;

class a
{
	public:
		void operator =(const a &)
		{
			cout<<"aha operator";
		}
};

class b: public a
{
	public:
		void operator =(const b &)
		{
			cout<<"MY OP";
		}
};

int main()
{
	b ob1,ob2;
	ob1=ob2;	
}
