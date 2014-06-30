#include <iostream>
#include <vector>
#include <cmath>
using namespace std;    
typedef long long ll;
int main() {
	ll n;
	cin >> n;
	while(n) {
		cout << (n*(n+1)*(2*n+1))/6 << endl;
		cin >> n;
	}
}


