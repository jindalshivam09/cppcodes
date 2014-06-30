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
#define imax  			numeric_limits<long long>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {
	ll n;
	cin >> n ;
	map<ll,vll> edges ;
	map<ll,vll> y ;
	ll a,b ;
	rep(i,n)  {
		cin >> a >> b ;
		edges[a].pb(b);
		y[b].pb(a);
	}
	map<ll,ll> put ;
	for(map<ll,vll>::iterator itr = y.begin() ; itr != y.end() ; itr++) {
		vll arr = itr->second ;
		for(int i=0;i<arr.size();i++)
			put[arr[i]] = 1;
	}
	for(map<ll,vll>::iterator itr = edges.begin();itr != edges.end() ; itr++) {
		ll u = itr->first ;
		vll arr = itr->second ;
		sort(all(arr));
		edges[u] = arr;
	}
	ll ans = 0;
	map<ll,vll>::iterator itr = edges.begin() ,itr2;
	itr++;
	
	for(;itr!=edges.end();itr++) {
		if (put[itr->first])
			continue;
		itr2 = itr;
		itr2--;
		vll arr = itr2->second ;
		vll arr2 = itr->second ;		
		ll dist = abs(itr->first-itr2->first) ;
		for(int j=0;j<arr.size();j++) {
			ll temp = arr[j];
			int index = lower_bound(all(arr2),temp) - arr2.begin() ;
			if (index<n) {
				dist = min(dist,abs(arr[j]-arr2[index])) ;
			}
			if (index>0) {
				index --;
				dist = min(dist,abs(arr[j]-arr2[index])) ;			
			}
		}
		ans += dist ;
	}
	cout << ans << endl;
}



