#include<iostream>
#define MOD 1000000007
#define MAX 1000000
using namespace std;
typedef long long ll;
ll pow(int q,int n)
{
	 ll ans;
	 if(n==1)
       		return q;
	else {
		ans=pow(q,n/2)%MOD;
		ans*=ans;
		ans%=MOD;
		if(n%2)
		{
				  ans*=q;
				  ans%=MOD;
		}
	}
	return ans;
}
ll fact[MAX];
void init()
{
	fact[0]=1;
	for(int i=1;i<=MAX;i++)
	{
		fact[i]=(fact[i-1]*i)%MOD;
	}
}
main() {
	int t;
	cin >> t;
	init();
	while(t--) {
		int n,m;
		cin >> n >> m ;
		int temp = m - n ;
		ll ans=1;
		int i=n;
		int j=0;
		if( m > 2*n-1)
		cout << fact[n] << endl;
		else if(m < (n+1))
		cout << 1 << endl;
		else {
					ans=fact[m/2 -(n-m/2)];
					ans*= ((pow(m-n+1,n-m/2)%MOD) * (pow((m-n),n-m/2)%MOD))%MOD;
		//			ans*=fact(m/2 -(n-m/2));
					ans %= MOD ;
		
			cout << ans << endl;
		}
	}
}
