/*
	Name: A1
	Copyright: no rights 
	Author: Shivam Jindal
	Date: 31/07/13 01:53
	Description: 
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
typedef vector < int >  arr;
////////////////////////////////////////////////////////////////////////////////

void input (arr &notes , int n ) {
	for(auto i = 0 ; i < n ; i ++)
	cin >> notes[i];
}

void output (arr a) {
	for (auto i : a)
	cout << i << " ";
	cout << endl;
}

void sumup (arr notes , arr &sum , int  n) {
	sum[0] = notes[0];
	for (int i = 1 ; i < n ; i ++) {
		sum[i] = sum[i-1] + notes[i];
	}
}

void difference (arr sum , arr &diff , int n , int m) {
	int i = 0;
	while ( m - sum[n-i-1] <= 0) {
		diff.push_back( m - sum[n-i-1] );
		i++;
	}
}

bool willPay (arr &notes , int n , int m)  {
	arr sum(n);
	arr diff;
	int key;
	sumup (notes , sum , n);
	output(sum);
	difference (sum , diff , n ,m);
	output(diff);
	for ( arr::iterator i = diff.begin() ; i != diff.end() ; i++ ) {
		key = -1 * (*i);
		cout << key << endl;
		if ( binary_search(sum.begin(),sum.end(),key) || key == 0)
		return true;
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////

main () {
	int test ; 
	cin >> test ;
	while(test -- ) {
		int n , m;
		cin >> n >> m;
		arr notes(n);
		input (notes , n);
//		output(notes);
		sort ( notes.begin() , notes.end() );
		willPay (notes , n , m) ? cout << "Yes" : cout << "No";
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
