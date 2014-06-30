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
#define MAX 5009
vector<vi> input(MAX) , matrix(MAX,vi(MAX)) , ans(MAX) , graph(MAX,vi(MAX));
vector<pii> pairs , edges(MAX);
int n,m,cnt;

bool check(int a, int b , int c , int d ){
	return matrix[a][c] && matrix[a][d] && matrix[b][c] && matrix[b][d] ;
}
//map <int,pii> edges;

void addEdge (int a,int i,int j) {
	edges[a] = mp(i,j);
	ans[i].pb(j) , ans[j].pb(i);
	graph[i][j] = graph[j][i] = 1 ;
}
int common (int a,int b) {
	if (edges[a].first == edges[b].first || edges[a].first == edges[b].second)
		return edges[a].first;
	else
		return edges[a].second ;
}
int free_node (int x) {
	int a = edges[x].first , b = edges[x].second; 
	if ( ans[a].size() == 1)	return a;
	return b ;
}

void solve (int i,int j) {
	int a,b,c,d;
	a = pairs[i].first , b = pairs[i].second;
	c = pairs[j].first , d = pairs[j].second;
	addEdge(a,1,2) , addEdge(b,1,3) , addEdge(c,1,4) , addEdge(d,1,5);
	int  u,r,t,v,w,y;	
	cnt = 6 ;
	queue<int> q;
	vb seen(n+1);
	seen[a] = seen[b] = seen[c] = seen[d] = true;
	int temp ;
	q.push(a) , q.push(b) , q.push(c) , q.push(d) ;
	while(!q.empty()) {
		temp = q.front() ;	q.pop() ;
		seen[temp] = true;
		a = edges[temp].first , b = edges[temp].second ;
		
		for (int i=0;i<input[temp].size();i++) {
			u = input[temp][i] ;
			if (seen[u]) continue ;
			seen[u] = true ;
			q.push(u);
			
			for(int j=0;j<input[temp].size();j++) {
				v = input[temp][j] ;
				if (seen[v] == 0 || v == u)	continue ;
				w = common(temp,v);
				if (matrix[u][v] == 0) {
					d = w==a ? b : a ;
					break;
				}
				d = w;
			}			
			int ct =0, p , q ;
			for(int j=0;j<input[u].size();j++) {
				v = input[u][j];
				if (seen[v] == 0 || v == temp) continue;
				if (edges[v].first == d || edges[v].second == d)	continue ;
				ct ++ ;
				if (ct==1)	p = v;
				else 		q = v;
				if (ct==2)	break;
			}
			if (ct==0)
				c = cnt ++ ;
			else {
				if (ct==1)	c = free_node(p);
				else		c = common(p,q);
				if (c == d || graph[c][d])	c = cnt ++;
			}
			addEdge(u,c,d);	
//			cout << cnt << endl;
  		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a,b;
		cin >> n >> m ;
		rep(i,m) {
			cin >> a >> b ;
			input[a].pb(b) ;
			input[b].pb(a) ;
			matrix[a][b] = matrix[b][a] = 1 ;
			pairs.pb(mp(min(a,b),max(a,b)));
		}
		bool flag = false;
		rep(i,m) {
			repi(j,i+1,m) {
				if(check(pairs[i].first,pairs[i].second,pairs[j].first,pairs[j].second)) {
					solve(i,j);
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		cout << cnt-1 << endl;
		repi(i,1,n+1)
			cout << edges[i].first << " " << edges[i].second << endl;
		pairs.clear() ;
		rep(i,n+2) 			input[i+1].clear();
		rep(i,cnt+2) rep(j,cnt+2)	graph[i][j] = graph[j][i] = 0 ;
		rep(i,n+2)	rep(j,n+2) matrix[i][j] = matrix[j][i] = 0 ;
		rep(i,cnt+2)	ans[i].clear() , edges[i] = mp(0,0);
				cnt = 0 ;

	}
}
