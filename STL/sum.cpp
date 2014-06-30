#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int n,k;
		cin >> n >> k;
		
		n = 2*n-1;
		int nth = n/k;
		cout << nth << endl;
		long long sum = ( nth * ( 2 * k + (nth-1) * k ) ) / 2;
		cout << sum << endl;
		sum /= 2;
		
		if(k%2)			cout << sum - nth/2;
		else			cout << sum - nth;
	}
}
