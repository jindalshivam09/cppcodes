#include<iostream>
using namespace std;
#include<string.h>
void rec(char *a,char *b,int n,int m)
{
      cout<<a<<b<<endl;
      *a^=*b^=*a^=*b;
      for(int j=1;j<m;j++)
      {
                rec(a+1,b+j,n,m);
      }


}
main()
{
      char a[]="XXX";
      char b[]="YYY";
      int n=strlen(a),m=strlen(b);
      rec(a,b,n,m);

}
