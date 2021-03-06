#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int l,r,x,y,q,d,yk1,yk2,i,j,n,m,ox[333333],a[333333],oy[333333];
int sq[33];
int rev(long long x, int d) {
	x = (x * 10 + d) % MOD;
	return x;
}
int main(){  
	scanf("%d",&q);
	for (i = 1; i <= 9; ++i) {
		sq[i] = i * i;
		if (i * i <= q) {
			++yk1;
			ox[yk1] = i;
			oy[yk1] = i * i;
		} 
	}
	while (yk1 > yk2) {
		if (yk1 >= 300000) break;
		++yk2;
		x = ox[yk2];
		y = oy[yk2];
		for (i = 0; i <= 9; ++i) {
			if (y + sq[i] <= q) {
				++yk1;
				ox[yk1] = rev(x, i);
				oy[yk1] = y + sq[i];
			}
			else break;   
		}
	}
	scanf("%d",&n);
	for (i = 1; i <= n; ++i) {
		scanf("%d", &x);
		a[i] = ox[x];
		a[i] = a[i - 1] + a[i];
		a[i] %= MOD;
	}
	scanf("%d",&m);
	for (i = 1; i <= m; ++i) {
		scanf("%d %d",&l,&r);
		d = a[r] - a[l-1];
		d = (d + MOD) % MOD;
		printf("%d\n", d);
	}

	return 0;
}  

