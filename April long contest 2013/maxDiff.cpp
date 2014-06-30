#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
#define MAX 100005
using namespace std;
int compare(const void *a,const void *b)
{
    //printf("\n%d %d\n",a,b);
    return(*(int*)a-*(int*)b);

}
main()
{
		int t;
		int n,k,count;
        //int hashMap[MAX];
        int a;
        int loop;
        int arr[MAX];
		int totSum,calSum;
		scanf("%d",&t);
		while(t--)
		{
			totSum=0;
			calSum=0;
			count=0;
			scanf("%d%d",&n,&k);
			//memset(hashMap,0,sizeof(hashMap));
			for(int i=0;i<n;i++)
			{
         			scanf("%d",&arr[i]);
					//hashMap[a-1]++;
					totSum+=arr[i];
			}
			qsort(arr,n,sizeof(int),compare);
			int j=0;
			if(k>n-k)
			loop=n-k;
			else
			loop=k;
			while(count!=loop)
			{
				calSum+=arr[count];
		//		cout<<count<<" ";
				count++;
		    }
			int ans=totSum-2*calSum;
			if(ans>0)
			printf("%d\n",ans);
			else
			printf("%d\n",-1*ans);
		}
		return 0;
}
