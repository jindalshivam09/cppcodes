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
#define MAX 1009
int main() {
	int t;
	cin >> t ;
	while(t--) {
		int n;
		int a,b;
		cin >> n;
		vi x(n),y(n);
		rep(i,n) {
			cin >> x[i] >> y[i] ;
		}
		sort(all(x));
		sort(all(y));
		ll medx = x[n/2]-x[(n-1)/2] + 1 ;
		ll medy = y[n/2]-y[(n-1)/2]+1;
		cout << ll(medx*medy) << endl;
	}			
}


