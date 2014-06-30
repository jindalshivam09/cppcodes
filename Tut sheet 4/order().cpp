#include<iostream>
using namespace std;
#include<conio.h>
void order(int *a,int *b)
{
	if((*a)>(*b))
	{
		cout<<*a<<*b<<endl;

       (*b)^=(*a)^=(*b)^=(*a);
 	   cout<<*a<<*b<<endl;
	}
}
main()
{
	int a,b;
	cin>>a>>b;
	order(&a,&b);
	cout<<a<<endl<<b;
	getch();
}
