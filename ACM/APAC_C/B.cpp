#include<bits/stdc++.h>
using namespace std ;

#define MAX 109
#define EDGES 100000 
vector<vector<pair<int,int> > > adj(EDGES) ;

int n ;
int node ;
map<pair<int,int> ,int > mapped;
vector<int> wait(EDGES), weight(EDGES), parent(EDGES) ;


class cmp{
	public:
		bool operator() (const pair<int,int> &a,const pair<int,int> &b) const {
			return a.second < b.second;
		}
};


void dijsktra(int source) {
	priority_queue<pair<int,int>,vector<pair<int,int> > , cmp> Q ;
	Q .push(make_pair(source,0));
	fill(weight.begin(),weight.end(),INT_MAX);
	fill(parent.begin(),parent.end(),INT_MAX);
	weight[source] = 0;
	
	while(!Q.empty()) {
		pair<int,int> popped = Q.top();
		Q.pop();
		int u = popped.first;
		int wu = popped.second;
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i].first;
			int wv = adj[u][i].second;
			if(weight[v] > wv + weight[u] && v != parent[u]) {
				weight[v] = wv + weight[u];
				parent[v] = u;
				Q.push(make_pair(v,weight[v]));
			}
		}
	}
}

int main() {
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;

	int t ;
	cin >> t;
	for(int test=1;test<=t;test++) {
		cin >> n ;
		node = -1 ;
		int sn, w ;
		for(int i=1;i<=n;i++) {
			cin >> sn >> w ;
			wait[i] = w ;
			int time ;
			mapped[make_pair(i,1)] = ++node ;
//			cout << node << " " ;
			for(int j=1;j<sn;j++) {
				cin >> time ;
				mapped[make_pair(i,j+1)] = ++node ;
	//			cout << node << " ";
				adj[node-1].push_back(make_pair(node,time)) ;
				adj[node].push_back(make_pair(node-1,time)) ;
			}
//			cout << endl;
		}
		int m ;
		cin >> m ;
		int a,b,c,d, time;
		for(int i=0;i<m;i++) {
			cin >> a >> b >> c >>  d >> time;
			int x = mapped[make_pair(a,b)] , y = mapped[make_pair(c,d)] ;
			adj[x].push_back(make_pair(y,time+wait[c])) ;
			adj[y].push_back(make_pair(x,time+wait[a])) ;
		}
		int q ;
		cin >> q ;
		int x1,x2,y1,y2 ;
		cout << "Case #" << test << ": " ;
		while(q--) {
			cin >> x1 >> x2 >> y1 >> y2 ;
			int u = mapped[make_pair(x1,x2)] , v = mapped[make_pair(y1,y2)] ;
//			cout << u << " "<< v << endl;
			dijsktra(u) ;
//			for(int i=0;i<=node;i++)
//				cout << weight[i] << " ";
			if(weight[v] >=  INT_MAX)
				cout << -1 << endl;
			else cout << weight[v] + wait[x1] << endl;
		}
		node = 0 ;
		mapped.clear() ;
		for(int i=0;i<=node;i++)
			adj[i].clear() ;
	}
}
