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

map<int,int> memo;

int dp(int n) {
	if ( memo[n] )
		return memo[n] ;
	if (n==1)
		return 0 ;
	int ans = 0 , temp , count;
	if ( n % 3 == 0 ) {
		temp = n , count = 0;
		while ( temp % 3 == 0)
			temp /= 3 , count ++;
		ans = count + dp(temp) ;
	}
	if ( n % 2 == 0 ) {
		temp = n , count = 0;
		while ( temp % 2 == 0 )
			temp /= 2 , count ++;
			ans = max ( ans , count + dp(temp) ) ;
	}
	if ( n % 3 && n % 2 ) {
		ans = max ( ans , 1 + dp(n-1) );
		ans = max ( ans , 1 + dp(n-2) ) ;
	}
	return memo[n] = ans ;
}

int main() {
	int t;
	cin >> t ;
	while(t--) {
		int n ;
		cin >> n ;
		cout << dp(n) << endl;
	}
}


