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
		int n,m;
		cin >> n >> m ;
		int A = sqrt(n) , B =sqrt(m) ;
		int count = 0;
		map<pair<int,int>,int> pairs ;
		rep(i,A+1) {
			int b = n - i*i ;
			if ( b <= B && i+b*b == m ) {
				pairs[mp(i,b)] = 1;
				count ++;
			} 
		}
		rep(i,B+1) {
			int a = m - i*i ;
			if ( a <= A && a*a + i == n && pairs[mp(a,i)] == 0) {
				pairs[mp(a,i)] = 1 ;
				count ++ ;
			}
		}
		cout << count << endl;
	}
	

