#include<iostream>
#include<math.h>
#include<cstring>
#include<conio.h>
#define MAX 1000000000
using namespace std;
main()
{
	long long	int n;
	cin>>n;
	static bool isPrime[MAX]={0};
	int s=sqrt(n);
//	cout<<s;
   int a;
	for(int i=2;i<=s;i++)
	{
		 a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=n;j+=2*i)
     	{
			   isPrime[j]=1;
            //	cout<<j<<" ";
	    }
	}
	//cout<<"2 ";
	for(int i=3;i<=n;i+=2)
	if(!isPrime[i])
	cout<<i<<" ";
	/*if(isPrime[n-1])
	cout<<"Not\n";
	else
	cout<<"Prime\n";*/
	
	
}
