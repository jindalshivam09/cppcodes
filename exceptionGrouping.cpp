//----------Program Name: Exception Handling  Grouping----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date: 8 April 2013------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MOD 1000000007
using namespace std;
class math
{
		int a;
		public:
			math(int q=0)
			{
				a=q;
				cout<<"math constructor\n ";
			}
			math(math &q)
			{
				a=q.a;
				cout<<"copy math \n";
			}
			virtual void print()
			{
				cout<<"math\n";
			}
			~math()
			{
					cout<<"destructor\n";
			}
};
class zero : public math
{
	int b;
	public:
		zero(int q=0)
		{
				cout<<"zero constructor\n";
		}
		zero(zero &q)
		{
				cout<<"copy zero \n";
		}
		void print()
		{
			cout<<"zero\n";
		}
};
class negative: public math
{
	public:
	int c;
	public:
		negative(int q=0)
		{
			c=q;
			cout<<"negative constructor\n";
		}
		negative(negative &q)
		{
				cout<<"copy negative \n";
		}
		void print()
		{
			cout<<"c= "<<c;
			cout<<"negative\n";
		}
};
void fun(math m)
{
	cout<<"function\n";
}
main()
{
 try{
	math m;
	zero z;
	negative n;
	n.print();
     float a,b;
	 int choice;
      //fun(math(1));
	do
	{
	  try{                              //to handle exceptions
		 cout<<"Press :\n";
		 cout<<"1 for addition\n";
		 cout<<"2 for subtraction\n";
		 cout<<"3 for multiplication\n";
		 cout<<"4 for divison\n";
		 cout<<"5 to exit\n";
		 cin>>choice;
		 if(choice>=1&&choice<=4)
		 {
                cout<<"enter the values: ";
	 			cin>>a>>b;
 		}
		 switch(choice)
		 {
				case 1:
         			cout<<"sum is :"<<a+b;
					break;
				case 2:
                	if((a-b)<0)
					throw n;
                	cout<<"subtraction is :"<<a-b;
					break;
				case 3:
                	cout<<"multiplication is :"<<a*b;
					break;
				case 4:
                	if(!b)
					throw z;
                	cout<<"divison is :"<<(float)a/b;
					break;
				case 5:
					return 1;
				default:
					throw m;
		}
		cout<<endl<<endl;
	   }
	   catch(negative n)                   // if result of subtraction is zero
	   {
			cout<<"Exception: Result of subtraction is negative\n";
			n.print();
			n.c=4;
			n.print();
			//throw;
       }
	   /*catch(math &b)                      //for divison by zero
	   {
			cout<<"Exception: Denominator cant be zero or choice is wrong\n";
			b.print();
       }*/
	   catch(...)                      // to handle any other exception
	   {
			cout<<" ellipsis\n";
				//	throw ;       //throw n to pass control to negative rethrow handler

	   }
	   /*
       catch()                   // for wrong choice by user
	   {
			cout<<"Exception: Wrong Choice\n\n";
       }*/
       n.print();
	   
	}while(1);
 }/*
 catch(negative n)
 {
   cout<<"rethrow";
 }*/
 catch(...)
 {
		cout<<"ellipsis rethrown\n";
 }
 int a;
 cin>>a;
    return 0;
}
