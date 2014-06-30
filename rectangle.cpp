#include<iostream>
using namespace std;
main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m,k;
        cin >> n >> m >> k;
        if((n==1 && m==1) || (n==1&&m==2) || (m==1&&n==2))
        cout << 0 << endl;
        else if(n==1 || m==1)
        cout << k << endl;
        else if(k%2)
        cout << k/2+1  << endl;
        else
        cout << k/2 << endl;
    }
}
