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
int ans ;

void dp (int i,int price,int quality) {
	if(quality < ans)
		return ;
	if (i > 6){
		ans = quality ;
		return ;
	}
	else if ( price > T )
		return ;
	for(int j=0;j<adj[i].size();j++) 
		dp(i+1,price+adj[i][j].first,min(quality,adj[i][j].second) )  ;
}

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
	dp(1,0,imax);
	cout << ans << endl;
}
