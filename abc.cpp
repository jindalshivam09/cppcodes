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
	ofstream cout("output.txt");
	ifstream cin("input.txt");
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n ;
		vi arr1(n) ,arr2(n);
		rep(i,n)	cin >> arr1[i] ;
		rep(i,n)	cin >> arr2[i] ;
		ll ans = 0;
		sort(all(arr1));
		sort(all(arr2),greater<int>());
		rep(i,n)
			ans += arr1[i]*arr2[i] ;
		cout << ans << endl;
	}
}


