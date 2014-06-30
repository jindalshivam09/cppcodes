#include<iostream>
using namespace std;
main() {
	char s[]="shiv",c[]="dal";
	cout.width(8);
	cout.setf(ios::left);
	cout.fill('*');
	cout << s ;
	cout.width(6);
	cout << c;
}
