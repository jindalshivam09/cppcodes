#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef struct path{
	int i;
	struct path *link;
}city;
city *start=NULL,*temp=NULL;
city* construct(int a,int b,city *start)
{
	city *trace=start;
	temp=new city;
			 if(!start)
			 {
				   //cout<<"hi";
					start=new city;
					start->i=a;
					
					temp->i=b;
					start->link=temp;
					temp->link=NULL;
			 }
			 else
			 {
                   //cout<<"hi1";
					while(trace->i!=a||trace->i!=b&&trace->link)
					trace=trace->link;
					if(trace->i==a)            //to use proper city number
					a=b;
					//cout<<"hi3";
						
					if(trace==start)
					{
						       temp->i=a;
						       temp->link=start;
							   start=temp;
					}
					else
					{
								trace->link=temp;
								temp->i=a;
								temp->link=NULL;
                    }
			 }
  return start;
}

main()
{
	int a,b;
	int t;
	cin>>t;
	
	while(--t)
	{
		cin>>a>>b;
		start=construct(a,b,start);
		cout<<start->i;
	}
	cout<<"ji";
	temp=start;
	cout<<"hi";
	while(temp)
	{
		cout<<"ih";
		cout<<temp->i;
		temp=temp->link;
	}
	getch();
}
