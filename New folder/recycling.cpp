#define B 0
#define G 1
#define W 2
#include<iostream>
#define N 3
using namespace std;
static int move=0;
void rec(int **bin,int n)
{
	if(n<1)
	return;
	else{
		int store[n][2];
		int maxColor=0;
		int Color=0;
		int max=bin[n-1][0];
		for(int i=0;i<n-1;i++)
		{

			for(int j=0;j<n-1;j++)
			{
				if(max<bin[i][j])
				{
				      max=bin[i][j];
				      store[i][0]=i;
				      store[i][1]=j;
				}
			}
			if(maxColor<bin[i][(store[i][1])])
			{
			            maxColor=bin[i][(store[i][1])];
			            Color=i;
			}
		}
		for(int i=0;i<n-1;i++)
		if(store[i][0]!=store[i+1][0]||store[i][1]!=store[i+1][1])
		break;
		move+=bin[Color][(store[Color][1]+1)%3]+bin[Color][(store[Color][1]+2)%3];
		rec(bin,n-1);
      }
}
main()\
{
	int t;
	cin>>t;
	while(t--)
	{
		int bin[N][N];
     	for(int i=0;i<N;i++)
     	for(int j=0;j<N;j++)
		cin>>bin[i][j];
		rec(bin,N);
		cout<<move<<endl;
	}
}
