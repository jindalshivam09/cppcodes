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
#define MAX 300009
vi arr ;
struct nodes {
	int left , right , left_seq , right_seq ,  len ;
} nodes[MAX];

void unite (int node) {
	int lval = arr[nodes[2*node].right] , rval = arr[nodes[2*node+1].left] ;
	if ( nodes[2*node].left_seq == nodes[2*node+1].left - nodes[2*node].left && lval == rval-1 ) {
		nodes[node].left_seq = nodes[2*node].left_seq + nodes[2*node+1].left_seq ;
	}
	else {
		nodes[node].left_seq = nodes[2*node].left_seq ;
	}
	if ( nodes[2*node+1].right_seq == nodes[2*node+1].right - nodes[2*node].right && lval == rval - 1) {
		nodes[node].right_seq = nodes[2*node].right_seq + nodes[2*node+1].right_seq ;
	}
	else {
		nodes[node].right_seq = nodes[2*node+1].right_seq ;
	}	
	nodes[node].len = max ( nodes[2*node].len , nodes[2*node+1].len ) ;	
	nodes[node].len = max ( nodes[node].len , max (nodes[node].left_seq , nodes[node].right_seq )) ;
	if ( lval == rval-1) {
		nodes[node].len = max ( nodes[node].len , nodes[2*node].right_seq + nodes[2*node+1].left_seq ) ;
	}
}

void init(int node , int a, int b) {
	nodes[node].left = a , nodes[node].right = b ;
	if ( a == b ) {
		nodes[node].len = 1 ;
		nodes[node].left_seq  = nodes[node].right_seq = 1 ;
		return ;
	}
	int mid = (a+b)/2 ;
	init(2*node,a,mid) ;
	init(2*node+1,mid+1,b) ;
	unite(node);
}

int idx,val;
void change ( int node , int a , int b ) {
	if ( b < idx || a > idx ) {
		return ;
	}
	if ( a == b )
		return ;
	int mid = (a+b)/2 ;
	change(2*node,a,mid) ;
	change(2*node+1,mid+1,b) ;
	unite(node) ;
}

int main() {
	int n,m;
	cin >> n >> m;
	arr.resize(n+1);
	rep(i,n)
		cin >> arr[i+1] ;
	init (1,1,n) ;
	cout << nodes[1].len << endl; 
	while(m--) {
		cin >> idx >> val ;
		arr[idx] = val ;
		change (1,1,n) ;
		cout << nodes[1].len << endl;
	}	
}
