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
#define all(a) 	a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {
	ll n,a,b;
	cin >> n >> a >> b ;
	vll arr(n) ;
	rep(i,n)
		cin >> arr[i] ;
	rep(i,n) {
		ll temp = (a*arr[i])/b ;
//		cout << temp << endl ;
		ll temp2 = ceil((1.00*temp*b)/a) ;
//		cout << temp2 << endl;
		if (temp2 < arr[i])
			cout << -temp2+arr[i] << " ";
		else
			cout << 0 << " ";
	}
}


