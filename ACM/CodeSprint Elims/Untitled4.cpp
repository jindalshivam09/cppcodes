#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 109
ll n,t;
ll llmax = numeric_limits<ll>::max();
vector<ll> wt(MAX) ,sum(MAX);
vector<vector<ll> > memo(MAX,vector<ll>(MAX)) ;

ll dp(int a, int b, ll c) {
	if(a == b) 
		return 0ll ;
	if(memo[a][b] != -1)
		return memo[a][b] ;
	ll ret = llmax;
	for(ll i=a;i<b;i++) {
		ret = min ( ret, max(0ll,dp(a,i,c) + dp(i+1,b,c) + (i-a+1)*(sum[i]-sum[a-1]) + (b-i)*(sum[b]-sum[i]) - c)) ;
	}
	return memo[a][b] = ret ;
}

bool possible(ll mid) {
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			memo[i][j] = -1;
	ll cost = dp(1,n,mid) ;
//	cout << mid << " " << cost << endl;
	return cost <= t ;
}

int main() {
	cin >> n >> t ;
	for(int i=1;i<=n;i++) {
		cin >> wt[i] ;
		sum[i] = sum[i-1] + wt[i] ; 
	}
	ll cost, a = 0, b = 10000000000 ;
	while(a<=b) {
		ll mid = (a+b)/2 ;
		if(possible(mid)) {
			cost = mid, b = mid-1;
		}
		else
			a = mid + 1;
	}
	cout << cost << endl;
}

