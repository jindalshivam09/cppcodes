#include<iostream>
#include<math.h>
#include<cstring>
#define MAX 1000000000000
using namespace std;
main()
{
	static bool isPrime[MAX];
//	memset(isPrime,1,sizeof(isPrime));
//	for(int i=0;i<n;i++)
//  cout<<isPrime[i]<<" ";
	int s=sqrt(MAX);
//	cout<<s;
   int a;
	for(int i=2;i<=s;i++)
	{
		 a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=MAX;j+=2*i)
     	{
			   isPrime[j]=1;
            //	cout<<j<<" ";
	    }
	}
	 int t;
	 scanf("%d",&t);
	 while(t--)
	 {
			int n;
			scanf("%d",&n);
			if(!isPrime[n-1])
			scamf("2\n");
			else
			scanf("1\n");
	 }
	return 0;
}
