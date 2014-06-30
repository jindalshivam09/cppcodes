#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
	
		int n,k;
		cin >> n >> k;
		
		vector<int> arr(n);
		vector<int> freq(12);
		
		for(int i=0;i<n;i++) {
			
			cin >> arr[i];
			freq[arr[i]%(k+1)]++;
		}
		
		int count = 0;
		for(int i=0;i<k+1;i++) {
			
			if(freq[i])
				count ++;
		}
		
		if(count == 1) 	cout << "YES" << endl;
		
		else if(count == 2) {
			
			for(int i=0;i<k+1;i++) {
				
				if(freq[i] == 1 || freq[i] == n-1) {
	
					cout << "YES" << endl;
					break;
				}
				else if (freq[i]) {
					
					cout << "NO" << endl;
					break;
				}
			}	
		}
		
		else			cout << "NO" << endl;
	}
}
