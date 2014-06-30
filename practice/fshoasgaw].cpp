#include<math.h>
#include<iostream>
using namespace std;

int main()
{
	double a=log(12)/log(24);
	double b=log(12)/log(36);
	double c=log(12)/log(48);
	cout<<1+a*b*c<<endl;
	cout<<2*a*c<<endl;
	cout<<2*b*c<<endl;
	cout<<2*a*b<<endl;
	
	cin.get();
}
