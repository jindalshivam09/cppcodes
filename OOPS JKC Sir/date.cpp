#include<iostream>
#include<cstdio>
#include<conio.h>
using namespace std;
class date
{
	 int d,m,y;
	 public:
			date(char *str)
			{
					int dd,mm,yy;
					sscanf(str,"%d/%d/%d",&dd,&mm,&yy);
					//cout<<dd<<" "<<mm<<" "<<yy;
					int valid=validDate(dd,mm,yy);
					if(valid)
					{
						   d=dd;
						   m=mm;
						   y=yy;
					}
					else
					d=m=y=0;
			}
			bool validDate(int dd,int mm,int yy)
			{
					if(mm>0&&mm<13&&dd>0)
					{
						if(mm==2&&dd<30&&(!(yy%100)&&!(yy%400))||(!(yy%4)))
						return true;
						else if(mm==2&&dd<29)
						return true;
						else if((mm==4||mm==6||mm==9||mm==11)&&dd<31)
						return true;
						else if(dd<32)
						return true;
						else
						return false;
					}
					else
					return false;
			}
			bool validDate()
			{
					if(m>0&&m<13&&d>0)
					{
						if(m==2&&d<30&&(!(y%100)&&!(y%400))||(!(y%4)))
						return true;
						else if(m==2&&d<29)
						return true;
						else if((m==4||m==6||m==9||m==11)&&d<31)
						return true;
						else if(d<32)
						return true;
						else
						return false;
					}
					else
					return false;
			}
			void operator ++(int)
			{
				//date dt;
				   bool flag=0;
				   d++;
				   flag=validDate();
				   if(flag)
				   return;
				   else
				   {
						d--;
						m++;
						flag=validDate();
						if(flag)
						return;
						else
						{
							m--;
							y++;
							return;
						}
				   }
			}

			void operator --(int)
			{
				//date dt;
				   bool flag=0;
				   d--;
				   flag=validDate();
				   if(flag)
				   return;
				   else
				   {
						d++;
						m--;
						flag=validDate();
						if(flag)
						return;
						else
						{
							m++;
							y--;
							return;
						}
				   }
			}
			void display()
			{
					cout<<"date :";
					cout<<d<<"/"<<m<<"/"<<y<<endl;
			}
};
main()
{
		date dt("1/2/1990");
		dt++;
		dt.display();
		dt--;
		dt--;
		dt.display();
		getch();
}
