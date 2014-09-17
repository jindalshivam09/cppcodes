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

#define MAX 100001
#define NIL 0
#define INF (1<<28)

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q ;
    cout << "bfs" << endl;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
        	cout << i << " ";
        	
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    cout << endl;
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
        	cout << u << "-> " ;
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                cout << v << "," << match[v] << endl;
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    cout << "exit from bfs" << endl;
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
    	cout << "(" << u << ") :" << endl;
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            cout << v << "," << match[v] << endl; 
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                	cout << "match found" << endl;
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++) {
			cout << i << "-> " ;
            if(match[i]==NIL && dfs(i)){
            	cout << "matched " << i << endl;
                matching++;
            }
            cout << endl;
        }
    return matching;
}

int main() {
	cin >> n >> m;
	int a, b ;
	rep(i,m) {
		cin >> a >> b ;
		G[a].pb(b) ;
		G[b].pb(a) ;
	}
	cout << hopcroft_karp() ;
}


