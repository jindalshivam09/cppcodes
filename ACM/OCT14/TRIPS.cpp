#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
inline long long read_int()
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

#define MAX 100009
int n,m ;
vector<vector<pair<int,int> > > adj(MAX) ;
vector<int> father(MAX), sz(MAX), level(MAX) ;
vector<vector<int> > parents;
vector<map<int,int> > values(MAX) ;
vector<bool> visited(MAX) ;

int dfs(int u, int parent) {	
	visited[u] = true ;
	father[u] = parent ;
	if(parent!=-1)
		level[u] = level[parent]+1;
	int ret = 0;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i].first ;
		if(parent != v && visited[v] == false) {
			ret += 1 + dfs(v,u) ;
		}
	}
	return sz[u] = ret;
}

void processLCA() {
	int logn = 0 ;
	for(int i=0;1<<i < n ; i ++)
		logn++ ;
	parents.resize(n,vector<int>(logn)) ;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<logn;j++)
			parents[i][j] = -1 ;
	
	for(int i=0;i<n;i++) 
		parents[i][0] = father[i] ;
	
	for(int j=1 ; 1<<j < n ; j++) {
		for(int i=0;i<n;i++)
			if(parents[i][j-1] != -1) 
				parents[i][j] = parents[parents[i][j-1]][j-1] ;
	}
}

int getLCA(int u, int v) {
	if(level[u] < level[v])
		swap(u,v) ;
	int logn = 0;
	for(;1<<logn <= level[u];logn++) ;
	logn -- ;
	for(int i=logn;i>=0;i--) {
		if(level[u]-(1<<i) >= level[v])
			u = parents[u][i] ;
	}
	if(u == v)
		return u ;
	for(int i=logn;i>=0;i--) {
		if(parents[u][i] != -1 && parents[u][i] != parents[v][i]) 
			u = parents[u][i], v = parents[v][i] ;
	}
	return father[u] ;
}


int chainNum ;
vector<int> chainPos(MAX), chainHead(MAX), chainIndex(MAX) ;
vector<vector<int> > chains(MAX) ;

void HLD(int u) {
	if(chains[chainNum].size() == 0) {
		chainHead[chainNum] = u ;
	}
	chains[chainNum].push_back(u) ;
	chainPos[u] = chainNum ;
	chainIndex[u] = chains[chainNum].size()-1 ;
//	cout << u << " " << chainIndex[u] << " " << chainPos[u] << endl;
	int pos, maxSize = -1 ;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i].first ;
		if(sz[v] > maxSize && father[v] == u) {
			maxSize = sz[v] ;
			pos = v ;
		}
	}
	
	if(maxSize != -1) {
		chainPos[pos] = chainNum ;
		HLD(pos) ;
	}
	
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i].first; 
		if( pos != v && sz[v] != -1 && father[v] == u) {
			chainNum ++ ;
			HLD(v) ;
		}
	}
}

class segmentTree {
	vector<int> arr;
	public :
		segmentTree() {};
		void init(const vector<int> &edges) {
			arr.resize( edges.size() -1 ) ;
			for(int i=0;i<edges.size()-1;i++) {
				int a = edges[i] , b = edges[i+1] ;
				int cost = values[a][b] ;
				arr[i] = cost ;
				if(i)
					arr[i] = arr[i] + arr[i-1] ;
			}
		}
		int retrieve(int l, int r) {
			if(l)
				return arr[r] - arr[l-1] ;
			return arr[r] ;
		}
};

vector<segmentTree> segTrees ;
void makeSegmentTrees() {
	segTrees.resize(chainNum+1) ;
	for(int i=0;i<=chainNum;i++) {
		segTrees[i].init(chains[i]) ;			
	}
}

int days(int l, int r, int pos, int cap, int &last) {
//	cout << "days\n" ;
	if(r<l)
		return 0;		
	int ret = 0 ;
	int val = last ;
	while(l <= r) {
//		cout << l << "," << r << endl;
		int a = l, b = r;
		bool flag = false ;
		while(a <= b) {
			int mid = (a+b)/2 ;
//			cout << "(" << a << "," << b << ")" << endl; 
			int ans = segTrees[pos].retrieve(a,mid) ;
//			cout << "jlk " << val << " " << ans << endl;
			if(ans > val)
				b = mid-1 ;
			else {
				val -= ans ;
				a = mid + 1;
				flag = true ;
			}
//			cin.get() ;
		}
		last = val;
		if(flag == false)
			val = cap, ret ++;
		l = a ;
	}	
	return ret ;
}

int hldFind(int u,int v,int cap,int &last) {
	int ans = 0 ;
//	cout << "hdlFind\n" ;
//	cout << u << " " << v << endl;
	while(true) {
		int pos1 = chainPos[u] , pos2 = chainPos[v] ;
//		cout << pos1 << " " << pos2 << " " << u << " " << v << endl;
		if(pos1 == pos2) {
			return ans + days(chainIndex[u],chainIndex[v]-1,pos1,cap,last) ;
		}
		ans += days(0,chainIndex[v]-1,pos2,cap,last) ;
		v = father[chainHead[pos2]] ;
		if(last >= values[v][chainHead[pos2]]) {
			last -= values[v][chainHead[pos2]] ;
		}
		else {
			ans ++ ;
			last = cap - values[v][chainHead[pos2]] ;
		}
	}
}

int retrieve(int l,int r, int cap) {
	int ancestor = getLCA(l,r) ;
//	cout << ancestor << endl;
	int last = cap ;
	return 1 + hldFind(ancestor,l,cap,last) + hldFind(ancestor,r,cap,last) ;
}

int main() {
//	n = read_int() ;
	cin >> n ;
	if(n == 1) {
		printf("0\n") ;
		return 0;
	}
	int a,b,d ;
	for(int i=0;i<n-1;i++) {
//		a = read_int() ;
//		b = read_int() ;
//		d = read_int() ;
		cin  >> a >> b >> d ;
		a--,b--;
		adj[a].push_back(make_pair(b,d)) ;
		adj[b].push_back(make_pair(a,d)) ;
		values[a][b] = d ;
		values[b][a] = d ;
	}

	dfs(0,-1) ;
	processLCA();
	HLD(0) ;
	makeSegmentTrees() ;

	int q ;
//	q = read_int() ;
	cin >> q ;
	while(q--) {
		int l,r,cap ;
//		l = read_int() ;
//		r = read_int() ;
//		cap = read_int() ;
		cin >> l >> r >> cap ;
		l--,r--;
/*		if(l==r) 
			printf("0\n") ;
		else
*/			printf("%d\n",retrieve(l,r,cap)) ;
	}
}
