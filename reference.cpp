#include<iostream>
using namespace std;
main()
{
	int b=9;
	int &a=b;;
	int r=8;
	a++;
	cout<<a<<" " ;
	const int *q=&a;
	string s1=" shivam";
	string s2="shivam";
	cout<<&s1<<" "<<&s2;
	cin>>r;
	
}
