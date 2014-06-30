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

int e,v ;
vector<vi> adj;
int num = 0 ;
vi start , finish , parent , child , linear_array , level ;
vb visited ;

void dfs (int u) {
	linear_array.pb(u) ;
	visited[u] = true ;
	start[u] = ++num ;
	rep(i,adj[u].size()) {
		int v = adj[u][i] ;
		if(visited[v] == false)  {
			parent[v] = u ;
			dfs(v);
		}
	}
	finish[u] = num ;
	child[u] = finish[u] - start[u] ;
}

void bfs() {
	queue<int> q ;
	vb visited(v) ;
	q.push(1) ;
	int l = 1 ;
	level[1] = l;
	visited[1] = true ;
	while ( q.empty() == false ) {
		int u = q.front() ;
		l = level[u] + 1;
		q.pop() ;
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i] ;
			if(visited[v] == false) {			
				level[v] = l ;
				q.push(v) ;
				visited[v] = true ;
			}
		}
	}
}

void update (int idx,int val,vi &arr) {
	int n = arr.size() ;
	while( idx <= n ) {
		arr[idx] += val ;
		idx = idx + (idx&-idx) ;
	}
}

int query (int idx,vi &arr) {
	int n = arr.size() ;
	int ret = 0;
	while( idx > 0 ) {
		ret += arr[idx] ;
		idx = idx - (idx&-idx) ;
	}
	return ret ;
}

void init() {
	adj.resize(v) ;
	start.resize(v) ;
	finish.resize(v) ;
	parent.resize(v) ;
	child.resize(v) ;
	visited.resize(v) ;
	level.resize(v) ;
	num = 0 ;
}

int main() {
	ifstream cin("input.txt") ;
	int t;
	cin >> t;
	while(t--) {
		cin >> v >> e ;
		v++;
		init() ;
		repi(i,1,v)
			visited[i] = false ;

		int a,b ;
		rep(i,e)	{
			cin >> a >> b ;
			adj[a].pb(b) , adj[b].pb(a) ;
		}
		
		dfs(1) ;
		bfs();
		
		map<int,int> mapped ;
		rep(i,v-1) {
			mapped[linear_array[i]] = i+1 ;
		}
		
		int q; 
		cin >> q ;
		vi freq(v) , tree(v) ;
		while( q-- ) {
			int type , node;
			cin >> type >> node ;
			int n = mapped[node] ;
			int l = level[node] ; 
			if ( type == 1 ) {
				int tot_child = child[node] ;
				int left = n , right = n + tot_child ;
				update(left,1,freq) , update(right+1,-1,freq);
				update(left,l,tree) , update(right+1,-1*l,tree);
			}
			else {
				int tot_queries = query(n,freq) ;
				int tot_val = query(n,tree) ;
				cout << (l+1)*tot_queries - tot_val << endl;
			}
		}
		adj.clear()  ;
		linear_array.clear();
	}
}


