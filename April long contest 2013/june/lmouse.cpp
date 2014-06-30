#include<iostream>
#define MAX 100
using namespace std;

int mices(int arr[][MAX],int n,int m,int i,int j,bool flag,int change) {
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
int map[MAX];
int MIN=10000;
int v=0;
int bt(int arr[][MAX],int n,int m,int i,int j,int count=0,bool flag=false,int change=0) {
	cout << i << " " << j << endl;
	count+=mices(arr,n,m,i,j,flag,change);	
/*	if(change==2 && i==0&&j>0) {
		//	cout << i << " " << j << " " << flag <<endl;
		//	cout << map[j+1] << " " << arr[i][j+1] << endl;
		count+=map[j+1]-arr[i][j+1];
		//cout << count << endl;
		j=m-1;
	}
*/	//cout << i << " " << j << " " << count <<  endl;
	if(!i&&!j) {
	//	cin.get();
//			cout << "count" << count << endl;
	
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
		if(i>0) {
			flag ? change=1:change=0;
			bt(arr,n,m,i-1,j,count,false,change);
		}
		if(j>0) {
			!flag ? change=2: change=0;
			bt(arr,n,m,i,j-1,count,true,change);
		}
	}
}

main() {
	int t;	
	cin >> t;
	cin.get();
	while(t--) {
		int n,m ;
		v=0;
		char str[102];
		cin >> n >> m ;
		cin.get();
		for(int i=0;i<n ;i++) {
			for(int j=0;j<m;j++){
				str[j]=cin.get();
				arr[i][j] = str[j]-48;
			}
			cin.get();
		}
//		for(int i=0;i<m;i++)
//		cout << arr[n-1][i] << " ";
//		map[m-1]=arr[n-1][m-1]+arr[n-2][m-1];
//		cout<<map[m-1] << endl;
//		for(int i=m-2;i>=0;i--) {
		//	cout << arr[n-1][i] << " " << arr[n-2][i] << " " ;
//			map[i]=map[i+1]+arr[n-1][i]+arr[n-2][i];
//			cout << map[i] << " ";
	//	}
		MIN=10000;
		bt(arr,n,m,n-1,m-1 );
	//	int min=10000;
	//	for(int i=0;i<v;i++)
		//cout << value[i];
		if(arr[0][0])
		MIN++;
		cout << MIN << endl;
	}
}
