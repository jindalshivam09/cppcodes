#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 2009
#define imax numeric_limits<ll>::max()
int n;
vector<vector<ll> > matrix(MAX,vector<ll>(MAX)) , ans(MAX,vector<ll>(MAX));
vector<vector<pair<ll,ll> > > tree(MAX), adj(MAX) ;
vector<pair<ll,int> > nodes; 

void prim() {
	priority_queue<pair<ll,pair<int,int> >,vector<pair<ll,pair<int,int> > >, greater<pair<ll,pair<int,int> > > > q ;
	nodes.resize(n) ;
	fill(nodes.begin(),nodes.end(),make_pair(imax,-1)) ;
	q.push(make_pair(0,make_pair(0,0))) ;
	map<int,int> mstset ;
	mstset[0] = 1;
	nodes[0].first = nodes[0].second = 0 ;
	int cnt = 0 ;
	while(q.empty()==false) {
		pair<ll,pair<int,int> > poped = q.top() ;
		q.pop() ;
		int u = poped.second.first, p = poped.second.second;
		ll wt = poped.first ;
		if(nodes[u].first != wt)	continue ;
//			cout << u << " " << p << " " << wt << endl;
		if(mstset[u] == 0 || mstset[p] == 0) {
			mstset[u] = mstset[p] = 1;
			tree[u].push_back(make_pair(p,wt)) ;
			tree[p].push_back(make_pair(u,wt)) ;
			cnt ++;
		}
		if(cnt == n-1)
			return;
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i].second ;
			ll w = adj[u][i].first ;
			if( nodes[v].first > w ) {
				nodes[v].first = w ;
				nodes[v].second = u ;
				q.push(make_pair(w,make_pair(v,u))) ;
			}
		}
	}
}

void bfs() {
	queue<pair<ll,int> > q ;
	vector<bool> visited(n) ;

	for(int i=0;i<n;i++) {
		fill(visited.begin(),visited.end(),false) ;
		q.push(make_pair(i,0)) ;
//		cout << i <<  endl ;
		while(q.empty()==false) {
			pair<ll,int> poped = q.front() ;
			q.pop() ;
			int u = poped.first ;
			ll wt = poped.second;
			visited[u] =true;
			for(int j=0;j<tree[u].size();j++) {
				pair<ll,ll> temp = tree[u][j] ;
				int v = temp.first ;
				ll w = temp.second ;
				if(visited[v] == false) {
//					cout << v << " "  << w+wt << endl;
					ans[i][v] = w+wt ;
					ans[v][i] = w+wt ;
					q.push(make_pair(v,w+wt)) ;
				}
			}
		}
	}
}

int main() {
//	cin >> n ;
	scanf("%d",&n) ;
	if(n == 1) {
		int temp;
//		cin >> temp ;
		scanf("%d",&temp) ;
		if(temp)
			cout << "NO";
		else
			cout << "YES" ;
		return 0;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
//			cin >> matrix[i][j] ;
//			matrix[i][j] = read_int() ;
			scanf("%d",&matrix[i][j]) ;
			if((i==j && matrix[i][j]) || (matrix[i][j] == 0 && i!=j)) {
				cout << "NO" ;
				return 0;
			}
			if(matrix[i][j])
				adj[i].push_back(make_pair(matrix[i][j],j)) ;
		}
	}
	prim() ;
	bfs() ;
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			 if(matrix[i][j] != ans[i][j]) {
				cout << "NO" ;				
				return 0;
			}
		}
	}
	cout << "YES" ;
}
