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

#define MOD 1000000007

string str ;

int main() {
	int t  ;
	cin >>  t ;
	while(t--) {
		cin >> str ;
		ll ans = 1 ; 
		rep(i,str.size()) {
			if(str[i] == 'l') {
				if(i%2==0)	ans = (ans*2)%MOD ;
				else 		ans = (ans*2-1+MOD)%MOD;
			}
			else {
				if(i%2==0)	ans = (ans*2+2)%MOD ;
				else		ans = (ans*2+1)%MOD;
			}
		}
		cout << ans << endl;
	}
}


