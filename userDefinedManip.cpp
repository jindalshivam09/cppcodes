#include<iostream>
#include<iomanip>
using namespace std;
ostream & setprecision (ostream & cout) {
	cout.precision(20);
	cout.setf(ios::showpos|ios::showpoint);-
	cout.width(10);
	cout.fill('*');
	return cout;
}
main() {
	cout<<setprecision<<"shivam" << 3.443;
}
