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

map<string,int> mapped ;
vector<string> ans ;

int main() {
	int n ;
	cin >> n ;
	string str ;
	int level = 1;
	int temp ;
	while(n--) {
		cin >> str ;
		temp = mapped[str] ;
		if(temp+1 == level ) {
			mapped[str] = temp + 1 ;
			level ++;
			ans.pb(str) ;
//			cout << str << endl;
		}
		else {
			mapped[str] = temp + 1 ;
		}
	}
	rep(i,ans.size()) {
		cout << i+1 << " " << ans[i] << endl;
	}
}


