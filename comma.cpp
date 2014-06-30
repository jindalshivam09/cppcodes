#include<iostream>
using namespace std;
int a=41;
int func() {
	
	return 5,a++;
}
main() {
	cout<<func();
	cout<< " " <<a;
}
