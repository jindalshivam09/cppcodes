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

	cout << v.max_size();
	cout << endl;
	cout << v.capacity() << endl;
	cout << boolalpha << v.empty() << endl;
	v.reserve(40);
	cout << v.capacity() << endl;
	//vector<char > c(v.max_size()-1);
	vector<char > d;
	cout << d.max_size();	
	vector<int > vec;
	/*vec.push_back(3);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);
*/
	/*v.swap(vec);   // or*/ swap(v,vec);
	cout << endl;
	for_each(vec.begin(),vec.end(),print);
	cout << endl;
	for_each(v.begin(),v.end(),print);
}
