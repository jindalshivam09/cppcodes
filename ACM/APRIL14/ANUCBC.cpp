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
#define MOD 1000000009
#define MAX 109
#define MAXA 100009
vll arr(MAXA) , fact(MAXA) , ifact(MAXA);
int n,q,m ;

void init() {
	fact[0] = 1;
	vll invert(MAXA);
	invert[1] = 1;
	ifact[0] = 1;
	for(int i=2;i<MAXA;i++){
		invert[i] = (MOD - ((MOD/i) * invert[MOD%i] % MOD)%MOD );
	}
	
	for(ll i=1; i<MAXA; i++){
		fact[i] = (i*fact[i-1])% MOD;
		ifact[i] = (invert[i] * ifact[i-1])% MOD;
	}	
}

ll C ( int n, int r) {
	return ((( fact[n]*ifact[r])%MOD)*ifact[n-r] ) % MOD ;
}

ll func(int m) {
	ll ans = 0 ;
	vi freq(m+9) , temp(m+8);
	vector<vll> dp(m+9,vll(m+9));
	
	rep(i,n) {
		int temp = arr[i]%m ;
		freq[(temp+m)%m] ++ ;
	}
	
	rep(i,m) {
		int count = 0 ;
		for(int j=1;j<=freq[i];j++) {
			dp[i][(i*j)%m] = ( dp[i][(i*j)%m] +  C(freq[i],j) ) % MOD; 
		}
		if(i) {
			rep(j,m){
				temp[j] = dp[i][j] ;
			}
			rep(k,m) {
				rep(l,m) {
					dp[i][(k+l)%m] = ( dp[i][(k+l)%m] + (temp[k] * dp[i-1][l])%MOD ) % MOD ;
				}
			}
			rep(j,m)
				dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD ;
		}
	}
	return dp[m-1][0]+1 ;
}

int main() {
	init() ;
	int t;
	scanf("%d",&t) ;
	while(t--) {
//		scanf("%d%d",&n,&q) ;
		n = 100000 , q = 1 ;
		rep(i,n)
//			scanf("%lld",&arr[i]) ;
		arr[i] = 1000000000;
		while(q--) {
//			scanf("%d",&m) ;
			m = 100 ;
			printf("%lld\n",func(m)) ;
		}
	}
}


