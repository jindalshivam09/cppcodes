#include<iostream>
using namespace std;

void recursive_fraction(int a,int b)
{
  int n,i;
  if(a>b)
  {
    n=a/b;
    for(i=1;i<=n;i+=1)
    {
       cout<<"1 ";
    }
    a=(a-b*n);
  }
  while(a!=0)
  {
    n=b/a;
    if(b%a!=0) n=n+1;
    cout<<n<<" ";
    a=n*a-b;
    b=n*b;
  }
}
int main()
{
  int a,b;
  cin>>a>>b;
  while(a!=1 || b!=1)
  {
    recursive_fraction(a,b);
    cout<<"\n";
    cin>>a>>b;
  }
  return 0;
}
