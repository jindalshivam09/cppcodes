#include<iostream>
#include<cmath>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		long long n;
		cin >> n;
		
		if (!(n&(n-1)))		cout << 2*n;
		else if ((n%2))	cout << 2;
		else {
			 for (long long i=2;i<=n; i *= 2) {
				
				long long temp = (n-i)/(2*i) + 1;
			 	if (n == i+(temp-1)*2*i){
			 		
			 		cout << 2*i;
			 		break;
			 	}
			 }
		} 
		cout << endl;
	}
}
