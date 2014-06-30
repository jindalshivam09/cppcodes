#include<iostream>
#include<array>
using namespace std;


int main()
{
	array<int,6> a;
	a[0]=1;
	a[1]=2;
	a[2]=3;
	a[3]=5;
	for(int &x:a)
	{
		cout<<x<<endl;
	}
}
