#include<iostream>
#include<cstdlib>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
main()
{
	int t,n,m,ans;
	cin>>t;
	int arr1[2000],arr2[2000];
	for(int k=1;k<=t;k++)
	{
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>m;
			arr1[i]=m;
		}
		for(int i=0;i<n;i++)
		{
			cin>>m;
			arr2[i]=m;
		}
		qsort(arr1,n,sizeof(int),cmp);
		qsort(arr2,n,sizeof(int),cmp);
		for(int i=0;i<n;i++)
		{
			ans+=arr1[i]*arr2[n-1-i];
		}
		cout<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}
