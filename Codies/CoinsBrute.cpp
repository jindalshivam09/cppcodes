//----------Program Name:----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date:------------------------
#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
main()
{
	int n,t;
	int count;
	bool flag;
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=n+1;;i++)
		{
				count=1;
				flag=0;
				for(int j=2;j<=n;j++)
				if((i%j)==1)
				count++;
				if(count==n)
				{flag=1;
				break;}

		}
		if(flag)
		cout<<t<<" "<<i<<endl;
		else
		cout<<"0\n";
	}
	getch();
    return 0;
}
