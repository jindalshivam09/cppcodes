#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
main()
{
		bool a[100],e[100];
		char ch;
		int counta,counte;
		int t,m,n,adam,eve;
		scanf("%d",&t);
		while(t--)
		{
			counta=counte=0;
			memset(a,0,sizeof(a));
			memset(e,0,sizeof(e));
			scanf("%d",&n);
			for(int i=0;i<n;i++)
			{
				cin>>ch>>m;
			//	printf("%c %d ",ch,i);
				if(ch=='A')
				{
        			a[m-1]=1;
					adam=m;
				}
				else
				{
					e[m-1]=1;
					eve=m;
				}
			}
			for(int i=0;i<adam;i++)
			{
					if(a[i]&&i)
					counta+=2;
					else
					counta++;
			}
			for(int i=0;i<eve;i++)
			{
					if(e[i]&&i)
					counte+=2;
					else
					counte++;
			}
			if(counta>counte)
			printf("%d\n",counta);
			else
			printf("%d\n",counte);
		}
}
