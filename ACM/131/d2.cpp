
#include<iostream>
#include<stdio.h>

#define p7 1000000007
#define LL long long

using namespace std;

LL n,k,a[10],C[102][102],DP[102][102],i,j,z,c,ans,mx,p;

main()
 {
  cin>>n;
  for (k=0;k<10;k++) cin>>a[k];
  for (i=0;i<=n;i++) C[0][i]=1;
  for (j=1;j<=n;j++)
   for (k=1;k<=j;k++) {
    C[k][j]=(C[k][j-1]+C[k-1][j-1])%p7;
    cout << C[k][j] << " " ;
}
  for (i=0;i<=n;i++)
   for (j=9;j>=0;j--)
    {
     if (j == 0)
      {
       for (p=a[0];p<=100;p++)
        if (i >= p) {DP[i][j]=(DP[i][j]+DP[i-p][1]*C[p][i-1])%p7; cout << i-1 << " ";}
      } else
     if (j < 9)
      {
       for (p=a[j];p<=100;p++)
        if (i >= p) DP[i][j]=(DP[i][j]+DP[i-p][j+1]*C[p][i])%p7;
      } else
      {
       if (i >= a[9]) DP[i][9]=1; else DP[i][9]=0;
      }
   }
  while (n--) ans=(ans+DP[n+1][0])%p7;
  cout<<ans<<endl;
 }