#include<stdio.h>
#include<math.h>
#define MAX 1000
main()
{
	static char isPrime[MAX];
//	memset(isPrime,1,sizeof(isPrime));
//	for(int i=0;i<n;i++)
//  cout<<isPrime[i]<<" ";
	long long int s=sqrt(MAX);
//	cout<<s;
   long long int a;
   long long int i,j;
	for( i=2;i<=s;i++)
	{
		 a=i;
		if(!isPrime[i])
    	for( j=a*a;j<=MAX;j+=2*i)
     	{
			   isPrime[j]=1;
           // 	cout<<j<<" ";
	    }
	}
	scanf("hi");
	 int t;
	 scanf("%d",&t);
	 while(t--)
	 {
			long long int n;
			
			scanf("%d",&n);
			if(!isPrime[n])
			printf("2\n");
			else
			printf("1\n");
	 }
	return 0;
}
