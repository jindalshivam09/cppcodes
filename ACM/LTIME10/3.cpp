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
#define MAX 100009
int n,k,d;
ll memo[MAX][1000];

int main() {
	cin >> n >> k >> d ;
	ll ans = 0;
	ll temp , temp2 ;
	bool flag = false ;
	for (int i=1;i<=n;i++) {
		for(int j=1;j<=d;j++) {
			memo[i][j] = 0 ;
			temp2 = (j*(j-1)) / 2 ;
			temp = ((k+j-1)*(k+j)) / 2 ;
			if ( temp - temp2 > n ) {
				memo[i][j] = 0;
				flag = true ;
				break;
			}
			else {
				if ( temp-temp2 == n )
					memo[i][j] = 1 ;
				for( int l = 1 ; l <= d ; l ++ )
					if ( i >= l*(k-j-1) )
						memo[i][j] = ( memo[i][j] + memo[i-l*(k-j-1)][j-1] ) % MOD ;
					else
						break ;
//				cout << memo[i][j] << endl;
			}
		}
		if (flag == true)
			break ;
	}
	repi(i,1,n+1)
		ans = (ans+memo[n][i]) % MOD ;
	cout << ans << endl;
}
