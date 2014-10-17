#include<bits/stdc++.h>
using namespace std;

vector<long long> der(21) ;

void init() {
	der[0] = 1, der[1] = 0 ;
	for(int i=2;i<=20;i++)
		der[i] = (i-1)*(der[i-1]+der[i-2]) ;
}

int main() {
	init() ;
	int t ;
	cin >> t ;
	while(t--) {
		int  n;
		cin >> n ;
		cout << der[n] << endl ;
	}
}
