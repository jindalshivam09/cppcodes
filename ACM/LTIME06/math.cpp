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
		
		double a,p,q;
		cin >> a >> p >> q;
		int D ;
		cin >> D ;
//		cout.precision(D);
//		cout.setf(ios::fixed);
		long double temp1 = 1, temp2 = 1;
		long double A = 0 , B = 0;
	
	
		A = a/(1-a);
		B = A/(1-a);
		
		
		cout.precision(D);
		cout.setf(ios::fixed);

		cout << A*p + B*q << endl;
	}

}


