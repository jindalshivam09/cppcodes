#include<iostream>
#include<cstring>
#include<vector>
#include<conio.h>
using namespace std;
main()
{
	vector<int> arr(100);
	for(int i=0;i<10;i++)
	cout<<(arr[i]=i)<<" "<<&arr[i]<<" ";
//	cout<<arr.size();
	cout<<(memset((vector<int>)&arr[0],0,sizeof(arr)));
	
	getch();
}
