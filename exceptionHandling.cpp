//--------EXCEPTION HANDLING----------------
//-------date:4 April 2013-------------------

#include<iostream>

//-----------defined for exceptions-----------
#define ZERO 1
#define WRONG (float)1.1
#define NEGATIVE 'a'
#define fromZERO int a
#define wrongCHOICE float a
#define fromNEGATIVE char a
//--------------------------------------------

using namespace std;
main()
{
	 float a,b;
	 int choice;
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
		 switch(choice)
		 {
				case 1:
                    cout<<"enter the values: ";
					cin>>a>>b;
					cout<<"sum is :"<<a+b;
					break;
				case 2:
                    cout<<"enter the values: ";
					cin>>a>>b;
					if((a-b)<0)
					throw NEGATIVE;
                	cout<<"subtraction is :"<<a-b;
					break;
				case 3:
                    cout<<"enter the values: ";
					cin>>a>>b;
                	cout<<"multiplication is :"<<a*b;
					break;
				case 4:
                    cout<<"enter the values: ";
					cin>>a>>b;
					if(!b)
					throw ZERO;
                	cout<<"divison is :"<<(float)a/b;
					break;
				case 5:
					return 1;
				default:
					throw (float)1;
		}
		cout<<endl<<endl;
	   }
	   catch(fromZERO)                      //for divison by zero
	   {
			cout<<"Exception: Denominator cant be zero\n\n";
       }
       catch(wrongCHOICE)                   // for wrong choice by user
	   {
			cout<<"Exception: Wrong Choice\n\n";
       }
	   catch(fromNEGATIVE)                   // if result of subtraction is zero
	   {
			cout<<"Exception: Result of subtraction is negative\n\n";
       }
	}while(1);
}
