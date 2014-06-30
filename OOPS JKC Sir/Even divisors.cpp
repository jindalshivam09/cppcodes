#include<iostream>
using namespace std;
main()
{
		int number;
		char choice;
		do
		{
				cout<<"Enter any positive number: ";
				cin>>number;
				if(number<=0)
				{
						cerr<<"Number must be greater than zero";
						cout<<endl;
				}
				else
				{
						cout<<"Even divisors"<<endl;
						for(int i=number/2;i>1;i--)
						if(!(number%i)&&!(i%2))
						cout<<i<<endl;
				}
				cout<<"Press y to continue or n to exit: ";
				cin>>choice;
		}while(choice=='y'||choice=='Y');
}
