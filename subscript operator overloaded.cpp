#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class complex{
	private:
		int *pointr;
		//float real,imag;
		int n;
	public:
		complex()
		{
			n=1;
			//cout<<"hi";
			pointr=new int;
		}
		complex(int a)
		{
			n=a;
			pointr=new int[a];
		}
		void *operator new(size_t size)
		{
			cout<<"over";
			void *p;
			p=malloc(size);
			return p;
		}
		void *operator new [](size_t size)
		{
			void *p;
			p=malloc(size);
			return p;
		}
		void operator delete(void *p)
		{
			free(p);
		}
		void operator delete [](void *p)
		{
			free(p);
        }
        int& operator [](int a)
        {
			  return pointr[a];
        }
        void set()
        {
            cout<<"enter elements"<<endl;
			for(int i=0;i<n;i++)
			{
				cin>>pointr[i];
			}
        }
};

int func(int &a)
{
	return a++,a;
}
main()
{
	complex c;
	complex d(4);
	c.set();
	d.set();
	cout<<c[0]<<endl;
    cout<<d[2]<<endl;
    d[8]=9;
	cout<<d[8]<<endl;
	double f=2.134;
	int a=1,b=2;
	
	a=b,a;
	b=(1,2),4;
	
	cout<<"a "<<a<<"b="<<b<<endl;
	b=(a,(4,3));
	b=func(a);
	cout<<b<<" "<<a<<endl;
	cout<<d[f]<<endl;
    cout<<d[1.999]<<endl;
    int q[2]={1,2};
    int i=0;
    q[i]=i++;
    cout<<"q="<<q[0]<<" "<<q[1]<<endl;
	if(a=0,1)
	cout<<"hi";
	else cout<<"bie";
	cout<<a;
	getch();
	
}
