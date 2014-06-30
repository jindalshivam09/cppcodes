#include<iostream>
#include<cstdio>
using namespace std;
main()
{
		int t,n;
		int arr[105],last,count;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d",&n);
			count=0;
			for(int i=0;i<n;i++)
			{
				scanf("%d",&arr[i]);
			}
   			for(int j=n-2;j>=0;j--)
			{
				if(arr[j]<arr[j+1])
				count++;
				else
				break;
			}
			printf("%d\n",n-count-1);
		}
}
