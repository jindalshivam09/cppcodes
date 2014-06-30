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

int n ;
vi A, B ;
int cal_steps(vi distinct) {
	int ret = 0, size = distinct.size();
	rep(i,size) {
		while(distinct[i]) {
			repi(j,i,size) {
				if(distinct[j])
					distinct[j] -- ;
				else
					break ;
			}
			ret ++ ;
		}
	}
	return ret ;

}
int brute(int i,vi &distinct) {
	if(i==distinct.size()) {
		int temp = cal_steps(distinct) ;
/*		if(temp == 10) {
			rep(i,distinct.size())
				cout << distinct[i] <<  " ";
			cout << endl;
		}
*/		return temp ;
	}
	distinct[i] += 4 ;
	int ans = brute(i+1,distinct) ;
	distinct[i] -= 4 ;
	ans = min( ans, brute(i+1,distinct)) ;
	return ans ;
}

int min_steps() {
	vi diff(n) ;
	rep(i,n) {
		int a = A[i] , b = B[i] ;
		if( b >= a )
			diff[i] = b - a ;
		else
			diff[i] = 4 + b - a ;
	}
	vi distinct ;
	for(int i=0;i<n;) {
		int temp = diff[i] ;
		while(temp == diff[i]) 
			i++ ;
		distinct.pb(temp) ;
	}
	int size = distinct.size() ;
	return brute(0,distinct) ;
}

int main() {
	ifstream cin("test_SEINC.txt") ;
	ofstream cout("SEINC_brute.txt") ;
	int t ;
	cin >> t ;
	while(t--) {
		cin >> n ;
		A.resize(n) ;
		B.resize(n) ;
		rep(i,n)
			cin >> A[i] ;
		rep(i,n)
			cin >> B[i] ;
		cout << min_steps() << endl;
	}
}


