#include<iostream>
using namespace std;
class exp
{
	int t;
	public:
		explicit exp(int d)
		{
			   t=d;
			  // cout<<d;
		}
		operator int()
        {

cout<<"shivam";
			cout<<t;
			cout<<"jindal";
			return t;
		}
};
main()
{
	exp e= exp(4);
	int r=(int)e;
	cout<<r;
	int f;
	cin>>f;
}
