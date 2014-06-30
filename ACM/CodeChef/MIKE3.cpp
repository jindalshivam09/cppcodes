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
#define MAX 20009
int n,m;
vector<vi> adj(MAX) , offer(21);
vb checked(21) , added(MAX);
int cnt = 0;
int cal_max (int i=1) {
	cout << cnt << " " << i << endl;
	if(cnt==n)
		return 0;
	if(i>n)
		return 0;
	if(added[i] || adj[i].size()==0)
		return cal_max(i+1);
	int ans = 0;
	cout << i << "->";
	rep(j,adj[i].size()) {
		int temp = adj[i][j] ;
		bool flag = false ;
		cout << "offer" << temp << endl;
		if (checked[temp]==false) {
			checked[temp] = true ;
			rep(k,offer[temp].size()) {
				int v = offer[temp][k];
				if (added[v]) {
					flag = true;
					break;
				}
			}
			if(flag == false) {
				rep(k,offer[temp].size()) {
					int v = offer[temp][k];
					cout << "item" << v << endl;
					added[v] = true;;
					cnt++;
				}
				ans = max(ans , 1+cal_max(i+1));
				rep(k,offer[temp].size()) {
					int v = offer[temp][k];
					added[v] = false;
					cnt--;
				}
			}
			checked[temp] = false ;
		}
	}
	return ans ;
}

int main() {
	cin >> n >> m;
	int k , a;
	rep(i,m) {
		cin >> k ;
		rep(j,k) {
			cin >> a ;
			offer[i+1].pb(a) ;
			adj[a].pb(i+1);
		}
	}
	cout << cal_max() << endl;
}


