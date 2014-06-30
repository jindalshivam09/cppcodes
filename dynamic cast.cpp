#include<iostream>
#include<conio.h>
using namespace std;
class base{
	int a;
	public:
		void virtual func()
		{
				 cout<<" base";
		}
};
class der:public base{
	int b;
	public:
		void func()
		{
			   cout<<"der";
		}
};
main()
{
	   base *bp,b;
	   der *dp,p;
	  // bp=&p;
	   //dp->func();
	   base &ptr=p;        // virtual func by reference
	   ptr.func();
	   ptr=b;
	   b.func();
	   bp=&p;
	   bp->func();
	   cout<<bp<<" "<<dp<<endl;
	   cout<<" h "<<(bp=dynamic_cast<base *>(dp))<<" ";
	   bp->func();           //error as bp is now of der type and virtual properties cant be used by der class pointers
	   cout<<bp<<" "<<dp;
	   getch();
}
