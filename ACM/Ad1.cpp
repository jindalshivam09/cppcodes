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

int getMinSplit(long width,long height,long nTiles) { 
	long long n = width , m = height , k = nTiles ;
	if (n*m == k )
		return 0;
	else {
		if ( (k/n == m) || (k/m == n))
			return 1 ;
		else {
			long long root = sqrt(k) ;
			for(int i=1;i<=root;i++) {
				if ( i * (k/i) == k && i <= n && k/i <= m ) {
//					cout << 2 << endl;
					return 2 ;
				}
			}
//			cout << -1 << endl;
	return -1;
		}
	}	
}
int main() {
	ll n,m,k;
	cin >> n >> m >> k ;
	if (n*m == k )
		cout << 0 << endl ;
	else {
		if ( k/n == m || k/m == n)
			cout << 1 << endl;
		else {
			cout << getMinSplit(n,m,k);
		}
	}	
}


