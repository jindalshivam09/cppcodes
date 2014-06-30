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
class BIT {
	ll n;
	vll tree;
	public :
		BIT (ll n=0) {
			this->n = n ;
			tree.resize(n+1,0) ;
			rep(i,n)
				tree[i] = 0 ;
		}
		BIT (int n , const vi &arr ) {
			tree.resize(n+1,0) ;
			rep(i,n) 
				tree[i] = arr[i] ;
		}
		void update ( int index , int val ) { 		// update the BIT with value 'val' from the index 'index'
			while ( index <= n ) {
				tree[index] += val;
				index += (index&-index) ;
			}
		}
		ll query ( ll index ) {			// return the summation of all the value till index 'index'
			ll ans = 0;
			while ( index > 0 ) {
				ans += tree[index] ;
				index -= (index&-index) ;
			}
			return ans ;
		}
		ll find_index ( ll val ) {			// find the index where the summation of values is 'val'
			ll bitmask = pow ( 2 , sqrt(n) ) ;	// kind of binary search
			ll index = 0 , temp = 0 ;
			while ( bitmask && temp <= n ) {
				index = temp + bitmask ;
				if ( tree[index] == val )
					return index ;
				if ( val > tree[index] ) {
					val -= tree[index] ;
					temp = index ;
				}
				bitmask >>= 1 ;
			}
			if ( !val )		return index ;
			else			return -1 ;
		}
};
int main() {
	ll n ;
	cin >> n ;
	BIT tree(n) ;
	map<ll,ll> left;
	vector<pair<ll,ll> > pairs(n) ;
	vll female(n);
	ll a,b;
	rep(i,n) {
		cin >> a >> b;
		pairs[i] = mp(a,b);
		female[i] = b ;
	}  
	sort(all(female)) ;
	sort(all(pairs));
	ll ans = 0 ;
	ll index = 1;
	rep(i,n) {
		left[female[i]] = index ;
		index ++ ;
	}	
	rep(i,n) {
		ll temp = pairs[i].second ;
		ll val = left[temp] ;
//		cout << val << " ";
		ans += i-tree.query(val) ;
		tree.update (val,1) ;
//		cout << ans <<  endl;
	}
	cout << ans << endl ; 
}


