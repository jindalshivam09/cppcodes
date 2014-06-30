#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
void print (int n) {
	cout << n << " ";
}
main() {
	list<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	list<int > vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);

 	
 	
 	list<int>::iterator i=v.begin();
 	v.splice(i,vec,vec.begin());
 	
 	for_each(v.begin(),v.end(),print);
 	cout << endl;
 	
 	for_each(vec.begin(),vec.end(),print);
 	cout << endl;
 	
 	v.merge(vec);
 	
 	v.sort();
 	vec.sort();
 	
 	for_each(v.begin(),v.end(),print);
 	cout << endl;
 	
 	for_each(vec.begin(),vec.end(),print);
 	cout << endl;
 	
}
