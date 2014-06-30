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
#define MAX 1000009
vll BIT(MAX) ;
int n ;
void update (int idx,int val) {
	while( idx <= n) {
		BIT[idx] += val ;
		idx += (idx&-idx) ; 
	}	
}

ll query (int idx) {
	ll ans = 0 ;
	while (idx > 0 ) {
		ans += BIT[idx] ;
		idx -= (idx&-idx) ;
	}
	return ans ;
}

int main() {
	cin >> n ;
	vll arr(n);
	map<ll,ll> rank ;
	rep(i,n) {
		cin >> arr[i] ;
		rank[arr[i]] = 1;
	}
	int idx  = 1 ;
	for(map<ll,ll>::iterator itr = rank.begin() ;  itr != rank.end() ; itr ++)
		itr->second = idx++;
	ll ans = 0;
	rep(i,n) {
		int val = rank[arr[i]] ;
		ans += i-query(val) ;
		update(val,1) ;
	}
	cout << "Number of inversions are " << ans << endl;
}


