#include<stdio.h>
double func(int n,int k)
{
	printf("%d %d \n",n,k);
	if(n>1&&k>0&&n!=k)
	{
       // 	printf("%d %d %f %f\n",n,k,1/(float)n,(float)n-1);
		return (1/(float)n)*((((float)n-1)*func(n-1,k))+func(n-1,k-1));
	}
	
	else {printf(" hi ");
	 return 0;
	}
}
main()
{
	int t;
	scanf("%d",&t);
	int n,k;
	while(t--)
	{
		   scanf("%d%d",&n,&k);
		  // double ans=func(n,k);
		  if(k==1)
		  printf("%f\n",(n-1)*1.0/2);
		  else
		   printf("%f\n",func(n,k));
	}
}
