#include<iostream>
using namespace std;


class a
{
	private:
		string x;
	public:
		a()
		{
			x="Weapon X";
		}
		void print(int s)
		{
			cout<<x;
		}
};

class b:public a
{
	public:
		void print()
		{
			a::print(5);
		}
};

int main()
{
	b ob;
	ob.print();
}
