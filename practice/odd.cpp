#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		bool flag=0;
		scanf("%d",&n);
		for(i=1;i<n;i*=2)
		{
			if((n/i)==1)
				break;
		}
		printf("%d\n",i);
	}
	return 0;
}
