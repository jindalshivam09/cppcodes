#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int n,m;
		cin >> n >> m;
		
		if (n==1)		cout << m << endl;
		else if(m==1)	cout << n << endl;
		else if(n==m) 	cout << n << endl;
		else			cout << __gcd(n-1,m-1) + 1 << endl;
	}
}
