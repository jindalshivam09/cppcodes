#include<iostream>
#include<cstdlib>
#include<fstream>
#define MAX 200
#define UP -1
#define LEFT 1
#define BOTH 2
using namespace std;


int arr[MAX][MAX];
		
int mices(int n,int m,int i,int j,int flag,int change) {
	int count=0;
	if(change == 1) {
		if(arr[i-1][j] && i>0)  			{count++;  }
		if(arr[i][j-1] && j>0)  			{count++;  }
		
	}
	
	else if(flag==UP){
		if( arr[i][j+1] && (j+1)<m )  			{count++; }
		if(arr[i-1][j] && i>0)  			{count++;}
		if(arr[i][j-1]  && j>0)			 	{count++; }	
//	if(i==5&&j==4)
//	cout << count << "sd ";
//	cout << arr[i][j+1] << " " << arr[i-1][j] << " " << arr[i][j-1] << " " << i << i-1 << j << j-1 << j+1 <<" df" << count << "gfdh";;
	}
//	if(arr[i][j]) 						{count++;  }//arr[i][j]=0;}
//	if(arr[i-1][j-1] && i>0 && j>0)  	count++;
//	if(arr[i-1][j+1] && i>0 && j+1<m)   count++;
	else if(flag == LEFT){
		if(arr[i][j-1] && j>0)  			{count++; }// arr[i][j-1]=0;}
		if(arr[i+1][j] &&(i+1)<n)  			{count++;  }
		if(arr[i-1][j] && i>0)  			{count++;  }
	}
	//cout << count << " ";
	return count;	
}

int cal (int n,int m) {
	
	int path[n][m];
	bool d = UP;
	int dir[n][m];
	path[n-1][m-1] = mices(n,m,n-1,m-1,LEFT,0) + arr[n-1][m-1];
	for(int i=m-2;i>=0;i--) {
		path[n-1][i] = path[n-1][i+1] + mices(n,m,n-1,i,LEFT,0);
		dir[n-1][i] = LEFT;
	}
	
	for(int i=n-2;i>=0;i--) {
		path[i][m-1] = (path[i+1][m-1]) + mices(n,m,i,m-1,UP,0);
		dir[i][m-1] = UP;
	}
	
	int count = 0;
	for(int i=n-2;i>=0;i--) {
		for(int j=m-2;j>=0;j--) {
			if(dir[i][j+1] == LEFT ) {
				path[i][j] = path[i][j+1] + mices(n,m,i,j,LEFT,0);
				dir[i][j] = LEFT;
				if(dir[i+1][j] == LEFT || dir[i+1][j] == BOTH ) {
					if(path[i][j] > path[i+1][j] + mices(n,m,i,j,UP,1))  {
						path[i][j] = path[i+1][j] + mices(n,m,i,j,UP,1);
						dir[i][j] = UP;
					}
					else if(path[i][j] == path[i+1][j] + mices(n,m,i,j,UP,1))  {
						path[i][j] = path[i+1][j] + mices(n,m,i,j,UP,1);
						dir[i][j] = BOTH;
					}
				}
				else if(dir[i+1][j] == UP ) {
					if(path[i][j] > path[i+1][j] + mices(n,m,i,j,UP,0))  {
						path[i][j] = path[i+1][j] + mices(n,m,i,j,UP,0);
						dir[i][j] = UP;
					}
					else if(path[i][j] == path[i+1][j] + mices(n,m,i,j,UP,0))  {
						path[i][j] = path[i+1][j] + mices(n,m,i,j,UP,0);
						dir[i][j] = BOTH;
					}
				}
			}
			else if(dir[i][j+1] == UP || dir[i][j+1] == BOTH) {
				path[i][j] = path[i][j+1] + mices(n,m,i,j,LEFT,1);
				dir[i][j] = LEFT;
				if(dir[i+1][j] == LEFT || dir[i+1][j] == BOTH ) {
					if(path[i][j] > path[i+1][j] + mices(n,m,i,j,UP,1))  {
						path[i][j] = path[i+1][j] + mices(n,m,i,j,UP,1);
						dir[i][j] = UP;
					}
					else if(path[i][j] == path[i+1][j] + mices(n,m,i,j,UP,1))  {
						path[i][j] = path[i+1][j] + mices(n,m,i,j,UP,1);
						dir[i][j] = BOTH;
					}
				}
				else if(dir[i+1][j] == UP ) {
					if(path[i][j] > path[i+1][j] + mices(n,m,i,j,UP,0))  {
						path[i][j] = path[i+1][j] + mices(n,m,i,j,UP,0);
						dir[i][j] = UP;
					}
					else if(path[i][j] == path[i+1][j] + mices(n,m,i,j,UP,0))  {
						path[i][j] = path[i+1][j] + mices(n,m,i,j,UP,0);
						dir[i][j] = BOTH;
					}
				}
			}
		}
	
	}/*
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {	
			cout.width(3);
			cout   <<path[i][j] << arr[i][j] << " ";//<< "(" << arr[i][j] << ")" << "  ";
		}
		cout << endl;
	}*/
	//int p;
	//cin >> p;
	return path[0][0];
}

main() {
	int t;
	cin >> t;
	while(t--) {
		
	//ifstream in("test.txt");
		int n,m;
		cin >> n >> m;
	//	int arr[n][m];
		char str[m+1];
		for(int i=0;i<n;i++) {
			cin >> str;
			for(int j=0;j<m;j++) {
				arr[i][j] = str[j] - 48;
			}
		}
		cout << cal(n,m) << endl; 
	}
}
