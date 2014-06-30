#include<iostream>
#include<map>
#include<vector>
using namespace std;


map<long long,long long> memo;

long long cal_sum (vector<long long> &arr,int n,int i=0) {

	if(i==n-1)
	    return arr[i];
	else if(memo[arr[i]]) {

		return memo[arr[i]];
	}
	else {

		long long ans = (arr[i]^cal_sum(arr,n,i+1)) + arr[i] ;
		memo[arr[i]] = ans ;
		if(i)
		memo[arr[i]] += memo[arr[i+1]];
		cout << i << " "  << memo[arr[i]] << endl;
		return memo[arr[i]];
	}
}

int main() {

	int t;
	cin >> t;
	while(t--) {

		int n;
		cin >> n;
		vector<long long> arr(n);
		for(int i=0;i<n;i++)
		cin >> arr[i];
		
		long long sum = 0;
		cal_sum(arr,n);
		for(int i=0;i<n;i++)
		    sum += memo[arr[i]];
		    
		cout << sum << endl;
	}
}
