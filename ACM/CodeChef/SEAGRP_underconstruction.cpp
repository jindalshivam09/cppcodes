/*
	Name: Edmond's Blossom Shrinking Algorithm 
	Copyright: no rights
	Author: jindalshivam09
	Date: 27/02/14 12:53
	Description: used to find maximum matching in a general graph O(v^3)
*/


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
#define MAX 1000009
vb is_shrinked(MAX);
class graph {
	vector<vi> adjlist ;
	int n ;
	vi match(MAX,-1);
	public :
		graph(int n = 0) {
			this.n = n ;
			adjlist.resize(n+1);
		}
		graph(int n,const vpii &edges) {
			this.n = n ;
			adjlist.resize(n+1);
			int a,b;
			rep(i,n) {
				a = edges[i].first ;
				b = edges[i].second ;
				adjlist[a].pb(b);
				adjlist[b].pb(a);
			}
		}
		int maximum_matching () {
			int count = 0;
			repi(i,1,n+1) {
				rep(j,adjlist[i].size()) {
					int temp = adjlist[i][j] ;
					if ( match[i] < 0 && match[temp] < 0 ) 
						match[i] = temp , match[temp] = i .count ++;
				}
			}
			repi(i,1,n+1) {
				rep(j,adjlist[i].size()) {
					if ( match[i] < 0 && bfs(i) )
						count ++ ;
				}
			}
			return count ;
		}
		bool bfs (int source) {
			vb visited(n+1) ;
			vi father(n+1) , pre(n+1,-1) ;
			repi(i,1,n+1)
				father[i] = i ;
			queue<int> q ;
			q.push(source);
			while ( !q.empty() ) {
				int u = q.front();
				q.pop() ;
				rep(i,adjlist[u].size()) {
					int v = adjlist[u][i] ;
					if ( father[u] != father[v] && match[u] != v ) {
						if ( v != source || match[v] >= 0 && pre[v] >= 0 ) {
							int next = contract(u,v);
							repi(i,1,n+1) {
								if ( is_shrinked[i] ) {
									father[i] = next ;
									if (!visited[i]) {
										visited[i] = true;
										q.push(i) ;
									}
								}
							}
						}
						else if ( pre[v] < 0) {
							pre[v] = u;
							if ( match[v] < 0 ) {
								expand(v);
								return truel
							}
							q.push(v);
							visited[v] = true ;
						}
					}
				}
			}
		}
		int contract ( int u,int v ) {
			int parent = get_father ( father[u] , father[v] ) ;
			is_shrinked.resize(n+1,false);
			change_blossom(key,u);
			change_blossom(key,v);
			if ( father[])
		}
};
int main() {
	int v,e;
	cin >> v >> e;
	
}


