#include<iostream>
using namespace std;

#define star *
#define point .

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int l,c;
		cin >> l >> c;
		
		for(int i=0;i<l;i++) {
		
			for(int j=0;j<c;j++) {
			
				if(!(i%2)) {
				
					if(!(j%2))		cout << "*";
					else			cout << ".";
				}
				else {
				
					if(!(j%2))			cout << ".";
					else			cout << "*";
				}
			}
			cout << endl;
		}
	}
}
