#include<iostream>
using namespace std;


class X
{
	public:
		X()
		{
			cout<<"Default Constructor"<<endl;
		}
		
		X(const X & ob)
		{
			cout<<"cOPY CONSTRUCTOR"<<endl;
		}
		~X()
		{
			cout<<"Destructor"<<endl;
					}
};
int main()
{
	try
	{
		throw X();
	}
	
	catch(X ob)
	{
	
	}
	cout<<"hi,.";

}
