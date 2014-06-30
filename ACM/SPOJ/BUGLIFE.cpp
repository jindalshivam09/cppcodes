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
#define MAX 2009
int n,k;
#define RED 1
#define BLUE 2

bool two_colorable (list<int> *adj) {
	vi colors(n+1,0);
	queue<int> q;
	int paint ;
	for (int i=1;i<=n;i++) {
		if (!colors[i]) {
			q.push(i);
			colors[i] = RED ;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
//				cout << u << "->";
				if (colors[u] == RED )
					paint = BLUE ;
				else
					paint = RED ;
				for(list<int>::iterator itr = adj[u].begin() ; itr != adj[u].end() ; itr ++) {
					int v = *itr ;
//					cout << v << " ";
					if (!colors[v])
						colors[v] = paint;
					else if ( colors[v] != paint )
						return false;
					q.push(v);
				}
//				cout << endl;
			}
		}
	}
	return true;
}

int main() {
	int t;
	scanf ("%d",&t);
	rep(test,t) {
		scanf ("%d%d",&n,&k);
		int a,b;
		list<int> adj[n+1];
		rep(i,k) {
			scanf ("%d%d",&a,&b);
			if (a < b)		adj[a].pb(b);
			else			adj[b].pb(a);
		}
		printf("Scenario #%d:\n" , test+1 );
		if ( two_colorable(adj) )
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}	
}


