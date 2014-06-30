#include<algorithm>
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

void print (int n) {						// function object
		cout << n << endl;
}
main() {
	vector<int> v;
	int arr [] = {1,2,3,4,5};

	copy (arr,arr + sizeof(arr)/sizeof(arr[0]),back_inserter(v));	// copy fund will copy elements
																	// back_inserter is used to do insert elemnets in vector as it is empty 
																	//it funct as push_back 
	// copy (arr,arr + sizeof(arr)/sizeof(arr[0]),v.begin());   // else use vector<int> v(5) and directly use v.begin()
	
	for_each(v.begin(),v.end(),print);
	
	copy(v.begin(),v.end(),ostream_iterator<int> (cout," "));
	cout << endl;
	v.insert(v.begin()+3,arr,arr + sizeof(arr)/sizeof(arr[0]));
	for_each(v.begin(),v.end(),print);
}	
