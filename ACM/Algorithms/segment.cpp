
/*
	Name: segment trees
	Copyright: no rights
	Author: Shivam Jindal
	Date: 16/09/13 23:33
	Description: to solve queries in log n time use segment tree
*/

#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

void segment_tree(vector<int> &heap ,int node, const vector<int> &arr , int a ,int b) {

//	cout << node << " " << a << " " << b << endl;
	if(a==b) {
	
		heap[node] = arr[b];
	}
	else {

		segment_tree(heap,2*node,arr,a,(a+b)/2);
		segment_tree(heap,2*node+1,arr,(a+b)/2+1,b);
		
		if(heap[2*node] > heap[2*node+1])	
			heap[node] = heap[2*node+1];
		else
			heap[node] = heap[2*node];
	}
}


int query(const vector<int> &heap ,int node, const vector<int> &arr , int a , int b , int i , int j) {
	
	if (a > j || b < i)
		return -1;
	if (a >= i && b <= j)	
		return heap[node];
	else {
	
		int p = query(heap,2*node,arr,a,(a+b)/2,i,j);
		int q = query(heap,2*node+1,arr,(a+b)/2+1,b,i,j);
		if(p==-1 )
			return q;
		else if(q==-1)
			return p;
		else if (p < q)
			return p;
		else 
			return q;
	}
}

int main() {

	int n,q;
	cin >> n >> q;;
	vector<int> arr(n);
	
	for(int i=0;i<n;i++)
	cin >> arr[i];	
	
	int node = 1;
	vector<int> heap (2*pow(2,log(n)+1)+1);
	segment_tree(heap,node,arr,0,n-1);
	while(q--) {

		int i,j;
		cin >> i >> j;
		cout << query(heap,node,arr,0,n-1,i,j) << endl;
	}
	
}

