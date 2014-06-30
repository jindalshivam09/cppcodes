#include<stdio.h>
main()
{
	int t,n,i;
	int arr[10];
	scanf("%d",&t);
	int ONE,          // flag to check that all we have 1 candle for each number
	    ZERO;
	int min,secMin;
	int minI,secMinI;      // flag to check that all we have 0 candle for each number
	while(t--)
	{
		min=10;
		secMin=10;
		ONE=ZERO=1;
		for(i=0;i<=9;i++)
		{
			scanf("%d",&n);
			arr[i]=n;
			if(n!=1)
			ONE=0;
			if(n!=0)
			ZERO=0;
		}
		if(ONE)                  // if we have 1 candle for each number
		{
			printf("11\n");
			continue;
		}
		if(ZERO)                   // zero candle for each number
		{
			printf("1\n");
			continue;
		}
		for(i=0;i<=9;i++)            // to find samllest and second smallest number
		{
				 if(min>arr[i])
				 {
        				min=arr[i];
						minI=i;
						continue;
				 }
				 if(arr[i]>=min&&secMin>arr[i])
				 {
						secMin=arr[i];
						secMinI=i;
				 }
		}
	//	printf(" %d %d ",min,secMin);
		if(!min)          // if samllest number is zero
		{
			if(minI)     // smallest number corresponding to any index of array but not zero
			{
				printf("%d\n",minI);
			}
			else
			{
				 for(i=0;i<secMin;i++)
				 printf("%d",secMinI);
				 printf("0\n");
			}

		}
		else
		{
			if(minI)
				for(i=0;i<=min;i++)
				printf("%d",minI);
			else
               for(i=0;i<=min;i++)
				printf("%d",secMinI);

				printf("\n");
		}
		
	}
	return 0;
}
