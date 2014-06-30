#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	long long int n,t,d,g;
	cout<<ln(2.0)<<endl;
	cin>>t;
	while(t--)
	{
		cin>>n;d=0;
/*		
		for(int i=1;i<=n;i++)
			d+=n/i;
		
		g=__gcd(d,n*n);
		d=d/g;
*/		
		long long ans = n*(long long)(log(n + 0.5)/log( 2.718281) + 0.5772 + 0.03759/(n*n + 1.171));
		 
		g=__gcd(ans,n*n);
		ans=ans/g;
		
		cout<<ans<<"/"<<(n*n)/ans<<endl;
	}
	
	return 0;
}
