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

vi A(35) , B(35) , K(35);

ll recurse(int i, bool flaga,bool flagb) {
	if(i<0)
		return 1 ;
	ll ans = 0 ;
	if(flaga)
		A[i] = 1 ;
	if(flagb)
		B[i] = 1;
	if(K[i] == 1) {
		ll temp = (1<<(i))*(1<<(i)) ;
		if(A[i] == 0 && B[i] == 0) 
			ans +=  temp;
		else if(A[i] == 0 && B[i] == 1) 
			ans += 2*temp ;
		else if(A[i] == 1 && B[i] == 0)
			ans += 2*temp ;
		else if(A[i] == 1 && B[i] == 1) {
			ans += 3*temp ;
			ans += recurse(i-1,flaga,flagb) ;
		}
	}
	else {
		ll temp = recurse(i-1,flaga,flagb) ;
		if(A[i] == 0 && B[i] == 0)
			ans += 1*temp ;
		else if(A[i] == 0 && B[i] == 1) {
			ans += temp ;
			ans += recurse(i-1,flaga,true) ;
		}
		else if(A[i] == 1 && B[i] == 0) {
			ans += temp ;
			ans += recurse(i-1,true,flagb) ;
		}
		else if(A[i] == 1 && B[i] == 1)
			ans += recurse(i-1,true,flagb) + recurse(i-1,flaga,true) + recurse(i-1,flaga,flagb);
	}
	return ans ;
}

int main() {
	int t;
	cin >> t;
	rep(test,t) {
		cout << "Case #" << test+1 << ": "  ;
		int a,b,k ;
		cin >> a >> b >> k ;
		k -- ;
		a -- ;
		b -- ;
		rep(i,32) {
			K[i] = ((1<<i)&k) ? 1 : 0;
			A[i] = ((1<<i)&a) ? 1 : 0;
			B[i] = ((1<<i)&b) ? 1 : 0;
//			cout << (1<<i) << " "<<  K[i] << " " << B[i] << " " << A[i] << endl;
		}
		cout << recurse(31,false,false) << endl;
	}
}


