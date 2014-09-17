#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

typedef long long  LL;
const LL  mo=1000000007;
string a[100010],s;
int n;
LL res,f[10],g[10];


void work()
{
	cin>>s;
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  cin>>a[i];
	for (int i=0; i<10; i++)  f[i]=i,g[i]=10;
	for (int i=n; i>=1; i--)
		{
			LL ff=0,gg=1,len=a[i].length();
			for (int j=3; j<len; j++)
				{
					int c=a[i][j]-'0';
					ff=((ff*g[c])%mo+f[c])%mo;
					gg=(gg*g[c])%mo;
				}
			f[a[i][0]-'0']=ff,g[a[i][0]-'0']=gg;
		}
	for (int i=0,len=s.length(); i<len; i++)
		res=((res*g[s[i]-'0'])%mo+f[s[i]-'0'])%mo;
	printf("%d",int(res));
}

int main()
{
	work();
	return 0;
}
