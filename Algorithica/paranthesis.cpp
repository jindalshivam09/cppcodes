#include<stdio.h>
main()
{
	int t,i=-1,k;
	long long long unsigned  ans,ans1,ans2;
	long long int ans3;
	char a;
	scanf("%d",&t);
	fflush(stdin);
	while(t--)
	{
		//i=0;
		ans=1;
		ans1=1;
		ans2=1;/*
	    while((a=getchar())!='\n')
		i++;
		i--;*/
		i++;
   		for(k=2*i;k>i;k--)
		{
			ans*=k;
		}
		for(k=1;k<i;k++)
		ans1*=k;
		printf("%lllu %lllu\n",ans,ans1);
	}
	getchar();
	return 0;
	
}
