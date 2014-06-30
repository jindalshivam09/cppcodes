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

vi arr;
int n ;
int LIS () {
	map<int,int> length ;
	int count = 0;
	for ( int i = 0 ; i < n ; i ++ ) {
		int val = arr[i] ;
		map<int,int>::iterator itr = length.lower_bound(val);
		if ( itr == length.end() ) {
			length[val] = ++count ;
		}
		else {
			int len = itr->second;
			length.erase(itr);
			length[val] = len ;
		}
	}
	return count ;
}
bool cmp (const pii &a,const pii &b) {
	return a.first==b.first ? a.second > b.second : a.first < b.first ;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n ;
		vpii books(n);
		rep(i,n) {
			cin >> books[i].first >> books[i].second ;
		}
		sort(all(books),cmp);
		int a,b;
		arr.resize(n);
		for(int i=n-1;i>=0;i--)
			arr[n-1-i] = books[i].second ;
		cout << LIS() << endl;		
	}
}


