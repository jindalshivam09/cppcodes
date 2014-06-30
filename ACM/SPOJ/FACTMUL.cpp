#include <iostream> 
#include <list>
#include <vector>
#include <algorithm>
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
#define MOD 109546051211
ll mulmod(ll a,ll b) {
	ll x=0,y=a%MOD;
	while(b>0) { 
		if(b%2)
			x = (x+y)%MOD;
		y = (y*2)%MOD;
		b /= 2;
	}
//	cout << a << " " << x << " "  << endl;
	return x%MOD;
}
int main() {
	ll n;
	cin >> n;
	ll temp=1 , ans=1 ;
	for(ll i=1;i<=n;i++) {
		temp = mulmod(temp,i) ;
		ans = mulmod(ans,temp);
		if(!ans)
			break;
	} 	
	cout << ans << endl;
}


