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
#define MAX 109
#define MOD 100
int n;
vi arr(MAX) ;
int dp () { 
	vector<vi> mul(MAX,vi(MAX)) , mod(MAX,vi(MAX)) ;
	
	for ( int i = 0 ; i < n; i ++ ) {
		for ( int j = 0 ; j+i < n ; j ++ ) {
			mul[j][j+i] = imax ;
			if ( !i ) {
				mul[j][j] = 0 ;
				mod[j][j] = arr[j] ;
			}
			else {			
				for ( int k=j ; k<j+i ; k ++) {
					if ( mul[j][j+i] > mul[j][k]+mul[k+1][j+i] + (mod[j][k]*mod[k+1][j+i]) ) {
						mul[j][j+i] = mul[j][k]+mul[k+1][j+i] + (mod[j][k]*mod[k+1][j+i]) ;
						mod[j][j+i] = (mod[j][k] + mod[k+1][j+i])%MOD ; 
					}
				}
			}
//			cout << j << " " << j+i <<  " " ;
//			cout << mul[j][j+1] << " " << mod[j][j+i] << endl;
		}
	}
	return mul[0][n-1] ;
}
int main() {
	while( cin >> n ) {
		rep(i,n) 
			cin >> arr[i];
		cout << dp() << endl;
	}
}

 
