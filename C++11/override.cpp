//--------use of keywords override and final -----------------
// override is used to tell that this method is overridden method of a virtual funtion
// final is used to prevent any method to be overriden

#include<iostream>
using namespace std;

class base {
	public:
	virtual void func() {
		cout << "base:func"; 
	}
	virtual void func2() final{
		cout << "base:func2";
	}
};

class derived : public base {
	public:
	void func() override {
		cout << "derived:func";
	}
	void func3() {
		cout << "derived:func2";
	}
};

main() {
	derived ob;
	ob.func();
	ob.func2();
}
