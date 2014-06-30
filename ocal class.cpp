#include<iostream>
using namespace std;
void localclas()
{
          class local
          {
                    
                    public:
                           local(int r)
                           {
								count=0;
                                  cout<<r<<" ";
                           }
                          void inc() const;;
                    private:
                            int count;
          };     
          
           local::inc() const
           {
				                  cout<<count;
           }
          local const ob(1);
          ob.inc();
          
}
//localclas.ob3(3);
main()
{
        //  localclas().class ob2(2);
          
          localclas();
          cin.get();
}
