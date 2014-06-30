#include<iostream>
#include<cstdio>
using namespace std;

#define ROOT 1.4142135623730
int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		printf("%0.6lf\n",ROOT*n);
	}
}
