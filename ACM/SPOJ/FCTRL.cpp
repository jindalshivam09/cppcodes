#include <iostream>
using namespace std;    
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll two = 0 , five = 0;
		ll count = 0;
		for(int i=2;i<=n;i*=2)
			two += n/i;
		count = 0;
		for(int i=5;i<=n;i*=5)
			five += n/i;
		cout << min(two,five) << endl;
	}
}


