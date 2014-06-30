#include<iostream>
using namespace std;
main()
{
	int t;
	cin>>t;
	int a;
	int count;
	while(t--)
	{
		   count=0;
		   cin>>a;
		   while(a)
		   {
				if(!(a%3))
				{
					a/=3;
					count++;
				}
				else if((!(a%2))&&!(a%6))
				{
					a/=6;
					count+=2;
				}
				else if(!((a-1)%3))
				{
					a-=1;
					a/=3;
					count+=2;
				}
				else if(!(a%2))
				{
					a/=2;
					count++;
				}
				else
				{
					a-=1;
					count++;
			    }
			cout<<a<<" ";
		   }
		   cout<<count<<endl;
	}
}
