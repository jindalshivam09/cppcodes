
/*
	Name: n-queen problem
	Copyright: no rights
	Author: shivam jindal
	Date: 12/09/13 19:32
	Description: using backtracking
*/


#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<ctime>
using namespace std;
#define MAX 1000

int count=0;
vector<vector<int> > memo(MAX,vector<int>(MAX));


bool is_allowed(vector<int > board , int n, int k,int i) {

	bool flag = true;
	for (int j = 0 ; j < k ; j ++) {
		
		if( abs(i-board[j]) == abs(k-j) ||  board[j] == i ) {
		
			flag = false;
			break;	
		}
	}
	if(flag)	return true;
	else		return false;
}

void n_queen(vector<int > board ,int n,int k) {

	for (int i = 0 ; i < n ; i ++) {
			if (is_allowed(board,n,k,i)) {
				if(k==(n-1)) {
					board[k] = i;
					count++;
//					for(int i=0;i<n;i++)
//					cout << board[i] << " ";
//					cout << endl;
					return ;
				}
				else {

					board[k] = i;
					n_queen(board,n,k+1);
				}
			}
	}
}

int main() {

	int n;
	cin >> n;
	double start = clock_t();
	vector<int > board(n);
	n_queen(board,n,0);
	cout << count << endl;
	cout << ( clock_t() - start ) / CLOCKS_PER_SEC;
	
}
