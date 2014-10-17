// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define IOS ios_base::sync_with_stdio(false)

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
#define MP make_pair
#define F first
#define S second

typedef vector<int> VI;
#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front


// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;
#endif

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define NMAX 105
#define MAX (2 * NMAX * 1005)

vector<int> S[NMAX];
vector<pair<int, int>> e[MAX];
int w[MAX];

int dis[MAX];
bool vis[MAX];

int spfa(int st, int ed)
{
    queue<int> q;

    for (int i = 0; i < MAX; ++i)
        dis[i] = INT_MAX, vis[i] = false;
    dis[st] = 0;
    q.push(st);
    vis[st] = true;

    while (not q.empty())
    {
        int a = q.front();
        q.pop();
        vis[a] = false;

        for (auto p : e[a])
        {
            int b = p.first;
            int c = p.second;

            if (dis[b] > dis[a] + c)
            {
                dis[b] = dis[a] + c;
                if (not vis[b])
                    q.push(b), vis[b] = true;
            }
        }
    }
    return dis[ed] == INT_MAX ? -1 : dis[ed];
}

int main()
{
//		ifstream cin("input.txt") ;
//	ofstream cout("output2.txt") ;

	freopen ("input.txt","r",stdin) ;
	freopen ("output2.txt","w",stdout) ;

    int z;
    scanf("%d", &z);
    for (int zi = 1; zi <= z; ++zi)
    {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < MAX; ++i)
            e[i].clear();

        int N = 0;
        for (int i = 0; i < n; ++i)
        {
            int m;
            scanf("%d %d", &m, &w[i]);

            for (int j = 0; j + 1 < m; ++j)
            {
                int t;
                scanf("%d", &t);

                e[N + j].PB(MP(N + j + 1, t));
                e[N + j + 1].PB(MP(N + j, t));
            }
            S[i].clear();
            for (int j = 0; j < m; ++j)
                S[i].PB(N + j);
            N += m;
        }
        for (int i = 0; i < n; ++i)
            for (int a : S[i])
            {
                e[a + N].PB(MP(a, w[i]));
                e[a].PB(MP(N + a, 0));
            }

        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            --x, --y;
            int a = S[x][y];
            scanf("%d %d", &x, &y);
            --x, --y;
            int b = S[x][y];

            int c;
            scanf("%d", &c);

            e[a].PB(MP(N + b, c));
            e[b].PB(MP(N + a, c));
            e[N + a].PB(MP(N + b, c));
            e[N + b].PB(MP(N + a, c));
        }
        int q;
        scanf("%d", &q);

        printf("Case #%d:\n", zi);
        while (q--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            --x, --y;
            int a = S[x][y];
            scanf("%d %d", &x, &y);
            --x, --y;
            int b = S[x][y];

            int ans = spfa(N + a, N + b);
            printf("%d\n", ans);
        }
    }
}

