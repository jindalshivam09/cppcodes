#include<iostream>
using namespace std;
main()
{
      int t;
      cin>>t;
      while(t--)
      {
           int a,b;
           cin>>a>>b;
           (a/b==2||b/a==2)?cout<<"BOB":cout<<"ALICE";
           cout<<"\n";
      }
}
