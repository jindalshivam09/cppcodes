#include<iostream>
using namespace std;
class abc
{
		int q;
		public:
			abc(int a=0):q(a)
			{
				cout<<"\nabc constructor\n";
			}
			friend ostream& operator <<(ostream&,abc&);
};
ostream &operator <<(ostream &cout, abc &a)
			{
				cout<<"<< operator "<<a.q;
				return cout;
			}
template<class c,int *i>class PRINT
{
		c a;
		public:
			PRINT(c q=0):a(q)
			{
				cout<<"template constructor";
			}
			void print()
			{
				cout<<a;
			}
};
main()
{
	int t=5;
	PRINT<int,&t> a;
	PRINT<abc,1> b;
	a.print();
	b.print();        //it will give error as << operator is not defined for class abc
	cin.get();
}
