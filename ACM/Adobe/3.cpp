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
#define MAX 100009
vector<vll> adj(MAX) ;
ll n , root ;

void func() {
	ll shakes=0, fists=0 ;
	ll node=0;
	queue<ll> q;
	q.push(root) ;
	ll count = 0;
	while(count < n) {
		vll arr;
		ll temp = q.size();
		shakes += (node*temp) ;
		node += temp ;
		while(q.empty()==false) {
			count ++ ;
			ll u = q.front();
			q.pop() ;
			for(int i=0;i<adj[u].size();i++) {
				ll v = adj[u][i] ;
				arr.pb(v) ; 
			}
		}
		for(int i=0;i<arr.size();i++)
			q.push(arr[i]) ;
	}
	ll tot = (n*(n-1))/2 ;
//	cout << tot << endl;
	cout << shakes << " " << tot-shakes << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n ;
//		n = 100000;
		int a;
		rep(i,n) {
			cin >> a ;
//			a = i+1;;
			if(a==0)
				root = i+1 ;
			else
				adj[a].pb(i+1);
		}
		func() ;
		rep(i,n)
			adj[i+1].clear() ;
	}
}


