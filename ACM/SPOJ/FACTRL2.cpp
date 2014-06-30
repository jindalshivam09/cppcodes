#include <iostream>
using namespace std;    
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		unsigned long long ans = 1;
		for(int i=1;i<=n;i++)
			ans *= i;
	
		cout << ans << endl;
	}
}


