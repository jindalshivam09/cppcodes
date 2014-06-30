#include<iostream>
using namespace std;
void func(int &a) {
	cout << a;
}
main() {
	int c=4,d=4;
	//func(c+d);
	string q="hi";
	string w="bie";
 	string&s=q+w;
	cout << s;
}
