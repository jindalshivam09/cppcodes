#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
#define MAX 10000009
struct tmp {
	int a,b,c;
} node[MAX];
int n;
string brackets;

void segment ( int v , int l,int r) {
	if(l==r) {
		if(brackets[l]=='(')
			node[v].b = 1;
		else
			node[v].c = 1;
		return;
	}
	int m = (l+r)/2;
	segment(2*v,l,m);
	segment(2*v+1,m+1,r);
	int t = min(node[2*v].b , node[2*v+1].c);
	node[v].a = node[2*v].a + node[2*v+1].a + t;
	node[v].b = node[2*v].b + node[2*v+1].b - t;
	node[v].c = node[2*v].c + node[2*v+1].c - t; 
}
struct tmp ret;
struct tmp query(int v,int l,int r,int a,int b) {
	if(a<=l && b>=r)
		return node[v];
	if (l>b || r<a)
		return ret;
	int m = (l+r)/2;
	struct tmp t1 = query(2*v,l,m,a,b);
	struct tmp t2 = query(2*v+1,m+1,r,a,b);
	struct tmp t3;
	int t = min(t1.b , t2.c);
	t3.a = t1.a + t2.a + t;
	t3.b = t1.b + t2.b - t;
	t3.c = t1.c + t2.c - t; 
	return t3;
}

int main() {
	cin >> brackets;
	segment(1,0,brackets.size()-1);
	cin >> n;
	while(n--) {
		int l,r;
		cin >> l >> r;	
		l--;
		r--;		
		struct tmp ans = query(1,0,brackets.size()-1,l,r);
		cout << 2*ans.a << endl;
	}
}


