#include<iostream>
#include<cstdio>
using namespace std;
main()
{
		int t;
		int arr[10],devil[10];
		char c;
		int i,j;
		bool flag;
		scanf("%d",&t);
		cin.get();
		while(t--)
		{
				
				i=j=0;
				flag=0;
				while((c=getchar())!='\n')
				arr[i++]=c-48;
				if(!arr[j])
				{
						printf("0");
						continue;
				}
				flag=0;
				for(int k=0;k<i;k++)
				{
					if(flag)
					{
						devil[k]=3;
					}
					else
					{
						if(arr[k]>=1&&arr[k]<3)
						{
							devil[k]=1;
							if(arr[k]>1)
							flag=1;
						}
						else if(arr[k]>=3)
						{
							devil[k]=3;
							if(arr[k]>3)
							flag=1;
						}
						else 
						{
							int l=k;
							while(arr[l]!=3&&l>0)
							{
								devil[l]=3;
								flag=1;
								l--;
							}
							devil[l]=0;
						}
					}
				}
				for(int k=0;k<i;k++)
				if(devil[k])
				printf("%d",devil[k]);
				printf("\n");
		}

}
