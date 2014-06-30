#include<iostream>
#include<conio.h>
using namespace std;
class integer
{
		int n;
		public:
			integer(int m=0)
			{n=m;}
};
class complex
{
		int real,imag;
		public:
			complex(int r=0,int i=0)
			{
						real=r;
						imag=i;
			}
			operator int()
			{
				 return real+imag;
			}
};
main()
{
	int n;
	cout<<"enter integer: ";
	cin>>n;
	int r,i;
	cout<<"enter complex number real and imaginary part: ";
	cin>>r>>i;
	complex c(r,i);
	int w=n+(int)c;
	cout<<w;
	getch();
}
