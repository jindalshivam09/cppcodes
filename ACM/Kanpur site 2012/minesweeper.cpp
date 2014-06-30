#include<iostream>
#include<vector>
using namespace std;

#define MAX 100

vector<vector<char>  > board(MAX,vector<char>(MAX)), played(MAX,vector<char>(MAX)), output(MAX,vector<char>(MAX));

int count_mines(int i,int j,int n) {

	int count = 0;
	if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == '*')	count++;
	if (i-1 >= 0 && j >= 0 && board[i-1][j] == '*')	    count++;
	if (i-1 >= 0 && j+1 < n && board[i-1][j+1] == '*')	count++;
	if (i >= 0 && j-1 >= 0 && board[i][j-1] == '*')	count++;
	if (i >= 0 && j+1 < n && board[i][j+1] == '*')	count++;
	if (i+1 < n && j-1 >= 0 && board[i+1][j-1] == '*')	count++;
	if (i+1 < n && j >= 0 && board[i+1][j] == '*')	count++;
	if (i+1 < n && j+1 < n && board[i+1][j+1] == '*')	count++;
	return count;
}

void minesweeper(int n) {

	bool flag = false;
	int f1 = 0 , f2 = 0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(played[i][j]=='x' && board[i][j]=='*' ) {
				flag = true;
				f1 = i;
				f2 = j;
				break;
			}
			
/*	if(flag) {
	
		for (int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				cout << board[i][j];
			cout << endl;
		}	
	}		
*/
//	else {
		for (int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
	
				if(flag && board[i][j] == '*') 
					cout << board[i][j];
				else {
					if (played[i][j] == '.')
					cout << ".";
					else if( played[i][j]=='x') {
		
						cout << count_mines(i,j,n);
					}
				}
			}
			cout << endl;
		}
//	}
}


int main() {

	int n;
	cin >> n;

	for (int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			cin >> board[i][j];
	}

	for (int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			cin >> played[i][j];
	}

	minesweeper(n);
}

/*
8
...**..*
......*.
....*...
........
........
.....*..
...**.*.
.....*..
xxx.....
xxxx....
xxxx....
xxxxx...
xxxxx...
xxxxx...
xxx.....
xxxxx...
*/
