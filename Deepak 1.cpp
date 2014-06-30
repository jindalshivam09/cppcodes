#include<iostream>
#define MAX 10
#define DMAX 20
#include<string.h>
using namespace std;
static int count=0;
void rec(char *a,char *b,char *c,int n,int m,int q,int i,int k,int l,int y=0)
{
//cout<<y;
//cout<<n<<m<<q<<i<<k<<l<<endl;
           c[i]=a[k];
           if(i==(q)&&!y)
           {
                //int e=strlen(c);
                cout<<c<<endl;
                ++count;
                //<<m<<n<<i<<q<<k<<l

                //cout<<"hi"<<endl;
           }

           else if(k<n&&l<m)
           {
              //  c[i]=a[k];
                //cout<<c[i]<<" "<<i<<" ";
                rec(a,b,c,n,m,q,(i+1),(k+1),l,0);
                rec(b,a,c,m,n,q,(i+1),(l+1),k,1);
           }

}
main()
{
       char a[MAX],b[MAX],c[DMAX];
       cin>>a>>b;
       int n=strlen(a),m=strlen(b),q=(m+n);
       c[q]='\0';
       rec(a,b,c,n,m,q,0,0,-1);
       rec(b,a,c,m,n,q,0,0,-1);
       cout<<count;
       cin.get();
}
