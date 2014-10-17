#include <bits/stdc++.h>

using namespace std;

int a,b,ks[10000000],ans,mod=1e9+7,top;

int main()
{
	scanf("%d %d",&a,&b);
	
	ks[0]=1;
	
	for(int i=1;;i++)
	{
		if(i*(i+1)/2>a+b) break;
		for(int j=a+b;j>=0;j--)
		{
			ks[j+i]+=ks[j];
			ks[j+i]%=mod;
		}
		top=i*(i+1)/2;
	}
	
	for(int i=a;i>=0;i--)
	{
		if(!ks[i]) continue;
		
		if(top-i<=b)
		{
			ans+=ks[i];
			ans%=mod;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}
