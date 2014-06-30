#include <iostream>
#include<vector>
#include<functional>        
#include<algorithm>
using namespace std;
void print (int n) {
	cout << n << " " ;
}
main() {
	int i=-34;
	try{
		vector<int> q(i);         // bad alloc exception as size of vector cant be negative
	}
	catch(...) {
		cout << "bad alloc exception" << endl;
	}
	
	vector<int> w(-i,11);       // all init with 11
	cout << w[0] << endl;
	
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	
	try{
		cout << v.at(10);
	}
	catch(...) {
		cout << "out of range exception \n";
	}
	cout << v.front() << " ";		//front() return refernce to first element
 	v.front() = 5;
	
	cout << v.front() << endl << v.back() << endl;
	
	for(vector<int>::const_iterator i=v.begin();i!=v.end();i++)
	cout << *i << " ";
}
