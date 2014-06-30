#include<iostream>
using namespace std;

#define MAX 100

int main() {
	
	string str[MAX];
	int i=0;
	
	int n;
	cin >> n;
	while (i<n){
		
		cin >> str[i++] ;
		//cout << s;
	}
	
	for(int j=i-1;j>=0;j--) {
		
		cout << str[j] << " ";
	}
}
