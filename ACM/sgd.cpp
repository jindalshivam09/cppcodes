#include<iostream>
#include<string>
using namespace std;

int main() {
	
	string str = "abc";
	auto i = &str;
	cout << *i;
}
