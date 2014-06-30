#include<iostream>
using namespace std;
using namespace std::rel_ops;
main() {
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	vector<int > vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);

	if(vec>v)
	cout << "true ";
	else
	cout << "false ";
}
