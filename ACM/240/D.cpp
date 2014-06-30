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
#define MAX 2009
#define MOD 1000000007
int n,k;
vector<vi> memo(MAX,vi(MAX)) ;

int dp (int i,int pre) {
	if ( i > k || pre > n )
		return 0;
	if ( i == k && pre <= n)
		return 1;
	if (memo[i][pre])
		return memo[i][pre];
	ll ans = 0;
	for(int j=pre;j<=n;j+=pre)
		ans = (ans + dp(i+1,j))%MOD ;
	return memo[i][pre] = ans ;
}

int main() {
	cin >> n >> k ;
	ll ans = 0 ;
	for(int i=1;i<=n;i++) {
		ans = (ans + dp(1,i))%MOD ;
	}
	cout << ans ;
}


