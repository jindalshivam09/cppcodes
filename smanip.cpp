#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
/*struct smanip{
	ios_base& (*func)(ios_base&,double);
	int n;
	smanip(ios_base&(*f)(ios_base& ,double ),double i):n(i),func(f)
	{
	}
};

ios_base& set_precision (ios_base &cout,double n)
{
	int i=n;
	cout.precision(i);
}
inline smanip setprecision(float n)
{
	return smanip(set_precision,n);
}*/
main()
{
	 cout<<setprecision(10)<<(17.0)/7;
	 getch();

}
