//----------Program Name: placement Syntax----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date: 9 april22013------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MOD 1000000007
class abc
{
	int a;
	public:
		void *operator new(size_t s,void *buf)
		{
			return buf;
		}
		void *operator new(size_t a)
		{
			return (void *)malloc(a);
		}
};
using namespace std;
main()
{
	int *p;
	abc *a,*b;
	p=new int;
	void *buf=reinterpret_cast<void *>(p);
	a=new abc;
	b=new(buf)abc;
	cout<<p<<" "<<a<<" "<<b;;
	cin.get();
	return 0;
}
