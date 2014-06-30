#include<iostream>
#include<vector>
#include<stack>
using namespace std;

main() {
	stack<int,vector<int> > stk;
	for(int i=0;i<4;i++)
	stk.push(i);
	cout << stk.top() << endl;
	stk.pop();
	stk.top()=5890;
	cout << stk.top() << endl;
	cout << boolalpha << stk.empty() << endl;
	cout << stk.size();
}
