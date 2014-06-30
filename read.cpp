#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
main()
{
	string buf="shivam jindal";
	char str[10];
	cout<<"\n";
	cin.get(str,20,'\n');
    char ch;
    int n=cin.gcount();
    //cout<<"n="<<n<<" ";
//	cin.ignore(ch);
	cout<<n<<str;
//	cout<<"   " <<"shivam"<<ch<<"shivam";
	cout.flush();
	cin.get();
	while(1);
}
