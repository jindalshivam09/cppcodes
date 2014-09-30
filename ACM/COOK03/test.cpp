#include<bits/stdc++.h>
using namespace std;;

int main() {
	ofstream cout("test.txt") ;
	int n = rand()%45+1;
	cout << n << endl;
	for(int i=0;i<n;i++) 
		cout << (rand()%100) << " " << (rand()%100) << endl;
	cout << (rand()%100) << " " << (rand()%100) ;
}
