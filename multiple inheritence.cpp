#include<iostream>
using namespace std;
class base{
    public:
    void func(int)
    {
           cout<<"shivam";
    }
};
class der1 {
   //using base::func;
public:   void func()
   {

   }
};
class der2: public der1,public base{
    public:
    using der1::func;
    using base::func;
    der2():der1()
    {}
};
main()
{
        der2 ob;
        ob.func(2);
}
