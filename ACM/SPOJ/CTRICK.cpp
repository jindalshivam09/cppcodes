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
		void resize(int n) {
			this->n = n ;
			tree.resize(n+1,0) ;
			rep(i,n)
				tree[i] = 0 ;			
		}
		void update ( int index , int val ) { 		// update the BIT with value 'val' from the index 'index'
			if( index <= 0 )
				return ;
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

BIT bit ;
vi arr ;
int n ;
int bin_search(int l, int r, int val) {
//	cout << val << endl;
 	int l_val = bit.query(l-1) ;
	while ( l <= r ) {
//		cout << l << " " << r << endl;
		int mid = (l+r)/2 ;
		if(l==r)
			return r;
		int mid_val = bit.query(mid);
//		cout << mid_val << " " << l_val << endl;
		if ( val < mid_val - l_val) {
			r = mid ;
		}
		else if (val > mid_val - l_val){
			l = mid+1 ;
		}
		else {
			while ( arr[mid] != 0)
				mid = mid- 1 ;
			return mid;
		}
	}
	return -1;
}

int main() {
	int t;
	cin >> t ;
	while(t--) {
		cin >> n ;
		arr.assign(n+1,0) ;;
		bit.resize(n) ;
		rep(i,n)
			bit.update(i+1,1) ;
		int last = 0 , gap = 2 ;
		for(int i=1;i<=n;i++) {
			int spaces = bit.query(n) - bit.query(last) , tot_spaces = bit.query(n) , index;
			if(spaces >= gap) {
//				cout << last << " " << gap << endl << endl;
				index = bin_search(last+1,n,gap) ;
			}
			else {
//				cout << gap << " " << spaces << endl;
				if(gap>spaces)
					gap -= spaces ;			
				int temp = gap ;
			
//				cout << last << " " << gap << " " << gap%tot_spaces << endl << endl;
				gap = gap%tot_spaces ;
				if(gap==0)
					gap = tot_spaces;
					
				index = bin_search(1,n,gap);
			}
//			if(index==0)
//				arr[n] = i ;
//			cout << index << "index \n " ;
			gap = i+2;
			last = index ;
			arr[index] = i ;
			bit.update(index,-1) ;
		}
		rep(i,n)
			cout << arr[i+1] << " ";
		cout << endl;
	}
}


