#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	int t,angle,sides;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&angle);
		sides=360/(180-angle);
		if(360==sides*(180-angle))
		printf("YES\n");
		else
		printf("NO\n");
	}
}
