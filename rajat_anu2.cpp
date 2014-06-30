#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long  MOD =1000000009;
long long powww(long long n,long long m,long long MOD) 
{ 
  	if(m==0) return (1)%MOD;
   	long long x=powww (n,m/2,MOD);
    if(m%2==0) return (x*x)%MOD; 
	else return (((x*x)%MOD)*n) %MOD;
}
    ll gcd(ll a,ll b)
    {
        ll t;
        while(b)
        {
            t=b;
            b=a%b;
            a=t;
        }
        return a;
    }

    void div_by_gcd(ll &a, ll &b)
    {
        ll g=gcd(a,b);
        a/=g;
        b/=g;
    }

    ll ncr(long long n,long long k)
    {
        ll num=1,den=1,toMul,toDiv;
        if(k>n/2) k=n-k;
        for(int i=k;i>0;i--)
        {
            toMul=n-k+i;
            toDiv=i;
            div_by_gcd(toMul,toDiv);
            div_by_gcd(num,toDiv);
            div_by_gcd(toMul,den);
            num*=toMul;
            den*=toDiv;
        }
        return num/den;
    }
int main(){
	long long t;
	cin>>t;
	while(t--){
		long long arr[100002];
		long long brr[100002];
		long long n,q;
		scanf("%lld%lld",&n,&q);//		
//n = 100000 , q = 1 ;

		//cin>>n>>q;
		for(long long i=1;i<=n;i++)
		 scanf("%lld",&arr[i]);
		//	cin>>arr[i];
//		arr[i]  = 1000000000;
		while(q--){
			long long dp[102][102]={0};
			long long ans[102][102] ={0};
			long long countt[102] = {0};
			long long m;
			scanf("%lld",&m);
			//cin>>m;
//			m = 100;
			for(long long i=1;i<=n;i++)
			 brr[i] = (arr[i]%m);
			for(long long i=1;i<=n;i++)
			{
				if(brr[i] < 0)
				 brr[i] += m , brr[i] %= m ;
			}
		    for(long long i=1;i<=n;i++)
		     countt[brr[i]]++;
		     dp[0][0] = powww(2,countt[0],MOD) -1 ;
		     if(dp[0][0] < 0)
		      dp[0][0] += MOD;
		      ans[0][0] = dp[0][0] ;
		    for(long long i=1;i<m;i++){
		    	  for(long long j=1;j<=countt[i];j++)
				  {
		    	  	dp[i][(i*j)%m] += ncr(countt[i],j);
		    	  	dp[i][(i*j)%m] %= MOD;
				  }
		    }
		   for(long long i = 1 ;i<m;i++){
		   	 for(long long j =0 ;j< m;j++){
					for (long long k = 0 ;k<m ;k++){
						ans[i][(j+k)%m] = ans[i][(j+k)%m] + (dp[i][j]*dp[i-1][k])%MOD;
							ans[i][(j+k)%m] %= MOD;
					}			
			   }
			   for(long long l=0;l<m;l++)
			 	 {
			 	   ans[i][l] += dp[i-1][l]+dp[i][l];
			 	   ans[i][l] %= MOD;
			 	   dp[i][l] = ans[i][l];
				}
		 }
	printf("%lld\n",(ans[m-1][0]+1)%MOD);
   }
}
}
		    
