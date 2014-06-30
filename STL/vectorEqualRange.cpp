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
	pair<vector<int>::iterator,vector<int>::iterator> p = equal_range(v.begin(),v.end(),key) ;   // equal_range will return pair 
																								// for first and one passed last occurence 
	cout << p.first - v.begin()  << " " << p.second - v.begin();         
	
}
