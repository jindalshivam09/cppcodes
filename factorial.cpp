//-------------defected program-----------------


#include<iostream>
#include<cstring>
#include<stdio.h>
#define MAX 50
using namespace std;
main()
{
	char arr[MAX][MAX];
	*arr[0]=1;
	for(char i=1;i<MAX;i++)
	{
			 strcpy(arr[i],i*(*arr[i-1]));
			 printf("%d %s\n",i,arr[i]);
	}
	cin>>arr[0];
}
