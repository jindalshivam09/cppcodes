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

string str;
vi prefix ;

int prefix_func () {
	int len = str.size () ;
	int k = 0, l = 1 ;
	prefix[0] = 0 ;
	while ( l < len ) {
//		cout << k << " " << l << endl;
		if ( str[l] ==  str[k] ) 
			prefix[l++] = ++k ;
		else {
			if ( k )
				k = prefix[k-1] ;
			else
				prefix[l++] = 0 ;
		}
		if ( k == l/2 && l%2 == 0)
			k = 0 ;
	}
}

int main() {
	int t;
	cin >> t ;
	while(t--) {
		cin >> str ;
		prefix.resize(str.size());
		prefix_func();
		rep(i,str.size())
			cout << prefix[i] << " " ; 
		cout << endl;
	}
}


