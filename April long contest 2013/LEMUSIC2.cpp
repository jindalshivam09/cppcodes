#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MAX 100000
using namespace std;
struct data
{
	long long l;
	long long b;
}length[MAX],band[MAX];
inline int compare(const void *a,const void *b)
{
		return ((struct data *)a)->l-((struct data *)b)->l;
}
inline int compare2(const void *a,const void *b)
{
		 if(((struct data *)a)->b-((struct data *)b)->b)
		 return ((struct data *)a)->b-((struct data *)b)->b;
		 else
		 return ((struct data *)a)->l-((struct data *)b)->l;
}
main()
{
	int diffBand;
	bool flag;
	long long ans,ans2,ans3;
	int t,n,j,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		ans2=0;
		ans3=0;
		diffBand=0;
		flag=0;
		for(int i=0;i<n;i++)
		{
				scanf("%lld%lld",&length[i].b,&length[i].l);
				ans+=length[i].l;
		}
		qsort(length,n,sizeof(struct data),compare2);
		band[0]=length[0];
		j=1;
		for(int i=1;i<n;i++)
		{
				if(band[j-1].b!=length[i].b)
				{
                    band[j].l=length[i].l;
 					band[j].b=length[i].b;
 					j++;
				}
		}
		qsort(band,j,sizeof(struct data),compare);
        for(int i=0;i<j;i++)
        {
		//	printf("(%lld %lld )",band[i].b,band[i].l);
				ans2+=(i+1)*band[i].l;
				ans3+=band[i].l;
		}
		ans-=ans3;
		ans*=j;
		printf("%lld\n",ans+ans2);
	}
}
