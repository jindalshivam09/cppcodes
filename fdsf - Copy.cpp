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
	file.open("shivam",ios_base::out);
	file.flush();
	file.seekp(10);
	file<<"this is use of seekp";
	file.seekp(-19,ios_base::end);
	file<<"at the end of the stream";
	int a=file.tellp();
	cout<<a;
	getch();
	
}
