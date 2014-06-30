#include<iostream>
#include<stdio.h>
#include<limits>
#include<vector>
using namespace std;
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)			
	{
		int n,m;
		scanf("%d%d",&n,&m);
		vector<int> array(n+1);
		vector<int> counter(n+2,0);
		
		for(int i=0;i<m;i++)
		{
			int w,x,y,z;
			scanf("%d%d%d%d",&w,&x,&y,&z);
			if(w==1)
			{
				counter[x]+=z;
				counter[y+1]-=z;
			}
			else
			{
				counter[x]-=z;
				counter[y+1]+=z;
			}
		}	
		
		// process
		
		int MAX=numeric_limits<int>::min();
		int MIN=numeric_limits<int>::max();
		
		int adder=0;
		for(int i=1;i<=n;i++)
		{
			adder+=counter[i];
			array[i]=i+adder;
			MIN=min(MIN,array[i]);
			MAX=max(MAX,array[i]);
		}
		cout<<MAX-MIN<<endl;
	}
}

			
