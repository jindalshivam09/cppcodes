#include<bits/stdc++.h>
using namespace std;

#define MAX 5003
typedef long long ll;
int n,m,k;
vector<ll> sum(MAX) ;
vector<vector<ll>  > memo(MAX,vector<ll>(MAX)) ;
ll dp(int n, int m, int k) {
	
	if(m*k > n || (k == 0)) {
		return memo[n][k] = 0;
	}
	
	if(memo[n][k] != -1)
		return memo[n][k] ;
	
	return memo[n][k] = max (dp(n-m,m,k-1)+sum[n]-sum[n-m],dp(n-1,m,k)) ;
}

int main() {
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			memo[i][j] = -1 ;
	cin >> n >> m >> k ;
	vector<ll> arr(n+1)  ;
	for(int i=1;i<=n;i++) {
		cin >> arr[i] ;
		sum[i] = sum[i-1] + arr[i]  ;
	}
	cout << dp(n,m,k) << endl;
		

}
