#include<iostream>
#include<string>
#define MAX 100
using namespace std;
main() {
    int t;
    cin >> t;
    while(t--) {
        int n,q,len;
        char ch;
        string str;
        cin >> str >> n >> ch;
        q = ch - 'a' ;
        len = str.length();
        cout << len << q;
    }
}
