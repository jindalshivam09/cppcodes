#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int n;
	while(cin >> n) {
		
		vector<int> arr(n),bits(n);
		for(int i=0;i<n;i++)
			cin >> arr[i];
			
		vector<long long> digit(n,0);
			
		for(int i=0;i<n;i++) {
			
			int c = 0;
			int temp = arr[i];
			while(temp) {
				
				int a = temp%10;
				digit[i] += (1<<a);
				temp /= 10;
				c++;
			}
			bits[i] = c;
			
//			cout << digit[i] << endl;
		}
		
		long long bitset;
		vector<long long> sum(1029,0);
		vector<int> cardinality(1029,0);
		
		for(int i=0;i<n;i++) {
			
			bitset = digit[i];
			if(!sum[bitset]) {
				
				sum[bitset] = arr[i];
				cardinality[bitset] = bits[i];
			}
				
			for(int j=1;j<=1024;j++) {
				
				if(!(bitset & j)) {
					
					sum[j+bitset] = max(sum[j+bitset], sum[j]+sum[bitset]);
				}
//				cout << sum[j+bitset] << " ";
			}
		}
		
		cout << sum[1023] << endl;
	}
}
