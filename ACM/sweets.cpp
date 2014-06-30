#include<iostream>
#include<limits>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n,x;
		cin >> n >> x;
		
		int m = numeric_limits<int>::max();
		long long sum=0;
		
		int a;
		for(int i=0;i<n;i++) {
			
			cin >> a;
			sum += a;
			m = min(m,a);
		}
		
		long long s = sum / x;
		
		long long temp = (sum-m) / x;
		
		if(s == temp)		cout << -1 << endl;
		else 				cout << s << endl; 
	}
}
