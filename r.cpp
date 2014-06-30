#include<iostream>
using namespace std;

char func(char n) {

	return n;
}

int main() {

	const char a = '3';
//	cin >> a;
	char n;
	cin >> n;
	const char b = func(n);
	cout << a << b;
}

