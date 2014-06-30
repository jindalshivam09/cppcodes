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

int main() {
	int n;
	cin >> n ;
	vi arr(10);
	rep(i,10)	
		cin >> arr[i] ;
	vector<vll> c(n+8,vll(n+8)) , dp(n+8,vll(n+8));
	rep(i,n+1)
		c[0][i] = 0 , c[i][0] = 1 ;
	repi(i,1,n+1) {
		repi(j,1,i+1) {
			c[i][j] =( c[i-1][j-1] + c[i-1][j] ) % MOD ;
		}
	}
	rep(i,n+1) {
		for(int j=9;j>=0;j--) {
			if (j==0) {
				repi(k,arr[0],n+1) 
					if (!i)	dp[i][0] = 0;
					else if (i>=k)
						dp[i][0] = (dp[i][0] + (dp[i-k][1]*c[i-1][k])%MOD ) % MOD ;
			}
			else if ( j < 9 ) {
				repi(k,arr[j],n+1) if (i>=k)
					dp[i][j] = (dp[i][j] + (dp[i-k][j+1]*c[i][k])%MOD ) % MOD ;			
			}
			else {
				if ( i >= arr[9] )	dp[i][9] = 1 ;
				else				dp[i][9] = 0 ;
			}
		}
	}
	ll ans = 0 ;
	repi(i,1,n+1)
		ans = (ans + dp[i][0])  % MOD ;
	cout << ans << endl;
}


