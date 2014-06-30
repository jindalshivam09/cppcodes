#include<iostream>
using namespace std;
class student
{
             int s1,s2,s3,s4;
        public:
             float get_total()
             {
                  return s1+s2+s3+s4;
             }

             void get_perc()
             {
                      float perc=get_total()/5;
                      cout <<  perc;
                      if(perc<40)
                      cout <<"fail";
                      else if(perc<60&&perc>40)
                      cout<<"pass";
                      else
                      cout<<"distinction";

             }
};
main()
{
          student st1,st2;
          cin>>st1.s1>>st1.s2>>st1.s3>>st1.s4;
          st1.get_perc();

}
