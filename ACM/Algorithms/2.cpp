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
	ll n, k;
	cin >> n >> k ;
	char a ;
	vector<ll> freq(26) ;
	rep(i,n) {
		cin >> a ;
		freq[a-'A'] ++ ;
	}
	sort(all(freq),greater<int>()) ;
	ll ans = 0;
	rep(i,26) {
//		cout << freq[i] << " ";
		if(freq[i] <= k) {
			k -= freq[i] ;
			ans += freq[i]*freq[i] ;
		}
		else {
			ans += k*k;
			k = 0;
			break;
		}
	}
	cout << ans << endl;

}


