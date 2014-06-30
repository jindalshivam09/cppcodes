//----------Program Name: LEMUSIC----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date: 9 April 2013------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MOD 1000000007
#define MAX 100000
using namespace std;
long long band[MAX];
long long length[MAX][2];
void mrg(long long a[][2],int p,int q,int r)
{
    int i,j,d=p,n1=(q-p+1),n2=(r-q);
    //printf("(%d %d) ",n1,n2);
	long long l1[n1][2],l2[n2][2];
    for(i=0;i<n1;i++)
    {
		l1[i][0]=a[p+i][0];
     	l1[i][1]=a[p+i][1];
	 }

    for(i=0;i<n2;i++)
    {
     	l2[i][0]=a[q+1+i][0];
        l2[i][1]=a[q+1+i][1];
	}
    i=0;j=0;
    while(i<n1&&j<n2)
    {
        if(l1[i][1]<l2[j][1])
        {
            a[d][0]=l1[i][0];
            a[d][1]=l1[i][1];
			i++;d++;
        }
        else
        {
            a[d][0]=l2[j][0];
            a[d][1]=l2[j][1];
            j++;d++;
        }
	}
    while(i<n1)
    {
            a[d][0]=l1[i][0];
            a[d][1]=l1[i][1];
            i++;d++;
    }
    while(j<n2)
    {
             a[d][0]=l2[j][0];
             a[d][1]=l2[j][1];
             j++;d++;
    }
}


void merge(long long a[][2], int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        //printf("(%d %d %d)",p,q,r);
        merge(a,p,q);
        merge(a,q+1,r);
        mrg(a,p,q,r);
    }
}

main()
{
	int t,n,i,loop,count,diffBand;
	bool flag;
	long long a,b,ans,ans2;
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
			flag=0;
			count=0;
			diffBand=0;
			scanf("%d",&n);
			loop=n;
		    while(loop--)
			{
				scanf("%lld%lld",&length[i][0],&length[i][1]);
				i++;
			}
			merge(length,0,n-1);
			/*for(int i=0;i<n;i++)
			printf("(%lld %lld)",length[i][0],length[i][1]);*/
			for(int i=0;i<n;i++)
			{
				flag=0;
                for(int j=0;j<diffBand;j++)
				{
					if(band[j]==length[i][0])
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					band[i]=length[i][0];
					diffBand++;
					//printf("hi..%d %d %d ",i,band[i],diffBand);
					ans+=diffBand*length[i][1];
					length[i][1]=0;
				}
				else
				ans2+=length[i][1];
				
			}
			ans+=ans2*(diffBand);
			printf("%lld\n",ans);
	}

    return 0;
}