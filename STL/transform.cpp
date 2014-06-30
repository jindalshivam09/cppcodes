#include<iostream>
#include<numeric>
#include<vector>
#include<functional>            
#include<algorithm>
using namespace std;
void print (int n) {
	cout << n << " ";
}
int operation (int n) {
	return n*n;
}
main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	
	vector<int> a;
	transform(v.begin(),v.end(),back_inserter(a),operation);
	
	for_each(a.begin(),a.end(),print);
	cout << endl ;
	
	for_each(v.begin(),v.end(),print);
	
	
	
}
