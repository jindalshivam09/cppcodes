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

//#define ONLINE_JUDGE

int n ;
vll arr ;
typedef struct node {
	ll sum , max_val;
} node;
vector<node> st ;

void init(int num, int i, int j) {
	if( j < i )
		return ;
	if( i == j ) {
		st[num].sum = arr[i] ;
		st[num].max_val = arr[i] ;
		return ;
	}
	int mid = (i+j)/2 ;
	init(2*num,i,mid) ;
	init(2*num+1,mid+1,j) ;
	st[num].sum = st[2*num].sum + st[2*num+1].sum ;
	st[num].max_val = max ( st[2*num].max_val , st[2*num+1].max_val ) ;
}

void update (int num, int i, int j, int a, int b) {
	if( j < a || i > b )
		return ;
	if( st[num].max_val == 1)
		return  ;
	if ( i == j ) {
		st[num].sum = sqrt(st[num].sum) ;
		st[num].max_val = st[num].sum ;
		return ;
	}
	int mid = (i+j)/2 ;
	update(2*num,i,mid,a,b) ;
	update(2*num+1,mid+1,j,a,b) ;
	st[num].sum = st[2*num].sum + st[2*num+1].sum ;
	st[num].max_val = max ( st[2*num].max_val , st[2*num+1].max_val ) ;
}

ll query (int num, int i, int j, int a, int b) {
	if( j < a || i > b )
		return 0 ;	
	if ( i >= a && j <= b ) {
		return st[num].sum ;
	}
	
	int mid = (i+j)/2 ;
	ll ans = query(2*num,i,mid,a,b) + query(2*num+1,mid+1,j,a,b) ;
	return ans ;
}

int main() {
	#ifdef ONLINE_JUDGE
		freopen("input_GSS4.txt","r",stdin) ;
	#endif
	
	int test = 1;
	
	while ( scanf("%d",&n) >= 0) {
		arr.resize(n+1) ;
		st.resize(4*n) ;
		rep(i,n)
			scanf("%lld",&arr[i+1]) ;

		init(1,1,n) ;

		int m ;
		scanf("%d",&m) ;

		printf("Case #%d:\n",test) ;
		test++;

		while(m--) {
			int type, x, y;
			scanf("%d",&type) ;
			scanf("%d%d",&x,&y) ; 
			if(x>y)
				swap(x,y);
			if ( type == 0 ) {
				update(1,1,n,x,y) ;
			}
			else {
				printf( "%lld\n" , query(1,1,n,x,y) ) ;				
			}
		}
		printf("\n");
		st.clear() ;
	}
}


