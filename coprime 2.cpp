#include<stdio.h>
#define max(a,b) a>b?a:b 
long long int dp[10008];
int gcd(int a, int b)
{
	if(b == 0)
	{
	        return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
int main()
{
      int i,t,n;
      scanf("%d",&t);
      //int aaa=0;
      //for(i=0;i<4000;i++)
      //aaa+=i;
      for(i=0;i<t;i++)
      {
              scanf("%d",&n);
              int a[n];
              scanf("%d",&a[0]);
              int j,maxi=a[0];
              for(j=1;j<n;j++)
              {scanf("%d",&a[j]);maxi=max(maxi,a[j]);}
              
              printf("%d\n",maxi);
              for(j=0;j<10008;j++)
              dp[j]=0;
              for(j=0;j<n;j++)
              {
                  int value=a[j];
                  int x,k;
                  for(k=1;k<=maxi;k++)
                  {
                      if(dp[k]>0)
                      {
                          x=gcd(value,k);
                          dp[x]+=(dp[k]);
		//		printf("%d %lld\n",x,dp[x]);              
		        }
                  }
                  dp[value]+=1;
        
              }    
              printf("%lld\n",dp[1]);
      }
return 0;
}
