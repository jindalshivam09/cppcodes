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
		vector<int> arr(n+1);
		for(int i=1;i<=n;i++)
			cin >> arr[i];
			
		int k;
		cin >> k;
		
		int temp = arr[k];
		
		sort(arr.begin(),arr.end());
		
		int pos = lower_bound(arr.begin(),arr.end(),temp) - arr.begin();
		
		cout << pos << endl;
	}
}
