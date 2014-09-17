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

vector<vi> matrix ,xored;
int n,m;	

void init () {
	rep(i,m) {
		xored[i][0] = matrix[i][0];
		repi(j,1,n) {
			xored[i][j] = matrix[i][j] ^ xored[i][j-1] ;
//			cout << xored[i][j] << " " ;
		} 
//		cout << endl;
	}
}

void update(int x,int y) {
	xored[x][0] = matrix[x][0] ;
	repi(i,1,n) {
		xored[x][i] = matrix[x][i]^xored[x][i-1] ;
//		cout << xored[x][i] << " ";
	}	
}

int query (int a,int b, int c,int d) {
	int ans = 0;
	if(b==0) {
		repi(i,a,c+1) {
			ans = ans ^ xored[i][d] ;
		}
		return ans ;
	}
	repi(i,a,c+1) {
		ans = ans ^ xored[i][b-1] ^ xored[i][d] ;
	}
	return ans ;
}

int main() {
	int t  ;
	cin >> t ;
	while(t--) {	
		cin >> m >> n ;
		matrix.resize(m+10,vi(n+10)) ;mu
		xored.resize(m+10,vi(n+10)) ;
		rep(i,m)
			rep(j,n)
				cin >> matrix[i][j];
		init() ;
		int q,type,x1,x2,y1,y2,k; 
		cin >> q ;
		while(q--) {
			cin >> type ;
			if(type == 0) {
				cin >> x1 >>y1 >> x2 >> y2 ;
				cout << query(x1,y1,x2,y2) << endl;
			}
			else {
				cin >> x1 >> x2 >> k ;
				matrix[x1][x2] = k ;
				update(x1,x2) ;
			}
		}
	}
}


