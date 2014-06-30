#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int a=100,b=100;
main() {
	//srand(unsigned(time(NULL)));
	ofstream out("test.txt");
//	out << a << " " << b << endl;
	for(int i=0;i<a;i++) {
		for(int j=0;j<b;j++)
		out << rand()%2;
	//	out << '\0';
		out << endl;
	}
}
