#include<bits/stdc++.h>
using namespace std;

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		int r,g,b,m ;
		cin >> r >> g >> b >> m ;
		int maxr = -1, maxg = -1, maxb = -1 ;
		int a ;
		for(int i=0;i<r;i++) {
			cin >> a ;
			maxr = max(maxr,a) ;
		}
		for(int i=0;i<g;i++) {
			cin >> a ;
 			maxg = max(maxg,a) ;
		}
		for(int i=0;i<b;i++) {
			cin >> a ;
			maxb = max(maxb,a) ;
		}
		vector<int> arr(3) ;
		arr[0] = maxr, arr[1] = maxg, arr[2] = maxb ;
		sort(arr.begin(),arr.end(),greater<int>()) ;
		int ans = arr[0] ;
		for(int i=0;i<m;i++) {
			arr[0] /= 2 ;
//			arr[1] ++ , arr[2] ++;
			sort(arr.begin(),arr.end(),greater<int>()) ;
			ans = min(ans,arr[0]) ;
		}
		cout << ans << endl;
	}
}
