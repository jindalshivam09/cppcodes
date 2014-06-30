#include<iostream>
#include<cmath>
#define INT_MAX 1000000000
using namespace std;

//---------------to calculate min diff------------------------------------------

int cal_min_diff(int *arr,int n,int x,int y) {
	int a,b;
	int min_diff = INT_MAX;
	bool flagx = false, flagy = false;
	for(int i=0;i<n;i++) {
		if(arr[i]==x && !flagx) {
			a = i;
			flagx = true;
		}
		if(arr[i] == y && !flagy) {
			b = i;
			flagy = true;
		}
		if(flagx && flagy) {
			if(min_diff > abs(a-b) )
			min_diff = abs(a-b);
		}
	}
	return min_diff;
}

main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i=0;i<n;i++)
		cin >> arr[i];
		int x,y;
		cin >> x >> y;
		cout << cal_min_diff(arr,n,x,y) << endl;
	}
}
