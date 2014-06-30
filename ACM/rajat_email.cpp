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

#define MAX 109
int n,m;
vector<vi> arr(MAX,vi(MAX)) , memo(MAX,vi(MAX)) ;

int dp(int i,int j) {
	if ( i > n || j > m )
		return 0;
	if ( i == n && j == m )
		return 1 ;
	if ( memo[i][j] )
		return memo[i][j] ;
	int ans = 0 ;
	if ( i <= n  && arr[i+1][j] > arr[i][j] )
		ans = 1 + dp(i+1,j) ;
	if ( j <= m && arr[i][j+1] > arr[i][j] )
		ans = max ( ans , 1 + dp(i,j+1) ) ;
	return memo[i][j] = ans ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		cin >> n >> m ;
		repi(i,1,n+1)	repi(j,1,1+m)
			cin >> arr[i][j] ;
		repi(i,1,n+1)	repi(j,1,1+m)
			memo[i][j] = 0 ;
		cout << dp(1,1) << endl ;
	}
}


