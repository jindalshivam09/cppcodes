#include<iostream>
using namespace std;
class cons
{
      private:
              int count,var;
      public:
             cons(): count(0),var(1)
             {}
             cons(int r,int v):count(r),var(v)
             {}
             cons operator ++()
             {
                      ++count;
                      ++var;
                      return cons(count,var);
             }
             cons operator +(cons c)const
             {
                     int co=count+c.count;
                     int va=var+c.var;
                     cout<<"c="<<co<<" "<<"v="<<va<<endl;
                     return cons(co,va);
             }
             void display();
};
void cons::display()
{
          cout<<count<<"  "<<var<<endl;
}

main()
{
              cons c1,c2,c3;
              c1.display();
              c2=++(++c1);
              c1.display();
              c2.display();
              c3=c1+c2+c1;
              c3.display();
              cin.get();
}
