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

#define rep(i,n)    	for(int i=0;i<n;i++)
#define repi(i,k,n) 	for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int n;
vpii books ;
#define MAX2 4009
#define MAX 2009
vb visited(MAX2);
vector<vi> memo(MAX2,vi(MAX));

int dp (int book,int wt,int str) {
	visited[book] = true ;
	if(str<=0)
		return 0; 
	if ( wt > MAX)
		return 0;
	if (memo[wt][str])
		return memo[wt][str];
	int ans = imin;
	for(int i=0;i<n;i++) {
		if(!visited[i] && str-books[i].first >= 0 ) {
			ans = max(ans,1+dp(i,wt+books[i].first,books[i].second-books[i],first));
			visited[i] = false;
		}
	}
	return memo[wt][str] = ans ;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n ;
		books.resize(n);
		rep(i,n)
			cin >> books[i].first >> books[i].second;
		int ans = 1;
		rep(i,n) {
			ans = max(ans,dp(i,books[i].first,books[i].second-books[i].first));
			visited[i] = false;
		}
		cout << ans << endl;
		rep(i,n)
			rep(j,MAX)
				memo[i][j] = 0 , visited[j] = false ;
	}
}
