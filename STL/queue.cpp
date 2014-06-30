#include<iostream>
#include<vector>
#include<queue>
using namespace std;

main() {
	queue<int > stk;
	for(int i=0;i<4;i++)
	stk.push(i);
	cout << stk.front() << endl;
	stk.pop();
	stk.front()=5890;
	stk.back() = 5;
	cout << stk.front() << endl;
	cout << boolalpha << stk.empty() << endl;
	cout << stk.size() << endl ;
	cout << stk.back();
}
