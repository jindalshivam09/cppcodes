//----------Program Name: Errno----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date: 9 April 2013------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<string.h>
#define MOD 1000000007
using namespace std;
main()
{
	cout<<errno;
	cout<<strerror(errno);
	ifstream infile("shiv123132am.txt");
	cout<<errno;
	cout<<strerror(errno);
	cin.get();
	return 0;
}
