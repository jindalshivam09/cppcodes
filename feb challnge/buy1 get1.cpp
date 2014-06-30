#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define MAX 26
using namespace std;
main()
{
    
	int t;
	cin>>t;
	while(t--)
	{
        int n=5;
        int str[MAX];
	    for(int i=0;i<MAX;i++)
	    str[i]=0;
		int count=0;
		char c;
		cin>>c;
		do
		{
			str[c-97]++;
		}while(/*(c=getch())!='\r'||*/(c=getche())!='\n\r');
		cout<<"hi";
		for(int i=0;i<MAX;i++)
		{
			!(str[i]%2)?count+=str[i]/2:count+=str[i]/2+1;
		}
		cout<<count<<endl;
	}
	getch();
	return 0;
}
