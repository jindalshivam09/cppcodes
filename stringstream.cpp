#include<iostream>
#include<sstream>
#include<conio.h>
using namespace std;
string compose (int n,const string &cs)
{
     char *str[3];
     str[1]="shivam jindal";
     ostringstream ost;
     istringstream ist;
     string input(str[1]);
     ist>>input;
     ost<<input;
     cout<<"hey";
     ost<<"("<<str[1]<<" ) "<<cs<<" "<<input;
	 cout<<"bie.. ";
	 return ost.str();
}
main()
{
	int n;
	string cs="hey ...";
	cout<<"shivam";
	string str=compose(3,"nit kurukshetra");
	cout<<str;
	getch();
	
}
