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
			this->n = n ;
			tree.resize(n+1,0) ;
			rep(i,n) 
				tree[i] = arr[i] ;
		}
		void resize(ll n) {
			tree.resize(n+1,0);
			this->n = n ;
		}
		void reset() {
			rep(i,n+1)
				tree[i] = 0;
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
} X,Y ;

struct cordis {
	int x,y;
} cords[MAX] ;

struct qury {
	int x,y,d,id;
} qry[MAX] ;

bool cmp_qry(const qury &a,const qury &b) {
	return a.x+a.y+a.d < b.x+b.y+b.d ;
}
bool cmp_cords (const cordis &a, const cordis &b) {
	return a.x+a.y < b.x+b.y ;
}

bool cmp_cords_x (const cordis &a,const cordis &b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x ;
}
bool cmp_qry_x (const qury &a,const qury &b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x ;
}

int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	rep(i,n) {
		scanf("%d%d",&cords[i].x,&cords[i].y);	
	}
	rep(i,q) {
		scanf("%d%d%d",&qry[i].x,&qry[i].y,&qry[i].d);
		qry[i].id = i;
	}
	sort(cords,cords+n,cmp_cords) ;
	sort(qry,qry+q,cmp_qry) ;
	X.resize(MAX);
	Y.resize(MAX);
	vi ans(q);
	for(int j=0,i=0;i<q;i++) {
		while(j<n && cords[j].x+cords[j].y <= qry[i].x+qry[i].y+qry[i].d) {
			X.update(cords[j].x,1);
			Y.update(cords[j].y,1);
			j++;
		}
		ans[qry[i].id] = j - X.query(qry[i].x-1) - Y.query(qry[i].y-1);
	}
	X.reset();
	Y.reset();
	sort(cords,cords+n,cmp_cords_x);
	sort(qry,qry+q,cmp_qry_x);
	for(int j=0,i=0;i<q;i++) {
		while(j<n && cords[j].x < qry[i].x) {
			Y.update(cords[j].y,1);
			j++;
		}
		ans[qry[i].id] += Y.query(qry[i].y-1);
	}
	rep(i,q)
		printf("%d\n",ans[i]);
}


