#include<bits/stdc++.h>
using namespace std;
int n, m ;
#define MOD 1000000007
typedef long long ll;
map<pair<int,int>,ll> memo ;

int dp(int i,int j,int cnt = 1) {
//	cout << i << " " << j << endl;
	if(i<cnt && j<cnt) {
//		cout << cnt-1 << endl ;
		return 0;
	}
	if(i<cnt || j<cnt) 
		return 0;
	if(memo.count(make_pair(i,j)))
		return memo[make_pair(i,j)] ;	
	ll ans = 0 ;
	if(i==j) {
		return 0;
	}
	else {
		if(i >= cnt)
			ans += dp(i-cnt,j,cnt+1) , ans %= MOD;
		if(j >= cnt)
			ans += dp(i,j-cnt,cnt+1) , ans %= MOD ;
	}
	return memo[make_pair(i,j)] = ans ;
}

int main() {
	cin >> n >> m ;
	cout << dp(n,m) << endl;
}
