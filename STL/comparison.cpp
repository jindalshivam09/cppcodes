#include <iostream>
#include<vector>
#include<functional>              
#include<algorithm>
using namespace std;
void print (int n) {
	cout << n << " " ;
}
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

	v==vec ? cout << "true " : cout << "false";
	cout << endl;
	v<vec ? cout << "true " : cout << "false";
	vector<int >::reverse_iterator r = v.rbegin();
	vector<int >::iterator i ;
	i=v.rend().base();
	cout << endl << *(i+1) << endl << *r;
	
}
