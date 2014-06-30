#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <complex>
#include <algorithm>
#include <numeric>
#include <exception>
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
typedef unsigned long long ull;
const int INFI = 1<<28;
const ll INFL = 1LL<<60;
const double INFD = 1e+300;
const double EPS = 1e-8;
//int dx[] = {1,-1,0,0};
//int dy[] = {0,0,1,-1};
//struct P { 
//    int id, cost; 
//    P () {}
//    P (int i, int c) : id(i), cost(c) {}
//    bool operator < (const P &p) const { return cost > p.cost; } 
//};
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int T;
    int A;
    set<ull> fib;
    fib.insert(0LL);
    ull p1 = 0, p2 = 1;
    for (int i = 0; i < 5000; i++) {
        ull next = p1 + p2;
        fib.insert(next);
        p1 = p2; p2 = next;
        cout << next << endl;
    }
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        ull t = 0;
        for (int i = 0; i < s.size() ; i++) {
            t *= 10;
            t += s[i]-'0';
        }
        cout << t;
        if (fib.count(t)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}
