#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll num = 1000000009 ;
	ll add = num ;
	while(1) {
		ll temp = sqrt(num+5) ;
		if(temp*temp == num+5) {
			cout << temp << " " <<  num+5 << " " << (num+5)%add << endl;
			break;
		}
		num += add ;
	}
}
