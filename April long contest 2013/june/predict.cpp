#include<iostream>
#include<iomanip>
using namespace std;
main() {
	int t;
	cin >> t;
	double prob,money;
	while(t--) {
		cin >> prob;
		double x = 1-2*prob;
		if(prob > 0.5) {
			cout <<setprecision(12) <<  x*(10000.00*prob - 10000.00) + 10000;
		}
		else if(prob < 0.5)
		cout << setprecision(12) << x*10000.00*prob + 10000.00;
		else
		cout << 10000;
		cout << endl;
	}
}
