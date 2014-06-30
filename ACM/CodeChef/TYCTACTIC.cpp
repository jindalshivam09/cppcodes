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
#define MAX 100009
vector<vi> graph(MAX);
int n,m;
vb visited(MAX); 
vi endval(MAX);
map<int,int> values;
int num = 0;
void dfs (int i=1) {
	visited[i] = true;
	values[i] = ++num ;
	for(int j=0;j<graph[i].size();j++) {
		int u = graph[i][j] ;
		if (!visited[u]) {
			dfs(u) ;
		}
	}
	endval[values[i]] = num;
}

class BIT {
	ll n;
	vll tree;
	public :
		BIT() {	
			// default constructor
		}
		BIT (ll n=0) {
			this->n = n ;
			tree.resize(n+1,0) ;
			rep(i,n)
				tree[i] = 0 ;
		}
		BIT (ll n , const vll &arr ) {
			tree.resize(n+1,0) ;
			repi(i,1,n+1) {
				tree[i] = arr[i] ;
				cout << tree[i] << endl;
			}
		}
		void update ( ll index , ll val ) { 		// update the BIT with value 'val' from the index 'index'
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
	cin >> n >> m ;
	int a,b ;
	vi arr(n+1) ;
	repi(i,1,n+1)
		cin >> arr[i] ;
	rep(i,n-1) {
		cin >> a >> b ;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	dfs();
	BIT tree(n) ;
	repi(i,1,n+1)
		tree.update(values[i],arr[i]);
	while(m--) {
		char ch;
		cin >> ch ;
		if ( ch == 'U' ) {
			cin >> a >> b ;
			int u = values[a] ;
			int change = b - ( tree.query(u) - tree.query(u-1) ) ;
			tree.update(values[a],change);
		}
		else {
			cin >> a ;
			int u = values[a] ;
			int v = endval[u] ;
			cout << tree.query(v) - tree.query(u-1) << endl;
		}
	}	
}


