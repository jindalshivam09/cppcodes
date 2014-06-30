#include<iostream>
using namespace std;
int a=2;
int f()
{
	if(a==2)
	return a=2;
	a*=2;
	return 0;
}

main()
{
	  int w=f();
	  cout<<w<<" "<<a<<" ";
	  w=f();
	  cout<<w<<" "<<a;
	  int q;
	  cin>>q;
}
