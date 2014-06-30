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
#define MAX 209
vector<vi> cost(4,vi(4))  , adj(MAX,vi(MAX));
void init() {
	cost[1][2] = 1 , cost[1][3] = 2 ;
	cost[2][1] = 2 , cost[2][3] = 1 ;
	cost[3][1] = 1 , cost[3][2] = 2 ;
}

int n;
vector<int> computers ,outdeg , indeg ;

int func() {
	queue<int> q ;
	repi(i,1,n+1) {
		if (indeg[i] == 0)
			q.push(i) , indeg[i] = -1;
	}
	ll ans = 0;
	while(1) {
		while(q.empty()==false) {
			int pc  = q.front() ;
			q.pop() ;
			for(int i=0;i<adj[pc].size();i++) {
				int a = adj[pc][i] ;
				int x  = computers[pc] , y = computers[a];
				indeg[a] -- , ans += cost[x][y]		;
			}
		}
		bool flag = false ;
		for(int i=1;i<n+1;i++) {
			if (indeg[i] == 0) {
				q.push(i);
				indeg[i] = -1 ;
				flag = true;
			}
		}
		if (flag == false)
			return ans ;
	}
}

int main() {
	init() ;
	cin >> n ;
	computers.resize(n+1) ;
	outdeg.resize(n+1) ;
	indeg.resize(n+1) ;
	repi(i,1,n+1)
		cin >> computers[i] ;
	repi(i,1,n+1) {
		int k;
		cin >> k ;
		indeg[i] = k ;
		while(k--) {
			int a ;
			cin >> a ;
			adj[a].pb(i);
			outdeg[a] ++ ;
		}
	}
	cout << func() ;
}


