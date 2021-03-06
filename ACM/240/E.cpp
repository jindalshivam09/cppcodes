#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int LL;

int n,m,a[1<<21];
LL dp[21][2];

void merge_sort(int l,int r,int dep)
{
//	cout << l << " " << r << endl;
    if(l>=r)
        return ;
    int m=(l+r)/2;
    merge_sort(l,m,dep-1);
    merge_sort(m+1,r,dep-1);
    for(int i=l; i<=m; i++)
    {
        dp[dep][0]+=lower_bound(a+m+1,a+r+1,a[i])-(a+m+1);
        dp[dep][1]+=r-m-(upper_bound(a+m+1,a+r+1,a[i])-(a+m+1));
    }
    sort(a+l,a+r+1);
}

int main()
{
    scanf("%d",&n);
    for(int i=1,sz=(1<<n); i<=sz; i++) scanf("%d",a+i);
    merge_sort(1,(1<<n),n);
    scanf("%d",&m);
    while(m--)
    {
        int q;
        LL ans=0;
        scanf("%d",&q);
        for(int i=1; i <= q; i++)
            swap(dp[i][0], dp[i][1]);
        for(int i=1; i<=n; i++)
            ans += dp[i][0];
        printf("%I64d\n",ans);
    }
    return 0;
}
