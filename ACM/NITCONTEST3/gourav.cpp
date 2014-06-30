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

int v,e;
vector<vi> adj ;
vi cc ;
int component = 1;
vb visited ;

void dfs (int i) {
	if (i > v)
		return ;
	visited[i] = true;
	cc[i] = component;
	for(int j=0;j<adj[i].size();j++) {
		int v = adj[i][j] ;
		if (visited[v] == false) 
			dfs(v) ;
	}
}

int main() {
	cin >> v >> e ;
	adj.resize(v+1) ;
	cc.resize(v+1) ;
	visited.resize(v+1) ;
	int a,b ;
	rep(i,e) {
		cin >> a >> b ;
		adj[a].pb(b) ;
		adj[b].pb(a) ;
	}
	repi(i,1,v+1) {
		if (visited[i]==false) {
			dfs(i) ;
			component++ ;
		}
	}
	vi ans(component) ;
	repi(i,1,v+1) {
		int c = cc[i] ;
		if (ans[c] == 0) 
			ans[c] = i ;
		else {
			int temp = ans[c] ;
			if (adj[temp].size() < adj[i].size() ) {
				ans[c] = i ;
			}
		}
	}
	cout << component-1 << endl;
	sort(all(ans));
	repi(i,1,component) 
		cout << ans[i] << " ";
}


