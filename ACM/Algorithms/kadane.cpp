/*
	Name: Kadane Algo
	Copyright: no rights
	Author: Shivam Jindal
	Date: 30/07/13 23:57
	Description: Maximum sub array problem O(n)
*/
#include<iostream>
#include<vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
#define INT_MAX -999
typedef vector<int> array;
////////////////////////////////////////////////////////////////////////////////

void input (array &arr , int n) {
	for(int i = 0 ; i < n ; i ++) {
		cin >> arr[i];
	}
}
////////////////////////////////////////////////////////////////////////////////

int kadane (array arr , int n ) {
	int max_till_yet = arr[0];
	int sum = arr[0];
	
	for (int i = 1 ; i < n ; i ++)  {
		sum += arr[i];
		max_till_yet = max ( max_till_yet , sum);			
		if(sum < 0)
			sum = 0;
	}
	return max_till_yet;	
}

////////////////////////////////////////////////////////////////////////////////

main() {
	int n;
	cin >> n;
	array arr(n); 
	input (arr , n);	
	cout << kadane (arr , n);
}
