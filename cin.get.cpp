#include<iostream>
#include<sstream>
using namespace std;
main()
{
	char ch;
	while(cin.get(ch))    //get by default red one character from istream
	cout.put(ch);
	cout<<cin.gcount();
	cout.flush();
	cin.sync();
	cin.get();
	
}
