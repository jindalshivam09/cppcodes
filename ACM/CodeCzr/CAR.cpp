#include<iostream>
w#include<vector>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		string str;
		char ch;
		long long price , tax;
		
		long long ans = -1;
		string ans2;
		int ans3 = -1;
		
		for(int i=0;i<n;i++) {
			
			cin >> str >> ch >> price >> tax >> ch;
			
			if(ans < (price*100) + (price*tax)) {
				
				ans2 = str;
				ans3 = price;
				ans = (price*100) + (price*tax);
			}
			else if ( ans == (price*100) + (price*tax) && ans3 < price) {
				
				ans2 = str;
				ans3 = price;
			}
		}
		
		cout << ans2 << endl;
	}
}
