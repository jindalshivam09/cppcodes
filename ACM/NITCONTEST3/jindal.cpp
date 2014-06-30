#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
#define MAX 1000007
vector<long long> ans(MAX) ;

void init () {
	
	ans[0] = ans[1] = ans[2] = 1 ;
	ans[3] = 2 ;
	for(int i=4;i<MAX;i++) {
		ans[i] = ( ans[i-1] + ans[i-3] + ans[i-4] ) % MOD ;
	}

}

int main() {
	init() ;
	int t;
	cin >> t;
	while(t--) {
		int n; 
		cin >> n ;
		cout << ans[n] << endl;
	}
}
