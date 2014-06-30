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
map<int,int> memo ;
int recurse ( int n ) {
//	cout << n << endl;
	if ( !n )
		return 0;
	if ( n == 1 )
		return 2 ;
	if ( memo[n] )
		return memo[n] ;
	int ans = n + 1 ;
	ans += recurse ( n/2 ) ;
	ans += recurse ( n - n/2-1 ) ;
	return memo[n] = ans ; 
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k ;
		int max_len = n*(n+3) / 2 ;
		int min_len = recurse ( n ) ;
		if ( min_len > k )
			cout << -1 ;
		else if ( max_len < k )
			cout << k-max_len ;
		else
			cout << 0 ;
		cout << endl;
	}
}
