#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b) ; 
}
int calGcd (int *numbers,int size) {
	int result = numbers[0];
	for(int i = 1; i < size; i++){
    	result = gcd(result, numbers[i]);
	}
	return result;

}
main() {
	int n,t;
	int numbers[100009];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0;i<n;i++) {
			cin >> numbers[i];
		}
		cout << calGcd(numbers,n) << endl;
	}

}
