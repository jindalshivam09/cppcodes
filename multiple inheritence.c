#include<iostream>
using namespace std;
class base{

};
class der1: public base{

};
class der2: public der1{
    public:
    der2():der1(),base()
    {}
};
main()
{
        der2 ob;
}
