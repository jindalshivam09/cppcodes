	#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define F first
#define S second
#define MOD 1000000007
#define D double
#define LD long double

#define N 200

LL INF;

LL dp[N][N];

inline void solve(){
	int i, j, n;
	LL k;
	cin>>n>>k;
	memset(dp, 0, sizeof dp);
	for(i = n; i >= 0; i--){
		dp[n][i] = 1;
		cout << dp[n][i] << " " ;
	}
	cout << endl;
	for(i = n - 1; i >= 0; i--){
		for(j = i; j >= 0; j--){
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1] ;
			if(dp[i][j] >= INF) {
				dp[i][j] = INF;
			}
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	if(dp[0][0] < k){
		cout<<"Doesn't Exist!";
	}
	else{
		i = 0;
		j = 0;
		while(i != n || j != n){
			if(i < n){
				if(dp[i + 1][j] >= k){
					printf("(");
					i++;
				}
				else{
					k -= dp[i + 1][j];
					printf(")");
					j++;
				}
			}
			else{
				j++;
				printf(")");
			}
		}
	}
	printf("\n");
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t, i;
	sd(t);
	INF = 1000000000;
	INF *= INF;
	INF *= 2;
	for(i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		solve();
	}
    return 0;
}
