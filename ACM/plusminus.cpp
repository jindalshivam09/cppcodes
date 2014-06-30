/*
	Name: Put pos n neg elements of array a;ternatively
	Copyright: no rights
	Author: Shivam Jindal
	Date: 28/07/13 22:36
	Description: naive method O(n^2)
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> Array;


void copy(Array &arr, int from,int to) {
	arr[to] = arr[from];
}
////////////////////////////////////////////////////////////////////////////////

//---------------to put positive n negative elements of array alternatively------
void separate_plus_minus(Array &arr) {
	int element, pre = 1;
	for(int i = 0 ; i < arr.size() ; i ++) {
		element = arr[i];
		if(element >= 0)
		continue;
		else {
			for(int j = i ; j > pre ; j--) {
				copy(arr , j-1 , j);
			}
			arr[pre] = element;
			pre += 2;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////

//-----------------------input n output-----------------------------------------

//---------input the array from user-------------------------------------------
void scan(int &a) {
	cin >> a;
}
///////////////////////////////////////////////////////////////////////////////

//-----------output the array--------------------------------------------------
void print(int a){
	cout << a << " ";
}
///////////////////////////////////////////////////////////////////////////////

void input(Array &arr) {
		for_each(arr.begin() , arr.end() , scan);
}

void output(Array &arr) {
		for_each(arr.begin() , arr.end() , print);
}

////////////////////////////////////////////////////////////////////////////////

main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		Array arr(n);
//		for_each(arr.begin() , arr.end() , print);
		input(arr);
		separate_plus_minus(arr);
		output(arr);
	}
}


