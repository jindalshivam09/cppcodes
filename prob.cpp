#include<iostream>
#include<iomanip>
using namespace std;


typedef long long ll;
main() {
    int t;
    cin >> t;
    while(t--) {
        ll t1,t2,t3,t4;
        cin >> t1 >> t2 >> t3 >> t4;
        cout << setprecision(8) << (float)t1/(t2+t1) << endl;
    }
}
