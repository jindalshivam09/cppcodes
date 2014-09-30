#include<bits/stdc++.h>
using namespace std;

int main() {
	int n ;
	cin >> n ;
	vector<bool> arr(n) ;
	
	int p ;
	cin >> p ;
	int a ;
	for(int i=0;i<p;i++) {
		cin  >> a ;
		arr[a-1] = true ;
	}
	cin >> p ;
	for(int i=0;i<p;i++) {
		cin  >> a ;
		arr[a-1] = true ;
	}
	int cnt = 0;
	for(int i=0;i<n;i++)
		if(arr[i])
			cnt++;
			
	if(cnt == n) 	cout << "I become the guy." ;
	else			cout << "Oh, my keyboard!" ;
}
