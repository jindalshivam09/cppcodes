#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		long long s,n,c;
		cin >> s >> n >> c;
		
		if(s > n + 2*c)
			cout << "NO" << endl;
		else {
			
			long long temp = (s-n)/2;
			if (s == n + 2*temp) 
				cout << "YES " << temp << endl;
			else 
				cout << "YES " << temp+1 << endl; 
		}
	}
}
