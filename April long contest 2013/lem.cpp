#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MOD 100003
#define MAX 100000
using namespace std;
struct data
{
		long long b;
		long long l;
}band[MAX],length[MAX];
int compare(const void *m,const void *n)
{
		return ((struct data *)m)->l-((struct data *)n)->l;
}
main()
{
	int t,n,i,j,k,loop,maxDisp,count,counter,diffBand;
	bool flag;
	long long a,b,ans,ans2,ans3;
	scanf("%d",&t);
	while(t--)
	{
			memset(band,0,sizeof(band));
	//		memset(index,0,sizeof(index));
			memset(length,0,sizeof(length));
	//		memset(bandPerformed,0,sizeof(bandPerformed));
			i=0;
			ans=0;
			ans2=0;
			ans3=0;
			flag=0;
			count=0;
			counter=0;
			diffBand=0;
			maxDisp=0;
			scanf("%d",&n);
			loop=n;
		    while(loop--)
			{
				scanf("%lld%lld",&length[i].b,&length[i].l);
				ans+=length[i].l;
				flag=0;
				k=length[i].b%MOD;
				printf(" %d %lld ",k,band[k].b);
				while(band[k].b&&band[k].b!=length[i].b)
				{
					k++;
					k%=MOD;
					counter++;
				}
				printf("(%d)",counter);
				if(!band[k].b)
				{
					if(counter>maxDisp)
					maxDisp=counter;
					band[k].b=length[i].b;
					band[k].l=length[i].l;
					printf("(%lld %lld)",band[k].b,band[k].l);
					diffBand++;
				}
				else if((band[k].b==length[i].b)&&(band[k].b>length[i].b))
				{
                    band[k].b=length[i].b;
					band[k].l=length[i].l;

				}
				i++;
			}
			for(int i=0;i<MAX;i++)
			if(band[i].l)
			printf("(%lld %lld)",band[i].b,band[i].l);

            qsort(band,MAX,sizeof(struct data),compare);
			for(int i=0;i<MAX;i++)
			if(band[i].l)
			printf("(%lld %lld)",band[i].b,band[i].l);
			for(int i=0;i<MAX;i++)
			{
             	ans2+=(i+1)*band[i].l;
             	ans3+=band[i].l;
			}
			printf("%d %lld %lld ",diffBand,ans3,ans2);
			ans-=ans3;
			ans*=(diffBand);
			printf("%lld\n",ans+ans2);
	}

    return 0;
}
