#include<iostream>
#include<conio.h>
using namespace std;
void func()
{
	ios_base::iostate s=cin.rdstate();
	if(s&ios_base::badbit)
	cout<<"badbit";
    else if(s&ios_base::eofbit)
	cout<<"eofbit";
	else if(s&ios_base::failbit)
	cout<<"failbit";
	else if(s&ios_base::goodbit)
	cout<<"goodbit";
	else
	cout<<"jindal";
}
main()
{
	func();
	getch();
}
