#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
int m, number ;
vector<vector<int> > adj(MAX) ;
vector<int> level(MAX), mapped(MAX), sz(MAX);

int dfs(int u, int parent) {
	mapped[u] = ++number ;
	if(parent != -1)	
		level[mapped[u]] = level[mapped[parent]] + 1 ;
	int ans = 0 ;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
		ans += 1 + dfs(v,u) ;
	}
	return sz[mapped[u]] = ans ;
}

vector<vector<int> > tree(2,vector<int>(MAX)) ;

void update(int l, int r, int freq, int row) {
	while(l<=r) {
		tree[row][l] += freq ;
		l += (l&-l) ;
	}
}

int retrieve(int idx,int row) {
	int ret = 0;
	while(idx > 0) {
		ret += tree[row][idx];
		idx -= (idx&-idx) ;
	}
	return ret ;
}

int retrieve(int l, int r, int row) {
	return retrieve(r,row) - retrieve(l-1,row) ;
}

void activate(int node, int child) {
	node = mapped[node] ;
	int lvl = level[mapped[child]] ;
	int subtree = sz[node] ;
	update(mapped[child],node+subtree,1,lvl%2) ;
}

int nC2(int n) {
	if(n < 2)
		return 0;
	return n*(n-1) / 2 ;
}

int result(int node) {
	node = mapped[node] ;
	int subtree = sz[node] ;
	return nC2(retrieve(node,node+subtree,0)) + nC2(retrieve(node,node+subtree,1)) ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		cin >> m ;		
		int type, node ;
		int till = 0 ;
		vector<pair<int,int> > queries(m) ;
		vector<int> assigned(m) ;
		for(int i=0;i<m;i++) {
			cin >> type >> node ;
			queries[i].first = type;
			queries[i].second = node ;
			if(type == 0 ) {
				till ++ ;
				assigned[i] = till ;
				adj[node].push_back(till) ;
			}
		}
		dfs(0,-1) ;
		activate(0,0) ;
		for(int i=0;i<m;i++) {
			type = queries[i].first ;
			node = queries[i].second ;
			if(type == 0) 	activate(node,assigned[i]) ;
			else			cout << result(node) << endl ;
		}
		
		number = 0 ;
		for(int i=0;i<=till;i++)
			adj[i].clear() ;
		fill(tree[0].begin(),tree[0].end(),0);
		fill(tree[1].begin(),tree[1].end(),0);
	}
}
