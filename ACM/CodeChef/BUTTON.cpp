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
vector<vi> initial(MAX,vi(MAX)) , final(MAX,vi(MAX));
int n;
bool check ( const vi &row, const vi &col) {
	rep(i,n) {
		rep(j,n) {
			if ( final[i][j] == initial[i][j] && (row[i]+col[j])%2)
				return false ;
			else if ( final[i][j] != initial[i][j] && (row[i]+col[j])%2==0 )
				return false; 
		}
	}
	return true;
}
pii dp () {
	vi row1(n) , col1(n) ,row2(n) , col2(n);
	int r1=0 , c1=0 , r2=0 , c2=0 ;
	for(int j=0;j<n;j++) {
		if ( initial[0][j] == 0 ) 	continue ;
		else 						col1[j] = 1 , c1 ++ ;
	}
	for(int i=1;i<n;i++) {
		if ( initial[i][0] == 0) {	
			if ( col1[0] )
				row1[i] = 1 ,r1 ++ ;
		}
		else {
			if ( col1[0] )
				continue;
			else
				row1[i] = 1 ,r1 ++;
		}
	}
	bool first = check(row1,col1) ;
	if(r1+c1>=n && first ) {
		r1 = n - r1;
		c1 = n - c1;
		rep(i,n)
			row1[i] ^= 1 , col1[i] ^= 1 ;
	}
	if(r1+c1 == 0)
		cout << 0 << endl;
	else if(first)  {
		cout << r1 << endl;
		rep(i,n)
			if (row1[i])	cout << i << endl;
		cout << c1 << endl;
		rep(i,n)
			if( col1[i])		cout << i << endl;
	}
	else
		cout << -1 << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int a;
		cin  >> n ;
		rep(i,n)	rep(j,n)	cin >> initial[i][j];
		rep(i,n)	rep(j,n)	{	cin >> a ; initial[i][j] ^= a ; }
		dp() ;
	}
}
