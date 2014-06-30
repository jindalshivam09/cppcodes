#include<iostream>
#include<windows.h>
using namespace std;

int * init()
{
	throw 5;
}
class ptr
{
	int *p;
	public:
		ptr()
		{
			cout<<"Constructing ptr"<<endl;
			unsigned int x=90000000;
			cout<<x;
			p=new int[x];
			p=init();
		}
		
		~ptr()
		{
			delete[] p;
			cout<<"Destructing ptr"<<endl;
		}

};

int main()
{
	try
	{
		ptr x;
	}
	catch(int)
	{
		cout<<"Handling exception"<<endl;
	}
	Sleep(10000000000);

}
