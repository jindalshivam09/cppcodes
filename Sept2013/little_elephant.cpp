#include<iostream>
#include<vector>
using namespace std;

#define MAX 50

struct n {
	
	double prob;
	int a , b;
}ticket[MAX];

double cal_prob (int n ,vector<bool> present , int i , int q) {
	
	present[q] = true;
//	cout << present[1] << " " << present[2] << endl;
	if (i == n)			return 1;
	else {
	
		double ans = 0;
		if (!present[ticket[i].a])	{
			
//			cout << ticket[i].a <<  " " << i << endl;
//			present[ticket[i].a] = true;
			ans += (ticket[i].prob * cal_prob (n,present,i+1,ticket[i].a));
//			present[ticket[i].a] = false;
		}
		if (!present[ticket[i].b])	{
			
//			cout << ticket[i].a << " " << i << endl;
//			present[ticket[i].b] = true;
			ans += ((1-ticket[i].prob) * cal_prob (n,present,i+1,ticket[i].b));
//			present[ticket[i].b] = false;
		}
//		cout << ans;
		return ans;
	}
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n ;
		
		for (int i = 0 ; i < n ; i ++) {
		
			cin >> ticket[i].prob >> ticket[i].a >> ticket[i].b;
			ticket[i].prob /= 100;
		}
		
		if (n > 16)
			cout << 0 << endl;
		else {
		
			vector<bool> present(20);
			cout << cal_prob(n,present,0,0) << endl;
		}
	}
}
