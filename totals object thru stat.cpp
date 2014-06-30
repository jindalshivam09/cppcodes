#include<iostream>
using namespace std;
#define MAX 10
class state
{
     private:
        static int count;
     public:
          state()   {count++;}
          state(int r) {count++;}
          static int disp();
          //{return count;}
};
int state::count;
int state::disp()
{
    return count;
}
state st1,st3;
main()
{
         state st2;
         state st3(3);
         int r=state::disp();
         cout<<r;
}
state st4;
