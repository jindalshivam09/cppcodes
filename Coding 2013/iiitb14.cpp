#include<iostream>
#include<cstring>
int price[2002][2];
using namespace std;
main()
{
	int t,credit;
	int i,p;
	int ans[101][2];
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		memset(price,0,sizeof(price));
		cin>>credit>>i;
		for(int j=1;j<=i;j++)
		{
			cin>>p;
			if(!price[p][0])
			{
				price[p][0]=1;
				price[p][1]=j;
			}
			else if(!price[1000+p][0])
			{
				price[1000+p][0]=1;
				price[1000+p][1]=j;
			}
		
		}
		for(int j=1;j<=1000;j++)
		{
			if(price[credit-j][0]&&j!=credit-j)
			{
				if(price[j][1]<price[credit-j][1])
				cout<<"Case #"<<k<<": "<<price[j][1]<<" "<<price[credit-j][1]<<endl;
				else
				cout<<"Case #"<<k<<": "<<price[credit-j][1]<<" "<<price[j][1]<<endl;
				break;
			}
			else if(price[1000+credit-j][0])
			{
				if(price[j][1]<price[1000+j][1])
				cout<<"Case #"<<k<<": "<<price[j][1]<<" "<<price[1000+j][1]<<endl;
				else
				cout<<"Case #"<<k<<": "<<price[1000+j][1]<<" "<<price[j][1]<<endl;
				break;
			}
		}
	}
	return 0;
}
