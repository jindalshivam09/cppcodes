//under construction----------------------------------------------------------


/*
	Name: Huffman codes
	Copyright: no rights
	Author: Shivam Jindal
	Date: 02/09/13 18:08
	Description: using full binary tree and greedy approach on the basis of the frequency of
				 each character in the file to be coded that is the character with highest freq 
				 is given min length and with least freq one is given max length 
				 we also have to take care that no prefix matches so as to remove ambiguity. 
*/
{/*header files*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define alpha first
#define freq second
#define NIL 0
}

typedef struct n {

	struct n *left;
	struct n *right;
	int freq;
	char alpha;
} node;

void swap (vector<pair<char,int> > &input , int i , int temp) {

    pair<char,int> tmp = input[temp];
	input[temp] = input[i];
	input[i] = tmp;
}

void heapify (vector<pair<char,int> > &input , int i) {

	int left = 2 * i ;
	int right = 2 * i + 1;
	int temp;

//	cout << input[i].second << " " << input[left].second << " " << input[right].second << endl;	

	if ( input[i].freq > input[left].freq && left < input.size())				
		temp = left;
	else 															
		temp = i;
	
	if (input[temp].freq > input[right].freq && right < input.size()) 		
		temp = right;
 	
	if(temp != i) {
			
//		cout << temp << " " << i << left << " " << right << endl;												
		swap (input , i , temp);
		heapify (input , temp);
	}
	
}

void min_heap (vector<pair<char,int> > &input) {

	for (int i = (input.size()-1)/2 ; i >= 1 ; i --) {
		
//		cout << i << " ";
		heapify (input,i);
	}
}

void print (const pair <char,int> &a) {

	cout << a.first << " " << a.second << endl;
}

pair<char,int> extract_min (vector<pair<char,int> > &input) {

	pair<char,int> m = input[1];
	swap (input,1,input.size()-1);
	input.pop_back();
	cout << input.size();
	heapify(input,1);
}

void insert(vector<pair<char,int> > &input , pair<char,int> p) {
	
	input.push_back(p);
	int i = input.size()-1;
	int parent  = (input.size()-1)/2;
	
	while (parent > 0) {
	
		if (input[parent] > input[i])
			swap (input,i,parent);
		else 
			break;
	}
}

void huffman_code (vector<pair<char,int> > &input) {}		// this part is under constructio

	pair<char,int> x = extract_min (input);
	pair<char,int> y = extract_min (input);
	pair<char,int> z = make_pair (NIL,x.freq+y.freq);
	insert(input,z);

}

void copy_heap (const vector<pair<char,int> > &input , node *codes) {}	//also under constructio

	node *temp;
	
	for (int i = 1 ; i < input.size() ; i ++) {
	
			temp = new node;
			temp->freq = input[i].freq;
			temp->alpha = input[i].alpha;
			temp->left = NULL;
			temp->right = NULL;
			
			if (!codes) {
				codes = temp;
			}
	//		else 
	}
}

int main () {

	int n;
	cin >> n;
	
	vector<pair<char,int> >  input (n+1);
	int b;
	char a;
	node *codes = NULL;
	
	for (int i = 1 ; i <= n ; i ++) {
	
		cin >> a >> b;
		input[i] = make_pair (a,b);
	}
	
	min_heap (input);
//	copy_heap (input , codes);
	
//	for_each (input.begin() , input.end() , print);


//	huffman_code (input);

}
