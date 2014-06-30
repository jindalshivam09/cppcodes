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

vi arr;

class segment_tree {
	public :
		
	vector<vi> nodes ;
	int n ;
	
	segment_tree () { }
	void init () {
		int n = arr.size();
		nodes.resize(2*n+2);
		rep(i,n)	
			update(1,0,n-1,i,i);
	}
	void update (int node , int a,int b ,int i , int j ) {
		if ( j < a || i > b )
			return ;
		if ( i == a && j == b) {
			nodes[node].pb(arr[a-1]) ;
			return ;
		}
		int mid = (a+b)/2 ;
		update (2*node,a,mid,i,j);
		update (2*node+1,mid+1,b,i,j);
		int size1 = nodes[2*node].size() , size2 = nodes[2*node+1].size() ; 
		int size = size1 + size2 ;
		nodes[node].resize(size) ;
		int p = 0 , q = 0 , k = 0 ;
		while (p<size1 && q<size2) {
			int temp1 = nodes[2*node][p] , temp2 = nodes[2*node+1][q] ;
			if (temp1 < temp2) {
				nodes[node][k] = temp1 ;
				p ++ , k ++ ;
			}
			else {
				nodes[node][k] = temp2 ;
				q ++ , k ++ ;
			}
		}
		while( p < size1 ) {
			int temp1 = nodes[2*node][p] ;
			nodes[node][k] = temp1 ;
			p ++ , k ++ ;		
		}
		while( q < size2 ) {
			int temp2 = nodes[2*node+1][q] ;
			nodes[node][k] = temp2 ;
			q ++ , k ++ ;
		}
	}

	int query (int node,int a,int b,int i,int j,int k) {
		if ( j < a || i > b )
			return 0 ;
		if ( i >= a &&  b <= j ) {
			return (upper_bound(all(nodes[node]),k)-nodes[node].begin());
		}
		int mid = (a+b)/2 ;
		int ans = query(2*node,a,mid,i,j,k);
		ans += query(2*node+1,mid+1,b,i,j,k);
		return ans ;
	}
};

int main() {
	int n ;
	cin >> n ;
	arr.resize(n);
	rep(i,n)
		cin >> arr[i] ;
	segment_tree tree ;
	tree.init();
	sort(all(arr));
	int q,l,r,k,temp,val;
	cin >> q;
	while(q--) {
		cin >> l >> r >> k ;
		k -- , l -- , r --;		 
		val = arr[k] ;
		temp = tree.query(1,0,n-1,0,l-1,val) ;
		temp += tree.query(1,0,n-1,r,n-1,val) ;
		cout << arr[k] << " " << arr[k+temp] << endl; 
	}
}
