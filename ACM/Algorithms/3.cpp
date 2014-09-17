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

int main() {
	int n ;
	cin >> n;
	vll arr(n)  ;
	rep(i,n)
		cin >> arr[i] ;
	if(n==1) {
		cout << arr[0] ;
		return 0;
	}
	if(n==2) {
		cout << (arr[0]+arr[1])*2 ;
		return 0;
	}
	sort(all(arr)) ;
	ll sum = 0 ;
	rep(i,n)
		sum += arr[i] ;
	ll ans = sum ;
	ll temp = 0;
	rep(i,n-2) {
		temp += arr[i];
//		cout << temp << " " << arr[i] << endl;
		ans += arr[i] + sum - temp;
	}
	ans += arr[n-2] + arr[n-1] ;
	cout << ans << endl;
}


