#include<iostream>
#include<cstdio>
using namespace std;
int arr[1000][1000];

main()
{
	int m,t;
	int min;
	scanf("%d%d",&m,&t);
	for(int i=0;i<m;i++)
	for(int j=0;j<m;j++)
	scanf("%d",&arr[i][j]);
	for(int i=0;i<m-t+1;i++)
	{
		for(int j=0;j<m-t+1;j++)
		{
				min=arr[i][j];
				for(int k=i;k<t+i;k++)
				for(int l=j;l<t+j;l++)
				{
						if(arr[k][l]<min)
						min=arr[k][l];
				}
				printf("%d ",min);
		}
		printf("\n");
		//while(1);
	}

}
