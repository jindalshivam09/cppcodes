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
#define MAX 100009
struct edge {
	int a,b,c ;
} edges[MAX];

bool cmp (const struct edge &p,const struct edge &q) {
	return p.a == q.a ? p.b < q.b : p.a < q.a ;
}
int n ;
int func () {
	vi white(MAX) , black(MAX) ;
	int index = 0 ;
	
	int i = 0 ;
	int c = edges[i].c ;
/*	while(c == edges[i].c) {
		if (c==1)		white[index] ++ ;
		else			black[index] ++ ;
		i ++ ;
	}
	index ++ ;
*/	for(;i<n;) {
		int a = edges[i].a ;
		while (a==edges[i].a) {
			c = edges[i].c ;
			if (c==1)		white[index] ++ ;
			else			black[index] ++ ;
			i ++ ;
		}
		index ++ ;		
	}
	rep(i,n) {
		cout << white[i] << " ";
	}
	cout << endl;
	rep(i,n) {
		cout << black[i] << " ";
	}
	cout << endl;
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n ;
		rep(i,n) {
			cin >> edges[i].a >> edges[i].b >> edges[i].c ;
		}
		sort(edges,edges+n,cmp) ;
		int res = func() ;
	}
}


