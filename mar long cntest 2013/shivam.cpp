#include<stdio.h>
main()
{
	int t,i;
	long int n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		double ans;
		if(k==1)
		printf("%f",(n-1)/2.0);
		else
		{
			ans=(n-k+1)*(n-k)/4.0;
			for(i=n;i>(n-k+1);i--)
			ans/=i;
			printf("%f",ans);
		}
		printf("\n");
		
	}
}
