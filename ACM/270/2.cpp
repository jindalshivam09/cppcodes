#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,k ;
	cin >> n >> k;
	vector<int> arr(n) ;
	for(int i=0;i<n;i++)
		cin >> arr[i] ;
	sort(arr.begin(),arr.end(),greater<int>());
	
	long long ans = 0 ;
	for(int i=0;i<n;i+=k)
		ans += (2*(arr[i]-1)) ;
	cout << ans ;
}
