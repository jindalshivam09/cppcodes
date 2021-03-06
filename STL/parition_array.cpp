/*
	Name: Sum-subset problem
	Copyright: no rights
	Author: Shivam Jindal
	Date: 31/07/13 23:52
	Description: using DP n following top down approach in O(sum*n)
				 We can solve the problem in Pseudo-polynomial time using Dynamic programming. 
				 We create a boolean 2D table subset[][] and fill it in bottom up manner. 
				 The value of subset[i][j] will be true if there is a subset of set[0..j-1] with sum equal to i., otherwise false.
				 Finally, we return subset[sum][n]
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void input (vector<int> &set) {
	for(int &i : set)
	cin >> i;
}


int sum_subset (vector<int> set , int n , int sum ) {
	bool subset[sum+1][n+1];
	
	for(int i = 0 ; i <= n ; i++) 
	subset[0][i] = true;
	
	for(int i = 1 ; i <= sum ; i++)
	subset[i][0] = false;
	
	for(int i = 1 ; i <= sum ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			subset[i][j] = subset[i][j-1] ;
//			cout << subset[i][j] << " " << i << " " << set[j-1];
			if (i >= set[j-1] && !subset[i][j]) {
//				cout << "if ";
				subset[i][j] = subset[i-set[j-1]][j-1]; 
			}
		}
//		cout << endl;
	}
/*	for(int i = 0 ; i <= sum ; i ++) {
		for(int j = 0 ; j <= n ; j ++) 
		cout << subset[i][j] << " ";
		cout << endl;
	}	
*/
	for(int i = sum ; i >= 0 ; i++)
	if (subset[i][n])
	return i;
}
main () {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;	
		vector<int> set;
		set.resize(n);
		input(set);
		int sum = accumulate(set.begin() , set.end() ,0);
		int half_max_sum = sum_subset(set,n,sum/2);
		int other_half = sum - half_max_sum;
		cout << abs(half_max_sum - other_half) << endl;
	}
}
