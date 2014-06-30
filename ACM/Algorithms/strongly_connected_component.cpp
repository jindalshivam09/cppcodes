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
#define  dmin            numeric_limits<double>::min()

// -----------------scc------------------------------------------------------------------------------

#define MAX 1000
#define SCC true
#define CC false

vector<vi> adj ;
vi finish , start ;
vb visited ;
int  tme =  1 , n ,m , cc = 1 , scc = 1 ;
struct node {
	int id , start , finish ,cc , scc;
} node[MAX] ;
void dfs (int i,const vector<vi> &adj ,bool flag) {
	visited[i] = true;
	node[i].id = i ;
	if(flag == CC)
		node[i].cc = cc ;
	else
		node[i].scc = scc ;
	node[i].start= tme ++ ;
	rep(j,adj[i].size()) {
		int v = adj[i][j] ;
		if(visited[v]==false) {
			dfs(v,adj,flag) ;
		}
	}
	node[i].finish = tme++ ;
}

bool cmp_time (const struct node &a,const struct node &b) {
	return a.finish > b.finish ;
}

bool cmp_id (const struct node &a,const struct node &b) {
	return a.id < b.id ;
}

vector<vi> transpose() {
	vector<vi> temp(n+1) ;
	repi(i,1,n+1) {
		rep(j,adj[i].size()) 
			temp[adj[i][j]].pb(i);
	}
	return temp ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	cin >> n >> m ;
	adj.resize(n+1);
	start.resize(n+1) ;
	finish.resize(n+1) ;
	visited.resize(n+1) ;
	int a,b;
	rep(i,m) {
		cin >> a >> b ;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	repi(i,1,n+1) if (visited[i]==false) {
		dfs(i,adj,CC) ;	
		cc ++ ;
	}
	vector<vi> transpose_matrix = transpose();
	repi(i,1,n+1)	visited[i] = false;
	sort(node+1,node+n+1,cmp_time);
	repi(i,1,n+1) {
		int u = node[i].id;
		if(!visited[u]) {
			dfs(u,transpose_matrix,SCC) ;
			scc ++;
		}
	}
	sort(node+1,node+1+n,cmp_id) ;
	repi(i,1,n+1)
		cout << node[i].scc << " ";
}


