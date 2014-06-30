#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

bool ok [128];
int a[128][128];

int main() {
//	freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int test, n, m;
    scanf ("%d", &test);
    while (test--)
    {
        scanf ("%d%d", &n, &m);
        int r = 0;
        REP (i, n)
        {
            REP (j, m)
            {
                scanf ("%d", &a[i][j]);
            }
            FORD (j, m-2, 0)
            {
                a[i][j]--;                
                if (a[i][j+1] <= a[i][j])
                    a[i][j]++;
            }
            r^=a[i][0];
        }    
        cout << (r ? "FIRST" : "SECOND") << endl;
    }
	return 0;
}

