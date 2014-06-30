#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	bool arr[200][1000]={0};
	int n,s,count;
	int a;
	int index;
	//int print[10000];
	int min=10000;
	scanf("%d%d",&n,&s);
	for(int i=0;i<s;i++)
	{
		scanf("%d",&count);
		while(count--)
		{
			scanf("%d",&a);
			arr[a][i]=1;
		}
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		count=0;
		for(int j=0;j<s;j++)
		{
				if(arr[i][j])
				{
					count++;
				}
		}
	//	printf("c= %d\n",count);

		if(count<min&&count)
		{
			index=i;
			min=count;
		}
	}
	printf("%d\n",min);
	for(int i=0;i<s;i++)
	{
		if(arr[index][i])
		{
			printf("%d ",i);
		}
	}
}
