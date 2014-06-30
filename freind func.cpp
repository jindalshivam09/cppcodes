#include<iostream>
using namespace std;
#include<conio.h>
class c2;
class c1{
	private:
		int print;
	public:
		c1():print(0)
		{ }
		c1(int flag): print(flag)
		{ }
		friend void  printNeed(c1,c2);
		
};
class c2{
	private:
		int print;
   public:
		c2():print(1)
		{ }
		c2(int flag):print(flag)
		{ }
		friend void  printNeed(c1,c2);

};
void printNeed(c1 o1,c2 o2)
{
	o1.print?cout<<"print needed for class 1":cout<<"no print req for class 1";
	cout<<endl;
	o2.print?cout<<"print needed for class 2":cout<<"no print req for class 2";
	cout<<endl;
}
main()
{
	c1 o11,o12(1),o13(0);
	c2 o21,o22(1),o23(0);
	printNeed(o11,o21);
	printNeed(o12,o22);
	printNeed(o13,o23);
	getch();
}
