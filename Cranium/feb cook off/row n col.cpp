#include<iostream>
#include<cstring>
#define MAX 314159
using namespace std;
main()
{
     int n,q;
     cin>>n>>q;
     static int row[MAX],col[MAX];
     /*memset(row,0,sizeof(row));
     memset(col,0,sizeof(col));*/
     int maxRow=0,maxCol=0;
     while(q--)
     {
          char oper[7];
          cin>>oper;
          int a,b;
          cin>>a>>b;
          if(oper[0]=='R')
          {
                  row[a-1]+=b;
                  if(maxRow<row[a-1])
                  maxRow=row[a-1];
          }
		  else
          {
                    col[a-1]+=b;
                    if(maxCol<col[a-1])
                    maxCol=col[a-1];
           }
     }
     cout<<(maxRow+maxCol)<<endl;
     return 0;
}
