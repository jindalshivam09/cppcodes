#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int ans, lim;
 
    void solve(int row, int ld, int rd) {
        if (row == lim) { // have placed row queens
            ans ++;  // we have a solution
            return;
        }
        int pos = lim & (~(row | ld | rd)); // valid positions
        while (pos != 0) {
            int p = pos & (-pos); // rightmost position
            pos -= p; // have tried this
            solve(row + p, (ld + p) << 1, (rd + p) >> 1);
        }
    }
 
    int totalNQueens(int n) {
        ans = 0;
        lim = (1 << n) - 1;
        solve(0, 0, 0);
        return ans;
    }
};

int main() {
	
	Solution a;
	int n;
	cin >> n;
	cout << a.totalNQueens(n);
}
