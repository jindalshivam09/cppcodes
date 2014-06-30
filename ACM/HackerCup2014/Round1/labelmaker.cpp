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
#define llmax  			numeric_limits<long long>::max()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

int main() {

	int t;
	cin >> t;
	while(t--) {
		
		string str;
		cin >> str;
		ll n;
		cin >> n;
		int len = str.size();
		
		vll powers(51) ,sum(51);
		powers[0] = 1;
		sum[1] = powers[1] = len;
		for(int i=2;i<51;i++) {
			powers[i] = len*powers[i-1];
			sum[i] = powers[i] + powers[i-1];
		}
		
		int strsize ;
		for(int i=1;i<51;i++) 
			if(powers[i] > n) {
				strsize = i-1;
				break;
			}
		cout << strsize << endl;
		cout << powers[strsize] << endl;
		vector<char> ans;
		ll rank = n - sum[strsize-1];
//		cout << rank << endl;
		for(int i=0;i<strsize-1;i++) {
			
			int pos = rank/powers[strsize-i-1];
//			cout << pos << " ";
			char a = str[pos];
			ans.push_back(a);
			rank -= (pos)*powers[strsize-i-1];
			cout << pos << " " << rank << " " << a << endl;
		}
		ans.pb(str[rank-1]);
		for(int i=0;i<ans.size();i++)
			cout << ans[i] ;
			cout << endl;
	}
}


