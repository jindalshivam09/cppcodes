/*
	Name: Finding second smallest in n + log(n) - 2 comparisons
	Copyright: no rights
	Author: Shivam Jindal
	Date: 31/07/13 16:42
	Description: 
*/


#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
#define INT_MIN 999
typedef vector <int>  Array;
///////////////////////////////////////////////////////////////////////////////

void input (Array &arr , int n) {
	for (int i = 0 ; i < n ; i ++) {
		cin >> arr[i];
	}
}

///////////////////////////////////////////////////////////////////////////////

int cal_min_right (Array arr , int p , int q) {
	if ( p == q) {
		return arr[p];
	}
//	cout << arr[p] << " " << arr[q] << " " << p << " " << q << endl;
//	cin.get();
	int m1 = cal_min_right (arr , p , (p+q)/2);
	int m2 = cal_min_right (arr , (p+q)/2+1 , q);
//	cout << m1 << " " <<  m2 << endl;
	if (m1 < m2)
	return m1;
	return m2;
}


int second_smallest (Array arr) {
	int min = arr[0];
	int pre ;
	int min_index ; 
	//-------to calculate smallest element first in n-1 comparisons
	for (int i = 1 ; i < arr.size() ; i ++) {
		if (min > arr[i]) {
			pre = min;
			min_index = i;
			min = arr[i] ;
		}
	}
//	cout << pre << " " << min << endl;
	int min_right = cal_min_right (arr , min_index+1 , arr.size()-1);		// min_right in log(n)-1
	if (pre > min_right)
	return min_right;
	return pre;
}

///////////////////////////////////////////////////////////////////////////////////
main () {
	int n;
	cin >> n;
	Array arr ;
	arr.resize (n);
	input (arr , n);
	int ans = second_smallest (arr);
	cout << ans ;
}
