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
	int n,m,k;
	cin >> n >> m >> k ;
	vector<map<int,int> > adj(n+1) ;
	int a,b ;
	rep(i,k) {
		cin >> a >> b ;
		adj[a][b] ++ ;
	}
/*	repi(i,1,n+1) {
		cout << i << " -> " ;
		for(map<int,int>::iterator itr = adj[i].begin() ; itr != adj[i].end() ; itr ++) {
			cout << itr->first << " " << itr->second << ", ";
		}
		cout << endl;
	}
*/
	ll ans = 0 ;
	repi(i,1,n+1) {
		ans = 0 ;
		int last , last_val ;
		bool flag = false ;
		if ( adj[i].size() == 0 ) {
			cout << m-1 << endl;
			continue ;
		}
		map<int,int>::reverse_iterator itr = adj[i].rbegin() ;
		last = itr->first + itr->second , last_val = itr->first ;
		if( m == last_val + 1 ) {
			if ( m >= last )
				ans += m-last ;
			else
				flag = true ; 
			itr ++ ;
		}
		else if ( m > last_val ) {
			int temp = last_val + 1 ;
			ans += m-temp ;
			last = temp ;
			last_val = temp ;	
		}
		else if ( m == last_val ) {
			itr ++ ;
		} 
		if(flag == false) {		
			for( ; itr != adj[i].rend() ; itr ++) {
				int temp = itr->first + itr->second ;
				int temp_val = itr->first ;
//				cout << temp << " " << temp_val << " " << last << " " << last_val << endl;
				if ( last_val == temp_val + 1) {
					if ( last >= temp )
						ans += last-temp ;
					else {
						flag = true; 
						break ;
					}
					last = temp ;
					last_val = temp_val ;
				}
				else {
					int val = temp_val + 1 ;
					ans += last - val ;
					last = val ;
					last_val = temp_val ;
					if(val < temp) {
						flag = true  ;
						break ;
					}
				}
			}
			if(last_val > 1  ) {
				ans += last - 1 ;
			}
			if(flag == false)	
				cout << ans << endl;
			else
				cout << -1 << endl;
		}
		else 
			cout << -1 << endl;
	}
}
