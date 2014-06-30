#include<iostream>
#include<cstring>
#define MAX 200
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int col;
		cin>>col;
		char encrypt[MAX];
		cin>>encrypt;

		int j,k;
		int gap=2*col;
		int length=strlen(encrypt);
		for(int i=0;i<col;i++)
		{
		        	j=i;
			        k=gap-i-1;
					for(;j<length;j+=gap,k+=gap){
					cout<<encrypt[j];
					if(k<length)
					cout<<encrypt[k];}

		}
		cout<<'\0'<<endl;
	}
	return 0;
}
