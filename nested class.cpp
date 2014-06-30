#include<iostream>
using namespace std;
class nestedmain
{
        public:
			inline void f();
            nestedmain(int r)
            {cout<<r;}

      private:
            class nested
            {
                public:
                    nested()
                    {cout<<"hi";}
                    nested(int r)
                    {cout<<r;}
            };
    nested o;
    private:
            int count;
    
};
inline void nestedmain::f()
{
	cout<<"\ni";
}

main()
{
      //nested o2;
       nestedmain o=1;
        o.f();
        cin.get();
}
