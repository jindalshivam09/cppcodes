#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

typedef vector<int> 	vi;

#define all(a) 			a.begin(),a.end()

int main() {

	int n,k;
	cin >> n >> k;
	
	vi stairs;
	
	int j=0;
	for(int i=0;i<k;i++) {
		
		cin >> j;	
		stairs.push_back(j);
	}
	if(!k) {
		
		cout << "YES" << endl;
		return 0;
	}	
	sort(all(stairs));
	
//	for(int i=0;i<k;i++)
//		cout << stairs[i] << endl;
	if(stairs[0] == 1 || (k && stairs[k-1] == n))
		cout << "NO" << endl;
	else {
		
		int temp = stairs[0];
		int count = 0;
		for(int i=1;i<k;i++) {
			
//			cout << stairs[i];
			if (temp + 1 == stairs[i]) {
				
				count++;
				if(count >= 2) {
					
					cout << "NO" << endl;
					return 0;
				}
//				temp = stairs[i];
			}
			else
				count  = 0;
			temp = stairs[i];	
		}
		cout << "YES" << endl;
	}
}


