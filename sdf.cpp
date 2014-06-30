#include<iostream>
using namespace std;
void func (int arr[]) {
	arr[0]=2;
}
main() {
	int arr[]={1,34,5};
	func(arr);+
	cout << arr[0];
}
