#include<iostream>
#include<conio.h>
using namespace std;
class complex
{
	private:
	//	int real,imag;
	public:
	/*	complex(int i=0,int j=0):real(i),imag(j)
	  { cout<<"hi";}
		ostream& operator <<(ostream&);
		istream& operator >>(istream&);*/
		virtual ostream & puts(ostream &)const=0 ;
		virtual istream & gets(istream &)const=0 ;
};
class der:public complex
{
	private:
		int real,imag;
	public:
		der(int i=0,int j=0)
		{
			real=i;
			imag=j;
		}
		ostream & puts(ostream &cout)const
		{
			cout<<real<<" "<<imag;
		}
		istream & gets(istream & cin) const
		{
			cout<<"gets";
		}

};
ostream& operator <<(ostream &cout,der &c)
{
	cout<<"<<";
	//cout<<c.real<<"+"<<c.imag<<"i";
	return c.puts(cout);
}
istream& operator >>(istream &cin, der &c)
{
	cout<<"shivam";
	//cin>>c.real>>c.imag;
	return c.gets(cin);
}

main()
{
	//complex &c;
	//cin>>c;n
	//cout<<c<<endl;
	der d;
	int a=9;
	cout<<"shivam"<<a<<" ";
	 cout<<d;
	 cin>>d;

//	 complex &c=d;
	getch();
}
