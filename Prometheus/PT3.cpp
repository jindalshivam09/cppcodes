#include<iostream>
#include<cstdio>
using namespace std;
main()
{
		int t,n;
		int last,m;
		int arr[100];
		int ans,count,count2,gift;
		bool flag;
		scanf("%d",&t);
		while(t--)
		{
			flag=0;
			ans=0;
			gift=1;
			scanf("%d",&n);
			last=m;
			arr[0]=1;
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&arr[i]);
				
			}
			flag=0;
			arr[0]=0;
		//	for(int i=0;i<=n;i++)
		//	printf("%d ",arr[i]);
			for(int i=1;i<=n;i++)
			{
				count=0;
				count2=0;
				while(arr[i]>arr[i-1]&&i<=n)
				{
					ans+=gift;
					gift++;
					//flag=1;
					count2++;
					i++;
				//	printf("%d %d\n",count2,ans);
				}
				while(arr[i]<arr[i-1]&&i<=n)
				{
					count++;
					i++;
				}
				while(arr[i]==arr[i-1]&&i<=n)
				{
					ans++;
					i++;
				}
				 gift=2;
				i--;
				ans+=((count+1)*count)/2;
				if(count2<count&&flag)
				ans+=count-count2;
                if(count2<count&&!flag)
				ans+=count-count2+1;
				if(count==count2&&!flag)
				ans++;
				flag=1;
			//	printf("%d %d\n",count,ans);
			}
			printf("%d\n",ans);
		}
}
