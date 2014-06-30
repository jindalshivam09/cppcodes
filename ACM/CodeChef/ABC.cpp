#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<ll,ll> 	pii;
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

string str ;

ll ABC () {
	ll ans = 0;
	ll n = str.size() , x , y , val;
	map <pii,ll> pos ;
	vll A(n),B(n),C(n) ;
	pos[mp(0,0)] = 1 ;
	if(str[0] == 'A')	A[0] = 1;
	if(str[0] == 'B')	B[0] = 1;
	if(str[0] == 'C')	C[0] = 1;
	x = A[0] - B[0] , y = A[0] - C[0] ;
	pos[ mp(x,y) ] = 1 ;
	repi(i,1,str.size()) {
		A[i] = A[i-1] , B[i] = B[i-1] , C[i] = C[i-1] ;
		if ( str[i] == 'A' ) 
			A[i] ++ ;
		if ( str[i] == 'B' ) 
			B[i] ++ ;
		if ( str[i] == 'C' ) 
			C[i] ++ ;
		x = A[i] - B[i] , y = A[i] - C[i] ;
//		cout << x << " " << y << endl;
		pos[mp(x,y)] ++;
	}
	ll k ;
	for(map<pii,ll>::iterator itr = pos.begin() ; itr != pos.end() ; itr ++) {
		k = itr->second ;
		k -- ;
//		cout << k <<  " " ;
		ans += (k*(k+1))/2 ;
	}
	return ans ;
}

int main() {
	cin >> str ;
	cout << ABC() << endl;
	
}


