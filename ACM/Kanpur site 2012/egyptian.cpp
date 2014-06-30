#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int a,b;
	cin >> a >> b;
	while(1) {
	
		if(a==1 && b==1)	break;
		
		while(1) {
		
//			cout << a << " " << b << endl;
			int q = __gcd(a,b);
			a /= q;
			b /= q;
			
			if(a==1) {
				
				cout << b << endl;
				break;
			}
			
			int temp = b/a;
			
			temp++;
			cout << temp << " ";
			
			a = a*temp - b;
			b = b*temp;
			
		}
		
		cin >> a >> b;
	}
}
