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

int main() {
	int v,e;
	cin >> v >> e;
	list<int> adj[v+1];
	int a,b;
	vi deg(v+1);
	rep(i,e) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
		deg[a] ++;
		deg[b] ++;
	}
	int count = 0;
	while(1) {
		bool flag = false;
		vi arr;
		for(int i=1;i<=v;i++) {
			if(deg[i]==1) {
				flag = true ;
				arr.pb(i);
			}
		}
		for(int j=0;j<arr.size();j++) {
			int i = arr[j];
			deg[i]=0;
			for(list<int>::iterator itr = adj[i].begin() ; itr != adj[i].end() ; itr++)  {
				deg[(*itr)]--;
			}
		}
		if(flag)	count++;
		else		break;
	}	
	cout << count ;
}


