#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		vector<int> arr(n);
		
		for(int i=0;i<n;i++)
			cin >> arr[i];
		
		int a;
//		cin >> a;
		int sum=0;
		bool flag = false;
		for(int i=0;i<n;i++) {
			
			cin >> a;
			arr[i] = a-arr[i];
			if(!(arr[i]%(n-2)))
				sum++;
			else flag = true;
		}
		
		
		if(flag)		cout << -1 << endl;
		else			cout << sum << endl;
	}
}
