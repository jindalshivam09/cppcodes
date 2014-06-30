#include<iostream>
#include<algorithm>
using namespace std;

long long val[66];

int gcd (long long val,long long n) {
	
	long long temp;
	while(n) {
		temp = n;
		n = val%n;
		val = temp;
	}
	return temp;

}
void init() {
	
	val[1] = 1;
	
	for (int i = 1 ; i < 65 ; i ++) {
	
		if (i%2==0) {
			
			long long temp = gcd (val[i],i/2+1);
			val[i+1]=((i+1)/((i/2+1)/temp))*(val[i]/temp);
		}
		else 
		{	
			val[i+1] = 2 * val[i];
		}
		//cout << val[i] << endl;
	}
}

int main() {


	init();
	int t;
	cin >> t;

	while(t--) {
	
		long long n;
		cin >> n;
		
		for (int i = 1 ; i < 65 ; i ++) {

			if (val[i]>=n) {
				cout << i << endl;
				break;
				
			}
		}
	}
}
