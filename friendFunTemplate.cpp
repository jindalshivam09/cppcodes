#include<iostream>
using namespace std;
template<class q>class xyz;
template<class t>class abc{
	t a;
	public:
		abc(t q=0):a(q)
		{}
		friend void func( abc<t> , xyz<class q>);
};
template<class q>class xyz{
	q a;
	public:
		xyz(q w=0):a(w)
		{}
		friend void func(abc<class t>,xyz<q>);	
};
void func(abc<class t> oba,xyz<class q> obx)
{
	cout<<"friend func\n";
}
main()
{
	abc<int> a;
	xyz<char> q;
	//a.func();
}
