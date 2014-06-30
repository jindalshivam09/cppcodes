#include<iostream>
#include<fstream>
using namespace std;
main()
{

	int t;
	fstream file("SJ",ios::in);
	if(!file)
	cout<<"shivam ";
	int pos=file.tellg();
	cout<<pos<<endl;
	file.seekg(10);
	file<<"shivam";
	char ch='a';
	file<<ch;
	file.putback(ch);
	ios_base::iostate flag=file.rdstate();
	if(flag==ios_base::badbit)
	cout<<"badbit";
	if(flag==ios_base::failbit)
	cout<<"failbit";
	cout<<flag;
	
	
	
	cin.get();
}
