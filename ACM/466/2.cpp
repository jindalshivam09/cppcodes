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
	ll n,a,b;
	cin >> n >> a >> b ;
	ll val = (6LL*n) ;
	ll A,B, AREA=imax;
	bool flag = false ;
	if(a>b) {
		swap(a,b) ;
		flag = true ;
	}
	cout << val << endl;
	if(a*b >= 6*n) {
		cout << a*b << endl;
		cout << a << " " << b<< endl;
		return 0;
	}
	
	for(int i=a;i*i<=val;i++) {
	}
	cout << AREA << endl;
	if(flag == true)
		swap(A,B);
	cout << A << " " << B << endl;
}


