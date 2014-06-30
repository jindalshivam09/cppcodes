#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define EULER 0.5772156649
#define e 2.718281828459 

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		long long n;
		cin >> n;
		
		long long temp = n ;
		int i = 1;
		long long ans = 0;
		
		for (int i = 1 ; i <= floor(sqrt(n)); i ++) 
		ans +=   floor(n/i);
		
		ans *= 2 ;
		ans -=  pow(floor(sqrt(n)),2);

		long long fact = __gcd(ans,n*n);
		cout << ans/fact << "/" << (n*n)/fact << endl;
	}
}
