#include<iostream>
using namespace std;

class base
{
	public:
		virtual void fx()
		{
			cout<<"hi";
		}
};

class inherited: public base
{
//	public:
	void fx()
		{
			cout<<"nothing to display";
		}
};

int main()
{
	inherited *ob;
	base bob;
	ob = dynamic_cast<inherited*>(&bob);
	if( ob )
	ob->fx();
	
	else 
	cout<<"null";
	
	return 0;
}
