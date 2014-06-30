#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cal_min_cost(vector<int> &arr,int n) {
	
	bool flag = true;
	int count = 0;
	for(int k=0;k<10000;k++){
		
		sort(arr.begin(),arr.end());
		flag = true;
		
		for(int i=0;i<n;i++) {
			
			if(arr[i]) {
				
				flag = false;
				break;
			}
		}
		
		if(flag)		
			return count;
			
		arr[0]++;
		for(int i=1;i<n;i++) 
			arr[i]--;
			
		count++;
		
		bool flag1 =false;
		
		for(int i=0;i<n;i++)	{
			
//			cout << arr[i] << " ";
			if(arr[i] != arr[0])  {
				
				flag1 = true;
				break;
			}
		}	
		
		if(!flag1 && arr[0] < 0)			
			return -1;
			
	}
	
	return -1;
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		
		vector<int> arr(n);
		
		for(int i=0;i<n;i++) {
			
			cin >> arr[i];
		}
		
		int a;
		for(int i=0;i<n;i++) {
			
			cin >> a;
			arr[i] = a - arr[i];
		}
		if(n==1) {
			
			if(arr[0]<0)	cout << abs(arr[0]) << endl;
			else 			cout << -1 << endl;
		}
		else 				cout << cal_min_cost(arr,n) << endl;
	}
}
