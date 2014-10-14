#include<bits/stdc++.h>
using namespace std;

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		int n,m;
		cin >> n >> m ;
		vector<int> arr(n) ;
		for(int i=0;i<n;i++)	
			cin >> arr[i] ;
		sort(arr.begin(),arr.end()) ;
		int ans = 0 ;
		for(int i=0;i<n-1;i++) {
			ans += (arr[n-1]-arr[i]) ;
		}
		if(ans <= m) {
			ans = m-ans ;
			if(ans % n == 0 )
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}
}
