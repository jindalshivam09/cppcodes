#include<bits/stdc++.h>
using namespace std;

int n ;

int grundy(int a, int b) {
	if(a == b)	return 0 ;
	if( b%a == 0 )	return (b/a) - 1;
	int ans = b/a ;
	int g = grundy(b%a,a) ;
	if(g == 0)	return ans ;
	if(ans <= g)	return ans-1;
	return ans ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		cin >> n ;
		int a,b;
		int ans = 0 ;
		for(int i=0;i<n;i++) {
			cin >> a >> b ;
			ans ^= grundy(min(a,b),max(a,b)) ;
		}
		if(ans == 0)	cout << "NO\n";
		else		cout << "YES\n" ;
	}
}
