#include<iostream>
using namespace std;
class assign{
	int a;
//	int &q;
	public:
		/*assign(int *e):q(*e)
		{
			a=9;
			cout<<&q<<" "<<e;
			delete e;
			cout<<" "<<e<<" shivam"<<q<<"jindal";
		}*/
		assign(int a)
		{
			//a=a;
		}
	/*	void operator =(int a)
		{
			a=a;
		}
*/		void dis()
		{
			cout<<"a= "<<a<<" ";
		}

};
main()
{
	/*int *e;
	e=new int;
	*e=1;*/
	 
	
	int e;
	int &a=e;
	int r=8;
	&a=r;
	assign q=e;;
	assign w=q;
	//delete e;
	q.dis();
	int t;
	cin>>t;
}
