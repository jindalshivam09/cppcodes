#include<bits/stdc++.h>
using namespace std ;

#define MAX 109
#define EDGES 200009
vector<vector<pair<int,int> > > adj(EDGES) ;
vector<vector<int> > number(EDGES) ;
int n, node ;
vector<int> wait(EDGES), weight(EDGES), parent(EDGES) ;
vector<bool> visited(EDGES) ;

class cmp{
	public:
		bool operator() (const pair<int,int> &a,const pair<int,int> &b) const {
			return a.second < b.second;
		}
};


void dijsktra(int source) {
	queue<int> Q ;
	Q .push(source);
	fill(weight.begin(),weight.end(),INT_MAX);
//	fill(parent.begin(),parent.end(),INT_MAX);
	fill(visited.begin(),visited.end(),false);
	weight[source] = 0;
	visited[source] = true ;
	while(!Q.empty()) {
		int u = Q.front() ;
		Q.pop();
		visited[u] = false ;
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i].first;
			int wv = adj[u][i].second;
			if(weight[v] > wv + weight[u] ) {
				weight[v] = wv + weight[u];
//				if(visited[v] == false)
					Q.push(v), visited[v] = true;
			}
		}
	}
}

int main() {
	freopen ("input.txt","r",stdin) ;
	freopen ("output.txt","w",stdout) ;

	int t ;
	scanf("%d",&t);
	for(int test=1;test<=t;test++) {
		scanf("%d",&n);
		node = 0 ;
		int sn, w ;
		for(int i=0;i<n;i++) {
			scanf("%d %d",&sn,&w);
			wait[i] = w ;
			int time ;
			for(int j=1;j<sn;j++) {
				scanf("%d",&time);
				adj[node+j].push_back(make_pair(node+j-1,time)) ;
				adj[node+j-1].push_back(make_pair(node+j,time)) ;
			}
			for(int j=0;j<sn;j++) 
				number[i].push_back(node+j) ;
			node += sn ;
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<number[i].size();j++) {
				int temp = number[i][j] ;
				adj[temp+node].push_back(make_pair(temp,wait[i])) ;
				adj[temp].push_back(make_pair(temp+node,0)) ;
			}
		}
		int m ;
		scanf("%d",&m);
		int a,b,c,d, time;
		for(int i=0;i<m;i++) {
			scanf("%d",&a);
			scanf("%d",&b);
			scanf("%d",&c);
			scanf("%d",&d);
			scanf("%d",&time);
			a--, b--, c--, d-- ;
			int x = node+number[a][b] , y = node+number[c][d] ;
			adj[x].push_back(make_pair(y,time)) ;
			adj[y].push_back(make_pair(x,time)) ;
		}
		int q ;
		scanf("%d",&q);
		int x1,x2,y1,y2 ;
		printf("Case #%d:\n",test);
		while(q--) {
			scanf("%d",&x1);
			scanf("%d",&x2);
			scanf("%d",&y1);
			scanf("%d",&y2);
			x1--, x2--, y1--, y2-- ;
			int u = node+number[x1][x2] , v = node+number[y1][y2] ;
			dijsktra(u) ;
			if(weight[v] >=  INT_MAX)	printf("-1\n") ;
			else 						printf("%d\n",weight[v]) ;
		}
		node = 0 ;
		for(int i=0;i<=EDGES;i++)
			adj[i].clear() , number[i].clear();
	}
}
