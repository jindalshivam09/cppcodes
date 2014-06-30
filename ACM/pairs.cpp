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

	int n,k;
	cin >> n >> k;
	vector<long long> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];
		
	sort(all(arr));
	int count = 0;
	
	for(int i=0;i<n;i++) {
		
		int key = k+arr[i];
		arr[i] = -1;
		pair<vector<ll>::iterator,vector<ll>::iterator> itr = equal_range(all(arr),key);
		count += (itr.second - itr.first);
	}
	cout << count << endl;
}


