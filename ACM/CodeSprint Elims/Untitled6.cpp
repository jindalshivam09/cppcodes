#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
 
#define LL long long int
#define ULL unsigned LL
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define MOD 1000000007
 
LL n, t;
LL dp[103][103];
LL c;
LL a[103];
LL p[103];
LL getans(int st, int en) {
    if (st == en)
        return 0;
    LL &ret = dp[st][en];
    if (ret == -1) {
        ret = 100000000000000LL;
        for (int i = st; i < en; i++) {
            ret = min(ret, max(0LL, getans(st, i) + getans(i + 1, en) + (i - st + 1) * (p[i] - p[st - 1]) + (en - i) * (p[en] - p[i]) - c));
        }
    }
    return ret;
}
int main() {
    int i;
    cin >> n >> t;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    LL lb = 0, ub = 10000000000LL, mid, ans = -1;
    while (lb <= ub) {
        mid = (lb + ub) / 2;
        c = mid;
        memset(dp, -1, sizeof(dp));
   		LL temp = getans(1, n) ;
   		cout << temp << " " << mid << endl;
        if ( temp <= t) {
            ub = c - 1;
            ans = mid;
        } else {
            lb = c + 1;
        }
    }
    cout << ans << endl;

    return 0;
}


