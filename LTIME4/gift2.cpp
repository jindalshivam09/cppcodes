#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

long long cal_min(const vector<int> &arr,int n) {
	
	long long min_value=arr[0] , max_value =arr[0];
	
	for(int i=1;i<n;i++) {
		
		long long mint = min_value,maxt = max_value;
		if(arr[i] >= 0) {
			
			min_value = min(mint+arr[i],min(mint-arr[i],mint*arr[i]));
			max_value = max(maxt+arr[i],max(maxt-arr[i],maxt*arr[i]));
		}
		else {
			
			min_value = min(mint+arr[i],min(mint-arr[i],maxt*arr[i]));
			max_value = max(maxt+arr[i],max(maxt-arr[i],mint*arr[i]));		
		}
//		cout << min_value << " " << max_value << endl;
	}
	
	return min_value;
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		vector<int> arr(n);
		
		for(int i=0;i<n;i++)
			cin >> arr[i];
			
		cout << cal_min(arr,n) << endl;
	}
}
