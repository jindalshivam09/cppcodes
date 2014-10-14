/*
	Name: HLD 
	Copyright: no rights 
	Author: jindalshivam09
	Date: 30/09/14 22:57
	Description: implementing HLD with segment tree and finding gcd between two nodes in a tree (codechef problem: DGCD)
*/

#include<bits/stdc++.h>
using namespace std ;

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

int n, lvl ;
vector<vector<int> > adj ;
vector<int> values, father, sz, level;
vector<vector<int> > parents;

int dfs(int u, int parent) {	
	father[u] = parent ;
	if(parent!=-1)
		level[u] = level[parent]+1;
	int ret = 0;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
		if(parent != v) {
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
vector<int> chainPos, chainHead, chainIndex ;
vector<vector<int> > chains ;

void HLD(int u) {
	if(chains[chainNum].size() == 0) {
		chainHead[chainNum] = u ;
	}
	chains[chainNum].push_back(u) ;
	chainPos[u] = chainNum ;
	chainIndex[u] = chains[chainNum].size()-1 ;
	cout << u << " " << chainIndex[u] << " " << chainPos[u] << endl;
	int pos, maxSize = -1 ;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i] ;
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
		int v = adj[u][i]; 
		if( pos != v && sz[v] != -1 && father[v] == u) {
			chainNum ++ ;
			HLD(v) ;
		}
	}
}

typedef struct node {
	int gcd, d, a ;
	bool lazy ;
} node ;

class segmentTree {
	vector<int> arr ;
	vector<node> segment ;
	public :
		segmentTree() {}
		segmentTree(const vector<int> &positions ) {
			arr.resize(positions.size()) ;
			for(int i=0;i<arr.size();i++) {
				arr[i] = values[positions[i]] ;
			}
			segment.resize(4*arr.size()) ;
			initSegmentTree(1,0,arr.size()-1) ;
		}
		void init(const vector<int> &positions ) {
			arr.resize(positions.size()) ;
			for(int i=0;i<arr.size();i++) {
				arr[i] = values[positions[i]] ;
			}
			segment.resize(4*arr.size()) ;
			initSegmentTree(1,0,arr.size()-1) ;
		}
		void initSegmentTree(int num, int a, int b) {
			if(a == b) {
				segment[num].lazy = false ;
				segment[num].a = arr[a] ;
				segment[num].gcd = 0 ;
				segment[num].d = 0 ;
				return ;
			}
			int mid = (a+b)/2 ;
			initSegmentTree(2*num,a,mid) ;
			initSegmentTree(2*num+1,mid+1,b) ;
			
			int val1 = segment[2*num+1].gcd ? segment[2*num+1].gcd : segment[2*num].a ;
			int val2 = segment[2*num].gcd ? segment[2*num].gcd : val1 ;
			segment[num].gcd = __gcd( segment[2*num+1].a, __gcd( val1, val2 ) ) ;
			segment[num].lazy = false;
			segment[num].d = 0 ;
			segment[num].a = segment[2*num].a ;
		}
		void pushlazy(int num, int i, int j) {
			if(segment[num].lazy == true) {
				segment[num].a += segment[num].d ;
				if(i != j) {
					segment[2*num].lazy = segment[2*num+1].lazy = true ;
					segment[2*num].d += segment[num].d ;
					segment[2*num+1].d += segment[num].d ;
				}
				segment[num].d = 0 ;
			}
		}
		void update(int num,int i, int j, int a, int b,int d) {
			pushlazy(num,i,j) ;
			if(i>b || j<a)
				return ;
			if(i>=a && j<=b) {
				segment[num].lazy = true ;
				segment[num].d += d ;
				pushlazy(num,i,j);
				return ;
			}
			int mid = (i+j)/2 ;
			update(2*num,i,mid,a,b,d) ;
			update(2*num+1,mid+1,j,a,b,d) ;
			
			segment[num].a = segment[2*num].a ;
			int num1 = segment[2*num+1].gcd ? segment[2*num+1].gcd : segment[2*num+1].a ;
			int num2 = segment[2*num].gcd ? segment[2*num].gcd : num1 ;
			segment[num].gcd = __gcd( segment[2*num+1].a, __gcd(num1, num2) ) ;
		}
		int retrieve(int num, int i, int j, int a, int b) {
			pushlazy(num,i,j) ;
			if(i>b || j<a) 
				return 0 ;
			if(i==j) {
				return segment[num].a ;
			}
			if(i>=a && j<=b) {
				int ret = __gcd(segment[num].a, segment[num].gcd) ;
				return ret ;
			}
			int mid = (i+j)/2 ;
			int ret1 = retrieve(2*num,i,mid,a,b) ;
			int ret2 = retrieve(2*num+1,mid+1,j,a,b) ;
			if(ret1 == 0)
				return ret2 ;
			else if(ret2 == 0)
				return ret1 ;
			return __gcd(ret1,ret2) ;
		}
		int retrieve(int l, int r) {
			return retrieve(1,0,arr.size()-1,l,r) ;
		}
		void update(int l, int r, int d) {
			update(1,0,arr.size()-1,l,r,d) ;
		}
} ;

