#include<iostream>
using namespace std;
class abc {
	public :
		void func(int a) {
			cout << "int" << endl ;
		}
};
class xyz : public abc {
	public :
		using abc::func;
		void func() {
			cout << "unparam" <<  endl;
		}
};
main() {
	xyz ob;
	ob.func(2);
	ob.func();
}
