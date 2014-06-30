#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int q;
		scanf("%d",&q);
		char side[q][6],addr[q][50];
		int i=0;
		while(i<q)
		{
				scanf("%s",side[i]);
				gets(addr[i]);
				i++;
		}
		printf("Begin%s\n",addr[q-1]);
		q--;
		while(q--)
		{
				if(side[q+1][0]=='R')
				{
						printf("Left%s\n",addr[q]);
				}
				else
				printf("Right%s\n",addr[q]);
				
		}

	}
	return 0;
}
