#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MAX 100000
using namespace std;
struct data
{
		long long b;
		long long l;
}band[MAX],length[MAX];
int compare(const void *a,const void *b)
{
		return ((struct data *)a)->l-((struct data *)b)->l;
}
main()
{
	int t,n,i,j,loop,count,diffBand;
	bool flag;
	long long a,b,ans,ans2,ans3;
	scanf("%d",&t);
	while(t--)
	{
			i=0;
			ans=0;
			ans2=0;
			ans3=0;
			flag=0;
			count=0;
			diffBand=0;
			scanf("%d",&n);
			loop=n;
		    while(loop--)
			{
				scanf("%lld%lld",&length[i].b,&length[i].l);
				ans+=length[i].l;
				flag=0;
				for(j=0;j<diffBand;j++)
				{
					if(band[j].b==length[i].b)
					{
						//printf("hi");
						flag=1;
						if(band[j].l>length[i].l)
				    	{
				    			band[j].l=length[i].l;
//                            		printf("(%lld %lld)",band[j].l,length[i].l);
				    	}

						break;
					}
				}
				if(!flag)
				{
					band[diffBand].l=length[i].l;
					band[diffBand].b=length[i].b;
					diffBand++;
				}


				i++;
			}
            qsort(band,diffBand,sizeof(struct data),compare);
		/*	for(int i=0;i<diffBand;i++)
			printf("(%lld %lld)",band[i].b,band[i].l);
			*/for(int i=0;i<diffBand;i++)
			{
             	ans2+=(i+1)*band[i].l;
             	ans3+=band[i].l;

			}
			//printf("%d %lld %lld ",diffBand,ans3,ans2);
			ans-=ans3;
			ans*=(diffBand);
			printf("%lld\n",ans+ans2);
	}

    return 0;
}
