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
typedef vector<pair<ll,ll> > vpll;
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
	ll n,u,q;
	cin >> n >> u >> q;
	vpll updates(u);
	ll a,b;
	rep(i,u) {
		cin >> a >> b;
		updates[i] = mp(a,b);
	}
//	sort(all(updates));
	ll ans = 0;
	ll mod = 10000 , first , terms;
	rep(i,q) {
		ans = 0;
		cin >> a >> b;
		rep(j,u) {
			if(updates[j].second >= a && b >= updates[j].first) {
				if(updates[j].first >= a) {
					first = 1;
					terms = min(b,updates[j].second) - updates[j].first + 1;
				}
				else {
					first = a-updates[j].first + 1;
					terms = min(b,updates[j].second) - a + 1;
				}
				if(terms%2==0)
					ans += ( (terms/2)%mod*(2*first + terms - 1)%mod ) %mod;
				else
					ans += ((terms%mod)*((first)%mod+((terms-1)/2)%mod))%mod;
				ans %= mod;
			}
		}
		cout << ans << endl;
	}
}


