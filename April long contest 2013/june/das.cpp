#include<iostream>

#include<fstream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	ifstream in("test.txt");
		int n,m;
		cin>>n>>m;
		
		char a[200][200];	
		for(int i=0;i<200;i++)
		{
			for(int j=0;j<200;j++)
				a[i][j]='0';
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				in>>a[i][j];
		
		int scared[200][200]={0};
		char dir[200][200]={0};
	
		
		for(int i=n;i>=1;i--)
		{
			for(int j=m;j>=1;j--)
			{
				if(i==n&&j==m)
				{
					scared[i][j]=(a[i-1][j]-'0')+(a[i][j-1]-'0');
					if(a[i][j]=='1')
						scared[i][j]++;
					
				}
				else if(i==n)
				{
					
					scared[i][j]=(a[i-1][j]-'0')+(a[i][j-1]-'0')+scared[i][j+1];
					dir[i][j]='L';
				//	cout<<i<<j<<"=>"<<scared[i][j]<<endl;
				}
				else if(j==m)
				{
					scared[i][j]=(a[i-1][j]-'0')+(a[i][j-1]-'0')+scared[i+1][j];
					dir[i][j]='U';
				}
				else
				{
					int lscared=0,uscared=0;
					
					
					
					if(dir[i][j+1]=='L')
						lscared=scared[i][j+1]+a[i+1][j]-'0';
					else if(dir[i][j+1]=='X')
						lscared=scared[i][j+1];
					else if(dir[i][j+1]=='U')
						lscared=scared[i][j+1];
					//---------------------------------------------
					if(dir[i+1][j]=='L')
						uscared=scared[i+1][j];
					else if(dir[i+1][j]=='X')
						uscared=scared[i+1][j];
					else if(dir[i+1][j]=='U')
						uscared=scared[i+1][j]+a[i][j+1]-'0';
					
					lscared+=(a[i-1][j]-'0')+(a[i][j-1]-'0');
					uscared+=(a[i-1][j]-'0')+(a[i][j-1]-'0');
					//int lscared=+(dir[i][j+1]=='L'?(a[i+1][j]-'0'):0)+scared[i][j+1];
					//int uscared=(a[i-1][j]-'0')+(a[i][j-1]-'0')+(isleft[i+1][j]?0:(a[i][j+1]-'0'))+scared[i+1][j];
					
					
					if(lscared<uscared)
					{
						dir[i][j]='L';
						scared[i][j]=lscared;						
					}
					else if(lscared>uscared)
					{
						dir[i][j]='U';
						scared[i][j]=uscared;		
					}
					else
					{
						dir[i][j]='X';
						scared[i][j]=uscared;
					}
				}
			}
		}
       void print(int scared[200][200],int n,int m);
		print(scared,n,m);
		cout<<scared[1][1]<<endl;
	
	}
}

void print(int scared[200][200],int n,int m)
{
 for(int i=1;i<=n;i++)
 {
 	for(int j=1;j<=m;j++)
    {
    	cout<<scared[i][j]<<" ";
    }
    cout<<endl;
 }
}
