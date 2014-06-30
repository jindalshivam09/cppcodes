#include<iostream>
#include<set>
using namespace std;
main() {
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(6);
	s.insert(2);
	set<int>::iterator i = s.begin ();
	for(int j=0;j<4;j++) {
		cout << *i << " ";
		i++;
	}
	
}
