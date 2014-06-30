#include<iostream>
using namespace std;


int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		cout.precision(15);
		cout << (double)(17*n*n)/6 << endl;
	}
}
