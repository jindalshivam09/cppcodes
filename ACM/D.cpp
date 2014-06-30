#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>

using namespace std;

typedef long long ll;

int n,k;
ll a[2222],dp[2222],ans;

bool ok(ll x)
{
	dp[1] = 0;
	if ( n == 1 ) return true;

	for ( int i = 2; i <= n; i++ ) {
		dp[i] = i - 1;
		for ( int j = 1; j < i; j++ ) {
			if ( abs(a[i] - a[j]) <= (i - j) * 1LL * x) 
				dp[i] = min(dp[i],dp[j] + i - j - 1);
		}
		if ( dp[i] + n - i <= k ) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&k);
	for ( int i = 1; i <= n; i++ )
		scanf("%I64d",&a[i]);

	ll l = -1,r = 2000 * 1000 * 1000;
	while( r - l > 1 ) {
		ll m = (long long)(l + r) / 2;
		if ( ok(m) ) {
			ans = m;
			r = m;
		}	
			else l = m;
	}
	printf("%I64d",r);
}
