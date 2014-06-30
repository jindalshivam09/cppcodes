//under construction--------------
//----------Program Name:barcelona Game ----------------------

//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date: 4 April 2013------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#define MOD 1000000007
using namespace std;
long long  calPow(int q,int n)
{
	long long ans;
	if(!n)
	return 1;
	if(n==1)
	return q;
	else
	{
		ans=calPow(q,n/2);
		ans*=ans;
		ans%=MOD;
		if(n%2){
		ans*=q;
		ans%=MOD;}
	}
	return ans%MOD;
}

main()
{
	int t;
	scanf("%d",&t);
	int n,k;
	long long ans;
	while(t--)
	{
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n/2;i++)
		{
			//cout<<calPow(k,i)<<" "<<calPow(k-1,n-2*i)<<endl;
			ans+=(calPow(k,i)*calPow(k-1,n-2*i)*)%MOD;  //multiply N-i+1 C i this are the positions for messi where N=n-2
			ans%=MOD;
		}
		printf("%lld\n",ans);

	}
    return 0;
}
