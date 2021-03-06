#include <iostream>
#include<vector>
#include<functional>            
#include<algorithm>
using namespace std;
void print (int n) {
	cout << n << " ";
}
main() {
	vector<int> v;
	v.push_back(41);
	v.push_back(23);
	v.push_back(23);
	v.push_back(4);
	v.push_back(45);
	v.push_back(24);
	v.push_back(12);
	v.push_back(135);
	v.push_back(19);
	
	for_each(v.begin(),v.end(),print);
	cout << endl;

	partial_sort(v.begin(),v.begin()+7,v.end());   // to sort only first 6 elements
	
	for_each(v.begin(),v.end(),print);
	
	cout << endl;
	sort(v.begin(),v.end());
	
	for_each(v.begin(),v.end(),print);
	
	
	
}
