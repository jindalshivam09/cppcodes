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

vector<vi> adj;
vi ans ,xor_val;
vb visited ;

void dfs(int u,int parent, int grandparent) {
	visited[u] = true ;
	if(xor_val[u]^grandparent) {
		grandparent ^= 1 ;
		ans.pb(u) ;
	}
	rep(j,adj[u].size()) {
		int v = adj[u][j] ;
		if(visited[v] == false) {
			visited[v] = true ;
			dfs(v,grandparent,parent) ;
		}
	}
}

int main() {
	int n ;
	cin >> n ;

	adj.resize(n+1) ;
	visited.resize(n+1) ;
	xor_val.resize(n+1) ;

 	int a,b ;
	repi(i,1,n) {
		cin >> a >> b ;
		adj[a].pb(b) ;
		adj[b].pb(a) ;
	}
	rep(i,n) 
		cin >> xor_val[i+1] ;
	rep(i,n) {
		cin >> a ;
		xor_val[i+1] ^= a ;
	}
	dfs(1,0,0) ;
	cout << ans.size() << endl;
	rep(i,ans.size())
		cout << ans[i] << endl;
	
}


