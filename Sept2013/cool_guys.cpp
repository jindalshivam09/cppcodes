#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long int n,t,d,g;
	cin>>t;
	while(t--)
	{
		cin>>n;d=0;
		for(int i=1;i<=floor(sqrt(n));i++)
			d+=n/i;
			
		d=2*d;
		d=d-pow(floor(sqrt(n)),2);
		g=__gcd(d,n*n);
		d=d/g;
		cout<<d<<"/"<<(n*n)/g<<endl;
	}
	
	return 0;
}
