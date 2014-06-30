#include<iostream>
using namespace std;


class x
{
	public:
		x operator ++()
		{
			cout<<"Prefix operator";
		}
		x operator ++(int)
		{
			cout<<"Post fix operator";
		}
		x operator +(const x &)
		{
			cout<<"Adittion";
			return  *this;
		}
};
int main()
{
	int a=10;
	cout<<	a++ + ++a + ++a +a;
	x b;
	b++ + ++b + ++b +b;
//		  12  +  12 + 11  +12
	
}

