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

int k,n,r ;
typedef struct node {
	int toll, length, destination ;
	node(int t=0,int l=0,int d=0) {
		toll = t , length = l , destination = d ;
	}
}node;
vector<vector<node> > adj ;
vector<vector<pair<bool,int> > > memo(100,vector<pair<bool,int> >(100));
vb visited ;

pair<bool,int> dp(int u, int coins = 0) {
	if(u==n) 
		return mp(true,0) ;
	if (memo[u][coins].second)
		return memo[u][coins] ;
	visited[u] = true ;
	pair<bool,int> ans(false,imax) ;
	for(int i=0;i<adj[u].size();i++) {
		node temp = adj[u][i] ;
		pair<bool,int> ret ;
		if( coins + temp.toll < k && visited[temp.destination] == false ) {
			ret = dp(temp.destination,coins+temp.toll);
			if(ret.first == true) {
				if(ans.first == false) 
					ans = mp(true,temp.length+ret.second) ;
				else if (ans.second > ret.second + temp.length )
					ans = mp(true,temp.length+ret.second) ;					
			}
		}
	}
	return memo[u][coins] = ans ;
}

int main() {
	int t;
	cin >> t ;
	while(t--) {
		cin >> k >> n >> r ;
		adj.resize(n+1) ;
		visited.resize(n+1) ;
		int s,d,l,t ;
		rep(i,r) {
			cin >> s >> d >> l >> t ;
			node temp(t,l,d) ;
			adj[s].pb(temp) ;
		}
		pair<bool,int> ans = dp(1);
		if(ans.first == true)
			cout << ans.second ;
		else
			cout << -1;
		cout << endl;
		rep(i,100)
			rep(j,100)
				memo[i][j] = mp(false,0) ;
		adj.clear();
		visited.clear() ;
	}
}


