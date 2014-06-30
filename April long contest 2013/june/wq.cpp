#include<iostream>
#define MAX 100
using namespace std;
 
int mices(int arr[][MAX],int n,int m,int i,int j,bool flag,bool change) {
	int count=0;
	if(change) {
		if(arr[i][j+1] && j+1<m)  			{count++;  }
		if(arr[i+1][j] && i+1<n)  			{count++;  }
		
	}
	
	else if(flag){
		if(arr[i][j+1] && j+1<m)  			{count++;  }
		if(arr[i+1][j] && i+1<n)  			{count++;  }
		if(arr[i-1][j]  && i>0)			 	{count++;  }//arr[i-1][j]=0;}
	}
//	if(arr[i][j]) 						{count++;  }//arr[i][j]=0;}
//	if(arr[i-1][j-1] && i>0 && j>0)  	count++;
//	if(arr[i-1][j+1] && i>0 && j+1<m)   count++;
	else {
		if(arr[i][j-1] && j>0)  			{count++; }// arr[i][j-1]=0;}
		if(arr[i][j+1] && j+1<m)  			{count++;  }
		if(arr[i+1][j] && i+1<n)  			{count++;  }
	}
//	cout << "count=" << count << endl;
	//arr[i][j+1]=0;}
//	if(arr[i+1][j-1] && i+1<n && j>0)   count++;
	//arr[i+1][j]=0;}
//	if(arr[i+1][j+1] && i+1<n && j+1<m) count++;
//	cout << "mices";
	return count;	
}
int arr[MAX][MAX];
 
int MIN=10000;
int v=0;
int bt(int arr[][MAX],int n,int m,int i=0,int j=0,int count=0,bool flag=false,bool change=false) {
	count+=mices(arr,n,m,i,j,flag,change);	
	
	//cout << i << " " << j << " " << count <<  endl;
	if(i==n-1&&j==m-1) {
	//	cin.get();
	//		cout << "count" << count << endl;
	
		if(MIN>count)
		MIN=count;
	}
	//	for(int f=0;f<n;f++)
	//	for(int q=0;q<m;q++)
	//	arr[f][q]=backup[f][q];
		//cout << count << endl;
		//cin.get();
	
	//cout << count << " << " " ";
	else {
		if(i<n-1) {
			flag ? change=1:change=0;
			bt(arr,n,m,i+1,j,count,false,change);
		}
		if(j<m-1) {
			!flag ? change=1: change=0;
			bt(arr,n,m,i,j+1,count,true,change);
		}
	}
}
main() {
	int t;	
	cin >> t;
//	cin.get();
	while(t--) {
		int n,m ;
		v=0;
		char str[102];
		cin >> n >> m ;
		for(int i=0;i<n ;i++) {
			
				cin >> str;
		
			for(int j=0;j< m ;j++) {
				arr[i][j] = str[j]-48;
			}
		}
		MIN=10000;
		bt(arr,n,m );
	//	int min=10000;
	//	for(int i=0;i<v;i++)
		//cout << value[i];
		if(arr[0][0])
		MIN++;
		cout << MIN << endl;
	}
} 
