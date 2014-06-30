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
		vector<char> input(26);
		string str ;
		cin >> str;
		int ch ;
		rep(i,str.size()) {
			ch = str[i]-'a';
			input[ch] ++;
		}
		int n;
		cin >> n ;
		int count = 0 ;
		while(n--) {
			cin >> str ;
			vector<char> temp(26);	
			rep(i,str.size()) {
				ch = str[i]-'a';
				temp[ch] ++;
			}
			bool flag = false;
			rep(i,26) {
				if ( temp[i] != input[i] ) {
					flag = true;
					break;
				}
			}
			if (!flag)
				count ++;
		}
		cout << count << endl;
	}
}


