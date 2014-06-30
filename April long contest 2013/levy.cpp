//----------Program Name: Levy Conjecture----------------------
//------------Author: Shivam Jindal(jindalshivam09)---------
//------------Date: 4 April 2013------------------------

#include<fstream>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define MAX 10009

using namespace std;
main()
{
//	ofstream file("shivam");
    bool isPrime[MAX]={1,1};
    int check[MAX];
    int s=sqrt(MAX);
	int a;
	int k=0;
    for(int i=2;i<=s;i++)
	{
		 a=i;
//		 cout<<isPrime[i]<<" ";
		if(!isPrime[i])
		{
    		for(int j=a*a;j<=MAX;j+=2*i)
     		{
				isPrime[j]=1;
            //	cout<<j<<" ";
	    	}
	    //	check[k++]=i;
		}
	}
	check[k++]=2;
	for(int i=3;i<MAX;i+=2)
	if(!isPrime[i])
	{
		check[k++]=i;
		//cout<<check[k-1]<<" ";
	}
	int t,n,count;
	int p,q;
	scanf("%d",&t);
	while(t--)
	{
			count=0;
	//		n=t;
			scanf("%d",&n);
			if(n<=5)
			{
				   cout<<"0\n";
				   continue;
			}
			for(int i=0;i<n&&check[i]<n-2;i++)
			{
                   if(!((n-check[i])%2))
                   {
						p=check[i];
						q=(n-check[i])/2;
						if(!isPrime[p]&&!isPrime[q]&&(q==2||q%2))
					 //   cout<<check[i]<<" "<<(n-check[i])<<" ";
						count++;
					}
			}
			cout<<count<<endl;
	}

    return 0;
}
