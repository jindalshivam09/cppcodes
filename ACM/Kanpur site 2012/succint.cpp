/*
	Name: Succint Randomness
	Copyright: 
	Author: 
	Date: 05/09/13 18:16
	Description: 
*/

#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

bool is_valid (const string &str , int n) {

	int val = 0;
	
	cout << n << endl;
	//bool bit = str[str.size()];
	vector<bool> set (n);
	int count = 0;
	
	for (int i = 1 ; i <= n ; i ++) {
	
		val += (val * 2 + str[str.size()-i]-48);
			count++;
			set[val] = true;
		
		cout << count << "1 " << val << endl;
	}
	
	for (int i = str.size()-n-1 ; i >= 0 ; i -- ) {
	
		val += (val*2 + str[i]-48);
		val -= (str[i+n]-48)*pow(2,n);
	
		cout << count << "2 " << val << endl;
		if (!set[val]) {
			count++;
			set[val] = true;
		}
		else	return false;
	}
	
	int j = n-1;
	for (int i = str.size()-1 ; i > str.size()-n ; i --) {
	
		val += val*2 + str[i]-48 ;
		val -= (str[j]-48)*pow(2,n);
		j--;
		
		cout << count << "2 " << val << endl;
		if (!set[val]) {
			count++;
			set[val] = true;
		}
		else	return false;
//		cout << count << "3 ";
	}
	
	if (count == str.size() )
	return true;
	return false;
}

bool is_exact (int n) {

//	cout << n;
	while (!(n%2) )
	n /= 2;
	
	if (n==1)	return true;
	else 		return false;
}

int main() {

	int t;
	string str;
	cin >> t;
	
	while(t--) {
	
//		cout << "f";
		cin >> str;
	 	int len =  str.size();
	 	
	 	if (is_exact (str.size())) {

			int n = log(str.size())/log(2);			
			bool flag = is_valid(str,n);
			if (flag)					cout << "valid" << endl;
			else						cout << "invalid" << endl;
		}
		else {
			
			cout << "invalid" << endl;
		}
//		cout << "wq";
	}
}

