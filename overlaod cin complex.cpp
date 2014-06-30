#include<iostream>
#include<conio.h>
using namespace std;
class complex
{
	private:
		int real;
	public:
		complex(int i=0,int j=0)
		{
			real=i;
		}
};
ostream & operator >> (ostream &cout,complex c)
{
	//cout<<c.real;
	cout<<"hi";
}
main()
{
	complex c;
	cout>>c;
	getch();
}
