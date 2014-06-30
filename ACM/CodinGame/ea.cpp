#include<iostream>
using namespace std;

class abc {
	
	private :
		virtual void func() {
			
			cout << "shivam";
		}
};

class qwe : public abc {
	
	
};

int main() {
	
	qwe e;
	e.func();
}
