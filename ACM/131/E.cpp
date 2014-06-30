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
#define inf -30000009
#define MAX 305
vector<vi> arr(MAX,vi(MAX)) ;
int n ;
int memo[2*MAX][MAX][MAX]  ;

inline int dp (int k,int x1,int x2) {
//  cout << x1 << " " << x2 << " " << k << endl;
//  cin.get() ;
    if (x1==n && x2==n && k==(2*n-1))
        return arr[n][n] ;
    if(x1 > n || x2 > n || k>2*n-1 || x1 > x2 ||  k-x1+1<1 || k-x1+1 > n || k-x2+1<1 || k-x2+1 > n )
        return inf ;
    if (memo[k][x1][x2]!=inf)
        return memo[k][x1][x2] ;
    int ans = dp(k+1,x1,x2) ;
    ans = max ( ans , dp(k+1,x1,x2+1)) ;
    ans = max ( ans , dp(k+1,x1+1,x2+1)) ;
    ans = max ( ans , dp(k+1,x1+1,x2)) ;
    ans += arr[x1][k-x1+1] + arr[x2][k-x2+1] ;
    if (x1==x2)
        ans -= arr[x1][k-x1+1] ;
    return memo[k][x1][x2] = ans ;
}

int main() {
	cin >> n ;
	repi(i,1,n+1)
		repi(j,1,n+1)
			cin >> arr[i][j] ;
	rep(i,2*n+1) rep(j,n+1) rep(k,n+1)
		memo[i][j][k] = inf ;
	cout << dp(1,1,1) << endl;
}
