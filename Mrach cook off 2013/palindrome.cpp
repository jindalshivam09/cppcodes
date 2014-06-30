#include<iostream>
#define N 26
#define MOD 1000000007
using namespace std;
long long p(long long n,long long m)
{
	if(m==0)
		return 1;
	long long temp=p(n,m/2)%MOD;
	if(m%2)
		return (((temp*temp)%MOD)*n)%MOD;
	else
		return (temp*temp)%MOD;
}
long long gp(int n)
{
	if(n)
		return (((N*(p(N,n)%MOD-1))%MOD)*((p(N-1,MOD-2))%MOD))%MOD;
	else return 0;
}
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long ans=0;
		int n;
		cin>>n;
		if(n%2)
		{
			ans=2*gp(n/2);
			ans%=MOD;
			ans+=p(N,(n+1)/2);
			ans%=MOD;
		}
		else
		{
			ans=2*gp(n/2);
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
