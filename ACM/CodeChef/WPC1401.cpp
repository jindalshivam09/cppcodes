#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
int n, q ,cnt;
vector<vector<int> > adj ;
vector<int> position, sz, values;
vector<ll> BIT ;
vector<bool> visited ;


#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
inline ll read_int()
{
int flag=1;
long long n = 0;
char c;
int sign=1;
while (1)
{
c=GETCHAR();
if(c=='-')	sign=-1;
else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
 }
return sign*n;
}

int dfs(int u) {
	visited[u] = true ;
	position[u] = ++cnt ;
	int val = 0;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
		if(visited[v] == false) {
			val += 1 + dfs(v) ; 
		}
	}
	return sz[u] = val ;
}

void update(int idx,ll val) {
	while(idx <= n ) {
		BIT[idx] += val ;
		idx += (idx&-idx) ;
	}
}

ll retrieve(int idx) {
	ll ret = 0;
	while(idx>0) {
		ret += BIT[idx] ;
		idx -= (idx&-idx) ;
	}
	return ret ;
}

int main() {
//	cin >> n >> q ;
	n = read_int() ;
	q = read_int() ;
	
	adj.resize(n+1) ;
	position.resize(n+1) ;
	sz.resize(n+1) ;
	visited.resize(n+1) ;
	values.resize(n+1) ;
	BIT.resize(n+1) ;
	
	int a, b ;
	for(int i=0;i<n-1;i++) {
//		cin >> a >> b ;
		a = read_int() ;
		b = read_int() ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}
	
	dfs(1) ;

	for(int i=1;i<=n;i++) {
//		cin >> a ;
		a = read_int() ;
//		cout << position[i] << " " << sz[i] << endl;
		values[i] = a ;
		if(a == 0) {
			int idx = position[i] ;
			int len = sz[i];
			update(idx,1) ;
			update(idx+len+1,-1) ;
		}
	}	
	
	while(q--) {
		char type;
		int x;
		ll v;
//		cin >> type ;
		scanf("%c",&type) ;
		if(type == 'U') {
//			cin >> x >> v ;
			x = read_int() ;
			v = read_int() ;
			int idx = position[x] ;
			int len = sz[x] ;
			ll pre = values[x] ;
			if(pre == 0) {
				if(pre + v) {
					update(idx,-1) ;
					update(idx+len+1,1) ;
				}
			}
			else {
				if(pre+v == 0) {
					update(idx,1) ;
					update(idx+len+1,-1) ;
				}
			}
			values[x] = pre + v ;
		}
		else {
//			cin >> x ;
			x = read_int() ;
			int idx = position[x] ;
			int len = sz[x] ;
			printf("%lld\n",retrieve(idx+len) - retrieve(idx-1));
		}
	}
}
