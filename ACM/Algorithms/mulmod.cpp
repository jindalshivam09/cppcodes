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

ll mulmod(ll a,ll b,ll c=100000) {
	ll x=0,y=a%c;
	while(b>0) { 
		if(b%2)
			x = (x+y)%c;
		y = (y*2)%c;
		b /= 2;
	}
	return x%c;
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		int a,b;
		cin >> a >> b ;
		cout << mulmod(a,b) << endl ;
	}
}


