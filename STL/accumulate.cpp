#include <iostream>
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
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	
	cout << accumulate(v.begin(),v.end(),0);	
	
}
