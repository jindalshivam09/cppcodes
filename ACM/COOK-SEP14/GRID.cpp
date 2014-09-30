#include<bits/stdc++.h>
using namespace std;
#define MAX 1009
int n ;
vector<vector<char> > grid (MAX,vector<char>(MAX)) ;
vector<vector<bool> > row (MAX,vector<bool>(MAX)) , col(MAX,vector<bool>(MAX)) ;

void cal_row() {
	for(int i=0;i<n;i++) {
		int j = n-1 ;
		while(j>=0 && grid[i][j] == '.') {
			row[i][j] = true ;
			j--;
		}
		while(j>=0) {
			row[i][j] = false ;
			j -- ;
		}
	}
}

void cal_col () {
	for(int i=0;i<n;i++) {
		int j = n-1 ;
		while(j>=0 && grid[j][i] == '.') {
			col[j][i] = true ;
			j--;
		}
		while(j>=0) {
			col[j][i] = false ;
			j -- ;
		}
	}
}

int cnt() {
	int ans = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(row[i][j] && col[i][j])
				ans ++;	
	return ans ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		cin >> n ;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> grid[i][j] ;
		
		cal_row() ;
		cal_col() ;
		
		cout << cnt() << endl;
	}
}
