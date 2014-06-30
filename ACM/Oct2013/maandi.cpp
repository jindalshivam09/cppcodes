#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int cal_overlucky(int n) {
	
	int count = 0;
	for(int i=1;i<=sqrt(n);i++) {
		
		if(!(n%i)) {
			
			int q = n/i;
			bool flag = false;
			while(q) {
				
				int r = q%10;
				if(r==4 || r==7) {
					
					flag = true;
					break;
				}
				q /= 10;
			}
			if(flag)
			count++;
			
			q = i;
			flag = false;
			while(q) {
				
				int r = q%10;
				if(r==4 || r==7) {
					
					flag = true;
					break;
				}
				q /= 10;
			}
			if(flag)
			count++;
		}
	}
	return count;
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		cout << cal_overlucky(n) << endl;
	}
}
