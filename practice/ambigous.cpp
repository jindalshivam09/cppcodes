#include<iostream>
#include<cstdio>
#define MAX 100000
using namespace std;
int perm[MAX];
main()
{
	int n;
	bool flag;
	scanf("%d",&n);
	while(n)
	{
		flag=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&perm[i]);
		}
		for(int i=1;i<n;i++)
		{
			if(perm[perm[i]]!=i)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		printf("not ambiguous\n");
		else
		printf("ambiguous\n");
        scanf("%d",&n);
	}
}
