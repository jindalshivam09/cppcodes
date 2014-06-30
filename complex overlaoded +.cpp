//------------ to implement overloading of operator for like a+b,3+b,b+3----------------
//-------------assign operator sometimes req to made private to deny access for user to use this operator
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class complex{
	private:

		int real,imag;
		complex operator =(complex a)
		{
			this->real=a.real;
			this->imag=a.imag;
		}
	public:
		complex()
		{
			real=imag=0;
		}
		complex(int r,int i)
		{
			real=r;
			imag=i;
		}
		/*complex operator +(complex c)
		{
					complex temp;
					temp.real=real+c.real;
					temp.imag=imag+c.imag;
					return temp;
		}*/
		complex operator +(int a)
        {
				   cout<<"int";
                    complex temp;
					temp.real=real+a;
					temp.imag=imag+a;
					return temp;
        }
   //     friend complex operator +(int,complex);
        friend complex operator +(complex,complex);
        void display()
        {
			cout<<real<<" "<<imag<<endl;
        }
        void assign(complex a)
        {
			*this=a;
        }
        operator int()                        //to convert complex to int type
        {
			return (real+imag);
        }
        friend complex operator  + (int a,complex ob) {
        	return ob;
        }
        friend class abc;
};
class abc {
  public :
  	void func(complex ob) {
  		ob.real=3;
  		cout<<ob.real << " " << ob.imag ; 
	}
};
/*
complex operator +(int a, complex c)
{
	                cout<<"friend1  "<<a<<" ";
                    complex temp;
					temp.real=c.real+a;
					temp.imag=c.imag+a;
					return temp;
}*/
complex operator +(complex a,complex b)
{
              cout<<"friend2  ";
                    complex temp;
					temp.real=b.real+a.real;
					temp.imag=b.imag+a.imag;
					return temp;
}
void operator delete(void *p)
{
	free(p);
}
main()
{
	complex c(2,3);
	complex b(1,1);
	abc ob;
	ob.func(c);
	complex *d=new complex;
	complex a;
	int w=b;    // firstly overloaded 1+class object is called and then it is converted into int and assigned to int
	cout<<"w="<<w<<" ";
	a.assign(1+c);
	a.display();
	/*a=1+b;
    a.display();
	a=4+b;
	a.display();
	*d=a+b;
	d->display();
	delete d;*/
	
	cout<<"hi";
	(*d).display();
	getch();
}
