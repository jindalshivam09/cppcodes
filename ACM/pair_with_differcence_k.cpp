#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

		int n,k;
		cin >> n >> k;
		vector<long long> arr(n);
		for(int i=0;i<n;i++)
		cin >> arr[i];
		
		sort(arr.begin() , arr.end());
		
		int count=0;
		for (int i=0;i<n;i++) {
			cout << arr[i] << " ";
			if (binary_search(arr.begin(),arr.end(),arr[i]+k))
			count++;
		}
		
		cout << count << endl;
}
