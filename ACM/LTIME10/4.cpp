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
		int n,m;
		cin >> n >> m ;
		vll row(n+1) , col(m+1) ;
		map<ll,int> freqCol;
		ll count = 0 ;
		for(int i=0;i<n;i++)
			row[i] = i^(n-i-1) ;
		for(int i=0;i<m;i++)
			col[i] = i^(m-i-1) , freqCol[col[i]] ++;
		for(int i=0;i<n;i++) {
			int temp = row[i] ;
			count += m - freqCol[temp] ;
		}
		cout << count << endl;
	}
}


