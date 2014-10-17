#include<bits/stdc++.h>
using namespace std ;

#define MAX 200009
#define HT 1009
#define MOD 1000000007
vector<vector<int> > memo(HT,vector<int>(MAX,-1)) ;
int ht,R,G ;
typedef long long ll ;

int calHt(int r, int g) {
	int ret = 1 ;
	for(;1;ret++) {
		if(ret*(ret+1)/2 > (r+g))
			break ;
	}
	return ret-1 ;
}

int dp(int r, int g,int h) {
	if(h == ht)
		return 1 ;
	if(r<h && g<h)
		return 0 ;
	if(memo[h][r] != -1)
		return memo[h][r] ;
	ll ans = dp(r-h,g,h+1) ;
	ans = (ans + dp(r,g-h,h+1)) % MOD;
	return memo[h][r] = ans ;
}

int main() {
	int r, g ;
	cin >> r >> g ;
	R = r, G = g ;
	ht = calHt(r,g) ;
	cout << dp(r,g,1) << endl;
}
