#include<iostream>
using namespace std;
main()
{
	int m,n;
	cin>>m>>n;
	int cord[m][2];
    for(int i=0;i<m;i++)
	cin>>cord[i][0]>>cord[i][1];
    while(n--)
	{
			int a,b,c,count=0;
			cin>>a>>b>>c;
			for(int i=0;i<m;i++)
			{
				if(cord[i][0]>=a&&cord[i][1]>=b&&(cord[i][0]-cord[i][1])<=(a+c-b)&&cord[i][0]<a+c&&cord[i][1]<b+c)
				count++;
			}
			cout<<count<<endl;
	}
return 0;
}
