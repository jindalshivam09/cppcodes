#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,n;
	cin >> a >> b >> n ;
	n -= a ;
	int temp = ceil(1.0*n / (a-b) );
	cout << temp+1 ;
	
}


