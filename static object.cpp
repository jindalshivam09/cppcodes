#include<iostream>
#include<conio.h>
using namespace std;
class abc{
	int a;
	char b;

	char c;
	int r;
	static abc ob;
	public:

		abc(int i=0,char j=0):a(i),c(j)
		{
			cout<<"constr";
		}
		virtual void display()
		{
			cout<<a<<" "<<c;
		}
};
main()
{
	abc d;
	cout<<" "<<sizeof(d);
	getch();
}
