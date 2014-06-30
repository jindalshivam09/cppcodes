#include<iostream>
#include<vector>
#include<algorithm>
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
			
		int count=1;
		
		sort(arr.begin(),arr.end());
		
		for(int i=1;i<n;i++) {
		
			if(arr[i]==arr[i-1])
			count++;
			else 
			count =1;
		}
		
		if(count==n)
			cout << 0 << endl;
		else if(count==2 ) {
			
			cout << arr[n-1] << endl;
		}
		else {
	
			int ans = 0;
			for(int i=0;i<n;i++) {
				
				for(int j=i+1;j<n;j++) {
					
					for(int k=j+1;k<n;k++) {
						
						ans = max (ans , ((arr[i]^arr[j])^arr[k]));
					}
				}
 			}
			 cout << ans << endl;		
		}
	}
}
