#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		int arr[a];
		memset(arr,1,sizeof(arr));
		for(int i=2;i<a;i++)
		{
			int k=0;
			for(int j=0;j<a;j++)
			{

					if(arr[j])
					k++;
					if(k==i)
						arr[j]=0;
			}
		}
		for(int i=0;i<a;i++)
		if(arr[i])
		cout<<i<<" ";
		
	}
	getch();
}
