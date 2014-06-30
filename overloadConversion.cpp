#include<iostream>
using namespace std;
class abc
{
		int a;
		public:
			abc(int q=0):a(q)
			{}
			operator float()
			{
				return a;
			}
};
main()
{
	abc ob=4;
	cout<<3+ob;
	while(1);
}
