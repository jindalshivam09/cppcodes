/*
	Name: Binary index tree
	Copyright: no rights
	Author: Shivam Jindal
	Date: 17/09/13 12:31
	Description: D:\Algorithms/BIT
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int last_digit(int i) {

	return i&-i;
}

void cal_tree(vector<int> &tree , const vector<int> &cum_freq) {

	int r ;
	
	for(int i=1;i<tree.size();i++) {
	
		r = last_digit(i);
		tree[i] = cum_freq[i] - cum_freq[i-r];
	}
}

int cal_cum_freq(const vector<int> &tree ,int idx) {

	int sum = 0;
	while(idx>0) {
	
		sum += tree[idx];
		idx -= (idx&-idx);
	}
	return sum;
} 

void change_freq(vector<int> &tree,int idx,int freq) {

	while(idx < tree.size()) {
		
		tree[idx] += freq;
		idx += (idx&-idx);
	}
}

int cal_index(const vector<int> &tree , int val) {

	int bitmask = pow(2,sqrt(tree.size()-1));
//	cout << bitmask << endl;
	int idx=0,tidx;
	while(bitmask && idx < tree.size()-1) {
	
		tidx = idx + bitmask;
		if(tree[tidx] == val)
			return tidx;
		else if (val > tree[idx]){
		
			val -= tree[idx];
			idx = tidx;
		}
		bitmask >>= 1;
	}
	if(!val)		return idx;
	else		return -1;
}

int main() {

	int n;
	cout << "total elements: ";
	cin >> n; 
	vector<int> freq(n+1) ;		//input of the frequencies for the BIT
	vector<int> cum_freq(n+1);	// to calculate the cumulative frequency of the input
	vector<int>	tree(n+1);		// this is the key for the BIT it stores the frequncies sun on the basis of bit ie from i+r-1 to i where r = 2^k , k is the
								//  is the first set bit from right of the index
	
	cout << "elements: ";
	for(int i=1;i<=n;i++) {
		cin >> freq[i];
		cum_freq[i] = freq[i] + cum_freq[i-1];
	}
	
	cal_tree(tree,cum_freq);
	
//	for(int i=1;i<=n;i++) 
//	cout << tree[i] << " ";
	int idx;
	cout << "index to calculate the cumulative frequency: ";
	cin >> idx;
	
	cout << cal_cum_freq(tree,idx) << endl;

	cout << "enter the index with its new freq : ";
	int val;
	cin >> idx >> val;
	
	change_freq(tree,idx,val-freq[idx]);
	
	for(int i=1;i<=n;i++) 
	cout << tree[i] << " ";
	cout << endl;
	
	cout << "enter the cum freq for which you find the index: ";
	cin >> val;
	
	cout << cal_index(tree,val);
}
