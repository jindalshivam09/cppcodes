#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax			numeric_limits<int>::max()
vector<vpii> adj(7);
int N,T;
vector<vi> memo(7,vi(10009));

int main() {
	cin >> N >> T ;
	int a,b,c;
	vi present(7);
	int count  = 0;
	rep(i,N) {
		cin >> a >> b >> c ;
		adj[a].pb(mp(b,c));
		present[a]++;
		if (present[a]==1)
			count ++ ;
	}
	if(count < 6) {
		cout << 0 ;
		return 0;
	}
	for(int k=0;k<adj[1].size();k++) {
		for(int j=0;j<=T;j++) {
			if(j>adj[1][k].first) {
				memo[1][j] = max(memo[1][j],adj[1][k].second);
				memo[1][j] = max(memo[1][j],memo[1][j-1]);
			}
			else
				memo[1][j] = 0 ;
		}
	}
	for(int i=2;i<7;i++) {
		for(int k=0;k<adj[i].size();k++) {
			for(int j=0;j<=T;j++) {
				if(j>adj[i][k].first) {
					memo[i][j] = max(memo[i][j] , min(memo[i-1][j-adj[i][k].first],adj[i][k].second));
					memo[i][j] = max(memo[i][j],memo[i][j-1]);
				}
				else 
					memo[i][j] = 0 ;
			}
		}
	}
	cout << memo[6][T] << endl;
}
