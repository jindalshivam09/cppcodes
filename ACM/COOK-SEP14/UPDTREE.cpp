#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m1, m2 ;
#define MAX 1000006
vector<vector<int> > adj(MAX), lca(MAX,vector<int>(20)) ;
vector<int> father(MAX), level(MAX);
vector<ll> values(MAX), sum(MAX) ;
vector<bool> visited(MAX) ;

#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
inline ll read_int()
{
int flag=1;
long long n = 0;
char c;
int sign=1;
while (1)
{
c=GETCHAR();
if(c=='-')	sign=-1;
else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
 }
return sign*n;
}


void lca_preprocess () {
		
	for(int i=0;i<n;i++)
		for(int j=0;1<<j<n;j++)
			lca[i][j] = -1 ;	
		
	for(int i=0;i<n;i++)
		lca[i][0] = father[i] ;
		
	for(int j = 1 ; 1 << j < n ; j ++) {
		for(int i = 0 ; i < n ; i ++) {
			if(lca[i][j-1] != -1)
				lca[i][j] = lca[lca[i][j-1]][j-1] ;
		}
	}
}

void find_parent (int u, int parent) {
	father[u] = parent ;
	if(parent != -1)
		level[u] = level[parent] + 1;
	else
		level[u] = 0 ;
		
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
		if(v != parent)
		find_parent(v,u) ;
	}
}

int find_lca(int a, int b) {
	if(level[a] < level[b])
		swap(a,b) ;
	
	int cnt = 0 ;
	for(int j = 0 ; 1 << j <= level[a] ; j ++)
		cnt ++ ;
	cnt -- ;	
	for(int j = cnt ; j >= 0 ; j --) {
		if(level[a] - (1<<j) >= level[b])
			a = lca[a][j] ;
	}
	if(a == b)
		return a ;
	for(int j = cnt ; j >= 0 ; j --) {
		if( lca[a][j] != -1 && lca[a][j] != lca[b][j])
			a = lca[a][j], b = lca[b][j] ;
	}
	return father[a] ;
}

void update(int a, int b, int c, int d) {
	if(a == b || c == d)
		return ;
	int p = find_lca(a,c) ;
	int q = find_lca(b,d) ;
	if(p == c) {
		if(q == b)
			values[b] --, values[a] --, values[find_lca(a,b)] += 2 ;
		else if (q == d && level[a] >= level[c] && level[a] < level[d])
			values[d] --, values[a] --, values[find_lca(d,a)] += 2 ;
		else {
			int t = find_lca(q,a) ;
			if( t == a)
				values[q] -- , values[a] --, values[a] += 2 ;
		}
	}  
	else if(p == a) {
		if(q == b && level[c] < level[b] && level[a] <= level[c] )
			values[c] --, values[b] --, values[find_lca(c,b)] += 2; 
		else if ( q == d && level[d] <= level[b] && level[c] < level[b] )
			values[d] --, values[c] --, values[find_lca(c,d)] += 2 ;
		else {
			int t = find_lca(q,c) ;
			if(t == c)
				values[c] --, values[q] --, values[c] +=2 ;
		}
	}
}

void cal_prefix (int u) {
	visited[u] = true;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
		if(visited[v] == false) {
			cal_prefix(v) ;
			values[u] += values[v] ;
		}
	}
}

void cal_sum () {
	fill(visited.begin(),visited.end(),false);
	queue<int> q ;
	q.push(0) ;
	sum[0] = values[0] ;
	while(q.empty() == false) {
		int u = q.front() ;
		ll val = sum[u] ;
		q.pop() ;
		visited[u] = true ;
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i] ;
			if( visited[v] == false) {
				q.push(v) ;
				sum[v] = values[v] + val ;
			}
		}
	}
}

int main() {
	n = read_int() ;
	m1 = read_int() ; ;
	m2 = read_int() ;
	int a, b;
	for(int i=0;i<n-1;i++) {
		a = read_int() ; ;
		b = read_int() ; 
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}
	find_parent(0,-1) ;
	lca_preprocess() ;
	
	int c,d ;
	while(m1--) {
		a = read_int() ;
		b = read_int() ;
		c = read_int() ;
		d = read_int() ;
		a--, b--, c--, d-- ;
		int p = find_lca(a,b) ; 
		int q = find_lca(c,d) ;
		values[a] ++, values[b] ++, values[p] -= 2 ;
		if(a == p && q == c)
			update(a,b,c,d) ;
		else if(a == p && q != c)
			update(a,b,q,c) , update(a,b,q,d) ;
		else if(a != p && q == c)
			update(p,a,c,d) , update(p,b,c,d) ;
		else
			update(p,a,q,c) , update(p,a,q,d), update(p,b,q,c), update(p,b,q,d) ;
	}
	cal_prefix(0) ;
	cal_sum() ;
	
	while(m2--) {
		a = read_int() ; 
		b = read_int() ;
		a--, b--;
		int p = find_lca(a,b) ;
		printf("%lld\n",sum[a]+sum[b]-2ll*sum[p]) ; 
	}
}
