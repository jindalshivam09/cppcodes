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
#include "BigIntegerLibrary.h"
    
    BigInteger a = 65536;

using namespace std;

typedef long long 		ll;
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

int main() {


	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		long long ans = 5*n*n + 4;
		long long ans2 = 5*n*n-4;
		
		long long temp = sqrt(ans);
		long long temp2 = sqrt(ans2);
		if(temp * temp == ans || temp2*temp2 == ans2)
			cout << "YES" << endl;
			
		else cout << "NO" << endl;
		
	}
}


