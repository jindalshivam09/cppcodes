#include<iostream>
using namespace std;

long long dearrangement(int n) {

	long long ans ,temp=1;
	if (n%2)	temp = -1;
	ans = temp;
	
	while(n) {
	
		temp = -1*temp*n;
//		cout << temp << " ";
		ans += temp;
		n--;
//		cout << ans << " ";
	}
	return ans;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int n;
		cin >> n;
		cout << dearrangement(n) << endl;
	}
}
