#include<bits/stdc++.h>
using namespace std;

class Apothecary {
	public:
		vector<int> balance (int wt ) {
			vector<long long> power3;
			long long temp = 1;
			while(temp<1000000000) {
				power3.push_back(temp);
				temp *= 3;
			}
			temp = 0;
			vector<int> ans ;
			int key = lower_bound(power3.begin(),power3.end(),abs(temp-wt)) - power3.begin();
			temp += power3[key];
			ans.push_back(power3[key]);
			while(temp!=wt) {			
				key = lower_bound(power3.begin(),power3.end(),abs(temp-wt)) - power3.begin();
				if(key)
					key--;
				cout << power3[key] << " ";
				if(temp<wt) {
					temp += power3[key];
					ans.push_back(power3[key]);
				}
				else {
					wt += power3[key];
					ans.push_back(-1*power3[key]);
				}
			}
			sort(ans.begin(),ans.end());
			return ans;
		} 
} ob;
int main() {
	ob.balance(17);
}
