#include<bits/stdc++.h>
using namespace std;
long long a,b,w,x,c,p=0;
int main( ){
    cin>>a>>b>>w>>x>>c;
    if (a<c) p=ceil((double((c-a)*x-b))/(w-x))+c-a;
    cout<<p<<endl;
    return 0;
}