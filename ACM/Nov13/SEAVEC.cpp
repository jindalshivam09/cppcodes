#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	long long t;
	cin >> t;
	while(t--) {
		
		long long n,k;
		cin >> n >> k;
		vector<vector<long long> > sereja(n,vector<long long>(k));
		
		for(long long i=0;i<n;i++) {
			
			for(long long j=0;j<k;j++) {
				
				cin >> sereja[i][j];
			}
		}
		
		vector<long long> A(k);
		for(long long i=0;i<k;i++) 
			cin >> A[i];
			
			
		long long ans;
		bool flag = false,flag2 = false;	
		for(long long i=0;i<n;i++) {
			
			flag = false;
			for(long long j = 0;j<k;j++) {
				
				if(sereja[i][j] > A[j]) {
					
					flag = true;
					break;
				}
			}
			if(!flag) {
				
				ans  = i+1;
				flag2 = true;
				break;
			}
		}
		if(flag2)
		cout << 1 << endl << ans << endl;
		else
		cout << 0 << endl;
	}
}
