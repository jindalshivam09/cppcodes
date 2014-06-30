#include<iostream>
using namespace std;
int add(long a,long b)
{
	cout<<"t5hat5s me add";
	return a+b;
}
float add(long a,int b)
{
	cout<<"long+int";
	return a+b;
}
float add(int a,int b)
{
    cout<<"int";
	return a+b;
}
/*double add(int a,long b)
{
	cout<<"int+long";
	return a+b;
}*/
float add(float a,double b)
{
	cout<<"flaot5";
	return a+b;

}
float add(double a,double b)
{
	cout<<"double";
	return a+b;
}
float add(float a,float b)
{
	return a+b;
}
main()
{
	int i=1;
	 long j=1;
	double a=1.1;
	float b=2.1;
	cout<<add(i,j)<<endl;

	cout<<add(a,b);
	cin.get();
}
