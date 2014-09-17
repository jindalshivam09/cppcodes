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

class TaroCoins {
	map<pair<ll,int>,ll > memo;
		ll ways (ll num,int index) {
			if(memo[mp(num,index)])
				return memo[mp(num,index)] ;
			if(num==0)
				return 1 ;
			if(num<0 || index < 0 || num > 4LL<<index )
				return 0;
			ll ans = ways(num,index-1) + ways(num-(1LL<<index),index-1) + ways(num-(2LL<<index),index-1) ;
			return memo[mp(num,index)] = ans ;
		}
		public :
		ll getNumber ( ll num ) {
			return ways(num,59);	
		}
};

int main() {
//	cout << (4LL<<60) << endl;
	TaroCoins obj;
	cout << obj.getNumber(6) << endl;
}


