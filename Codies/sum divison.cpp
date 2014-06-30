//----------Program Name: Sum Product Divison----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date: 7 April 2013------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
main()
{
	int n,t;
	int count,a,b,sum;
	scanf("%d",&t);
	while(t--)
	{
			count=0;
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
			{
				a=i;
				for(int j=1;j<i;j++)
				{
					b=j;
					if(!((a*b)%(a+b)))
				//	printf("%d %d ",a,b);
					count++;
				}
			}
			printf("%d\n",count);
	}
    return 0;
}
