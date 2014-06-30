//program GERALD05

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;
#define  MOD 1000000007
int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

const int mod=1000000007;
vector<long long> rev(101);


long long calpow(long long a,long long b)
{
  if(!b)
    return 1;
  long long t=calpow(a*a%mod,b/2);
  if(b&1)
    t=t*a%mod;
  return t;
}
 
void init() {
	for(int i=1;i<101;i++) {
		rev[i] = calpow(i,mod-2);
		cout << rev[i] << " ";
	}
}

int main()
{
  int test=get();
 init();
  while(test--)
    {
      int c0=get(),c1=get(),c2=get(),c3=get(),n=get();
      static long long c[101][101];
      for(int i=1;i<=n;i++)
        {
          long long m=c0+c1*i+c2*i*i+c3*i*i*i;
          c[i][0]=1;
//          cout << m << endl;
          for(int j=1;j<=n;j++)
         {
         	cout << rev[j] << " ";
            c[i][j]=c[i][j-1]*(m+j-1)%mod*rev[j]%mod;
        	cout << c[i][j] << endl;
        }
        }
      static long long dp[101][101];
      memset(dp,0,sizeof(dp));
      for(int i=0;i<=n;i++)
        dp[0][i]=1;
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          for(int k=0;j*k<=i;k++)
            {
              dp[i][j]+=dp[i-j*k][j-1]*c[j][k];
              dp[i][j]%=mod;
            }
            
        for(int i=1;i<=n;i++) {
        	for(int j=1;j<=n;j++);
   //     		cout << dp[i][j] << " ";
    //    	cout << endl;
        }
      output(dp[n][n]);
    }
  return 0;
}
