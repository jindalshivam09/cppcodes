#include<iostream>
using namespace std;
main()
{
/*	fstream file;
	string name;
	cin>>name;
	file.open(name.c_str(),ios::)*/
	char c,d;
	while(1)
	{
		c=cin.get();
		cout<<"1 "<<c;
		cout<<endl;
		cin.sync();
		cout<<endl;
		d=cin.get();
		cout<<endl;
		cout<<"2 "<<c;
		cout<<endl;
        cin.sync();
		c=cin.get();
		cout<<endl;
		cout<<"3 "<<c;
		cout<<endl;
		cin.sync();
		cout<<endl;
		cin.putback(d);
		cout<<endl;
		c=cin.get();
		cout<<endl;
		cout<<"4 "<<c;
		cout<<endl;
		cin.sync();
	}
}
