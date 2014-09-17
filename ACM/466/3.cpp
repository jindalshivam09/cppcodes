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
	int n ;
	cin >> n ;
	vi arr(n) ;
	rep(i,n)
		cin >> arr[i] ;
	vll sum(n) ;
	sum[0] = arr[0] ;
	map<int,vi> indexes;
	map<int,int> freq;
	freq[sum[0]]++;
	indexes[sum[0]].pb(0) ;
	repi(i,1,n)  {
		sum[i] = arr[i] + sum[i-1] ;
		indexes[sum[i]].pb(i) ;
		freq[sum[i]] ++ ;
	}
	ll ways = 0 ;
	bool zero = false;
	rep(i,n-2) {
		ll sz = 0;
		ll temp = sum[i] ;
		if(temp*3 == sum[n-1] ) {
			sz = indexes[2*temp].size() - (lower_bound(all(indexes[2*temp]),i) - indexes[2*temp].begin());
			ways += sz ;
		}
		if(temp == 0 && sum[n-1] == 0 && sz >= 2)
			ways -= 2 ;
		
//		cout << ways << endl;
	}	
	cout << ways << endl;
}


