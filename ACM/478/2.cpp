#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
	ll n,m;
	cin >> n >> m ;
	
	if(n == m)
		cout << "0 0"  ;
	else {
		ll temp =n- (m-1) ;
		ll valMax = (temp*(temp-1))/2 ;
		ll eq = (n/m), rem = n%m ;
		ll valMin = (m-rem)*(eq*(eq-1))/2 ;
		valMin += (rem*((eq+1)*eq))/2 ;
		cout << valMin << " " << valMax << endl;
	}
}
