#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c,q;
		scanf("%d%d%d",&n,&c,&q);
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(c>=l&&c<=r)
			c=r+l-c;
		}
		printf("%d\n",c);
	}
}
