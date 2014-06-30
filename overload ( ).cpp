#include<iostream>
#define MAX 10
#include<stdlib.h>
#include<conio.h>
using namespace std;
class complex{
	private:
		float real;
		float imag;
	public:
		complex()
		{
			real=imag=0;
		}
		complex(int a,int b)
		{
			real=a;
			imag=b;
		}
		complex(int *arg)
		{
			real=arg[0];
			imag=arg[1];
		}
		/*void operator () (int a,long b)
		{
			cout<<"overloaded int: ";
			real=a;
			imag=b;
		}*/
        /*void operator () (float a,float b)
		{
			cout<<"overloaded float: ";
			real=a;
			imag=b;
		}*/
  /*      void operator () (long a,long b)
		{
			cout<<"overloaded: ";
			real=a;
			imag=b;
		}
*/
		void display()
		{
			cout<<"real="<<real<<" imag="<<imag<<endl;
		}


};

main()
{
	complex c[2]={{1,2},{3,4}};
	c[1].display();
	int arg[MAX];
	cout<<"enter arguments";
	cin.get(arg,10);
	complex d(arg);
	d.display();
	getch();
}
