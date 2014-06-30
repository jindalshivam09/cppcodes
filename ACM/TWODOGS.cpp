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
#define MAX 1000009
vi apples(MAX);
vector <pii> pos(MAX,mp(-1,-1)) ;
int main() {
	int n , k;
	cin >> n >> k;
	rep(i,n)
		cin >> apples[i];
	rep(i,n) {
		int temp = apples[i];
		if (pos[temp].first == -1)
			pos[temp].first = i;	
	}
	for(int i=n-1;i>=0;i--) {
		int temp = apples[i];
		if (pos[temp].second == -1)
			pos[temp].second = i;	
	}
	int ans = imax;
	bool flag = false;
	for(int i=1;i<=k;i++) {
		int val = i;
		int posl = pos[i].first ;
		int posr = pos[i].second ;
		int rem = k - val ;
		if (rem == val  )
			continue;
		if ( rem < 0 )
			break;
		if ( pos[val].first != -1 && pos[rem].first != -1  ) {
			int pos2l = pos[rem].first  ;
			int pos2r = pos[rem].second ;
			ans = min ( ans , max(posl+1 , pos2l+1 ));
			ans = min ( ans , max(n-posr , n-pos2r));
			ans = min ( ans , max(posl+1 , n-pos2r));
			ans = min ( ans , max(n-posr , pos2l+1));
			flag = true;
		}
	}
	if(flag)	cout << ans;
	else 		cout << -1;
}


