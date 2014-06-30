#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#define MAX 10
using namespace std;
int flag[MAX][MAX];
class MAZE{
		private:
			   int flag[MAX][MAX];
				int maze[MAX][MAX];
				int flg;
				int n;
		public:
              	static int count;
				void set(){
						cin>>n;
						for(int i=0;i<n;i++)
	 					for(int j=0;j<n;j++)
						cin>>maze[i][j];

				}
				void setflag()
				{
					memset(flag,0,sizeof(flag));
				}
				void dfs(int i,int j,int flg=0)
                {
					   flag[i][j]=1;

						//cout<<i<<","<<j<<" ";
						if(i==(n-1)&&j==(n-1)){
							 //memset(flag,0,sizeof(flag));
							// cout<<endl;
							 count++;
						}
						else
						{
								if(!maze[i+1][j]&&(i+1)<n&&flg!=4)                   dfs(i+1,j,2);
								if(!maze[i][j+1]&&(j+1)<n&&flg!=5)                   dfs(i,j+1,2);
					     		if(!maze[i-1][j]&&!flag[i-1][j]&&(i-1)>-1)        {dfs(i-1,j,4);}
								if(!maze[i][j-1]&&!flag[i][j-1]&&(j-1)>-1)        {dfs(i,j-1,5);}
						}
				}
};

int MAZE::count;


main()
{
	MAZE Maze;
		 Maze.set();
		 Maze.setflag();
		 Maze.dfs(0,0);
		 cout<<MAZE::count;
		return 0;
}
