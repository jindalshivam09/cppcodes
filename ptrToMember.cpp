#include<iostream>
using namespace std;
class abc {
	public:
		int a;
		int b;
		abc():a(0)
		{}
		void func ( ) {
			cout << " hi.." << a+20 << " ";
		} 
		int c;
		float g;
};

main() {
	float abc::*ptrData;		// pointer to member data of class abc
	void (abc::*ptrFunc)();	// pointer to member func of class abc
	cout << " " << ptrData << " " << ptrFunc;

	abc ob;
	ptrData = &abc::g; 		// this will put offset of member a of abc in ptrData
	ptrFunc = &abc::func;	// this will put offset of member func of abc in ptrFunc
	cout<<ob.*ptrData;
	(ob.*ptrFunc)();
	cout << " " << ptrData << " " << ptrFunc;
}

