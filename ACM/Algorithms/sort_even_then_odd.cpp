#include<bits/stdc++.h>
using namespace std;

bool cmp ( const int &a, const int &b) {
	if(a%2 == 0) {
		if(b%2)
			return true;
		return false ;
	}
	else {
		if(b%2)
			return false ;
		return true ;
	}
}

int main() {
	int n ;
	cin >> n ;
	vector<int> arr(n) ;
	for(int i=0;i<n;i++)
		cin >> arr[i] ;
	stable_sort(arr.begin(),arr.end(),cmp) ;
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
}
