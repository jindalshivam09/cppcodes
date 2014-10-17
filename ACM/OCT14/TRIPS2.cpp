#include<bits/stdc++.h>
using namespace std ;

#define SQRTN 30
#define MAX 1000
#define LOGN 18
int n, logn ;
vector<vector<pair<int,int> > > adj(MAX) ;
vector<int> dist(MAX), ht(MAX), father(MAX), level(MAX) ;
vector<vector<int> > parents(MAX,vector<int>(LOGN)) ;
//vector<vector<vector<int> > > memo(SQRTN,vector<vector<int> >(MAX,vector<int>(LOGN))) ;
int memo[SQRTN][MAX][LOGN] ;

void dfs(int u,int parent) {
	father[u] = parent ;
	if(parent == -1) 		ht[u] = 0, dist[u] = 0, level[u] = 0 ;
	else  					ht[u] = ht[parent] + 1, level[u] = level[parent]+1 ;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i].first ;
		int wt = adj[u][i].second ;
		if(parent != v) {
			dist[v] = dist[u] + wt ;
			dfs(v,u) ;
		}
	}
}

void processLCA() {
	logn = 0 ;
	for(int i=0;1<<i < n ; i ++)
		logn++ ;
	for(int i=0;i<n;i++)
		for(int j=0;j<logn;j++)
			parents[i][j] = -1 ;
	
	for(int i=0;i<n;i++) 
		parents[i][0] = father[i] ;
	
	for(int j=1 ; 1<<j < n ; j++) {
		for(int i=0;i<n;i++)
			if(parents[i][j-1] != -1) 
				parents[i][j] = parents[parents[i][j-1]][j-1] ;
	}
}

int getLCA(int u, int v) {
	if(level[u] < level[v])
		swap(u,v) ;
	for(int i=logn-1;i>=0;i--) {
		if(level[u]-(1<<i) >= level[v])
			u = parents[u][i] ;
	}
	if(u == v)
		return u ;
	for(int i=logn-1;i>=0;i--) {
		if(parents[u][i] != -1 && parents[u][i] != parents[v][i]) 
			u = parents[u][i], v = parents[v][i] ;
	}
	return father[u] ;
}

int singleMove(int u,int w,int c) {
	int dis = dist[u] ;
	for(int i=logn-1;i>=0;i--) {
		int v = parents[u][i] ;
		if(v == -1)				continue ;
		if(dis - dist[v] > c)	continue ;
		if(dis - dist[v] < c && v == w)	break ;
		u = v ;
	}
	return u ;
}

pair<int,int> stepsAndRemDays1(int u, int w, int c) {
	pair<int,int> ret(0,0) ;
	while(u != w) {
		int ancestor = singleMove(u,w,c) ;
		if(dist[ancestor]-dist[w] < 0 || ancestor == u)
			break ;
		ret.first ++ ;
		u = ancestor ;
	}
	ret.second = dist[u]-dist[w] ;
	return ret ;
}

pair<int,int> stepsAndRemDays2(int u, int w, int c) {
//	cout << "stepsAndRemDays: " ;
//	cout << u << " " << w << " " << c << endl ;
	pair<int,int> ret(0,0);
	for(int i=logn-1;i>=0;i--) {
		int v = memo[c][u][i] ;
//		cout << u << " " << v << " " << c << endl ;
		if(v == -1)				continue ;
		if(dist[v]-dist[w]<0)	continue ;
		if(v == w)				continue ;
		u = v ;
		ret.first += (1<<i) ;
	}
	ret.second = dist[u]-dist[w] ;
//	cout << ret.first << " " << ret.second << endl ;
	return ret ;
}

int firstType(int u, int v,int c) {
	int lca = getLCA(u,v) ;
	int steps = 0, rem = 0 ;
	pair<int,int> ret = stepsAndRemDays1(u,lca,c) ;
	steps = ret.first, rem = ret.second ;
	ret = stepsAndRemDays1(v,lca,c) ;
	steps += ret.first, rem += ret.second ;
	steps += (ceil)(rem*1.00/c) ;
	return steps ;
}

int secondType(int u, int v, int c) {
	int lca = getLCA(u,v) ;
	int steps = 0, rem = 0 ;
//	cout << u << " " << v << " " << c << endl ;
	pair<int,int> ret = stepsAndRemDays2(u,lca,c) ;
	steps = ret.first, rem = ret.second ;
	ret = stepsAndRemDays2(v,lca,c) ;
	steps += ret.first, rem += ret.second ;
//	cout << rem << endl ;
	steps += (ceil)(rem*1.00/c) ;
	return steps ;	
}

int query(int a, int b, int c) {
	if( c > (int)sqrt(n) ) 
		return firstType(a,b,c) ;
	return secondType(a,b,c) ;
}

void processForSecondQuery() {	
	for(int c=2;c<=(int)sqrt(n);c++) {
		for(int j=0;j<n;j++) {
			int k = singleMove(j,-1,c) ;
			if(k == j)	memo[c][j][0]  = -1 ;
			else		memo[c][j][0] = k ;	
		}
	}
	for(int c=2;c<=(int)(sqrt(n));c++) {
		for(int i=1;i<logn;i++) {
			for(int j=0;j<n;j++) {
				int k = memo[c][j][i-1] ;
				if( j == k)		memo[c][j][i] = -1 ;
				else {
					k = memo[c][k][i-1] ;
					memo[c][j][i] = k ;
				}
			}
		}
	}
}

void preprocess() {
	dfs(0,-1) ;
	processLCA() ;
	processForSecondQuery() ;
}

int main() {
	cin >> n ;
	int a, b, c ;
	for(int i=0;i<n-1;i++) {
		cin >> a >> b >> c ;
		a--, b-- ;
		adj[a].push_back(make_pair(b,c)) ;
		adj[b].push_back(make_pair(a,c)) ;
	}
	preprocess() ;
	int m ;
	cin >> m ;
	while(m--) {
		cin >> a >> b >> c ;
		a--, b-- ;
		cout << query(a,b,c) << endl;
	}

}	
