#include<iostream>
#define MAX 5
#define LENGTH 3
using namespace std;
void rec(char *a,char *b,int i,int n)
{
	if(i==n)
	cout<<b<<endl;
	else
	for(int j=0;j<n;j++)
    {
		b[i]=a[j];
		rec(a,b,i+1,n);
	}
}
main()
{
	char a[MAX]="abc",b[MAX];
	rec(a,b,0,LENGTH);
	cin.get();
}
