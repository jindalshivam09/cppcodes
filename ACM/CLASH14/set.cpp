#include<bits/stdc++.h>
using namespace std;

int main() {
	set<int> arr ;
	for(int i=0;i<5;i++)
		arr.insert(i) ;
	
//	arr.erase(0) ;
	
	while(arr.size()) {
		int temp = *arr.begin() ;
		cout << *arr.begin() << " ";
		arr.erase(arr.begin()) ;
//		arr.insert(temp) ;
	}
}
