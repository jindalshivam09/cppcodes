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

void dfs() {
	vb visited(v) ;
	stack<int> stk ;
	rep(i,v) {
//		cout << i << " " ;
		if(visited[i] == false)	
			stk.push(i) , visited[i] = true ;
		while ( stk.empty() == false ) {
			int u = stk.top() ;
//			visited[u] = true ;
			cout << u << " ";
			stk.pop() ;
			rep(i,adj[u].size()) {
				int v = adj[u][i] ;
				if ( visited[v] == false ) {
					visited[v] = true ;
					stk.push(v) ;
				}
			}
		}		
	}
}

int main() {
	ifstream cin("input.txt");
	cin >> v >> e ;
	adj.resize(v) ;
	int a,b ;
	rep(i,e) {
		cin >> a >> b ;
		adj[a].pb(b) , adj[b].pb(a) ;
	}
	dfs() ;
}


