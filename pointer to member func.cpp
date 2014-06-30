#include<iostream>
#include<conio.h>
using namespace std;
class base{
	private:
		int a;
	public:
	virtual	void func(int a)
		{
			cout<<"func";
		}
};
class der:public base
{
	public:
		void func(int a)
		{
			cout<<"base func";
		}
};
main()
{
	der b;
	der ::*ptr;
	ptr=& (base::func);
	b.*ptr;
	getch();
}
