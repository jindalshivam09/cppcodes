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
	int n;
	cin >> n ;
	vi arr(n);
	rep(i,n) 
		cin >> arr[i];
	
	sort(all(arr));
	vi ans ;
	ans.pb(arr[0]);
	int last = arr[0];
	arr[0] = 0;
	for(int i=1;i<n;i++) {
		if(arr[i] != last) {
			last = arr[i];
			ans.pb(last);
			arr[i] = 0;
		}
	}
	
	for(int i=n-1;i>=0;i--) {
		if(arr[i] != last && arr[i]) {
			last = arr[i];
			ans.pb(last);
		}	
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
}


