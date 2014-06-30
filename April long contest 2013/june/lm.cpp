#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#define MAX 100
#define UP true
#define LEFT false
using namespace std;


int arr[MAX][MAX];
		
int abs(int m) {
	if(m<0)
	return -1*m;
	return m;
}
int mices(int n,int m,int i,int j,bool flag,int change) {
	int count=0;
	if(change==2 || change == 1) {
		if(arr[i-1][j] && i>0)  			{count++;  }
		if(arr[i][j-1] && j>0)  			{count++;  }
		
	}
	
	else if(change == 0 && flag==UP){
		if( arr[i][j+1] &&(j+1)<m   )  			{count++; }
		if(arr[i-1][j] && i>0)  			{count++;}
		if(arr[i][j-1]  && j>0)			 	{count++; }	
//	if(i==5&&j==4)
//	cout << count << "sd ";
//	cout << arr[i][j+1] << " " << arr[i-1][j] << " " << arr[i][j-1] << " " << i << i-1 << j << j-1 << j+1 <<" df" << count << "gfdh";;
	}
//	if(arr[i][j]) 						{count++;  }//arr[i][j]=0;}
//	if(arr[i-1][j-1] && i>0 && j>0)  	count++;
//	if(arr[i-1][j+1] && i>0 && j+1<m)   count++;
	else if(change == 0 && flag == LEFT){
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
	bool dir[n][m];
	path[n-1][m-1] = mices(n,m,n-1,m-1,LEFT,0) + arr[n-1][m-1];
	for(int i=m-2;i>=0;i--) {
		path[n-1][i] = path[n-1][i+1] + mices(n,m,n-1,i,LEFT,0);
		dir[n-1][i] = LEFT;
	}
	
	for(int i=n-2;i>=0;i--) {
		path[i][m-1] = -1*(abs(path[i+1][m-1]) + mices(n,m,i,m-1,UP,0));
		dir[i][m-1] = UP;
	}
	
	int count = 0;
	for(int i=n-2;i>=0;i--) {
		for(int j=m-2;j>=0;j--) {
			if(abs(path[i][j+1])<abs(path[i+1][j]) && path[i][j+1] < 0) {
				path[i][j] = abs(path[i][j+1]) + mices(n,m,i,j,LEFT,1);			
			}
			else if(abs(path[i][j+1])<abs(path[i+1][j]) ) {
				path[i][j] = abs(path[i][j+1]) + mices(n,m,i,j,LEFT,0);/*
				if((abs(path[i][j+1]) + mices(n,m,i,j,LEFT,0))>=(abs(path[i+1][j]) + mices(n,m,i,j,UP,0))&&arr[i+1][j]<0)
				path[i][j]=-1*abs(path[i+1][j]) + mices(n,m,i,j,UP,0);
				else if((abs(path[i][j+1]) + mices(n,m,i,j,LEFT,0))>=(abs(path[i+1][j]) + mices(n,m,i,j,UP,1))&&arr[i+1][j]>0)
				path[i][j]=-1*abs(path[i+1][j]) + mices(n,m,i,j,UP,1);*/
			}
			else if(abs(path[i][j+1])>abs(path[i+1][j]) && path[i+1][j] < 0) {
				path[i][j] = abs(path[i+1][j]) + mices(n,m,i,j,UP,0);		
				path[i][j]*=-1;
				
			}
			else if(abs(path[i][j+1])>abs(path[i+1][j]) ) {
				path[i][j] = abs(path[i+1][j]) + mices(n,m,i,j,UP,1);		
				path[i][j]*=-1;
			}
			else if((path[i][j+1])<=(path[i+1][j])){
				path[i][j] = abs(path[i+1][j]) + mices(n,m,i,j,UP,1);		
				path[i][j]*=-1;				
				if(path[i][j+1]==path[i+1][j] && path[i+1][j]<0)
				path[i][j]*=-1;
				
			}
			else {
				int m;
				if(mices(n,m,i,j,UP,0) >mices(n,m,i,j,LEFT,0))
					path[i][j] = abs(path[i][j+1]) + mices(n,m,i,j,LEFT,0);
				else if(mices(n,m,i,j,UP,0) <mices(n,m,i,j,LEFT,0)){
	//					if(i==5&&j==4)
		//		cout <<  mices(n,m,i,j,UP,0) << " " <<(path[i+1][j]); 
					path[i][j] = abs(path[i+1][j]) + mices(n,m,i,j,UP,0);		
					path[i][j]*=-1;
				}
				else {
					if(mices(n,m,i,j-1,LEFT,1)>mices(n,m,i-1,j,UP,1))
						path[i][j]=abs(path[i][j+1]) + mices(n,m,i,j,LEFT,0);
					else {
						path[i][j] = abs(path[i+1][j]) + mices(n,m,i,j,UP,0);		
					path[i][j]*=-1;
					}
				}
			}
		}
	
	}/*
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {	
			cout.width(4);
			cout   <<path[i][j] << "(" << arr[i][j] << ")" << "  ";
		}
		cout << endl;
	}*/
	//int p;
	//cin >> p;
	return abs(path[0][0]);
}

main() {
	int t;
	cin >> t;
	while(t--) {
		
	ifstream in("test.txt");
		int n,m;
		cin >> n >> m;
	//	int arr[n][m];
		char str[m+1];
		for(int i=0;i<n;i++) {
			in >> str;
			for(int j=0;j<m;j++) {
				arr[i][j] = str[j] - 48;
			}
		}
		cout << cal(n,m) << endl; 
	}
}
