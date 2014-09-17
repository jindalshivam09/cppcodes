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
	cin >> t ;
	string str ;
	
	int a = 0 , b = 0 , count = 0;
	while (t--) {
		cin >> str ;
		stack<char> stk ;
		rep(i,str.size()) {
			if(stk.empty() == true) 
				stk.push(str[i]) ;
			else if ( stk.top() == str[i])
				stk.pop() ;
			else
				stk.push(str[i]) ;
 		}
	 	if(stk.empty()==true)
	 		count ++ ;
	}
	cout << count << endl;
}


