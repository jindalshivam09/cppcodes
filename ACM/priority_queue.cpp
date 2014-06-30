#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
class compa
{
    public:
    bool compar(const int&a,const int& b)const
    {
       return(a<b);
    }
};
int main()
{
    int i,k;
    priority_queue<int,vector<int>,compa> q(compa());
    for(i=0;i<4;i++)
    {
        cin>>k;
        q.push_back(k);
    }
    while(!q.empty())
    {
        k=q.top();
        cout<<k<<" ";
        q.pop_back();
    }
    return 0;
}
