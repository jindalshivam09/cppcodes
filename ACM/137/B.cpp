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
#define MAX 1009
vector<vi> arr(MAX,vi(MAX));
int main() {
	int n,m,k;		scanf("%d%d%d",&n,&m,&k);

	rep(i,n)
		rep(j,m)
		scanf("%d",&arr[i][j]);
		
	vi row(n) , col(m) ;
	rep(i,n)
		row[i] = i;
	rep(i,m)
		col[i] = i ;
	char ch;
	int a,b;
	int u,v;
	while(k--) {
//		cin >> ch >> a >> b ;
		cin >> ch;
		scanf("%d%d",&a,&b);
		a-- ;
		b--;
//		cout << a << " " << b << endl;
		if (ch == 'g') {
			u = row[a];
			v = col[b] ;
			printf("%d\n",arr[u][v]) ;
		}
		else if (ch =='r') {
			u = row[a];
			v = row[b] ;
			row[a] = v ;
			row[b] = u ;
		}
		else {
			u = col[a];
			v = col[b] ;
			col[a] = v ;
			col[b] = u ;
		}
	}
}
