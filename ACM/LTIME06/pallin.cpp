/*
	Name: segment trees
	Copyright: no rights
	Author: Shivam Jindal
	Description: to solve queries in log n time use segment tree
*/

#include<bits/stdc++.h>
using namespace std;

// make a segment tree of logn height

struct node {
	
	char a;
	bool rev = false;
	vector<bool> freq(10);
} ;
void segment_tree(vector<int> &heap ,int q, const string &arr , int a ,int b) {

//	cout << node << " " << a << " " << b << endl;
	if(a==b) {
	
		heap[q].a = str[a];
		heap[q].freq[a-'a'] = 1;
	}
	else {

		segment_tree(heap,2*q,arr,a,(a+b)/2);
		segment_tree(heap,2*q+1,arr,(a+b)/2+1,b);
		
		for(int i=0;i<10;i++) {
			
			heap[q].freq[i] = heap[2*q].freq[i] + heap[2*q+1].freq[i];
		}			
	
	}
}


// return index of the min value of the required query
void query(const vector<int> &heap ,int q, const vector<int> &arr , int a , int b , int i , int j) {
	
	if (a > j || b < i)
		return ;
	if (a == i && b == j)	
		heap[q].rev = true;
	else {
	
		query(heap,2*q,arr,a,(a+b)/2,i,j);
		query(heap,2*q+1,arr,(a+b)/2+1,b,i,j);
		
		
	}
}

int main() {

	int n.m;
	cin >> n >> m;
	
	string str;
	cin >> str;
	
	int q = 1;
	vector<node> heap (2*pow(2,log(n)+1)+1);
	segment_tree(heap,q,str,0,str.size()-1);
	
	for(int i=0;i<m;i++) {

		int op,l,r;
		cin >> op >> l >> r;
		
		if(op == 1) {
			
			query(heap,1,str,0,n-1,l,r)
		}
	
//	cout << query(heap,node,arr,0,n-1,i,j);
	
}

