#include<iostream>
#include<fstream>
using namespace std;
main()
{
    cout<<"enter name of the file : ";
	char name[10];
	cin>>name;

	fstream file;
	file.open(name,ios::out);
	char ch='a',CH='A';
	if(!file)
	cerr<<"error in opening file";
	
	//file.open(name,ios_base::in);
	for(int i=0;i<26;i++)
	file<<(ch++)<<" ";
	file<<endl;
	
	for(int i=0;i<26;i++)
	file<<CH++<<" ";
	file<<endl;
	
	ch='a';
	CH='A';
	
	for(int i=0;i<26;i++)
	{
		file<<ch++<<" :"<<ch+i<<" "<<CH++<<" :"<<ch-32+i;      //using rule that characters changed into integers sfter any mathematical operation
		file<<endl;
    }
    
    ios_base::iostate s=file.rdstate();
	if(s==ios_base::failbit)
	cout<<"failure";
	cin.sync();
	cin.get();
	
	
}
