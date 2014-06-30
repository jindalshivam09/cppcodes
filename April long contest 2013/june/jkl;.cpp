#include<iostream>
using namespace std;
class abc {
	public: abc() {
		cout << "abc constructor";
	}
};

class xyz : public abc {
	public: xyz() {
		cout << "xyz constructor";
	}
};

main() {
	xyz ob;
}
