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
		string str ;
		cin >> str ;
		int length = 0 , ans = 0;
		stack<char> stk;
		rep(i,str.size()) {
			char a = str[i] ;
			if(a == '<')
				stk.push(a) ;
			else {
				if(stk.empty() == false && stk.top() == '<') {
					stk.pop() ;
					length += 2 ;
				} 
				else
					stk.push(a) ;
				if(stk.empty())
					ans += length , length = 0 ;
			}
		}
		cout << ans << endl;
	}
}


