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

string str1,str2 ;

void route(int i,int j,string ans) {
	if(i >= str1.size() || j >= str2.size()) {
		cout << ans << endl;
		return ;
	}
	if (str1[i] == str2[j]) {
		char a = str1[i] ;
		ans.pb(a);
	}
	route(i+1,j+1,ans) ;
	route(i+2,j+1,ans) ;
	route(i+1,j+2,ans) ;
}

int main() {
	int t;
	t=1;
//	cin >> t;
	while(t--) {
		string ans = "" ;
//		cin >> str1 >> str2 ;
		str1 = "abcabcaa" ;
		str2 = "acbabca" ;
		route(0,0,ans) ;
	}
}


