#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
using namespace std;

#define lli  long long int
inline lli read() 
{
    int flag=1;
    lli n = 0;
    char c;
    int parity=1;
    int i=0;
    while (1)
    { 
      c=GETCHAR();
      if(i==0&&c=='-') parity=-1;
      else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
      else if(flag!=1) break; 
      i++;
    }
    return parity*n;
}


vector< pair<int,int> > a;
vector<pair < int,int> > b;


int main()
{
    int test;
    //cin>>test;
    test = read();
    int n,k,p;
    while(test--)
    {
        int l,r;
        //cin>>n>>k>>p;
        
        n=read();
        k=read();
        p=read();
        
        if(p>k)
        {
            printf("No\n");
            continue;
        }
        
        while(k--)
        {
            l=read();
            r=read();
            a.push_back(make_pair(l,r));
        }
        while(p--)
        {
            l=read();
            r=read();
            b.push_back(make_pair(l,r));
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        auto i=a.begin();
        auto j=b.begin();
        int processed = 0;
        // now match
        while(j!=b.end())
        {
            int x =  i->first;
            int y =  i-> second;
            int X = j-> first;
            int Y = j-> second;
            //cout<<"Checkin "<<x<<"  "<<y<<" in "<<X<<" "<<Y<<endl;
            if(X<=Y)
            {
                if(x<=y && x>= X  && y <=Y)
                {
                    processed++;
                    i++;
                }
                else
                j++;
            }
            else // X>Y
            {
                if(x>=y && x>= X  && y <=Y)
                {
                    processed++;
                    i++;
                }
                else if(x<=y && x>=X && y>=X)
                {
                    processed++;
                    i++;
                }
                else if(x<=y && x<=Y && y<= Y)
                {
                    processed++;
                    i++;
                }
                else
                j++;
            }
            //cout<<"P : "<<processed<<endl;
        }
        
        if(processed ==  a.size())
            printf("Yes\n");
        else
            printf("No\n");        
        a.clear();
        b.clear();    
    }
    return 0;
}
