#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 10
class date
{
	  private:
			int m,y,d;
			char mon[MAX];
	  public:
			date()
			{
				d=1; m=1; y=2001;
			}
			date(char a[],int flag)
			{
				sscanf(a,"%d/%d/%d",&d,&m,&y);
			}
			date(int a,int c,int b)
			{
				d=a; m=c; y=b;
			}
			date(char a[],double flag)
			{
				sscanf(a,"%d.%d.%d",&d,&m,&y);
			}
			void distype()
			{
                		 cout<<"\nto display date   press:"<<endl;
		 				 cout<<"1  for -> american"<<endl;
		 				 cout<<"2  for -> british"<<endl;
		 				 cout<<"3  for -> indian"<<endl;
		 				 int q;
		 				 cin>>q;
		 				 switch(q)
						 {
									case 1:
					  					display(1);
					 					break;
									case 2:
					 					display(1.0);
					 					break;
									case 3:
					 					display(q);
					 					break;
				 					default:
					 					cout<<"invalid option";
						 }
		}
		void display(int a)
		{
				cout<<d<<" "<<m<<" "<<y;
		}
		void display(double a)
		{
				cout<<m<<" "<<d<<" "<<y;
		}

		void display(char a)
		{
				cout<<d<<"-"<<m<<"-"<<y;
		}

};
main()
{

	while(1)
	{
		 cout<<"\nto enter date   press:"<<endl;
		 cout<<"1  for -> dd mm  yyyy"<<endl;
		 cout<<"2  for -> dd/mm/yyyy"<<endl;
		 cout<<"3  for -> dd.mm .yyyy"<<endl;
		 int q;
		 cin>>q;
		 switch(q)
		 {
				case 1:
				{
		    		 int a,b,c;
					 cin>>a>>b>>c;
					 date dat(a,b,c);
					 dat.distype();
					 break;
				}
				case 2:
				{
					 char w[MAX];
					 cin>>w;
					 date dat(w,1);
                     dat.distype();
					 break;
			   }
			   case 3:
			   {

					 char w[MAX];
					 cin>>w;
					 date dat(w,1.0);
					 dat.distype();
					 break;
			  }
		      default:
					 date dat;
                     dat.distype();
		 }
		 
		 
	}
}
