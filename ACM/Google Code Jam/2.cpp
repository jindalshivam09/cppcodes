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
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;
	int t;
	cin >> t;
	for(int test = 1 ; test <=t ; test ++) {
		double c,f,x;
		cin >> c >> f >> x ;
		double time = 0;
		double rate = 2.0 ;
		cout.setf(ios_base::fixed);
		cout.precision(7);
		while(1) {
			if ( ((x / (rate+f)) + (c / rate)) < (x / rate) ) {
				time += c/rate;
				rate += f;
			} 
			else {
				time += x/rate ;
				break;
			}
		}
		cout << "Case #" << test << ": " ;
		cout.setf(ios_base::fixed);
		cout.precision(7);
		cout << time << endl;
		
	}
}


