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

/*
// fast io 
#define getcx getchar_unlocked
#define putcx putchar_unlocked
 
inline void readInt( int &n ) {
    n=0;
    int ch=getcx();
    while( ch < '0' || ch > '9' ){ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
 
inline void writeInt(int n) {
	int i = 10;
	char buf[11];
	buf[10] = '\n';
	
	while (n) {
		buf[--i] = n % 10 + '0';
		n /= 10;
	}
	
	do {
		putcx(buf[i]);
	} while (buf[i++] != '\n');
}
*/
#define MAX 100009
int n , t = 0;
vi arr(MAX) , level(MAX) , child(MAX) , start(MAX) , finish(MAX);
map<int,int> mapped ;
vector<vi> adj(MAX) ;
vb visited(MAX) ;
int turn;

void dfs(int u) {
	visited[u] = true ;
	level[turn++] = u ;
	start[u] = turn;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
		if ( visited[v] == false)
			dfs(v) ;
	}
	finish[u] = turn-1 ;
}

struct node {
	int alive_count , least_healthy , decrement;
};
vector<node> st(4*MAX) ;

void init(int num,int i, int j) {
	if ( i == j ) {
		st[num].decrement = 0 ;
		st[num].least_healthy = arr[level[i]];
		st[num].alive_count = 1 ;
		return ;
	}
	init(2*num+1,i,(i+j)/2) ;
 	init(2*num+2,(i+j)/2+1,j) ;
 	st[num].alive_count = st[2*num+1].alive_count + st[2*num+2].alive_count  ;
	st[num].least_healthy = min ( st[2*num+1].least_healthy , st[2*num+2].least_healthy ) ;
	st[num].decrement = 0 ;
	return ;	
}

void update(int num, int i, int j, int a, int b, int x) {
	if ( i > b || j < a )
		return ;
	if ( i == j ) {
		st[num].decrement  += x ;
		st[num].least_healthy -= x;
		return ;
	}
	if ( i >= a && j <= b ) {
		st[num].decrement  += x ;	
		st[num].least_healthy -= x ;	
		return ;		
	} 		
	st[2*num+1].decrement += st[num].decrement ;
	st[2*num+2].decrement += st[num].decrement ;
	st[2*num+1].least_healthy -= st[num].decrement ;
	st[2*num+2].least_healthy -= st[num].decrement ;
	st[num].decrement = 0 ;	

	update(2*num+1,i,(i+j)/2,a,b,x) ;
 	update(2*num+2,(i+j)/2+1,j,a,b,x) ;

	st[num].least_healthy = min ( st[2*num+1].least_healthy , st[2*num+2].least_healthy );
	return ;
}

int query (int num, int i, int j, int a, int b) {
 	if ( j < a || i > b || j < i)
		return 0 ;
	if(i==j) {
		if (st[num].least_healthy <= 0) {
			st[num].least_healthy = imax ;
			return st[num].alive_count = 0;
		}
		return st[num].alive_count;
	}

	st[2*num+1].decrement += st[num].decrement ;
	st[2*num+2].decrement += st[num].decrement ;
	st[2*num+1].least_healthy -= st[num].decrement ;
	st[2*num+2].least_healthy -= st[num].decrement ;
	st[num].decrement = 0 ;	

	if ( i >= a && j <= b ) {
		if( st[num].least_healthy <= 0 ) {
			query(2*num+1,i,(i+j)/2,a,b) ;
			query(2*num+2,(i+j)/2+1,j,a,b);
			st[num].alive_count = st[2*num+1].alive_count + st[2*num+2].alive_count  ;
			st[num].least_healthy = min ( st[2*num+1].least_healthy , st[2*num+2].least_healthy );
		}
		return st[num].alive_count ;
	}

	int ans = query(2*num+1,i,(i+j)/2,a,b) + query(2*num+2,(i+j)/2+1,j,a,b);
 
 	st[num].alive_count = st[2*num+1].alive_count + st[2*num+2].alive_count  ;
	st[num].least_healthy = min ( st[2*num+1].least_healthy , st[2*num+2].least_healthy );	

	return ans ;
}

int main() {	
	scanf("%d", &n);
//	readInt(n) ;
	int h,e;
	rep(i,n) {
		scanf("%d%d", &h, &e);
//		readInt(h) ;
//		readInt(e) ;
		arr[i+1] = h ;
		adj[e].pb(i+1);
	}
	dfs(0) ;	
	arr[0] = imax ;
	init(0,0,n) ;
	
	int q ;
	scanf("%d", &q);
//	readInt(q) ;
	while(q--) {
		int type, a, x ;
		scanf("%d", &type);
//		readInt(type) ;
		if (type == 1) {
			scanf("%d%d", &a, &x);
//			readInt(a) ;
//			readInt(x) ;
			update(0,0,n,start[a],finish[a],x) ;
		}
		else {
			scanf("%d", &a);
//			readInt(a) ;
			printf("%d\n", query(0,0,n,start[a],finish[a]));
		}
	}	
}
