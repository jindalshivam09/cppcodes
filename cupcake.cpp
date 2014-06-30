#include<iostream>
#include<cmath>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		int q = sqrt(n);
		if (q*q == n)		cout << 0 << endl;
		else {
		
			while(q*(n/q) != n)			q--;
			cout << abs(q - n/q) << endl;
		}
	}
}
