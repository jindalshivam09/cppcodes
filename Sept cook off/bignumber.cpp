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

#define MAX 1000000
#define MOD 1000000007


string number;
vector<int> values(MAX);
vector<int> heap (2*pow(2,log(MAX)+1)+1);			// this is heap for the segment tree
vector<bool> is_flipped(2*pow(2,log(MAX)+1)+1);		// to maintain that whether child nodes are to be flipped
vector<int> cal_power(MAX);

// make a segment tree of logn height
void segment_tree(int node , int a ,int b) {

//	cout << node << " " << a << " " << b << endl;
	if(a==b) {
	
		heap[node] = (number[a]-48)*values[a];
	}
	else {

		segment_tree(2*node,a,(a+b)/2);
		segment_tree(2*node+1,(a+b)/2+1,b);
		
		heap[node] = heap[node*2] + heap[node*2+1];
		
	}
}


void query(int node,  int a , int b , int i , int j) {
	
	cout << a << " " << b << " " << i << " " << j << endl;
	if (a > j || b < i) {
		cout << "returning..\n";
		return ;
	}
	if (a == i && b == j ) {

		cout << heap[node] << " ";	
		if(i)		heap[node] = (cal_power[j]-cal_power[i-1]) - heap[node];
		else		heap[node] = cal_power[j] - heap[node];
		
		if (is_flipped[node]) 	is_flipped[node] = false;
		else					is_flipped[node] = true;	
		cout << "range found..\n" << heap[node] << " " << is_flipped[node] << endl;
	}
	
	else if (a==b) {
	
		cout << heap[node] << " ";
		if(heap[node])		heap[node] = 0;	
		else				heap[node] = values[a];
		
		if (is_flipped[node]) 	is_flipped[node] = false;
		else					is_flipped[node] = true;
		cout << "node...\n" << heap[node] << " " << is_flipped[node] << endl ;
	}
	else {
		
		if (is_flipped[node]) {
		
			is_flipped[node*2] = is_flipped[node*2]^true;
			is_flipped[node*2+1] = is_flipped[node*2+1]^true;
		}
		query(2*node,a,(a+b)/2,i,j);
		query(2*node+1,(a+b)/2+1,b,i,j);
		
		cout << heap[node] << " ";
		heap[node] = (heap[node*2] + heap[node*2+1])%MOD ;
		cout << "else ...\n" << heap[node] << " " << is_flipped[node] << endl;
	}
}

int main() {

	
	cin >> number;
	int count=0;
	int temp=1;
	for(int i=number.size()-1; i >=0 ; i--) {
	
		if (i != number.size()-1) {
		
			temp = (temp*2)%MOD;
		}
		if(count)		cal_power[count] = (cal_power[count-1] + temp)%MOD ;
		else 			cal_power[count] = temp;
		
		values[count++] = temp;
	}
	
	int node = 1;
	segment_tree(node,0,number.size()-1);
	
	int m,l,r;
	cin >> m;
	while(m--) {
		cin >> l >> r; 
		query(node,0,number.size()-1,number.size()-r,number.size()-l);
		cout << heap[1] << endl;
	}
}

