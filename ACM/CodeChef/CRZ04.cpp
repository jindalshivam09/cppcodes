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
	int t ;
	cin >>  t;
	while(t--) {
		int h,m;
		cin >> h >> m ;
		if ( h > 23 || m > 59)  {
			cout << "Invalid Time" << endl;
			continue ;
		}
		h = h  % 12 ;
		double mint = m ;
		double hour = abs(h*5 + (5.0*mint)/60 - mint);
		double ans = hour*6.0;
		ans = min (ans,360-ans) ;
		printf("%0.1f\n",ans) ;
	}
}


