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

ll smaller (ll a ) {
	if(a == 1)
		return -1 ;
	vi bits(32) ;
	ll i = 0 ;
	while(a) {
		bits[i++] = a%2 ;
		a /= 2 ;
	}
	i = 1;
	while( i < 32 &&  bits[i++] == 0) ;
	bits[i-1] = 0;
	if(i-2>=0)
	bits[i-2] = 1 ;
	ll num = 0 ;
	for(ll j=31;j>=0;j--) {
		num = num*2 + bits[j] ;
	}
	return num ;
}

ll larger ( ll a ) {
	if ( a == 1 << 32)
		return -1 ;
	vi bits(32) ;
	ll i = 0 ;
	while(a) {
		bits[i++] = a%2 ;
		a /= 2 ;
	}
	i = 0;
	while( i < 32 &&  bits[i++] == 0) ;
	bits[i-1] = 0 ;
	while( i < 32 && bits[i++] == 1) ;
	if(i==32)
		return -1;
	bits[i-1] = 1 ;	
	ll num = 0 ;
	for(ll j=31;j>=0;j--){
		num = num*2 + bits[j] ;
	}
	return num ;
}
int main() {
	int t ;
	cin >> t ;
	int cnt = 0 ;
	ll stardom = 0 ;
	ll a,srk,sk ;
	while(t--) {
		cin >> a ;
		srk = smaller(a) ;
		sk = larger(a) ;
		cout << srk << " " << sk << endl;
		if(srk < a && a < sk) {
			if ( a*a == srk*sk)
				cnt ++ ;			
		} 
		stardom += (sk-srk) ; 
	}
	printf("%0.6f %0.6f", ((double)cnt) / t , (double)stardom / t) ;
}


