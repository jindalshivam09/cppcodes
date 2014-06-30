#include<iostream>
using namespace std;

void print(int *arr) {
	for(int &x : arr) 
	cout << x << " ";
}

main() {
	int arr[5];
	for(int i =0 ;i < 5 ; i++)
	arr[i]= i+1;
	print(arr);
}
