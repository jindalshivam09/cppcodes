#include<iostream>
#include<bitset>
using namespace std;
main() {
	bitset<8> b(string("10011"));
	cout << b.to_ulong() << endl;
	
	cout << b.to_string() << endl; 
	
	cout << boolalpha << b.any();
	cout << endl;
	bitset<8> v = b <<1;
	cout << v << endl;
	//b <<= 1;
	cout << b << endl;
	b=b|v;
	cout << b << endl;
}
