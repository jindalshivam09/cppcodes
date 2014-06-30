#include<iostream>
using namespace std;
#define MAX 10
class stat
{
     private:   stat int count;
     public:
          stat()   {count++;}
          stat(int r) {count++;}
          int disp()
          {return count;}
};
int stat::count;
stat st1;
main()
{
         stat st2;
         stat st3(3);
         int r=st2.disp();
         cout<<r;
}
stat st4;
