#include<iostream>
using namespace std;

typedef long long ll;
int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n,k;
		cin >> n >> k;
		if(n==0)
		cout << 0 << " " << 0;
		else if(k==0)
		cout << 0 << " " << k;
		else cout << n/k << " " << n%k ;
		cout << endl;
	}
}
