#include<iostream>
using namespace std;
int add(int a,int b)
{
	return a+b;
}
float add(int a,float b)
{
	return a+b;
}
main()
{
	int a,b;
	int c=add(a,b);
	float d=add(a,(float)b);
}
