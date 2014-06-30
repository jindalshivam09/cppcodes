#include<iostream>
#include<conio.h>
#include<iterator>
using namespace std;
main()
{
	istream_iterator<int> shivam(cin);
	int a=*shivam;
	ostream_iterator<int>  jindal(cout);
	*jindal=a;
	ostream_iterator<string> oo(cout);
	*oo="shivam";
	++oo;
	*oo="jindal";
	getch();
}
