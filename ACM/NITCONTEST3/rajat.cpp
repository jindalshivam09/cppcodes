#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
#define NUM 5
long long matrix[][5] = {{1,2,3,2,1},{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0}} , ans[5][5];
long long init_mat[] = {1,2,3,2,1} ;

void logn_mul (long long n) {
	if (n==1) {
		for(int i=0;i<NUM;i++)
			for(int j=0;j<NUM;j++)
				ans[i][j] = matrix[i][j] ;
		return ;
	}
	logn_mul(n/2);
	vector<vector<long long> > temp(NUM,vector<long long>(NUM)) ;
	for(int i=0;i<NUM;i++)
		for(int j=0;j<NUM;j++)
			for(int k=0;k<NUM;k++) {
				temp[i][j] = ( temp[i][j] + ( ans[i][k]*ans[k][j])%MOD ) % MOD ;
			}
	for(int i=0;i<NUM;i++)
		for(int j=0;j<NUM;j++)
			ans[i][j] = temp[i][j] ;	

	if(n%2) {
		for(int i=0;i<NUM;i++)
			for(int j=0;j<NUM;j++) {
				ans[i][j] = 0 ;
				for(int k=0;k<NUM;k++) 
					ans[i][j] = (ans[i][j] +  (matrix[i][k]*temp[k][j])%MOD ) % MOD;		
			}
	}

}

long long func(long long n) {
	logn_mul(n-5) ;
	long long ret = 0 ;
	for(int k=0;k<5;k++)
		ret = (ret + (ans[0][k]*init_mat[k])%MOD)%MOD ;
	return ret ;
}

int main() {
	int t;
	cin >> t ;
	while(t--) {
		long long n ;
		cin >> n ;
		if ( n <= NUM ) {
			cout << init_mat[n-1] << endl;
			continue ;
		}
		for(int i=0;i<NUM;i++)
			for(int j=0;j<NUM;j++)
				ans[i][j] = 0 ;
		cout << func(n) << endl;
		
	}
}

 
