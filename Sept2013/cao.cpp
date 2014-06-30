#include<iostream>
#include<vector>
using namespace std;

#define MAX 51
#define L 1
#define R 2
#define T 3
#define B 4

int cal_cpc(string grid[] , int flag , int m , int n , int i,int j) {

	int count = 0;
	if (flag == L) {
		
		for (int k = j-1 ; k >= 0 ; k--) {
		
			if (grid[i][k] == '^')		count++;
			else						break;
		}
	}
	if (flag == R) {
		
		for (int k = j+1 ; k < n ; k++) {
		
			if (grid[i][k] == '^')		count++;
			else						break;
		}
	}
	if (flag == T) {
		
		for (int k = i-1 ; k >= 0 ; k--) {
		
			if (grid[k][j] == '^')		count++;
			else						break;
		}
	}
	if (flag == B) {
		
		for (int k = i+1 ; k < m ; k++) {
		
			if (grid[k][j] == '^')		count++;
			else						break;
		}
	}
	return count;
}

int monsters (string grid[] , int m,int n){

	int l,r,t,b,p;
	int count=0;
	
	for (int i = 0 ; i < m ; i ++ ) {
		
		for (int j = 0 ; j < n ; j ++) {
		
			if (grid[i][j] != '#') {
			
				l = cal_cpc (grid,L,m,n,i,j);	
				r = cal_cpc (grid,R,m,n,i,j);
				t = cal_cpc (grid,T,m,n,i,j);
				b = cal_cpc (grid,B,m,n,i,j);
				p = min (min(l,r),min(t,p));
			//	p = min (t,p);
			//	p = min (b,p);
				
				if (p > 1)
				count++;
			}
		}
	}
	return count;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
	
		int r,c;
		cin >> r >> c;
		string grid[r];
		
		for (int i = 0 ; i < r ; i ++) {
			
			cin >> grid[i];
		}
		
		cout << monsters(grid,r,c) << endl;
	}
}
