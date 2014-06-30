#include<iostream>
using namespace std;
void change(int &a,int b)
{
       a*=2;
       b=0;
}
int main()
{
     cout <<"hi!" <<endl;
     int i,j;
     cin>>i>>j;
     change(i,j);
     cout<<i  <<endl <<j;
     return 0;
}
