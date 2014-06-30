#include<iostream>
#include<map>
#include<string>
using namespace std;
void foo (const map <int ,string> &m) {
	//cout << m[3];
	map <int ,string>::const_iterator i = m.find(3);
	if (i == m.end()) {
		cout << "no match found" << endl;
	}
	else
	cout << i->second << endl ;
}
main() {
	map<int ,string> m;
	m[13] = "three";
	//foo( m );
	m[5] = "five ";
	m[4] = "shivam";
	
	for (map<int ,string>::iterator i = m.begin(); i!=m.end(); i++)
	cout << i->first << " " << i->second << endl;
	
	
}
