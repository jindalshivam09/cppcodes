#include<bits/stdc++.h>
using namespace std;

int v,e;
vector<vector<pair<int,int> > >  adj ;
vector<pair<int,int> > nodes; 
vector<vector<pair<int,int> > > tree ;

void prim() {
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > q ;
	nodes.resize(v) ;
	fill(nodes.begin(),nodes.end(),make_pair(INT_MAX,-1)) ;
	q.push(make_pair(0,make_pair(0,0))) ;
	map<int,int> mstset ;
	mstset[0] = 1;
	nodes[0].first = nodes[0].second = 0 ;
	int cnt = 0 ;
	while(q.empty()==false) {
		pair<int,pair<int,int> > poped = q.top() ;
		q.pop() ;
		int u = poped.second.first, p = poped.second.second;
		int wt = poped.first ;
		if(nodes[u].first != wt)	continue ;
//			cout << u << " " << p << " " << wt << endl;
		if(mstset[u] == 0 || mstset[p] == 0) {
			mstset[u] = mstset[p] = 1;
			tree[u].push_back(make_pair(p,wt)) ;
			tree[p].push_back(make_pair(u,wt)) ;
			cnt ++;
		}
		if(cnt == v-1)
			return;
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i].second ;
			int w = adj[u][i].first ;
			if( nodes[v].first > w ) {
				nodes[v].first = w ;
				nodes[v].second = u ;
				q.push(make_pair(w,make_pair(v,u))) ;
			}
		}
	}
}

int main() {
	cin >> v >> e ;
	adj.resize(v) ;
	int a,b,wt ;
	for(int i=0;i<e;i++) {
		cin >> a >> b >> wt ;
		adj[a].push_back(make_pair(wt,b)) ;
		adj[b].push_back(make_pair(wt,a)) ;
	}
	prim() ;
}
