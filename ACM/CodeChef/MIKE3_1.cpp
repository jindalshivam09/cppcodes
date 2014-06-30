#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long 		ll;
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

int n,m;
vector<vi> offer ;
vi forbiden  ;

int cal_max (ll sets, int i) {
//	cout << (sets&forbiden[i] ) << endl;
//	cout << sets << " " << forbiden[i] << " ";
//	cout <<  i << endl;
	if ( i > m )
		return 0 ;
	int ans =  cal_max(sets,i+1) ;
	if ((sets & (1<<i)) == 0) 
		ans = max (ans,1+cal_max(sets|forbiden[i],i+1)) ;
	return ans ;
}


int main() {
	cin >> n >> m ;
	int k,a;
	ll sets = 0 ;
	offer.resize(n+2) ;
	rep(i,m) {
		cin >> k ;
		rep(j,k) {
			cin >> a ;
			offer[a].pb(i+1) ;
		}
	}
	forbiden.resize(m+1) ;
	repi(i,1,n+1) {
		ll mask = 0 ;
		rep(k,offer[i].size())
			mask |= (1<<offer[i][k]) ;
		rep(k,offer[i].size())
			forbiden[offer[i][k]] |= mask;
	}
//	repi(i,1,m+1)
//		cout << forbiden[i] << " " ;
	cout << cal_max(sets,1) << endl;
}
