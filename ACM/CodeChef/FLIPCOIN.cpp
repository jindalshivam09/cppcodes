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
struct node {
	bool flag ;
	int heads ;
};

vector<node> heap(MAX);

void update (int pos, int a,int b, int l,int r) {
//	cout << l << " " << r << endl;
	if ( b < l || a > r )
		return ;
	if ( a <= l && b >= r ) {
		heap[pos].heads = (r-l+1) - heap[pos].heads ;
		heap[pos].flag ^= true ;
		return ;
	}
	int mid = (l+r)/2;
	update (2*pos,a,b,l,mid);
	update (2*pos+1,a,b,mid+1,r);
	heap[pos].heads = heap[2*pos+1].heads + heap[2*pos].heads ;
	if ( heap[pos].flag )
		heap[pos].heads = (r-l+1) - heap[pos].heads ;
}

int query ( int pos, int a, int b, int l , int r  , bool flag = false) {
	
	if ( b < l || a > r )
		return 0;
	if ( a <= l && b >= r ) {
		if ( flag )	
			return (r-l+1) - heap[pos].heads;
		return heap[pos].heads ;
	}
	int mid = (l+r)/2;
	return query(2*pos,a,b,l,mid,flag^heap[pos].flag ) + query(2*pos+1,a,b,mid+1,r,flag^heap[pos].flag) ;
}

int main() {
	int n,q;
	cin >> n >> q;
	int op,a,b;
	while(q--) {
		cin >> op >> a >> b ;
		a++;
		b++;
		if ( op == 0 )
			update (1,a,b,1,n);
		else
			cout << query (1,a,b,1,n) << endl;
	}
}


