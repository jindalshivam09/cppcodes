#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long int test,i,n,x,count,j,k;
	cin>>test;
	while(test--)
	{
		cin>>n;count=0;
		if(n==1) cout<<"1"<<endl;
		else if(n==2) cout<<"2"<<endl;
		else if(n==3) cout<<"3"<<endl;
		else
		{
			count=2;x=3;
			while(x<=n)
			{
				count++;x+=count;
			}
			cout<<count<<endl;
		}
		
	}
	return 0;
}
