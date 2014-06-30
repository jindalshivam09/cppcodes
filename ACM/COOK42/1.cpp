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
	int t;
	cin >> t;
	while(t--) {
		int x1,x2,y1,y2,a1,a2,b1,b2;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> a1 >> b1 >> a2 >> b2;
		int ans = 0;
		ans = (x2-x1)*(y2-y1) + (a2-a1)*(b2-b1);
		int p = max(x1,a1) , q = min(x2,a2) , r = max(y1,b1) , s = min(y2,b2);
		if ((p==a1 && q == a2 && r == b1 && s == b2))
			ans =  (x2-x1)*(y2-y1);
		else if ( a1 >= x2 || b1 >= y2 || b2 <= y1 || a2 <= x1);
		else if (p==x1 && q ==x2 && r == y1 && s == x2 )
			ans = (a2-a1)*(b2-b1);
		else 
			ans -= abs((q-p)*(r-s));
		cout << ans << endl;
	}
}


