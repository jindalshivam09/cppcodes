#include <cstdio>
#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int dx[4]={-1,-1,0,0},
          dy[4]={-1,0,-1,0};
int f[606][303][303],a[303][303];
int n,m;
int main() {
  int i,j,k,p,q,d;
//  scanf("%d",&n);
	n = 300 ;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    	a[i][j] = j ;
//      scanf("%d",&a[i][j]);
  memset(f,0xf0,sizeof(f));
  f[1][0][0]=0;
  for (k=2;k<=n*2;k++)
    for (p=1;p<=min(n,k-1);p++)
      for (q=1;q<=min(n,k-1);q++) {
        int tmp=a[p][k-p]+a[q][k-q];
        if (p==q) tmp=a[p][k-p];
        for (d=0;d<4;d++)
          f[k][p][q]=max(f[k][p][q],f[k-1][p+dx[d]][q+dy[d]]);
        f[k][p][q]+=tmp;
        if (k-p>350)
        cout << k-p << " " << k-q << endl;
      }
  printf("%d\n",f[n*2][n][n]);
  return 0;
}
