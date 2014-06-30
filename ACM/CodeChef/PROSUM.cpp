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
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n ;
		ll two  = 0 , one_zero = 0  , a ;
		rep(i,n) {
			cin >> a;
			if (a==2)
				two ++;
			else if (a==1 || a==0)
				one_zero ++;
		}
		ll ans = 0 ;
		ll temp = n-one_zero-1;
		rep(i,n-one_zero-two) {
			ans += temp;
			temp -- ;
		}
		cout << ans << endl; 
	}
}


