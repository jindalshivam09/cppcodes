#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int tot,a,f;
		cin>>tot>>a>>f;
		int m,n;
		int max=-1;
	    int *frend;
		frend=(int *)calloc(tot,sizeof(int));
		while(f--)
		{
			cin>>m>>n;
			if(m==a||n==a)
			{
				frend[m-1]=-1;
				frend[n-1]=-1;
			}
			else
			{
                frend[m-1]++;
                frend[n-1]++;
                if(max<frend[n-1])
                max=frend[n-1];
                if(max<frend[m-1])
                max=frend[m-1];
        	}
		}
		cout<<max+1<<endl;
	}
}
