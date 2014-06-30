#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int dp[100222][333], a[100222], n;
int x, i, j, m, dist, all, ll, l[100222], sum;

void write(int n, int numb) {
	numb = l[n] - numb + 1;
	n = a[n];
	while (n) {
		numb--;
		if (numb==0) {
			printf("%d\n",n%10);
			return; 
		}
		n/=10;
	}
	printf("0\n");
	return;
}

int main(){
	//	freopen("input13.txt","r",stdin);
	//   freopen("output13.txt","w",stdout);
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		a[i] = x;
		while (x > 0) {
			l[i]++;
			x /= 10;
		}
		if (l[i] == 0) l[i] = 1;
	}
	for (int q = 1; q <= 300; ++q) {
		for (int i = 0; i < n; ++i) {
			dp[i][q] = l[i];
			if (i - q >= 0) dp[i][q] += dp[i - q][q];
		}
	}
	scanf("%d",&m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d",&ll, &dist, &sum);
		ll--;
		if (dist > 300) {
			bool printed = false;
			while (ll < n) {
				if (sum > l[ll]) sum -= l[ll];
				else {
					printed = true;
					write(ll,sum);
					break;
				}
				ll += dist;
			} 
			if (!printed) printf("So sad\n");		  
		}
		else {
			bool printed = false;
			int st = 0;
			if (ll >= dist) st = dp[ll - dist][dist];
			if (sum <= l[ll]) {
				write(ll, sum);
				continue;
			}
			for (int j = 18; j >= 0; --j) {
				if (ll + (1 << j) * dist >= n) continue;
				if (sum > dp[ll + (1 << j) * dist][dist]- st) ll += (1 << j) * dist;
			}
			ll += dist;
			if (ll < n) {
				printed = true;
				write(ll, sum - (dp[ll - dist][dist] - st));
			}
			if (!printed) printf("So sad\n");
		}
	}
	return 0;
}

