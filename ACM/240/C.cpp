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
	
	int n,k ;
	cin >> n >> k ;
	if( k < n/2 ) {
		cout << -1 ;
		return 0;
	}
	if ( n==1) {
		if(k)
			cout << -1 ;
		else
			cout << 1;
		return 0;
	}
	int gcd = k - n/2 + 1 ;
	if(gcd==0)
		gcd++ ;
	cout << gcd << " "  << 2*gcd << " " ;
	int temp = 2*gcd+1 ;
	for(int i=2;i<n-1;i+=2) {
		cout << temp << " " << temp+1 << " ";
		temp += 2;
	}
	if(n%2)
		cout << temp ;
}


