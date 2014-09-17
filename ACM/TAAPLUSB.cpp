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

vector<double> prob(MAX), ans(MAX) ;

void init () {
	prob[0] = 0.0 ;
	repi(i,1,MAX) {
		prob[i] = 0.45 + 0.1*prob[i-1] ;
	}
	ans[0] = 0.0 ;
	repi(i,1,MAX) {
		ans[i] = prob[i] + ans[i-1] ;
	}
}

int main() {
	init() ;
	int t ;
	cin >> t ;
	while(t--) {
		int n;
		cin >> n ;
		cout.precision(14) ;
		cout << ans[n] << endl;
	}
}


