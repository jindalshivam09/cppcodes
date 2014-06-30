/*
	Name: Trie
	Copyright: no rights
	Author: Shivam Jindal
	Date: 29/09/13 17:13
	Description: 
*/

#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
using namespace std;

#define BITS 30

class trie {
	
	private :
		int count;
		trie *child[2];
		
	public:
		
		trie() {
			
			child[0] = child[1] = NULL;
			count = 0;
		}
		
		void insert (int num,int bit) {
			
			++count;
			if( bit < 0 )		return ;
			int b = ( (1 << bit) & num ) ? 1 : 0;
			
			if(child[b] == NULL)	child[b] = new trie();
			child[b]->insert(num,bit-1);
		}
		
	    void remove(int num, int bit) {
	        --count;
	        if(bit < 0) return;
	        int b = ((num & (1 << bit))? 1: 0);
	
	        child[b]->remove(num, bit - 1);
	    }
		
		int search(int num,int bit) {
			
			if(bit<0)			return 0;
			int b = ( (1 << bit) & num ) ? 1 : 0;
		
			if (child[1-b] != NULL && child[1-b]->count > 0)		return ( (1 << bit) | child[1-b]->search(num,bit-1));
			else return child[b]->search(num,bit-1);
		}
		~trie() {
			
			for(int b = 0; b < 2; ++b) 
            	if(child[b] != NULL)
                	delete child[b];
		}
} *root;

int brute(int n,const vector<int> &num) {
    int ans = 0;

    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            for(int k = j + 1; k < n; ++k)
                ans = max(ans, num[i] ^ num[j] ^ num[k]);

	return ans;
}

int max_xor(const vector<int> &arr,int n) {
	
	root = new trie();
	int ans = numeric_limits<int>::min();
//	cout << "trie";
	for(int i=0;i<n;i++)
		root->insert( arr[i] ,BITS );

//	cout << "trie inserted..";		
	for(int i=0;i<n;i++) {
		
//		cout << "b4 remove";
		root->remove(arr[i],BITS);
//		cout << "root";
		for(int j=i+1;j<n-1;j++) {
			
//			cout << "for";			
			root->remove(arr[j],BITS);
			ans = max(ans,root->search(arr[i]^arr[j],BITS));
			root->insert(arr[j],BITS);
		}
	}
	delete root;
	return ans;
}

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		vector<int> arr(n);
		
		for(int i=0;i<n;i++)
			cin >> arr[i];

		if(n <= 200)	cout << brute(n,arr) << endl;
		else		cout << max_xor(arr,n) << endl; 
	}
}
