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
struct item {
	int val;
	vi arr ;
} ;
bool cmp (const struct item &a,const struct item &b) {
	return a.val < b.val;
}
int main() {
	int n,m;
	cin >> n >> m ;
	vi freq(n+1);
	struct item offer[m];
	vb added(n+1);
	int k,a;
	rep(i,m) {
		cin >> k ;
		offer[i].val = 0;
		rep (j,k) {
			cin >> a ;
			offer[i].arr.pb(a);
			freq[a] ++ ;
		}
	}
	int temp ,cnt;
	rep(i,m) {
		cnt = 0;
		rep(j,offer[i].arr.size()) {
			temp = offer[i].arr[j];
			if (freq[temp]>1)
				cnt += freq[temp];
		}
		offer[i].val = cnt ;
	}
	sort(offer,offer+m,cmp);
	int ans = 0 ;
	bool flag ;
	rep(i,m) {
		flag = false;
		rep(j,offer[i].arr.size()) {
			temp = offer[i].arr[j];
			if (added[temp] == true) {
				flag = true;
				break;
			}
		}
		if(flag == false) {
			rep(j,offer[i].arr.size())  {
				temp = offer[i].arr[j];
				added[temp] = true ;
			}
			ans ++ ;
		}
	}
	cout << ans << endl;
}
