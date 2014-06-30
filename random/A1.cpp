#include<iostream>
using namespace std;
void merge(int a[],int p,int q,int r)
{
int a1=q-p+1;
int b1=r-q;
int aa[a1+1];
int bb[b1+1];
aa[a1]=10000000;
bb[b1]=10000000;
for(int x=0;x<a1;x++)
aa[x]=a[p+x];
for(int y=0;y<b1;y++)
bb[y]=a[q+1+y];
int i=0,j=0;
for(int x=p;x<=r;x++)
{
if(aa[i]<=bb[j])
{
a[x]=aa[i];
i+=1;
}
else
{
a[x]=bb[j];
j+=1;
}
}
}
void sort(int a[],int p,int r)
{
if(p<r)
{
int q=(p+r)/2;
sort(a,p,q);
sort(a,q+1,r);
merge(a,p,q,r);
}
}
int paying(int a[],int m,int k)
{
int x;
if(m==0)
return 1;
if(m<0)
return 0;
for(x=k;x>=0;x--)
{
if(a[x]<=m)
{
if(paying(a,m-a[x],x-1))
return 1;
else
{
;
}
}
}
return 0;
}
int main()
{
int t;
cin>>t;
while(t--)
{
int n,m;
cin>>n>>m;
int a[n];
for(int y=0;y<n;y++)
cin>>a[y];
//sort(a,0,n-1);
if(paying(a,m,n-1))
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
}
return 0;
}


