#include<iostream>
#include<conio.h>
using namespace std;
class base{
	private:
		int a;
	protected:
		int b;
		void virtual func()
		{
			cout<<"virtual protected";
		}
	public:
		int g;

		
};
class der: public base
{
	int a;
	public:
		 void func()
		 {
				cout<<"base";
		 }
};
main()
{
		 base *g,v;
		 der a;
		 g=&a;
		 //g->func();
		 a.func();
		 getch();
}
