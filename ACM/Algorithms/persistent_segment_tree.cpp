#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
inline long long read_int()
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

#define MAX 100009
int n, m, node ;
map<int,int> mapped ;
vector<int> value(MAX) ;
vector<vector<int> > adj(MAX) ;
vector<int> father(MAX), level(MAX), wt(MAX);
vector<vector<int> > parents(MAX,vector<int>(50));

class segment {
	public :
		int cnt ;
		segment *left, *right ;
		segment() {
			cnt = 0, left = NULL, right = NULL ;
		}
		segment(int cnt, segment *left, segment *right) {
			this->cnt = cnt , this->left = left , this->right = right ;
		}
		segment * insert(int l, int r, int w) ;
};

segment *null = new segment(0,NULL,NULL) ;
vector<segment *> root(MAX) ;

segment * segment::insert(int l, int r, int w) {
	if(r<w || l>w)
		return this ;
	if(l == r) {
		return new segment(this->cnt+1,null,null) ;
	}
	int mid = (l+r)/2 ;
	return new segment(this->cnt+1,this->left->insert(l,mid,w),this->right->insert(mid+1,r,w)) ;
}


void dfs(int u, int parent) {	
	father[u] = parent ;
	if(parent!=-1) {
		level[u] = level[parent]+1;
		root[u] = root[parent]->insert(0,node,mapped[wt[u]]) ;
	}
	else {
		level[u] =  0;
		root[u] = null->insert(0,node,mapped[wt[u]]) ;
	}
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
		if(parent != v) {
			dfs(v,u) ;
		}
	}
}

void processLCA() {	
	int logn = 0 ;
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
	int logn = 0;
	for(;1<<logn <= level[u];logn++) ;
	logn -- ;
	for(int i=logn;i>=0;i--) {
		if(level[u]-(1<<i) >= level[v])
			u = parents[u][i] ;
	}
	if(u == v)
		return u ;
	for(int i=logn;i>=0;i--) {
		if(parents[u][i] != -1 && parents[u][i] != parents[v][i]) 
			u = parents[u][i], v = parents[v][i] ;
	}
	return father[u] ;
}

int query(segment *a, segment *b, segment *c, segment *d,int l, int r, int k) {
	if(l == r) {
		return l ;
	}
	int cnt = a->left->cnt + b->left->cnt - c->left->cnt - d->left->cnt ;
	int mid = (l+r)/2 ;
	if(cnt >= k) 
		return query(a->left,b->left,c->left,d->left,l,mid,k) ;
	return query(a->right,b->right,c->right,d->right,mid+1,r,k-cnt) ;
		
}

int retrieve(int u, int v, int k) {
	int LCA = getLCA(u,v) ;
	if(father[LCA] != -1) 	return query(root[u],root[v],root[LCA],root[father[LCA]],0,node,k) ;
	else					return query(root[u],root[v],root[LCA],null,0,node,k) ;
}

int main() {
	n = read_int() ;
	m = read_int() ;
	int a ;
	for(int i=0;i<n;i++) {
		a = read_int() ;
		wt[i] = a ;
		mapped[a] = 1 ;
	}
	node = 0;
	for(map<int,int>::iterator itr = mapped.begin(); itr != mapped.end(); itr ++) {
		mapped[itr->first] = node ;
		value[node] = itr->first ;
		node ++ ;
	}
	node -- ;
	null->left = null->right = null ;
	int u, v ;
	for(int i=0;i<n-1;i++) {
		u = read_int() ;
		v = read_int() ;
		u --, v -- ;
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;
	}
	dfs(0,-1) ;
	processLCA() ;
	int  k ;
	while(m--) {
		u = read_int(), v = read_int(), k = read_int() ;
		u--, v-- ;
		printf("%d\n",value[retrieve(u,v,k)]) ;
	}
}
