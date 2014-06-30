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
vector<vll> adj(MAX) ;
ll n , root ,val;
vb visited;
ll ans = 0 ;
void dfs(int u, ll temp) {
	visited[u] = true;
	ans += temp*adj[u].size() ;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
		if(visited[v]==false) {
			dfs(v,temp+1);
		}
	}
}

void func() {
	dfs(root,1) ;
	ll tot = (n*(n-1))/2;
	cout << ans << " " << tot-ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n ;
//		n = 100000;
		visited.resize(n+1) ;
		rep(i,n+1)
			visited[i] = false;
		
		int a;
		rep(i,n) {
			cin >> a ;
//			a = i+1;;
			if(a==0)
				root = i+1 ;
			else
				adj[a].pb(i+1);
		}
		func() ;
		ans = 0;
		rep(i,n)
			adj[i+1].clear() ;
	}

}


