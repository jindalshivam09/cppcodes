#include<iostream>
#include<conio.h>
#include<typeinfo>
using namespace std;
class abc{
	int a;
	public:
		void fun()
		{
			cout<<"base";
		}
};
class xyz : public abc{
	int a;
	public :
		void func()
		{}
};
main()
{
	   abc b;
	   xyz c;
	   abc &e=c;
	// type_info &ptr=typeid(b);
	   cout<<typeid(b).name();//<<" "<<ptr;
	   if(typeid(e)==typeid(c))
	   cout << " equal ";
	   else
	   cout << " not equal ";
}
