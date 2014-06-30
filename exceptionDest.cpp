//----------Program Name:----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date:------------------------
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MOD 1000000007
using namespace std;
ofstream file("memory");
class abc
{
	public:
	int a;
    public:
		abc(int b=9)
		{
			a=b;
			file<<"constructor\n";
		}
		~abc()
		{
				file<<"destructor\n";
		}
		void* operator new(size_t s)
		{
			file<<"manual consrtuctor";
			return (void *)malloc(s);
		}
		void operator delete(void *p)
		{
			file<<"manual destructor";
		}
};
main()
{
	abc d;
	abc *ob;
	ob=new abc;
	try
	{
		throw d;
	}
	catch(abc ob)
	{
			file<<ob.a;
			file<<"exception\n";
			file<<ob.a;
	}
	file<<d.a;
	cin.get();
    return 0;
}
