#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int a,b,c;
		cin >> a >> b >> c;
		
		if(!c)							cout << 0 << endl;
		else if(c==a || c==b)			cout << 1 << endl;
		else if(c>a && c > b)			cout << -1 << endl;
		else if(c%__gcd(a,b))			cout << -1 << endl;
		else {
			
			int steps1 = 0,steps2 = 0;
			int a1=0,b1=0;
			
			while(a1 != c && b1 != c) {
				
//				cout << a1 <<  " " << b1 << endl;
				if(a1 == 0)	{
					
					a1 = a;
					steps1++;
				}
				else if(b1 == b) {
					
					b1 = 0;
					steps1++;
				}
				else {
					
					int sum = a1+b1;
					b1 = sum<b ? sum : b;
					a1 = sum - b1;
					steps1++;
				}
			}
			
			a1 = 0 ;
			b1 = 0;
			
			while(a1 != c && b1 != c) {
				
//				cout << a1 <<  " " << b1 << endl;
				if(b1 == 0)	{
					
					b1 = b;
					steps2++;
				}
				else if(a1 == a) {
					
					a1 = 0;
					steps2++;
				}
				else {
					
					int sum = a1+b1;
					a1 = sum<a ? sum : a;
					b1 = sum - a1;
					steps2++;
				}
			}
			cout << min(steps1,steps2) << endl;
		}
	}
}
