#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int g[50][50], n, m;
bool used[50];

vector <int> cur;

vector <vector <int> > c[50];

void dfs(int v){
	used[v] = true;
	cur.pb(v);
	for (int i=1; i<=n; i++)
		if (g[v][i] && !used[i])
			dfs(i);
}

int main(){
#ifdef dudkamaster
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	memset(g, 0, sizeof(g));
	memset(used, 0, sizeof(used));
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	for (int i=1; i<=n; i++){
		if (!used[i]){
			cur.clear();
			dfs(i);
			c[sz(cur)].pb(cur);
		}
	}
	vector <vector <int> > out = c[3];
	for (int i=4; i<50; i++){
		if (sz(c[i])!=0){
			cout << -1;
			return 0;
		}
	}
	if (sz(c[2])>sz(c[1])){
		cout << -1;
		return 0;
	}
	if ((sz(c[1])-sz(c[2])) % 3 != 0){
		cout << -1;
		return 0;
	}
	forn(i,sz(c[2])){
		vector <int> tout;
		tout.pb(c[2][i][0]);
		tout.pb(c[2][i][1]);
		tout.pb(c[1][i][0]);
		out.pb(tout);
	}
	for (int i=sz(c[2]); i<sz(c[1]); i += 3){
		vector <int> tout;
		forn(j,3)
			tout.pb(c[1][i+j][0]);
		out.pb(tout);
	}
	forn(i,n/3){
		forn(j,3)
			cout << out[i][j] << ' ';
		cout << endl;
	}
			
	return 0;
}
