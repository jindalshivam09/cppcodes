#include<iostream>
#define MAX 10
#include<conio.h>
using namespace std;
class student
{
       private:
               int roll;
               int marks[MAX];
               static int a,b,d,f;
       public:
              
              float compute(int *m,int sub)
              {
                          int tot=0;
                          for(int i=0;i<sub;i++)
                           tot+=m[i];
                           return tot;
                                  
              }      
              void perc(int *m,int sub)
              { 
                         float perc=compute(m,sub)/sub;
                         if(perc<40)
                         f++;
                         else if(perc<60)
                         b++;
                         else if(perc<80)
                         a++;
                         else 
                         d++;
              }
              void dispSummary()
              {
                       cout<<a<<endl 
                           <<b<<endl
                           <<d<<endl
                           <<f<<endl;
              }
};
int student::a;
int student::b;
int student::d;
int student::f;
 main()
{
         
          student st[MAX];
          int n,s;
          int m[MAX];
          cout<<"students";
          cin>>s;
          cout<<"subjects";
          cin>>n;
          for(int i=0;i<s;i++)
          {
                 for(int j=0;j<n;j++)
                 cin>>m[j];
                 st[i].perc(m,n);
          }
          /*cout<<student::d
               <<student::a
               <<student::b
               <<student::f;
          */
          st[0].dispSummary();
          getch();
}
