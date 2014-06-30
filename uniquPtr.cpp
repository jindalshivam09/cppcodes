#include<iostream>
#include<ostream>
#include<memory>
using namespace std;
main() {
	unique_ptr<int> up(new int(3));
	cout << *up << endl;
}
