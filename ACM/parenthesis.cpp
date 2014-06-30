/*
	Name: To print all the combinations of the parenthesis
	Copyright: no rights
	Author: Shivam Jindal
	Date: 21/09/13 22:54
	Description: brute force approach O(2^n)
*/


#include<iostream>
#include<vector>
using namespace std;

int count;
void parenthesis(int i ,int n , int left,int right, vector<int> &brackets) {

	if(i==n && left == right) {
		
		for(int j=0;j<n;j++) {
		
			if(brackets[j] == 1) 		cout << "(";
			else						cout << ")";
		}
		cout << endl;
		count++;
		return;
	}
//	else if (i==n)		return;
	
	if(left < n/2) {
	
		brackets[i] = 1;
		parenthesis(i+1,n,left+1,right,brackets);
	}
		
	if (left > right) {
		
		brackets[i] = -1;
		parenthesis(i+1,n,left,right+1,brackets);
	}
}

int main() {

	int n;
	cin >> n;
	vector<int> brackets(n);
	parenthesis(0,n,0,0,brackets);	
	cout << count << endl;
}
