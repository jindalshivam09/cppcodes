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
	cin >> n;
	vi arr(5);
	int a;
	rep(i,n) {
		cin >> a;
		arr[a]++;
	}
	int ans = 0;
	ans += arr[4];
	ans += arr[3];
	arr[1] -= arr[3];
	ans += arr[2]/2;
	arr[2] %= 2;
	if(arr[1]>0) {
		if(arr[2]) {
			ans += 1;
			arr[1] -= 2;
		}
		if(arr[1]>0) {
			ans += arr[1]/4;
			if(arr[1]%4)
				ans ++;
		}
		
	}
	else
		ans += arr[2];
	cout << ans;
}


