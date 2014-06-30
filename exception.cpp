#include<iostream>
#include<stdlib.h>
#define TAKEIP cout<<"\nEnetr the two operands respectively(separated\
by space):";cin>>a>>b;
using namespace std;

int main()
{
	
	int choice,a,b,c;
	
while(1)
{
cout<<"\n\n\nSelect an operation:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.\
Division\n5.Exit\n";
cin>>choice;


try
{

switch(choice)
{
case 1: TAKEIP;
		c=a+b;break;
case 2:TAKEIP;
		c=a-b;
		if(c<0)
		throw 3;
		break;	
case 3:TAKEIP;
		c=a*b;break;
case 4:TAKEIP;
		if(b==0) throw 2;
		c=a/b;
		break;	
case 5:exit(0);	
default:throw 1;
}
}
catch(int x)
{
	if(x==1)
	cout<<"\nWrong choice";
	
	else if(x==2)
	cout<<"\nDivide by zero error";
	
	else
	cout<<"\nSubtraction resulted in negative value";
	
	continue;
	
}

cout<<"\nAnswer is "<<c;

}
	
return 0;	
}
