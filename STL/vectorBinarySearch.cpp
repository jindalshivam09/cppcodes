#include <iostream>
#include<vector>
#include<functional>              // to use greater string
#include<algorithm>
using namespace std;
main() {
	vector<int> v;
	v.push_back(12);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	
	sort(v.begin() , v.end());
	int key=12;
	cout  << boolalpha << binary_search(v.begin(),v.end(),key);        
}
