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
vector<pair<pii,ll> > edges ;
ll n,m,k;

bool cmp ( const pair<pii,ll> &a,const pair<pii,ll> &b) {
	return a.second > b.second ;
}

ll max_dist() {
	vi bikers(n,m) , bikes(m,n) ;
	sort(all(edges),cmp);
	ll delbike = 0 , delbiker = 0;
	rep(i,edges.size()) {
		ll u = edges[i].first.first ;
		ll v = edges[i].first.second ;
		bikers[u] -- ;
		bikes[v] -- ;
		if (!bikers[u])
			delbiker ++ ;
		if (!bikes[v])
			delbike ++ ;
		if ( k == (n-delbiker+1) || k == (m-delbike+1) )
			return edges[i].second ;
	}
	return 0;
}

int main() {
		cin >> n >> m >> k ;
		vpii bikers(n);
		rep(i,n) {
			cin >> bikers[i].first >> bikers[i].second ;
		}
		ll a,b,u,v;
		rep(j,m) {
			cin >> a >> b ;
			rep(i,n) {
				u = bikers[i].first ;
				v = bikers[i].second ;
				edges.pb(mp(mp(i,j),((u-a)*(u-a)+(v-b)*(v-b)))) ;
			}
		}
		cout << max_dist() << endl;
		edges.clear();
}


