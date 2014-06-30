#include<iostream>
#include<conio.h>
using namespace std;
main()
{
	int a=1,b=9,d=1;
	int c=d>b?d=b:b=d;
	cout<<&a<<" ";
	++a;
	cout<<&a<<" ";
	
	int *p=&++a;
	cout<<c<<" "<<*p;
	getch();
}
