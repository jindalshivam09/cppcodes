#include<iostream>
using namespace std;
#define MAX 10
#include<string.h>
#include<conio.h>
class expression
{
            private:
                    int opn[MAX],opt[MAX],n,m;
            public:
                   expression()
                   {    n=m=-1;}
                   inline void init();
                   void calc();
                             
};
inline void expression::init()
{
            
                int a;
                char b;
               for(int i=0;i<5;i++)
               {
                       if(!i%2)
                       {
                              cin>>a;
                                cout<<(opn[++n]=a)<<endl;
                       }
                      else 
                        {
                              cin>>b;  
                             cout<<(opt[++m]=b)<<endl;
                        }
                        
                              
               }
}
void expression::calc()
{ 
           
            int temp1=0,temp=0;
            cout<<n;
            for(int i=n-3;i>=0;i--)
            {
                     for(int j=0;j<=i+1;j++)
                     {
                                for(int k=0;k<=n-1;k++)
                                {
                                        int kdup=k;
                                        cout<<"("<<k<<"(";
                                          if(k==j)
                                          {
                                                  switch(opt[k])
                                                  {
                                                       case '+':
                                                            temp=opn[k]+opn[k+1];
                                                            cout<<"hk";
                                                            break;
                                                            
                                                       case '-':
                                                            temp=opn[k]-opn[k+1];
                                                             break;
                                                       case '*':
                                                            temp=opn[k]*opn[k+1];
                                                            break;
                                                       case '/':
                                                             temp=opn[k]/opn[k+1];
                                                             default: cout<<"hey";
                                                   
                                                  }
                                                  k++;
                                          }
                                         else 
                                              temp=opn[k]; 
                                          if(kdup)        
                                                  switch(opt[kdup-1])
                                                  {
                                                       case '+':
                                                            temp1+=temp;
                                                            break;
                                                       case '-':
                                                            temp1-=temp;
                                                             break;
                                                       case '*':
                                                            temp1*=temp;
                                                            break;
                                                       case '/':
                                                             temp1/=temp;
                                                   
                                                  }
                                          else temp1=temp;
                                          
                                }
                            cout<<endl<<temp1<<endl;
                            temp1=temp=0;
                                                      
                     }
                     
            }
}
main()
{
          expression e;
          char ep[MAX];
          //cin.get(ep,10);
          e.init();
          e.calc();
          getch();
          
}
