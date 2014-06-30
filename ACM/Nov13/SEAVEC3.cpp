#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<long long> &a,vector<long long>&b) {
	return true;
}

int main() {
	
	long long t;
	cin >> t;
	while(t--) {
		
		long long n,k;
		cin >> n >> k;
		vector<vector<long long> > sereja(n,vector<long long>(k));

		vector<int> temp(k);
		for(long long i=0;i<n;i++) {
			
			for(long long j=0;j<k;j++) {
			
				cin >> sereja[i][j];
			}
		}
		long long count  = 0;
		long long index  = 0;
		for(long long i=0;i<n;i++) {
			
			if(!i) {
				
				for(long long j = 0 ; j < k ; j ++)
					temp[j] = sereja[i][j];
			}
			else {
					long long tmp = 0;
					for(long long j = 0 ; j < k ; j ++)
					if(temp[j] > sereja[i][j])
					tmp++;
					
					if(tmp > count ) {
						
//						cout << i << endl;
						count = tmp;
						index = i;
						for(long long j = 0 ; j < k ; j ++)
							temp[j] = sereja[i][j];

					}
			}
		}
//		cout << index <<endl;
		vector<long long> A(k);
		for(long long i=0;i<k;i++) 
			cin >> A[i];
			
		vector<int> ans;
		int m = -1;
		bool f = false;	
	
			for(int i = 0 ; i < k ; i ++)
				if(A[i] > sereja[index][i]) {
					
					f = true;
					
					A[i] -= sereja[index][i];
				}
				else {
					f=false;
					break;
				}
				
			if(f) {
			
			
			for(int j=0;j<n;j++) {
				
				bool flag = false;
				for(int l=0;l<k;l++) {
			
					if ( sereja[j][l] > A[l] ) {
								
						flag = true;
						break;
					}
				}
				
				
				if(!flag) {
		
					for(int l=0;l<k;l++)
						A[l] -= sereja[j][l];			
					index = 1;				
					ans.push_back(j+1);
				}
			}
			}
		if(!f)		cout << 0 << endl;
		else {
			
			cout << ans.size() << endl;
			for(int i=0;i<ans.size();i++) {
				
				cout << ans[i] << " ";
			}
			cout << endl;
		}	
	}
}

