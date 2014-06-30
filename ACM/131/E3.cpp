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
int dx[] = {-1,-1,0,0} ; 
int dy[] = {-1,0,-1,0} ;
			
int main() {
	cin >> n ;
	repi(i,1,n+1)
		repi(j,1,n+1)
			cin >> arr[i][j] ;
	rep(i,2*n+1) rep(j,n+1) rep(k,n+1)
		memo[i][j][k] = inf ;
	memo[1][1][1] = arr[1][1];
	for(int i=2;i<2*n;i++) {
		for(int j=1 ; j<=n ; j++) {
			for (int k=1 ; k<=n ; k++) {
				if ( i-j+1<1 || i-j+1 > n || i-k+1<1 || i-k+1 > n )	continue;
				rep(l,4)
					memo[i][j][k] = max ( memo[i][j][k] , memo[i-1][j+dx[l]][k+dy[l]] ) ;
				memo[i][j][k] += arr[j][i-j+1] + arr[k][i-k+1] ;
				if (j==k)
					memo[i][j][k] -= arr[j][i-j+1];
			}
		}
	}	
	cout << memo[2*n-1][n][n] << endl;
}


