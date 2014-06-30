#include<iostream>
#define MOD 99999999999
using namespace std;
long long power (long long base ,long long  exponent ) {
	long long  result = 1;
	while(exponent > 0) {
		if(exponent % 2 == 1) 
		result = (result * base)% MOD;
		exponent = exponent >> 1;
		base = (base * base) % MOD; ;
	}
	return result;
}
main() {
	int b,e;
	cin >> b >> e ;
	cout << power (b,e);
}
