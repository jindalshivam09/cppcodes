#include<iostream>
using namespace std;
class xyz {
	int a;
	public :
		xyz(int q=0):a(q)
		{}
		void operator = (xyz ob) {
			a=ob.a;
			//return 
		}
};
union abc {
	int a;
	int b;
	double c;
	//xyz ob;
	void set() {
		a=4;
		b=2;
		//c=4.5;
		b=5;
	}
	int operator = (abc a) {
		this->a = a.a * 100;
		return a.a;
	}
};
main() {
	abc a;
	abc c;
	c.set();
	a.set();
	cout<<a.a<<" "<<a.b<<" " ;
	cout << " " << sizeof(abc);
	cout << " " << &a.a << " " << &a.b << " " << &a.c;
	a=c;
	cout  << " " << a.a;
}
