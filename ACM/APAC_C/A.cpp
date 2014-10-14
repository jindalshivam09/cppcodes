#include<bits/stdc++.h>
using namespace std;

#define MAX 300
int  n , mines;

int dx[8] = {-1,-1,-1,0,0,1,1,1} ;
int dy[8] = {-1,0,1,-1,1,-1,0,1} ;
vector<vector<char> > matrix(MAX,vector<char>(MAX)) ;
vector<vector<int> > values(MAX,vector<int>(MAX)) ;

bool check(int i,int j) {
	return (i>=0 && i<n && j>=0 && j<n);
}

int counter(int i, int j) {
	int cnt = 0 ;
	if(check(i-1,j-1) && matrix[i-1][j-1] == '*') cnt ++;	
	if(check(i-1,j) && matrix[i-1][j] == '*') cnt ++;	
	if(check(i-1,j+1) && matrix[i-1][j+1] == '*') cnt ++;	
	if(check(i,j-1) && matrix[i][j-1] == '*') cnt ++;	
	if(check(i,j+1) && matrix[i][j+1] == '*') cnt ++;	
	if(check(i+1,j-1) && matrix[i+1][j-1] == '*') cnt ++;	
	if(check(i+1,j) && matrix[i+1][j] == '*') cnt ++;	
	if(check(i+1,j+1) && matrix[i+1][j+1] == '*') cnt ++;	
	return cnt ;
}

void countMines() {
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(matrix[i][j] == '*')
				values[i][j] = -1 ;
			else values[i][j] = counter(i,j) ;
		}
	}
}

int cut(int i,int j) {
	int ret = 0 ;
	values[i][j] = -1;
	queue<pair<int,int> > q ;
	q.push(make_pair(i,j)) ;
	while(q.empty()==false) {
		pair<int ,int> popped = q.front() ;
		q.pop() ;
		for(int i=0;i<8;i++) {
			int tempi = popped.first+dx[i] ;
			int tempj = popped.second + dy[i] ;
			if(check(tempi,tempj)) {
				if(values[tempi][tempj] != -1)
					ret  ++ ;
				if(values[tempi][tempj] == 0) {
					q.push(make_pair(tempi,tempj)) ;
				}
				values[tempi][tempj] = -1;
			}
		}
	}
	return ret ;
	
}

pair<int,int> recursion() {
	pair<int,int> ret = make_pair(0,0) ;
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(values[i][j] == 0) {
				ret.second += cut(i,j) ;
				ret.first ++ ; 
			}
		}
	}
	return ret;
}


int main() {
	
	ifstream cin("input.txt") ;
	ofstream cout("output.txt") ;
	
	int t ;
	cin >> t ;
	for(int test = 1 ; test <= t; test++) {
		cin >> n ;
		mines = 0 ;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) {
				cin >> matrix[i][j] ;
				if(matrix[i][j] == '*')
					mines ++ ;
			}
				
		countMines() ;
		pair<int,int> ret = recursion() ;
		int clicks = ret.first ;
		clicks = (n*n - mines - ret.second) ;
		cout << "Case #" << test << ": " << clicks << endl;
	}
}
