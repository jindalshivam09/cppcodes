#include<stdio.h>
#include<string.h>
#define MAX 10000
main()
{
	int t,i,n,k,temp,flag,max;
	int arr[MAX];
	scanf("%d",&t);
	while(t--)
	{
			 max=-1;
			 flag=0;
			 scanf("%d%d",&n,&k);
			 memset(arr,0,sizeof(arr));
			 for(i=0;i<n;i++)
			 {
					scanf("%d",&temp);
					arr[temp]++;
					if(max<temp)
					max=temp;
			 }
			 for(i=1;i<=max;i++)
			 {
					if(arr[i]>=n-1)//||arr[i]>=(n-1-arr[0]))
					{
						flag=1;
						break;
					}
			 }
			 if(flag)
			 printf("YES");
			 else
			 printf("NO");
			 printf("\n");
	}
}
