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
#define MAX 1000000000
int main() {
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		char op ;
		int num;
		string val;
		vi lesser , greater ;
		map <int,int> equal ;
		rep(i,k) {
			cin >> op >> num >> val ;
			if ( val[0] == 'Y') {
				if ( op == '<' && num > 1)
					 lesser.pb ( num - 1 );
				else if ( op == '>' && num < MAX )
					greater.pb ( num + 1 );
				else
					equal[num]++;
			}
			else {
				if ( op == '<'  )
					 greater.pb ( num );
				else if ( op == '>' )
					lesser.pb ( num  );
				else {
					if( num > 1 ) lesser.pb ( num - 1 ) ;
					if ( num < MAX ) greater.pb( num + 1 );
				}
			}
		}
		sort ( all( lesser ) );
		sort ( all( greater ) );
		int truth = 0;
		int count = 0;
		int less = lesser.size() , great = greater.size() ;
		for(int i=0;i<lesser.size();i++) {
			count = 0;
			int temp =  lesser[i];
			count  = upper_bound(all(greater),temp) - greater.begin() ;
			if ( greater.size() && greater[count] <= temp )
				count ++;
			less += count ;
		}
		for(int i=0;i<greater.size();i++) {
			count = 0;
			int temp =  greater[i];
			count  = upper_bound(all(lesser),temp) - lesser.begin() ;
			if ( lesser.size() && lesser[count] <= temp )
				count ++;
			great += count ;
		}	
		truth = max ( less , great) ;
		for ( map <int,int>::iterator itr = equal.begin() ; itr != equal.end() ; itr ++ ) {
			int temp = itr->first ;
			int count = 0;
			count  = upper_bound(all(greater),temp) - greater.begin() ;
			if ( greater.size() && greater[count] <= temp )
				count ++;
			cout << count << " ";
			count += upper_bound(all(lesser),temp) - lesser.begin() ;
			if ( lesser.size() && lesser[count] <= temp )
				count ++;
			cout << count << endl;
			truth = max (truth , count + itr->second) ;
		}
		cout << k - truth << endl;
	}
}
