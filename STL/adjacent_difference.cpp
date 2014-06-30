#include<iostream>
#include<numeric>
#include<vector>
#include<functional>            
#include<algorithm>
using namespace std;
void print (int n) {
	cout << n << " ";
}
main() {
	vector<int> v;
	v.push_back(1000);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	
	cout << *(adjacent_difference(v.begin(),v.end(),v.begin())-7);
	cout << endl;
	for_each(v.begin(),v.end(),print);
	
	
}
