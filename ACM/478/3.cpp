#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
int main() {
	vector<ll> arr(3) ;
	for(int i=0;i<3;i++)
		cin >> arr[i] ;
	ll ans = 0 ;
	
	while(1) {
		sort(arr.begin(),arr.end(),greater<int>()) ;
		if(arr[2] == 0 && arr[1] == 0)
			break;
		if(arr[2] == 0 && (arr[1] == arr[0] && arr[1] == 1))
			break;
		if(arr[0]==arr[1] && arr[1] == arr[2]) {
			ans += arr[0] ;
			break;
		}
//		cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
		int a = arr[0] , b = arr[1] ;
		arr[0] -= 2*min(a/2,b) ;
		arr[1] -= min(a/2,b) ;
		ans += min(a/2,b) ;
	}
	cout << ans << endl;
}
