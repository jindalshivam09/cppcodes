#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n ;
	cin >> n ;
	int ans = 0;
	for(ll ht = 1 ; n-2*ht >= (3*ht*(ht-1))/2; ht ++)
		if( (n - 2*ht) % 3 == 0)
			ans ++;
	cout << ans ;
}
