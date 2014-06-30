#include<iostream>
#include<random>
using namespace std;

int main()
{
	freopen("input.txt","w",stdout);
	int n=1000000000,m=300000;
	cout<<n<<" "<<m<<endl;
	
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,n);
	uniform_int_distribution<int> queryType(1,3);
	while(m--)
	{
		int type=queryType(generator);
		cout<<type<<" ";
		if(type==1||type==2)
		{
			int u=1,v=0;
			while(u>v)
			{
				u=distribution(generator);
				v=distribution(generator);
			}
			cout<<u<<" "<<v<<" ";
			if(type==1)
				cout<<distribution(generator)<<" "<<distribution(generator);
			else
				cout<<1+distribution(generator)%10000<<" "<<1+distribution(generator)%10000;
		}
		else
			cout<<distribution(generator);
		cout<<endl;
	}
}
