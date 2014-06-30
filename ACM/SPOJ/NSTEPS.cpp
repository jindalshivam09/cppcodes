#include <iostream>
using namespace std;    
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int x,y;
		cin >> x >> y;
		if(x==y)	{
			if(x%2==0) 
				cout << 2*x;
			else
				cout << 2*x-1;
		}
		else if (x-y == 2) {
			if(x%2==0)
				cout << 2*x-2;
			else
				cout << 2*x-3;
		}
		else
			cout << "No Number";
		cout << endl;
	}
}


