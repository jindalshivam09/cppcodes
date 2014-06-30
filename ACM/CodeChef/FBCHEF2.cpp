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

int n, cnt = 0;
vb visited ;
vi arr, linear, weight, start, last;
vector<vi> adj ;
struct node {
	int least, alive, dec ;
};
vector<struct node> st ;

void resizing() {
	int size = n+1 ;
	arr.resize(size) ;
	weight.resize(size) ;
	adj.resize(size) ;
	st.resize(size) ;
	visited.resize(size) ;
	start.resize(size) ;
	last.resize(size) ;
}

void dfs(int u) {
	visited[u] = true ;
	start[u] = ++cnt ;
	linear.pb(u);
	rep(i,adj[u].size()) {
		int v = adj[u][i] ;
		if(visited[v]==false) {
			visited[v] = true ;
			dfs(v) ;
		}
	}
	last[u] = cnt ;
}
map<int,int> mapped ;
void init(int num, int i, int j) {
	if( i > j )
		return ;
	if( i == j ) {
		int index = mapped[i] ;
		st[num].least = weight[index] ;
		st[num].alive = 1 ;
	}
	int mid = (i+j)/2 ;
	init(2*num,i,mid) ;
	init(2*num+1,mid+1,j) ;
	st[num].least = min ( st[2*num].least , st[2*num+1].least ) ;
	st[num].alive = st[2*num].alive + st[2*num+1].alive ;
}

void update(int num, int i, int j, int a, int b, int dec) {
	if ( j < a || i > b )
		return ;
	if ( i >= a && j <= b ) {
		st[num].dec += dec ;
		return ;
	}
	int mid = (i+j)/2 ;
	int val = 1; // to be computed later
	update(2*num,i,mid,a,b,dec) ;
	update(2*num+1,mid+1,j,a,b,val) ;
}

int query(int num, int i, int j, int a, int b) {
	if( j < a || i > b )
		return 0 ;

	if( i == j ) {
		if ( st[num].least <= st[num].dec ) {
			st[num].least = 0 ;
			st[num].dec = 0 ;
		}
		st[num].least -= st[num].dec ;
		return st[num].alive ;
	}

	st[2*num].dec += st[num].dec ;
	st[2*num+1].dec += st[num].dec ;
	st[num].dec = 0 ;

	int mid = (i+j)/2 ;
	
	if( i >= a && j <= b ) {
		if(st[num].least > 0) {
			query(2*num,i,mid,a,b) ;
			query(2*num+1,mid+1,j,a,b) ;
			st[num].least = min (st[2*num].least,st[2*num+1].least) ;
			st[num].alive = st[2*num].alive + st[2*num+1].alive ;
		}
		return st[num].alive ;
	}
	
	int ans = query(2*num,i,mid,a,b) + query(2*num+1,mid+1,j,a,b) ;
	st[num].least = min (st[2*num].least,st[2*num+1].least) ;
	st[num].alive = st[2*num].alive + st[2*num+1].alive ;
	return ans ;
}

void bfs() {
	queue<int> q ;
	q.push(1) ;
	vi level(n+1), visited(n+1);
	level[1] = 1 ;
	while(q.empty() == false) {
		int v = q.front() ;
		int l = level[v] ;
		q.pop() ;
		rep(i,adj[v].size()) {
			int u = adj[v][i] ;
			if(visited[u]==false) {
				visited[u]=true ;
				q.push(u) ;
				level[u] = l+1;
			}
		}
	}
}

int main() {
	cin >> n ;
	resizing() ;
	rep(i,n)
		cin >> weight[i+1] ;
	
	int a,b ;
	rep(i,n-1) {
		cin >> a >> b ;
		adj[a].pb(b) ;
		adj[b].pb(a) ;
	}
	
	dfs(1) ;
	bfs() ;
	
	rep(i,linear.size()) {
		mapped[i+1] = linear[i] ;
	}
	
	init(1,1,n) ;
	
	int q ;
	cin >> q ;
	while(q--) {
		int type, a, x ;
		cin >> type ;
		if(type==1) {
			cin >> a >> x ;
			update(1,1,n,start[a],last[a],x) ;
			int diff = ( leve[a] - level[1] ) ;
			int logVal = (ceil)((double)log(x)/log(2)) ;
			if
			update(1,1,n,start[1],last[1],)
		}
		else {
			cin >> a ;
			cout << query(1,1,n,start[a],last[a]) << endl;
		}
	}
}	


