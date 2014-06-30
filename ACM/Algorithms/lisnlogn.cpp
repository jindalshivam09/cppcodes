/*
	Name: LIS nlogn
	Copyright: no rights
	Author: Shivam Jindal
	Date: 21/08/13 00:36
	Description: maintaining only a single array where ith element contain the 
				 last element of the longest possible subsequence of i length where
				 i <= j < array.size() , j is length of array traversed.
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 9999
int n ;
vector<int> arr;

int LIS () {
	map<int,int> length ;
	int count = 0;
	for ( int i = 0 ; i < n ; i ++ ) {
		int val = arr[i] ;
		map<int,int>::iterator itr = length.lower_bound(val);
		if ( itr == length.end() ) {
			length[val] = ++count ;
		}
		else {
			int len = itr->second;
			length.erase(itr);
			length[val] = len ;
		}
	}
	return count ;
}

int main() {			
	cin >> n;
	arr.resize(n);
	for (int i=0;i<n;i++)			
		cin >> arr[i];
	cout << LIS() << endl;	

}
