#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<string>
#define MAX 1000100
#define ll long long

using namespace std;

char s[MAX],ans[MAX];
int t[] = {1,6,8,9};

int main()
{
    int cnt[10],res,vis[10];
    char a[10][10];
    memset(vis,0,sizeof(vis));
    do{
        int temp = 0;
        for (int i=0; i<4; i++)
            temp = temp*10+t[i];
        int c = temp%7;
        if (vis[c])
            continue;
        vis[c] = 1;
        for (int i=0; i<4; i++)
            a[c][i] = t[i]+'0';
        a[c][4] = '\0';
    }while(next_permutation(t,t+4));

    while (scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        memset(cnt,0,sizeof(cnt));
        res = 0;
        int n = 0,count = 0;
        for (int i=0; i<len; i++)
        {
            if (s[i]=='0')
                count++;
            else if (s[i]-'0'==1&&!cnt[1])
                cnt[1]++;
            else if (s[i]-'0'==6&&!cnt[6])
                cnt[6]++;
            else if (s[i]-'0'==8&&!cnt[8])
                cnt[8]++;
            else if (s[i]-'0'==9&&!cnt[9])
                cnt[9]++;
            else
            {
                res = res*10+(s[i]-'0');
                res = res%7;
                ans[n++] = s[i];
            }
        }
        for (int i=0; i<4; i++)
            res = (res*10)%7;
        res = res%7;
        ans[n] = '\0';
        printf("%s",ans);
        printf("%s",a[(7-res)%7]);
        for (int i=0; i<count; i++)
            printf("%c",'0');
        printf("\n");
    }
    return 0;
}



