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

string str;
vector<string> query ;

ll output() {
	vll val(10), mul(10) ;
	rep(i,10)
		val[i] = i, mul[i] = 10 ;
	ll num, temp ;
	for(int i=query.size()-1;i>=0;i--) {
		num = query[i][0]-'0' ;
		ll v = 0, m = 1;
		repi(k,3,query[i].size()) {
			temp = query[i][k]-'0';
			v = ((v*mul[temp])%MOD + val[temp])%MOD ;
			m = (m*mul[temp])%MOD; 
		}
		val[num] = v, mul[num] = m;
	}
	ll ret = 0;
	rep(i,str.size()) {
		num = str[i]-'0';
		ret = ((ret*mul[num])%MOD + val[num])%MOD ;
	}
	return ret ;
}

int main() {
	cin >> str ;
	int n;
	cin >> n ;
	query.resize(n) ;
	rep(i,n) {
		cin >> query[i] ;
	}
	cout << output() ;
}


