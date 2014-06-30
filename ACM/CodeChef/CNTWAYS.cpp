#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
#define MOD 1000000007
#define MAX 800009
vll fact(MAX),ifact(MAX);
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
	vll invert(MAX);
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
	n += r ;
	return ((( fact[n]*ifact[r])%MOD)*ifact[n-r] ) % MOD ;
}
int main() {
	init();
	int r;
	cin >> r;
	while(r--) {
		int n,m,a,b ;
		cin >> n >> m >> a >> b ;
		ll ans = 0 ;
		if(a==0||b==0) {
			cout << C(n,m) << endl;
			continue ;
		}
		for(int i=0;i<=n-a;i++) {
			if(i==n-a)
				ans += (C(i,b)*C(n-i,m-b)) % MOD ;
			else
				ans += (C(i,b)*C(n-i,m-b-1)) % MOD ;
			ans %= MOD ;
		}
		cout << ans << endl;;
	}
}


