#include <iostream>
#include<vector>
#include<string>
#include<functional>              // to use greater string
#include<algorithm>
using namespace std;
main() {
	vector<string> v;

	v.push_back("pen");
	v.push_back("pencil");
	v.push_back("car");
	
	sort(v.begin(),v.end(),
	[](const string &left,const string &right) {
		return left.size() < right.size() ;
	});                        //greater<int> to sort vector in reverse order
	for(vector<string>::iterator i=v.begin(); i!=v.end(); ++i)
	cout << *i <<endl;
}
