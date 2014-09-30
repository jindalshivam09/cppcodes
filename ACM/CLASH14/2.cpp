#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m,k;
	cin >> n >> m >> k ;
	int ans = 0;
	vector<int > arr(m) ;
	for(int i=0;i<m;i++) {
		cin >> arr[i] ;
	}
	int player ;
	cin >> player ;
	
	for(int i=0;i<m;i++) {
		int temp = (player ^ arr[i]) ;
		int cnt = 0;
		while(temp) {
			if(temp%2)
				cnt ++ ;
			temp /= 2 ;
		}
		if(cnt <= k)
			ans ++ ;
	}
	cout << ans << endl;
}
