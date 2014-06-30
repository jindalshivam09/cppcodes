#include<stdio.h>
#include<stdlib.h>
#define MAX 102
int compare(const void *a,const void *b)
{
  //  printf("\n%d %d\n",a,b);
    return(*(int*)a-*(int*)b);
}
int findAP(int *arr,int n)
{
	int i;
	int diff=0;
	int count=1;
	int max=-1,j;
	for(i=1;i<n;i++)
	{
			for(j=0;j<n;j++)
			{

			}
	}
	return max+1;
}
main()
{
	int t,i,count;
	int arr[MAX];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	scanf("%d",&arr[i]);
	if(t==1)
	{
		printf("2");
		return 0;
	}
	qsort(arr,t,sizeof(int),compare);
	count=findAP(arr,t);
	printf("%d\n",count);
	getch();
//	return 0;
}
