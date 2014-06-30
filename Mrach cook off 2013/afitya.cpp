#include<stdio.h>
#include<math.h>

int main()
{
int t,n,i,j;
unsigned long long int ans=0;

scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%d",&n);
for(j=1;j<=n;j++)
{
ans=(ans+pow(26,((j+1)/2)));
ans=ans%1000000007;
//printf("%d\n",ans);
}
printf("%lld\n",ans%1000000007);
ans=0;
}
return 0;
}
