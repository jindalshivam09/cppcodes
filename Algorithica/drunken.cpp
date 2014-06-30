#include<stdio.h>
#define MAX 1000000
main()
{
	int t;
	long int n;
	int i,j;
	char arr[MAX];
	scanf("%d",&t);
	while(t--)
	{
		   i=0;
		   scanf("%d",&n);
		   if(!(n%2))
		   {
				printf("0\n");
				continue;
		   }
		   while(n>1)
		   {
			//	printf(" %d ",n);
				if(((n+1)/2)%2)
				{
					arr[i]=1;
					n=(n+1)/2;
				}
				else
				{
                    arr[i]=2;
                    n=n/2;
				}
				i++;

		   }
		   for(j=i-1;j>=0;j--)
		   printf("%d",arr[j]);
		   printf("\n");
	}
	return 0;
}
