#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
main()
{
	cout<<"shivam";
	ofstream file;
	ifstream input;
	cout<<"nit";
	file.open("shivam.txt",ios_base::out);
	file.seekp(10);
	file<<"this is use of seekp";
	file.seekp(-9,ios_base::end);
	file<<"at the end"<<endl;
	cout<<endl;
	int p=file.tellp();
	cout << p;
	
}
