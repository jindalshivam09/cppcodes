#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
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
				
				scanf("%lld",&sereja[i][j]);
			}
		}
		
		vector<long long> A(k);
		for(long long i=0;i<k;i++) 
		scanf("%lld",&A[i]);
			
		vector<vector<int> > ans(n+1);
		int index = 0;
		int m = -1;
		
		
		for(int i=0;i<n && i <= 20;i++) {
			
			vector<int> temp(k);
			int count = 0;	
			
bool flag = false;
				for(int l=0;l<k;l++) {
			
						if (  sereja[i][l] > A[l] ) {
						
						flag = true;
						break;
					}
				}
				if(!flag) {
				
					for(int l=0;l<k;l++)
					temp[l] = sereja[i][l];
					ans[i+1].push_back(i+1);
					count++;
				}

			for(int j=0;j<n;j++) {
				
				flag = false;
				if(j != i) {
				
				for(int l=0;l<k;l++) {
			
					if ( temp[l] + sereja[j][l] > A[l] ) {
						
						flag = true;
						break;
					}
				}
				if(!flag) {
				
					for(int l=0;l<k;l++)
					temp[l] += sereja[j][l];
					ans[i+1].push_back(j+1);
					count++;
				
				}
				}
			}
			
			if( m < count) {
				
				index  = i+1;
				m = count;
			}
		}
		if(!index)		printf("0\n");
		else {
			
			printf("%d", ans[index].size());
			sort(ans[index].begin(),ans[index].end());
			for(int i=0;i<ans[index].size();i++) {
				
				if(!i)		cout << endl;
				printf("%d ",ans[index][i]);
			}
			printf("\n");
		}	
		printf("\n");
	}
}
