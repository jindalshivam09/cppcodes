#include<iostream>
#include<vector>
using namespace std;

vector<vector<bool> > bit(109,vector<bool>(10));
vector<long long> integer(109);

int digits[10]={1,2,4,8,16,32,64,128,256,512};

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		bit.resize(10);
		integer.resize(109);
		
		int n;
		
		cin >> n;
		vector<int> arr(n);
		
		int a;
		for(int i=0;i<n;i++) {
			
			cin >> a;
			arr[i] = a;
			
			while(a%10) {
				
				bit[i][a%10] = 1;
				cout << a << " ";
				a /= 10;
			}
			cout << endl;
			
			for(int j=0;j<10;j++) {
				
				integer[i] += digits[j] * bit[i][j];
			}
			cout << integer[i] << endl;
			
			
		}
	}
}
