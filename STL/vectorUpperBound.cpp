#include <iostream>
#include<vector>
#include<functional>             
#include<algorithm>
using namespace std;
main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(12);
	v.push_back(13);
	v.push_back(19);

	
	
	int key=4;
	vector<int>::iterator i = upper_bound(v.begin(),v.end(),key);
	cout  << upper_bound(v.begin(),v.end(),key) - v.begin();         // this will return one passed last occurence of key
	
}
