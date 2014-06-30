#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		unsigned long long n;
		cin >> n;
//		cout << n << endl;
		if (n==1)		cout << 1 << endl;
		else if(n==2)	cout << 2 << endl;
		else {
			unsigned long long temp = 25LL + (4LL*(n-3LL)*2LL );
			unsigned long long ans = (unsigned long long)(-5LL + (long long)floor(sqrt(temp)))/2LL;
			cout << ans + 3LL << endl; 
		}
	}
}
