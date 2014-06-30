#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int n,k;
	cin >> n >> k;
	
	if(k>n) {
		
		for(int i=0;i<n;i++) {
			
			for(int j=0;j<n;j++) {
				
				if(i==j)
					cout << k-n+1 << " ";
				else
					cout << 1 << " ";
			}
			cout << endl;
		}
	}
	else {
		
		for(int i=0;i<n;i++) {
			
			for(int j=0;j<n;j++) {
				
				if(i==j)
					cout << k << " ";
				else
					cout << 0 << " ";
			}
			cout << endl;
		}
	}
}
