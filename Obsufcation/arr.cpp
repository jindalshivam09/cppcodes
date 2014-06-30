#include<iostream>
#define ASCII 65
#define MAX 10
#define CHARS 26

using namespace std;

int hashMap[CHARS][MAX][2];
int indexHash[CHARS];
char arr[MAX][MAX];

void setArr(int m,int n)
{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				//cout<<indexHash[j]<<" ";
				 //cout<<(arr[i][j]-ASCII)<<" ";
				  hashMap[(arr[i][j]-ASCII)][(indexHash[arr[i][j]-ASCII])][0]=i;
				  hashMap[(arr[i][j]-ASCII)][(indexHash[arr[i][j]-ASCII])++][1]=j;
			}
		}
			for(int i=0;i<CHARS;i++)
		{
			for(int j=0;j<indexHash[i];j++)
			{
				  cout<<indexHash[i]<<" ";
				  cout<<hashMap[i][j][0]<<" ";
				  cout<<hashMap[i][j][1]<<" \n";
			}
			cout<<"\n";
		}
}/*
int search(int a,int m,int n)
{
	int M,N;
    for(int i=0;i<indexHash[a+1];i++)
	{
		M==hashMap[a+1][i][0];
		N==hashMap[a+1][i][1];
		if(m==M-1&&n==N-1)   return true;
		if(m==M&&n==N-1)     return true;
		if(m==M+1&&n==N)     return true;
		if(m==M-1&&n==N)     return true;
		if(m==M+1&&n==N)     return true;
		if(m==M-1&&n==N+1)    return true;
		if(m==M&&n==N+1)      return true;
		if(m==M+1&&n==N+1)    return true;
		return false;
	}
}*/
int path(int a,int m=0,int n=0,int len=0)
{
	if(a<CHARS)
	{

	//	m=hashMap[a][i][0];
	//	n=hashMap[a][i][1];
		int maxLen[MAX],M,N;
		int max[MAX];
        for(int i=0;i<indexHash[a+1];i++)
     	{
			  /*if(M>m+1||N>n+1)            // if it goes out of scope
			   return len;*/
			  int count=0;
		      M==hashMap[a+1][i][0];
		      N==hashMap[a+1][i][1];
              if(m==M-1&&n==N-1)   {
					maxLen[0]=path(a+2,M,N,len+1);
					count++;
              }
        	  if(m==M&&n==N-1)     {
                    maxLen[1]=path(a+2,M,N,len+1);
                    count++;
			  }
		      if(m==M+1&&n==N)    {
                    maxLen[2]=path(a+2,M,N,len+1);
                    count++;
		      }
		      if(m==M-1&&n==N)    {
                    maxLen[3]=path(a+2,M,N,len+1);
                    count++;
		      }
		      if(m==M+1&&n==N)    {
                    maxLen[4]=path(a+2,M,N,len+1);
                    count++;
		      }
		      if(m==M-1&&n==N+1)    {
                    maxLen[5]=path(a+2,M,N,len+1);
                    count++;
		      }
		      if(m==M&&n==N+1)     {
                    maxLen[6]=path(a+2,M,N,len+1);
                    count++;
		      }
		      if(m==M+1&&n==N+1)   {
                    maxLen[7]=path(a+2,M,N,len+1);
                    count++;
		      }
			  else{
						return len;
			  }
			  int Max=-1;
			  for(int j=0;j<count;j++){
			  cout<<" a= "<<a<<" "<<maxLen[j];
			  if(Max<maxLen[j])
			  Max=maxLen[j];
			  max[i]=Max;
			}
		 }
		 int Max=-1;
         for(int i=0;i<indexHash[a+1];i++)
         {
				if(MAX<max[i])
				Max=max[i];
         }
         return Max;
         

	}
}


main()
{
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	cin>>arr[i][j];
	setArr(m,n);
	int t;
	cin>>t;
	while(t--)
	{
	char c;
	cin>>c;
	int maxLen[MAX],max=-1;
	for(int i=0;i<indexHash[c-ASCII];i++)
    maxLen[i]=path(c-ASCII,hashMap[c-ASCII][i][0],hashMap[c-ASCII][i][1]);
	for(int i=0;i<indexHash[c-ASCII];i++)
	if(max<maxLen[i])
	max=maxLen[i];
	cout<<max;
	}
			  int f;
			  cin>>f;

	
}
