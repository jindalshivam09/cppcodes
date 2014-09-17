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

bool cmp (const pii &a, const pii &b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first ;
}

int main() {
	int t;
	cin >> t ;
	while(t--) {
		int n, m ;
		cin >> n >> m ;
		vi permute(n+1) ;
		repi(i,1,1+n)
			cin >> permute[i] ;
		vpii pairs(m) ;
		rep(i,m)
			cin >> pairs[i].first >> pairs[i].second ;
		sort(all(pairs),cmp) ;
		vpii merge, merge2 ;
		int a,b,c,d ;
		a = pairs[0].first , b = pairs[0].second ;
		merge2.pb(mp(a,b));
		repi(i,1,m) {
			c = pairs[i].first , d = pairs[i].second ;
			if( c <= b ) {
				merge2.pb(mp(a,max(b,d))) ;
				b = max(b,d) ;
			}
			else {
				merge2.pb(mp(c,d)) ;
				a = c, b = d ;
			}
		}
		
		for(int i=0;i<merge2.size();) {
			int a = merge2[i].first ;
			while( i < merge2.size() && a == merge2[i].first)
				i++ ;
			merge.pb(merge2[i-1]);
		}
		
		bool flag = false ;
		int j = 1 ;
		rep(i,merge.size()) {
			a = merge[i].first ,b = merge[i].second ;
	//		cout << j << " " << a << " " << b << endl;	
			while(j<a) {
				if(permute[j] != j) {
					flag = true ;
					break;
				}
				j ++ ;
			}
			while(j<=b) {
				if(permute[j] >= a && permute[j] <= b)
					j ++;
				else {
					flag = true ;
					break ;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			cout << "Impossible" << endl;
		else
			cout << "Possible" << endl;
	}
}


