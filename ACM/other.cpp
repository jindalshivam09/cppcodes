#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>

#define CLEAR(X) memset(X,0,sizeof(X))

using namespace std;

int main()
{
    int n,k,i,j,m,l,begin[2]={0,0},end[2]={0,0},flag=0,set[1000]={0},first[1000]={0},second[1000]={0},temp,count;
    pair<long,int> sticks[1000];
    long long sum[1000]={0},sum1,sum2;
    CLEAR(sum);
    scanf("%d %d",&n,&k);
    
    for(i=0;i<n;i++)
    {
        cin>>sticks[i].first;
        sticks[i].second = i;
    }
    sort(sticks,sticks+n);
    
    sum[0] = sticks[0].first;
    for(i=1;i<n;i++)
    sum[i] = sum[i-1] + sticks[i].first;
    i=0;
    
    if(sticks[k-1].first<sum[k-2])
    {
        begin[0] = 0;
        end[0] = k-1;
        //cout<<"\nbegin[0]= "<<begin[0]<<" end[0]= "<<end[0]<<endl;
        for(m=begin[0],l=0;m<end[0]+1;m++,l++)
        {
            set[m] = 1;
            first[l] = sticks[m].second;
        }
        sum1 = sum[k-2];        
    }
    
    else
    for(i=k;i<n;i++)
    if(sticks[i].first<(sum[i-1]-sum[i-k]))
    {
        begin[0] = i-k+1;
        end[0] = i;
        //cout<<"\nbegin[0]= "<<begin[0]<<" end[0]= "<<end[0]<<endl;
        for(m=begin[0],l=0;m<end[0]+1;m++,l++)
        {
            set[m] = 1;
            first[l] = sticks[m].second;
        }
        sum1 = sum[i-1]-sum[i-k];
        //i+=k;
        break;
    }
    if(i==n || i==(n-1))// && n!=2*k)
    printf("No\n");
    
    else
    {
        m=0;
        for(i=begin[0];i<end[0];i++)
        {
            for(j=i-1;j>=0;j--)
            {
                sum1 -= sticks[j+1].first;
                sum1 += sticks[j].first;
                if(sticks[end[0]].first > sum1)
                break;
                if(set[j]==0)
                {
                    first[m] = sticks[j].second;
                    set[j+1] = 0;
                    set[j] = 1;
                    //cout<<"\nfirst["<<m<<"]= "<<first[m]<<endl;
                
                }
            }
            if(j==i-1)
            break;
            m++;
        }
        temp = i-1;
        //for(m;i<end[0]+1;i++,m++)
        //first[m] = sticks[i].second;
        
        //find 2nd k-convex polygon
        sum1 = 0;
        if(end[0]>2*k-1)
        i = end[0] +1;
        else
        i = 2*k -1;
        for(i;i<n;i++)
        {
            count = 1;
            sum1 = 0;
            m = 0;
            for(j=i-1;count<k;j--)
            {
                if(set[j]==0)
                {
                    count++;
                    sum1+=sticks[j].first;
                    second[m] = sticks[j].second;
                    //cout<<"\nsecond["<<m<<"]= "<<second[m]<<endl;
                    m++;
                }
            }
            
            if(sticks[i].first < sum1)
            {
                //cout<<"\nm= "<<m<<endl;
                second[m] = sticks[i].second;
                break;
            }
            
        }
        
        if(i==n)
        {printf("No\n");
        //cout<<"\nhere\n";
        }
        else
        {
            printf("Yes\n");
            for(i=0;i<k;i++)
            printf("%d ",first[i]+1);
            for(i=0;i<k;i++)
            printf("%d ",second[i]+1);
        }
    }
    
    return 0;
}
