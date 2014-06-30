#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long  MOD =1000000007;

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
#define MAX 100009
long long factorial[MAX] , inv_factorial[MAX];
	long long inv[MAX] ;
void func() {
//	cout << "fd";
	factorial[0] = 1;
	inv[1] = 1;
	inv_factorial[0] = 1;
	for(int i=2;i<MAX;i++){
		inv[i] = (MOD - ((MOD/i) * inv[MOD%i] % MOD)%MOD );
	}
	
	for(ll i=1; i<MAX; i++){
		factorial[i] = (i*factorial[i-1])% MOD;
		inv_factorial[i] = (inv[i] * inv_factorial[i-1])% MOD;
	}	
}

long long ncr ( ll n, ll r) {
	return ((( factorial[n]*inv_factorial[r])%MOD)*inv_factorial[n-r] ) % MOD ;
}

int main(){
	func() ;
	long long t;
	cin>>t;
	while(t--){
		long long arr[100002];
		long long brr[100002];
		long long n,q;
		scanf("%lld%lld",&n,&q);
		//cin>>n>>q;
		for(long long i=1;i<=n;i++)
		 scanf("%lld",&arr[i]);
		//	cin>>arr[i];
		while(q--){
			long long dp[102][102]={0};
			long long ans[102][102] ={0};
			long long countt[102] = {0};
			long long m;
			scanf("%lld",&m);
			//cin>>m;
			for(long long i=1;i<=n;i++)
			 brr[i] = (arr[i]%m);
			for(long long i=1;i<=n;i++)
			{
				if(brr[i] < 0)
				 brr[i] += m;
			}
		    for(long long i=1;i<=n;i++)
		     countt[brr[i]]++;
		     dp[0][0] = powww(2,countt[0],MOD) -1 ;
		     if(dp[0][0] < 0)
		      dp[0][0] += MOD;
	//	     cout<<dp[0][0]<<endl;
//-----------------------------------------------------------
		    for(long long i=1;i<m;i++){
		    	  for(long long j=1;j<=countt[i];j++)
				  {
		    	  	dp[i][(i*j)%m] += ncr(countt[i],j);
		    	  	dp[i][(i*j)%m] %= MOD;
				  }
		    }
/*		    for(long long i=0;i<m;i++)
		 {    for(long long j=0;j<m;j++)
		      cout<<dp[i][j]<<" ";
		      cout<<endl;
		  }
		  cout<<endl;
		  cout<<endl;
*/	
//-------------------------------------------------------------
		   //dp[1][0] += dp[0][0];
		   //ans[1][0] = dp[1][0];
		   //for(long long i = 0;i<m;i++)
		   // ans[1][i] = dp[1][i];
		   for(long long i = 1 ;i<m;i++){
		   	 for(long long j =0 ;j< m;j++){
					for (long long k = 0 ;k<m ;k++){
						ans[i][(j+k)%m] = ans[i][(j+k)%m] + (dp[i][j]*dp[i-1][k])%MOD;
							ans[i][(j+k)%m] %= MOD;
					//	if((k+j)%m==3)
					//	 cout<<ans[i][0]<<endl;
					}			
			   }
			   for(long long l=0;l<m;l++)
			 	 {
			 	   ans[i][l] += dp[i-1][l]+dp[i][l];
			 	   ans[i][l] %= MOD;
			 	   dp[i][l] = ans[i][l];
				}
		 }
//-------------------------------------------------------
/*  		for(long long i=0;i<m;i++)
			 {    
			 	for(long long j=0;j<m;j++)
			      cout<<ans[i][j]<<" ";
			      cout<<endl;
			  }
 			cout<<endl;
		  cout<<endl;
		  for(long long i=0;i<m;i++)
		 {    for(long long j=0;j<m;j++)
		      cout<<dp[i][j]<<" ";
		      cout<<endl;
		  }
		  */
//------------------------------------------------------
	printf("%lld\n",(ans[m-1][0]+1)%MOD);
	//cout<<(ans[m-1][0]+1)%MOD<<endl;
   }
}
}
		    
