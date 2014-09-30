#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > matrix(20,vector<int>(20)), mincost(20,vector<int>(20)), sum(20,vector<int>(20)) , ans(20,vector<int>(20));

int main() {
	cin >> n >> m ;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++)
			cin >> matrix[i][j];
	}
	
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++)
			if(!j)
				sum[i][j] = matrix[i][j] ;
			else
				sum[i][j] = sum[i][j-1] + matrix[i][j];
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			ans[i][j] = mincost[i][j] = INT_MAX;
	}
	
	cout << endl;	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) 
			cout << sum[i][j] << " ";
		cout << endl;
	}


	
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			for(int k=j;k<n;k++) {
				cout << j << " " << k << endl;
				if(j)
					mincost[j][k] = min ( mincost[j][k] , sum[i][k] - sum[i][j-1] ) ;
 				else
					mincost[j][k] = min ( mincost[j][k] , sum[i][k]  ) ;
			}
		}
	}

	cout << endl;	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) 
			cout << mincost[i][j] << " ";
		cout << endl;
	}

	
	for(int len=0;len<n;len++) {
		for(int i=0;i+len<n;i++) {
			int k = i+len ;
			for(int j=i;j<=i+len;j++) {
				if(len) 
					ans[i][k] = min ( ans[i][k], ans[i][j] + ans[j][k]) ;
				else
					ans[i][i] = mincost[i][i] ;
			}
			cout << ans[i][k] << " ";
		}
		cout << endl;
	}	
	cout << ans[0][n-1] << endl;
}
