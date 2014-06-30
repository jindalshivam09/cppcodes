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
#define MAX 55
int n ;
vector<vi> arr(MAX,vi(MAX)) ;
int memo[MAX][MAX][MAX][MAX] ;
int dp (int x1 , int y1 , int x2 , int y2) {
	if ( x2 < x1 || y2 > y1 )
		return imin ;
	if (x1==n && y1==n && x2==n && y2 == n)
		return arr[n][n] ;
	if (x1>n || y1>n || x2>n || y2>n)
		return imin;
//	cout << x1 << " " << y1 << " " << x2 << " " << y2 << "->" <<   endl;

	if (memo[x1][y1][x2][y2]!=imin)       
		return memo[x1][y1][x2][y2] ;
	int ans = dp(x1+1,y1,x2+1,y2) ;
	ans =  max (ans , dp(x1,y1+1,x2+1,y2)) ;
	ans =  max (ans , dp(x1,y1+1,x2,y2+1)) ;
	ans =  max (ans , dp(x1+1,y1,x2,y2+1)) ;
	ans += arr[x1][y1] + arr[x2][y2] ;//- ((x1==x2&&y1==y2)?arr[x1][y1]:0) ;
	if(x1==x2&&y1==y2)
		ans -= arr[x1][y1] ;
//
	return memo[x1][y1][x2][y2] = ans ;
}

int main() {
	cin >> n ;
	repi(i,1,n+1) 
		repi(j,1,n+1) 
			cin >> arr[i][j] ;
	rep(i,n+1)	rep(j,n+1) rep(k,n+1) rep(l,n+1)
			memo[i][j][k][l] = imin;
	cout << dp (1,1,1,1)  << endl;;
}


