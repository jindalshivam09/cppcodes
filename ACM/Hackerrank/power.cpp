#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;
typedef vector<pair<int, int> > vpii;
typedef vector<double> 	vd;
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

ull calPow(ull q,ull n)
{
	 ull ans;
	 if(n==1)	return q;
	 else{
		ans=calPow(q,n/2)%MOD;
 		ans*=ans;
		ans%=MOD;
		if(n%2)	{
				  ans*=q;
				  ans%=MOD;
		}
	}
	return ans;
}


int main() {

	int t;
	cin >> t;
	while(t--) {
		
		string a,b;
		cin >> a >> b;
		
		ull A=0,B=0;
		
		for(int i=0;i<a.size();i++) {
			
			A *= 10;
			A = A+a[i]-'0';	
			A %= MOD;	
		}
//			cout << A << endl;
		for(int i=0;i<b.size();i++) {
			
			B *= 10;
			B = B+b[i]-'0';		
			B %= MOD-1;	
		}
//		cout << B << endl;
		cout << calPow(A,B) << endl;
	}
}


