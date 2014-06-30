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
	int t;
	cin >> t;
	while(t--) {
		int n ;
		cin >> n ;
		ll ans = 0 , mul , mul2 , temp;
		for (int i=1;i<=n-i;i++) {
			mul = i*(n-i) ;
			for (int j=1;j<=sqrt(mul);j++) {
				mul2 = j*(mul/j) ;
				temp = mul/j ;
				if (mul2 == mul)
					temp -- ;
				int cnt = 0;
				if ( temp >= j ) {
					cnt = 2*(temp-j);
					cnt ++ ;
				}
				if ( i != n-i ) 
					ans += 2*cnt ;
				else 
					ans += cnt ;
			}
		}
		cout << ans << endl;
	}
}


