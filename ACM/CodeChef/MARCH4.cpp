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

ll prefix ( int n , int m, int k) {
	long double logn = m * log10l( n );
	logn -= (ll)logn ;
	long double ans = pow( 10, logn );
	ll pow10 = 1;
	for(int i=1;i<k;i++)
		pow10 *= 10 ;
	return ans*pow10 ; 
} 
ll calPow(ll n,ll m,ll MOD)
{
    if(m==0) return 1%MOD;
    
    ll x=calPow(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}
ll put_zero(ll a,ll k) {
	int digit_count=0;
	do
	{
		digit_count++;
		a /= 10;
	}while(a) ;

	if( digit_count < k ) {
		for(int i=digit_count;i<k;i++)
			cout << 0 ;		
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k;
		ll mod = 0;
		cin >> n >> k ;
		cout << prefix ( n , n , k ) << " ";
		ll pow10=1;
		for(int i=0;i<k;i++)
			pow10*=10;
		mod = calPow (n,n,pow10) ;
		put_zero (mod,k) ;
		cout << mod << endl;
	}
}


