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

int main() {
	int n,m;
	cin >> n >> m;
	vi bulb (m) ;
	rep(i,m)
		cin >> bulb[i] ;
	vi ans(n+1) ;
	int min_b = n+1;
	rep(i,m) {
		int temp = bulb[i] ;
		while(temp<n+1 && temp < min_b ) {
			ans[temp] = bulb[i] ;
			temp ++ ;
		}
		min_b = min (min_b,bulb[i]) ;
	}
	repi(i,1,1+n)
		cout << ans[i] << " ";
}


