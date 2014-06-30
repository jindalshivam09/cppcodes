     #include <iostream>
    using namespace std;
     
    
    int R,C;
    int min(int a,int b)
    {
    return a>b?b:a;
    }
    int Calculate_l(char str[][500],int r,int c)
    {
    int i=c-1,count=0;
    while(i>=0&&str[r][i]=='^')
    {
    count++;i--;
    if(count==2) return 2;
    }
    return count;
    }
    int Calculate_r(char str[][500],int r,int c)
    {
    int i=c+1,count=0;
    while(i<C&&str[r][i]=='^')
    {
    count++;i++;
    if(count==2) return 2;
    }
    return count;
    }
    int Calculate_t(char str[][500],int r,int c)
    {
    int i=r-1,count=0;
    while(i>=0&&str[i][c]=='^')
    {
    count++;i--;
    if(count==2) return 2;
    }
    return count;
    }
    int Calculate_b(char str[][500],int r,int c)
    {
    int i=r+1,count=0;
    while(i<R&&str[i][c]=='^')
    {
    count++;i++;
    if(count==2) return 2;
    }
    return count;
    }
    int Calculate_min_length(char str[][500],int r,int c)
    {
    int ll,rr,tt,bb,i,j;
    ll=Calculate_l(str,r,c);
    rr=Calculate_r(str,r,c);
    tt=Calculate_t(str,r,c);
    bb=Calculate_b(str,r,c);
    return min(min(ll,rr),min(tt,bb));
    }
     
    int Count_monster(char str[][500],int r,int c)
    {
    int min_length,monster_count=0,i,j;
    for(i=0;i<r;i++)
    {
    for(j=0;j<c;j++)
    {
    min_length=Calculate_min_length(str,i,j);
    if(min_length>=2&&str[i][j]=='^') monster_count++;
    }
    }
    return monster_count;
    }
    int main()
    {
     
    
    int test,i,j,k,ans;
    char str[500][500];
    
    cin>>test;
    while(test--)
    {
    cin>>R>>C;
    for(i=0;i<R;i++)
    cin>>str[i];
    ans=Count_monster(str,R,C);
    cout<<ans<<endl;
    }
     
    return 0;
    } 
