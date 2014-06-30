// even if we do overloading then too preecedence order remain same

#include<iostream>
#include<conio.h>
using namespace std;
class abcd{
	int a,b;
	public:
		abcd()
		{
			a=0;
		}
		abcd(int r)
       {
				   a=r;
				   b=2;
       }
		abcd operator +(abcd q)
		{

			 abcd w;
			// w.b=b+q.b;
			 w.a=a+q.a;
			 
			return w;
		}
		abcd operator *(abcd q)
		{
			return (a+q.a);
		}
		void disp()
		{
			cout<<a<<" "<<b;
		}
};
main()
{
   abcd a(3),b(2);
   abcd w=a*b+b;
   w.disp();
   getch();
}
