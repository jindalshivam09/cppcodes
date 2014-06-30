#include<iostream>
#include<fstream>
using namespace std;
main()
{
	ifstream file;
	file.open("shivam");
	if(!file)
	perror("");
	char ch;
	int count=0,countW=0;
	while(!file.eof())
	{
		  ch=file.get();
		  if(ch=='\n')
		  count++;
		  if(isspace(ch))
		  countW++;
		  cout<<ch;
	}
	cout<<endl<<"newline characters: "<<count<<endl;
	cout<<"blank: "<<countW<<endl;
	cin.get();

}
