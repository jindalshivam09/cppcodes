//----------Program Name:----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date:------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#define MOD 1000000007
using namespace std;
main()
{
	int t;
	int n,k;
	long long  temp,temp2,temp3;
	long long ways;
	int loop;
	scanf("%d",&t);
	while(t--)
	{
		ways=1;
		temp=1;
		temp2=0;
		scanf("%d%d",&n,&k);
		loop=n;
		while(loop--)
		{
          //  printf("%lld %lld ",temp,temp2);
				temp3=temp;
				temp=temp2;
				temp2=((k*temp3)%MOD+((k-1)*temp2)%MOD)%MOD;
		}
		printf("%lld\n",temp);
	}
    return 0;
}
