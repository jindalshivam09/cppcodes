#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int n,k;
	cin >> n >> k;
	
	if(n==k)		cout << -1 << endl;
	else if ( n == k+1) {
		
		for(int i=0;i<n;i++)
		cout << i+1 << " ";
	}
	else {
		
		if( (n-k)%2 ) {
			
			int i=2;
			cout << 1 << " ";
			for(;i<=n-k;i+=2) {
				
				cout << i+1 << " " << i << " ";
			}
			for(;i<=n;i++)
				cout << i << " ";
		}
		else {
			
			int i=1;
			for(;i<=n-k;i+=2) {
				
				cout << i+1 << " " << i << " ";
			}
			for(;i<=n;i++)
				cout << i << " ";
		}
	}
}