vector<segmentTree> segTrees ;
void makeSegmentTrees() {
	segTrees.resize(chainNum+1) ;
	for(int i=0;i<=chainNum;i++) {
		segTrees[i].init(chains[i]) ;			
	}
}

int calGCD(int u, int v) {
	int ans = 0 ;
	cout << "gcd\n" ;
	cout << u << " " << v << endl;
	while(1) {
		int pos1 = chainPos[u], pos2 = chainPos[v] ;
		cout << pos1 << " " << pos2 << " " << endl;
		if(pos1 == pos2) {
			return ans ? __gcd(segTrees[pos1].retrieve(chainIndex[u],chainIndex[v]),ans) : segTrees[pos1].retrieve(chainIndex[u],chainIndex[v]) ; 
		}
		int head = chainHead[pos2] ;
		ans = ans ? __gcd(segTrees[pos2].retrieve(0,chainIndex[v]),ans) : segTrees[pos2].retrieve(0,chainIndex[v]) ; 
		v	 = father[head] ;
		cout << ans << endl;
	}
}

void updateValues(int u, int v, int d) {
	while(1) {
		int pos1 = chainPos[u], pos2 = chainPos[v] ;
		if(pos1 == pos2) {
			segTrees[pos1].update(chainIndex[u],chainIndex[v],d) ; 
			return ;
		}
		int head = chainHead[pos2] ;
		segTrees[pos2].update(0,chainIndex[v],d) ; 
		v = father[head] ;
	}
}

int retrieve(int u, int v) {
	int ancestor = getLCA(u,v) ;
	cout << "ret\n" ;
	cout << ancestor << endl;
	cout << calGCD(ancestor,u) << " " << calGCD(ancestor,v) << endl;;
	return __gcd(calGCD(ancestor,u), calGCD(ancestor,v)) ;
}

void update(int u, int v, int d) {
	int ancestor =getLCA(u,v) ;
	updateValues(ancestor,u,d) ;
	updateValues(ancestor,v,d) ;	
	updateValues(ancestor,ancestor,-d) ;
}

int main() {
	
	ofstream out("input_HLD.txt");
	
	n = read_int() ;
	out << n << endl;
	
	values.resize(n) ;
	adj.resize(n) ;
	father.resize(n) ;
	sz.resize(n) ;
	chainHead.resize(n) ;
	chainPos.resize(n) ;
	chains.resize(n) ;
	level.resize(n) ;
	chainIndex.resize(n) ;
	
	int a, b ;
	for(int i=0;i<n-1;i++) {
		a = read_int() ;
		b = read_int() ;
		out << a << " " << b << endl;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}
	for(int i=0;i<n;i++) {
		a = read_int() ;
		out << a << " " ;
		values[i] = a ;
	}
	out << endl;
	dfs(0,-1) ;
	processLCA() ;
	HLD(0) ;
	makeSegmentTrees() ;
	
	int q ;
	q = read_int() ;
	out << q << endl;
	while(q--) {
		char type ;
		int l, r, d ;
		scanf("%c",&type) ;
		l = read_int() ;
		r = read_int() ;
		out << type << " " << l << " " << r ;
		if(type == 'F') {
			printf("%d\n",retrieve(l,r)) ;
		}
		else {
			d = read_int() ;
			out << " " << d ;
			update(l,r,d) ;
		}
		out << endl;
	}
}
