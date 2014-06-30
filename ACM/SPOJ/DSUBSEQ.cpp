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
	int t;
	cin >> t;
	while(t--) {
		cin >> str ;
		vi comb(str.size()+1);
		vi char_pos(26) ;
		ll ans = 0 ;
		rep(i,str.size()) {
			int temp = str[i]-'A';
			if (char_pos[temp]==0) {
				comb[i+1] = 1 ;
				if(i)	comb[i+1] = (comb[i+1]+(2*comb[i])%MOD)%MOD;
			}
			else {
				int pos = char_pos[temp] ;
				int pre = (MOD + comb[i] - comb[pos-1])%MOD ;
				comb[i+1] = (2*pre)%MOD;
				comb[i+1] = (comb[i+1] + comb[pos-1])%MOD ;
			}		
			char_pos[temp] = i+1;
		}
		cout << (comb[str.size()]+1)%MOD << endl;
	}
}


