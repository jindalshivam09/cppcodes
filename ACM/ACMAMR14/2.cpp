#include<bits/stdc++.h>
using namespace std; 

int q ;
#define MAX 100009
vector<int> parent(MAX), sz(MAX), level(MAX), freq(MAX) ;
vector<vector<int> > adj(MAX) ;
int num ;

void insert(int node) {
	adj[node].push_back(++num) ;
	parent[num] = node;
	level[num] = level[node] + 1 ;
	sz[node] ++ ;
	
	int temp = parent[node] ;
	while(temp != -1) {
		sz[temp] ++ ;
		temp = parent[temp] ;
	}
}

int maxLevel ;
void dfs(int u,int father) {
//	cout << "df" ;
	int ret = 0 ;
	for(int j=0;j<adj[u].size();j++) {
		int v = adj[u][j] ;
		if(v != father) {
			ret ++ ;
			dfs(v,u) ;
		}
	}
	maxLevel = max(maxLevel, level[u] ) ;
	freq[level[u]] += ret ;
//	cout << ret << endl;
}


long long retrieve ( int node) {
	fill(freq.begin(),freq.end(),0) ;
	maxLevel = -1;
	dfs(node,parent[node]) ;
	int minLevel = level[node] + 1 ;
	long long ans = 0;
	cout << maxLevel << " , " << minLevel << endl;
	for(int i=minLevel ; i <= maxLevel; i ++) {
		ans += (freq[i]*(freq[i]-1))/2 ;
	}
	return (ans * (num - sz[node] )) ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		num = 0 ;
		level[0] = 0 ;
		fill(parent.begin(),parent.end(),-1) ;
		cin >> q ;
		while(q--) {
			int type,node ;
			cin >> type >> node; 
			if(type == 0 ) {
				insert(node) ;
			}
			else {
				cout << retrieve(node) << endl ;
			}
		}
		for(int i=0;i<=num;i++)
			adj[i].clear() ;
	}
}
