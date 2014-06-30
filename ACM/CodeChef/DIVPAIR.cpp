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
		ll n,m;
		scanf("%lld%lld",&n,&m);
		if ( m > 2*n-1 ) {
			cout << 0 << endl;
			continue ;
		}
		ll ans = 0 ;
		ll cycles = n/m;
		ll partial_cycle = n%m;
		ans = cycles*cycles*(m-1);
		ans += cycles*(cycles-1) ;
		if(!(m%2))
			ans -= n/m ;
		ans /= 2 ;
		ans += cycles*(n%m);
		if ( (n%m) > m/2 )
			ans += (n%m)-m/2 ;
		printf("%lld\n",ans);
	}
}


