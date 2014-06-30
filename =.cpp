#include<iostream>
using namespace std;
template<class r>class abc
{
		r a[8];
		public:
			abc(int q=0)
			{}
			void operator =(abc q)
			{
				cout<<"operator =";
					a[1]=q.a[1];
			}
};
main()
{
	abc<int> a;
	abc<int> q(2);
	a=q;
	cin.get();
}
