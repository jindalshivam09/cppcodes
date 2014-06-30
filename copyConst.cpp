//----------Program Name:----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date:------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;
class abc
{
  int a;
  public:
		abc(int y=0)
		{
			a=y;
			cout<<"constructor\n";
		}
		abc( abc &q)
		{
			a=q.a;
			cout<<"copy constructor";
		}
		void copy(abc q)
		{}
};

main()
{
	abc a(3);
	abc f;
	a.copy(f);
	cin.get();
    return 0;
}
