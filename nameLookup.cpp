#include<iostream>
using namespace std;
namespace abc {
	namespace xyz {
		int a;
		void func()
		{cout << "xyz ";}
	}
	void func(int a) {
		cout << "abc ";
	}
	using namespace xyz;
}
using namespace abc;
main() {
	abc::a;
	func(a);
	operator << (std::cout,"shivam");
}
