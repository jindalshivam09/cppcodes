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

#define rep(i,n)    	for(int i=0;i<n;i++)
#define repi(i,k,n) 	for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

vector<vi> edges ;
vi sz ;
vb visited;
void dfs(int u=1) {
	visited[u] = true ;
	int cnt = 0;
	rep(i,edges[u].size()) {
		int v = edges[u][i] ;
		if(visited[v] ==false) {
			cnt ++ ;
			dfs(v) ;
		}
	}
	sz[u] = cnt ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		int n ;
		cin >> n ;
		edges.resize(n+1) ;
		sz.resize(n+1) ;
		visited.resize(n+1) ;
		int u,v ;
		if(n==1) {
			cout << 1 << endl;
			continue ;
		}
		rep(i,n-1) {
			cin >> u >> v ;
			edges[u].pb(v) ;
			edges[v].pb(u) ;
		}
		dfs() ;
		int ans = 2 ;
		int left = n-2;
		vb checked(n+1) ;
		queue<int> q;
		q.push(1) ;
		while(q.empty()==false) {
			vi arr ;
			int temp = 0;
			while(q.empty()==false) {
//				cout << "d: " << q.front() << " "; 
					arr.pb(q.front()) ;
				q.pop() ;
			}
//			temp += arr.size(); 
			rep(i,arr.size()) {
				int k = arr[i] ;
//				cout << "k " <<  k<< endl; 
				rep(j,edges[k].size()) {
					int v = edges[k][j] ;
//					cout << v << " " ;
					if(checked[v] == false) {
						q.push(v) ;
						checked[v] = true;
						temp ++ ;
					}
				}
			}
//			cout << temp << endl;
			if( left > 0 )
				left -= temp ,ans ++ ;
			if(left > 0)
				left -- , ans ++ ;
		}
		cout << ans << endl;
		edges.clear() ;
		sz.clear();
		
	}
	
}


