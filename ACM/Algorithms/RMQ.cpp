/*
	Name: RMQ in n*sqrt(n)
	Copyright: no rights
	Author: Shivam Jindal
	Date: 21/08/13 14:15
	Description: file:///D:/pd/Algorithm%20Tutorials.htm
*/

#include<iostream>
#include<vector>
#include<list>
#include<limits>
#include<cmath>

using namespace std;

void rmq_preprocessing ( vector<int> &arr , vector<int> &pre) {
	
	int m;
	int r = sqrt(arr.size());
	for (int i = 0 ; i < arr.size() ; i += r ) {
		m = numeric_limits <int> :: max() ;
		for (int j = i ; j < i + r && j < arr.size() ; j ++) {		
			if (m > arr[j])
			m = arr[j];
		}		
		pre[i] = m ;
	}
}

int rmq (const vector<int> &arr, vector<int> &pre , int a,int b) {

	int m = numeric_limits<int>::max();
	int i = a , r = sqrt(arr.size());
	while( i %  r) {		
		if ( m > arr[i])
		m = arr[i];
		i++;
	}	
	for ( ; i <= b ; i += r) {
		if (m > pre[i])
			m = pre[i];
	}	
	for ( ; i <= b ; i ++) {			
		if (m > pre[i])
			m = pre[i];
	}
	return m ;	
}

int main() {
	
	int n;
	cin >> n;
	vector<int> arr(n) , pre(n);
	for (auto &i : arr)
		cin >> i;	
	rmq_preprocessing(arr,pre);
//----------------test cases to process rmq in 3*sqrt(n) -----------------------		
	int t;
	cin >> t;
	while(t--) {	
		int a,b;
		cin >> a >> b;
		cout << rmq(arr,pre,a,b) << endl;
	}	
}

