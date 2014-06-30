#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;

#define MOD 1000000007
#define MAX 1009
vector<long long> fact(MAX),ifact(MAX);
long long int calPow(int q,int n)
{
	 long long int ans;
	 if(n==1)	return q;
	 else{
		ans=calPow(q,n/2)%MOD;
 		ans*=ans;
		ans%=MOD;
		if(n%2)	{
				  ans*=q;
				  ans%=MOD;
		}
	}
	return ans;
}

void init() {
	fact[0] = 1;
	vector<long long> invert(MAX);
	invert[1] = 1;
	ifact[0] = 1;
	for(int i=2;i<MAX;i++){
		invert[i] = (MOD - ((MOD/i) * invert[MOD%i] % MOD)%MOD );
	}
	
	for(ll i=1; i<MAX; i++){
		fact[i] = (i*fact[i-1])% MOD;
		ifact[i] = (invert[i] * ifact[i-1])% MOD;
	}	
}
ll C ( int n, int r) {
	return ((( fact[n]*ifact[r])%MOD)*ifact[n-r] ) % MOD ;
}


int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int n,p;
		cin >> n >> p;
		ll sum =  0;
		for(int i = 0;i<p+1;i++) {
			sum = (sum + C(n,i)) % MOD ;
//			cout << sum << endl;
		}
		cout << sum << endl;
	}
}


