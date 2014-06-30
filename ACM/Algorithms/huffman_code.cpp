/*
	Name: Huffman Code
	Copyright: no rights
	Author: Shivam Jindal
	Date: 11/11/13 10:55
	Description: refer to coremen or http://jqyhuffman.blogspot.in/
*/


#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
#include<queue>
using namespace std;

class node {

	public:
	node *lchild,*rchild;
	double freq;
	string code;
	string val;
	
	bool operator < (const node &temp) const {
	
		return this->freq > temp.freq;
	}
};

priority_queue<node> huffman;

node* huffman_code(int n) {
	
	for(int i=0;i<n-1;i++) {
		
		node *temp = new node;
		*temp = huffman.top();
		
		huffman.pop();
		
		node *temp2 = new node;
		*temp2 = huffman.top();
//		cout << temp->val <<  " " << temp2->val << endl;
		huffman.pop();
		
		node *parent = new node;
		parent->freq = temp->freq + temp2->freq;
		
		
		parent->lchild = temp;
		parent->rchild = temp2;
		
		huffman.push(*parent);
		
	}
	node *tmp = new node;
	*tmp = huffman.top();
	huffman.pop();
	return tmp;
}

void huffman_tree(node *root,string str) {
	
//	cout  << "tree...";
//	cout << str << endl;
//	cin.get();
//	cout << str << endl;
	if(root == NULL)
	return;
	else if(root->lchild == NULL && root->rchild == NULL) {
		
		root->code = str;
		cout << root->val << " " << root->code << endl;
		return;
	}
	else {
		
		huffman_tree(root->lchild,str.append("0"));	
		str.erase(str.end()-1);
		huffman_tree(root->rchild,str.append("1"));
		str.erase(str.end()-1);
		return;
	}
}

int main() {
	

	int n;
	cin >> n;
	
	double f;
	char a;
	
	for(int i=0;i<n;i++) {
		
		cin >> a >> f;
		node *temp = new node;
		temp->freq = f;
		temp->val = a;
		temp->lchild = temp->rchild = NULL;
		huffman.push(*temp);
	}
	
	node *root = huffman_code (n);
//	cout << root->lchild->val;
	huffman_tree(root,"");
}
