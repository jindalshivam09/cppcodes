/*
	Name: Pouring Water
	Copyright: no rights
	Author: Shivam Jindal
	Date: 30/07/13 21:17
	Description: Using Euclid's Division Lemma
*/


#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////

int ecd (int a , int b ,int c ) {
	int steps = 2;
	int pre;
	while(b-a != c && a >= 0) {
//		cout << a <<  " " << b << " " << c << endl;
//		cin.get();
		steps += 3;
		//if(b - a == c)	return steps;
		 		//	steps ++;
		pre = a;
		a = a - b % a;
		if(a == pre)
		return -1;
	}
	if(a < 0)
	return -1;
	return steps;
}
///////////////////////////////////////////////////////////////////////////////

main() {
	int test;
	cin >> test;
	while(test--) {
		int a,b,c;
		cin >> a >> b >> c;
		if (a > b) {
			a = a + b;
			b = a - b;
			a = a - b;
		}
		if ( c > a && c > b)	cout << -1;
		if ( c == a || c == b)	cout << 1;
		else					cout << ecd(a,b,c);
		cout <<  endl;
	}
}
