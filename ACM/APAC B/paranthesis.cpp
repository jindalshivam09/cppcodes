#include<bits/stdc++.h>
using namespace std;

#define MAX 102
typedef long long ll ;
ll INF=1000000000 ;
ll n, k ;
vector<vector<ll> > dp(MAX,vector<ll>(MAX)) ;


void init() {
	INF *= INF ;
	dp[0][0] = 1 ;
	
	for(int i=1 ; i<MAX ; i++)  {
		dp[i][0] = 1 ;
		for(int j=1 ; j<=i ; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
			if(dp[i][j] > INF)
				dp[i][j] = INF ;
//			cout << dp[i][j] << " ";
		}
//		cout << endl;
	}
}

string paranthesis () {
	if( dp[n][n] < k ) {
		return "Doesn't Exist!" ;
	}
	string ans ;
	int l = n, r = n ;
	while( l > 0 || r > 0  ) {
//		cout << k << " " << dp[l][r-1] << " "  << l << " " << r-1 << endl;;
		if( r > 0) {
			if( dp[l][r-1] >= k ) {
				ans += "(" ;
				r-- ;
			}
			else {
				ans += ")";
				k -= dp[l][r-1] ;  
				l--;
			}
		}
		else if(l > 0) {
			ans += ")";
			l--;
		}
//		cout << ans << endl;
	}
	return ans; 
//	cout << ans << endl;
}

int main() {
		ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;

	init() ;
	int t ;
	cin >> t ;
	for(int test=1;test<=t;test++) {
		cin >> n >> k;
		cout << "Case #" << test << ": " ; 
		cout << paranthesis() << endl; ;
	}
}
