#include<iostream>
#include<cstring>
#include<stdio.h>
#define MAX 500
#define LEN 200
using namespace std;
main()
{
	   int t;
	   cin>>t;
	   while(t--)
	   {
			char que[LEN];
			memset(que,0,sizeof(que));
			char c;
			fflush(stdin);
			while((c=getchar())!='\n')
			{
				que[c]++;
			 //  cout<<(c)<<endl;
			}
			int flag=0;
			char p;
			for(int i=0;i<26;i++)
			if((!que[65+i])&&(!que[97+i]))
			{
			    p=65+i;
		//	    cout<<"hi";
				cout<<p;
				flag=1;
            }

			if(!flag&&!que[32])
			{
				p=32;
				cout<<p;
				flag=1;
			}
			if(!flag)
			cout<<"~";
			cout<<endl;

	}
	return 0;
}
