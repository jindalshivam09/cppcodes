#include<iostream>
using namespace std;

#define E 0.000001

int main() {
	int t;
	cin >> t;
	while(t--) {
		int min , offers;
		float tt;
		cin >> tt >> min >> offers;
		float cost = tt*min;
//		cout << cost;
		int mon , plan;
		float rate;
		int adv = 0 ;
		float c;
		pair<float,int> pre;
		pre.first = cost;
		pre.second = 0;
		for(int i = 0 ; i < offers ; i ++) {
			cin >> mon >> rate >> plan;
			c = ((float)rate*min) + (float)plan/mon;
//			cout << rate*min << " " << (float)plan/mon << " " << c << endl;
			if (c < (float)cost + E && c < pre.first + E) {
				pre = make_pair(c,i+1);
			}
			
		}
		cout << pre.second << endl;
	}
	return 0;
}
