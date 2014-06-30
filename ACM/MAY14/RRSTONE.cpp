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
#define imin 			numeric_limits<ll>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {
	int n ;
	ll k;
	cin >> n >> k;
	vll arr(n) ;
	ll max1 = imin , max2 = imin ;
	rep(i,n) {
		cin >> arr[i] ;		
		max1 = max ( max1 , arr[i] ) ;
	}
	if(k==0) {
		rep(i,n)
			cout<< arr[i] << " ";
		cout << endl;
		return 0;
	}
//	cout << max1 << endl;
	vll ans1(n) , ans2(n) ;
	rep(i,n) {
		ans1[i] = max1 - arr[i] ;
//		cout << ans1[i] << " ";
		max2 = max ( max2 , ans1[i]) ;
 	}
 //	cout << max2 << endl;
 	rep(i,n) {
 		ans2[i] = max2 - ans1[i] ;
 	}
 	if( k % 2 == 0)
 		rep(i,n)
 			cout << ans2[i] << " ";
 	else
 		rep(i,n)
 			cout << ans1[i] << " ";
 	cout << endl;
}


