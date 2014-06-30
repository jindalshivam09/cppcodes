#include<iostream>
using namespace std;


int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int arr[10];
		int min = 10;
		int index;
		for (int i=0 ; i<10 ; i++ ) {
			cin >> arr[i];
			if (min > arr[i]) {
				min = arr[i];
				index = i;
			}
		}
		
		if(index==0) {
			cout << 1;
		}		
		for (int i=0 ; i<=min ; i++)
			cout << index;
		
	}
}
