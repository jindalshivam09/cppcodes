//worong solution

//----------Program Name: kingdom unity----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date: 8 April 2013------------------------
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#define MAX 3000
using namespace std;
int cityToBeProtected(bool connect[][MAX],bool *con,int n)
{
		int count=0;
		int temp[MAX];
		int i=0;
		for(int row=0;row<n;row++)
		{
			i=0;
			for(int col=0;col<n;col++)
			{
				if(connect[row][col])
				{
					//printf("%d %d ",row,col);
					for(int city=0;city<n;city++)
					{
                      //  printf("%d %d %d \n",row,col,city);
							if(connect[col][city]&&row!=city&&!con[col]&&!connect[row][city])
							{
							//	printf("%d %d %d \n\n",row,col,city);
									count++;
									con[col]=1;
									//connect[row][col]=0;
									break;
							}
					}
				}
			}
		}
		return count;
}

bool connect[MAX][MAX];             // contain connections between cities
bool con[MAX];                    //it will contain cities which are already protected

main()
{
	int t,n,m,k,a,b;
	scanf("%d",&t);
	while(t--)
	{
		memset(con,0,sizeof(con));
		memset(connect,0,sizeof(connect));
		scanf("%d%d%d",&n,&m,&k);
		while(m--)
		{
				scanf("%d%d",&a,&b);
				connect[a][b]=1;
				connect[b][a]=1;
		}
		printf("%d\n",cityToBeProtected(connect,con,n)*k);
	}
    return 0;
}
