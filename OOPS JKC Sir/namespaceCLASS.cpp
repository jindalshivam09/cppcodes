#include<iostream>
using namespace std;

//---------user defined namespace CLASS---------------

namespace CLASS
{
	class abc
	{
		int a;
		public:
			abc(int q=0):a(q)
			{}
			void display();
	};
}

namespace CLASS
{
	int a=4;
}
/////////////////////////////////////////////////

using namespace CLASS;
void abc::display()
{
	cout<<"abc::display";
}
main()
{
	using CLASS::abc;
	abc ob;
	
	//or use CLASS::abc ob;

	ob.display();
	cout<<" "<<a;
	while(1);
}
