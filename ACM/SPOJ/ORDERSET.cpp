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
#define MAX 2000009
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
} bit(MAX);
int main() {
 	int q ;
	cin  >> q;
	map <int,int> s ;
	char ch ;
	int a;
	vi arr;
	int count = 0 ;
	map<int,int> mapped ;
	vector<pair<char,int> > op(q);
	rep(i,q) {
		cin >> op[i].first >> op[i].second ;
		if ( op[i].first == 'I' ) {
			arr.pb(op[i].second);
		}
	}
	sort(all(arr));
	rep(i,arr.size())
		mapped[arr[i]] = i+1;
	rep(i,q) {
		ch = op[i].first ;
		a = op[i].second ;
		if ( ch == 'I' ) {
			if(!s[a]) { 
				s[a] = a , count ++;
				bit.update(mapped[a],1);
			}
		}
		else if ( ch == 'C' ) {
			map<int,int>::iterator itr = s.lower_bound(a);
			int temp = itr->second;
			cout << temp << " " ;
			if ( temp != a ) {
				if(itr != s.begin() ) {
					itr--;
					temp = itr->second ;
					cout << bit.query(temp) << endl;
				}
				else	cout << 0 << endl;
					
			}
			else			cout << bit.query(temp) << endl;
		}
		else if ( ch == 'D' ) {
			s.erase(a);
			count -- ;
			bit.update(mapped[a],-1);
		}
		else  {
			if ( a <= count)	cout << s[a] << endl;
			else				cout << "invalid" << endl;
		}
			
	}
}


