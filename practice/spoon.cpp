#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
	//	cin.get();
		int s[10002][2];
		int count=-1;
		int array[100][101];
		char str[101];
		char spoon[4]={'p','o','o','n'};
		char SPOON[4]={'P','O','O','N'};
		for(int i=0;i<r;i++)
		{
			scanf("%s",str);
			for(int j=0;j<c;j++)
			{
				array[i][j]=str[j];
				if(str[j]=='s'||str[j]=='S'){
					s[++count][0]=i;
					s[count][1]=j;
				//	printf(" %d %d ",s[count][0],s[count][1]);
			    }
			  //  cin.get();
			}
		}
		bool flag=0;
		for(int i=0;i<=count;i++)
		{
			if((s[i][1]+4)<c)
			{
				int k=0,q=0;
				while(array[s[i][0]][++s[i][1]]==spoon[k]||array[s[i][0]][s[i][1]]==SPOON[k]){
					q++;
					k++;
			    }
				if(q==4){
					flag=1;
					break;
				}
			}
			else if((s[i][0]+4)<r)
			{
				int k=0,q=0;
				while(array[++s[i][0]][s[i][1]]==spoon[k]||array[s[i][0]][s[i][1]]==SPOON[k]){
					q++;
					k++;
				}
				if(q==4){
					flag=1;
					break;
				}
			}
		}
		if(flag)
		printf("There is a spoon!\n");
		else
		printf("There is indeed no spoon!\n");
	}
	return 0;
}
