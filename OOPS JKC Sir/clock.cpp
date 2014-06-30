#include<iostream>
#include<conio.h>
using namespace std;


class clocktype
{
	int hr,min,sec;
	public:
		clocktype(int a=0,int b=0,int c=0)
		{
				hr=a;
				min=b;
				sec=c;
		}
		void setTime(int a,int b,int c)
		{
			hr=a;
			min=b;
			sec=c;
		}
		virtual clocktype & retTime()
		{
					return *this;
		}
		void printTime()
		{
				cout<<hr<<":"<<min<<":"<<sec;
		}

		bool compare(clocktype x)
		{
			if(hr==x.hr&&min==x.min&&sec==x.sec)
			return 1;
			return 0;
		}
	
};

class extraclocktype:public clocktype
{
	float timezone;
	public:
		extraclocktype(int a=0,int b=0,int c=0,float d=0):clocktype(a,b,c)
		{
		timezone=d;	
		}
		extraclocktype & retTime()
		{
			return *this;
		}
		
};

main()
{
	extraclocktype c1(3,5,7,5.5),c2(8,3,5,4.5),c3;
	c1.setTime(1,2,5);
	cout<<"\nTime in first clock:";
	c1.printTime();
	cout<<"\nTime in second clock:";
	c2.printTime();
	c3 = c1.retTime();
	cout<<"\nTime in third clock:";
	c3.printTime();
	if(c1.compare(c2))
	cout<<"\nEqual Time";
	getch();
}
