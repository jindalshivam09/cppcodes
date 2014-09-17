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
#define MAX 109
vll fact(MAX),ifact(MAX);

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

map<pair<int,ll>,ll> memo ;
int n,m;
ll dp ( int i, int sum) {
//	cout << i << " " << sum << endl;
	if(sum >= n && i < m  || sum+(m-i) > n)
		return 0 ;
	if(sum == n && i == m+1)
		return 1 ;
	if(i > m)
		return 0 ;
	if(memo[mp(i,sum)])
		return memo[mp(i,sum)] ;
	
	ll ans = 0 ;
	for(int j=1;j<=n-m+1;j++) {
		ans = (ans+(ifact[j]*dp(i+1,sum+j))%MOD)%MOD ;
	}
	return memo[mp(i,sum)] = ans;
}


int main() {
	init() ;
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;

	int t ;
	cin >> t ;
	for(int test = 1;test <= t;test ++){
		cin >> m >> n ;
		cout << "Case #" << test << ": " ;
		cout << (dp(1,0)*fact[n])%MOD << endl;
		memo.clear() ;
	}
}


