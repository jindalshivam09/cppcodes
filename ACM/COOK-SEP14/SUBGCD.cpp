#include<bits/stdc++.h>
using namespace std ;

int main() {
	int t ;
	cin >> t;
	while(t--) {
		int n  ;
		cin >> n ;
		vector<int> arr(n) ;
		for(int i=0;i<n;i++)
			cin >> arr[i] ;
		
		int gcd = arr[0] ;
		for(int i=0;i<n;i++) 
			gcd = __gcd(gcd,arr[i]) ;
		
		if(gcd == 1)
			cout << n ;
		else
			cout << -1 ;
		cout << endl;
	}
}
