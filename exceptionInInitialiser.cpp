//----------Program Name:----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date:------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MOD 1000000007
using namespace std;
class x
{
	int a;
	public:
		x(int);
};
x::x(int b=0)
{
try
{
	a=b;;
	throw *this;
}
catch(x g)
{
	cout<<"exception";
}
}
main()
{
	x d;
	cin.get();
    return 0;
}
