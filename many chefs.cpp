#include<iostream>
#define MAX 2013
#include<conio.h>
using namespace std;
main()
{
	int t,flag=0;
	char check[]={'C','H','E','F'},string[MAX];
	cin>>t;
	while(t--)
	{
		cin >> string;

		for(int i=0;string[i];i++)
		{
			int pre=i,count=0,temp=i;
			while(string[i++]=='?')
			{
				count++;
			}

			int q=count%4;
			if(count>3)
			{
			           while(q--)
		               {
											string[temp++]='A';
					   }
					   for(int q=0;q<4&&;q++)
					   string[temp+q]=check[q];
		   }
		    else{
			 i=pre;
			if(string[i]=='?'||string[i]=='C')
			{
				
				
			for(int j=1;j<4;j++)

			{
					if(string[i+j]=='?'||string[i+j]==check[j])
					flag=1;
					else
					{
						flag=0;
						break;
					}
			}
			if(flag)
			for(int k=0;k<4;k++)
			string[i+k]=check[k];
			else if(string[i]=='?')
			string[i]='A';
			}
		    else if(string[i]=='?')
			string[i]='A';
		}
		}
		cout<<(string)<<endl;
		
	}
	getch();
		return 0;
}
