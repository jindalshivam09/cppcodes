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
	int t; 
	cin >> t ;
	while(t--) {
		int n ;
		cin >> n ;
		vector<int> arr(n) ;
		rep(i,n)
			cin >> arr[i] ;
		sort(all(arr)) ;
		int q ;
		cin >> q ;
		while(q--) {
			int key ;
			cin >> key ;
			int pos1 = lower_bound(all(arr),key) - arr.begin();
			int pos2 = upper_bound(all(arr),key) - arr.begin();
			cout << pos1 << " "<< pos2 << endl;
			int lesser = pos1;
			int same = pos2-pos1;
			int greater = n - lesser - same ;
			cout << lesser << " " << same << " " << greater << endl;
		}
	}
}


