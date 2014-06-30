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
	int t ;
	cin >> t ;
	for(int test=1 ; test<=t ; test ++) {
		int n,l ;
		cin >> n >> l ; 
		vector<string> flow(n) ;
		rep(i,n)
			cin >> flow[i] ;
		vi zero_flow(l) , one_flow(l) ;
		rep(i,l) {
			rep(j,n) {
				if(flow[j][i] == '0')
					zero_flow[i] ++ ;
				else
					one_flow[i] ++ ;
			}
		}
		vector<string> device(n) ;
		rep(i,n)
			cin >> device[i] ;
		vi zero_device(l) , one_device(l) ;
		rep(i,l) {
			rep(j,n) {
				if(device[j][i] == '0')
					zero_device[i] ++ ;
				else
					one_device[i] ++ ;
			}
		}
		int flips = 0 ;
		bool possible = true ;
		rep(i,l) {
			int one = one_flow[i] ;
			if(one == one_device[i]) ;
				// do nothing
			else if (one == zero_device[i])
				flips ++ ;
			else
				possible = false ;
		}
		cout << "Case #"<< test <<": " ;
		if(possible == false)
			cout << "NOT POSSIBLE" ;
		else
			cout << flips  ;
		cout << endl;
	}
}


