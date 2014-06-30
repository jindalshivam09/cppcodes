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

bool cmp (const pii &a,const pii &b) {
	
	return a.second > b.second;
}

int main() {

	int n,m;
	cin >> n >> m;
	
	vpii coupons(m);
	
	int a,b;
	rep(i,m) {
		
		cin >> a >> b;
		coupons[i] = mp(a,b);
	}
	
	sort(all(coupons),cmp);
	long  long ans = 0, temp = 0;;
	for(int i=0;i<m;i++) {
		
		ans += coupons[i].second;
		temp += coupons[i].first;
	}
	
	if(temp % 2) {
		
		long long q=0;
		for(int i=n-1;i>=0;i--) {
			
			if(coupons[i].first % 2) {
				
				q += coupons[i].first;
				break;
			}
		}
		cout << ans - q << endl;
	}
	else
		cout << ans << endl;
}


