//      O(log n) algo to calculate fibonacci


#include<iostream>
using namespace std;
#define MAX 2
#define MOD 1000000007
long long int fib[MAX][MAX]={{1,1},{1,0}};
long long int a=1,b=1,c=1,d=0;
void calFib(int n)
{
	 if(n==2)
	{
            fib[0][0]=2;
		    fib[0][1]=1;
            fib[1][0]=1;
            fib[1][1]=1;
	 }
	else if(n>2)
	{
		calFib(n/2);
		a=  fib[0][0]%MOD;
		b=  fib[0][1]%MOD;
		c=  fib[1][0]%MOD;
		d=  fib[1][1]%MOD;
	//	cout<<a<<" ";
		fib[0][0]=((a*a)%MOD+(b*c)%MOD)%MOD;
		fib[0][1]=((a*b)%MOD+(b*d)%MOD)%MOD;
		fib[1][0]=((c*a)%MOD+(d*c)%MOD)%MOD;
		fib[1][1]=((c*b)%MOD+(d*d)%MOD)%MOD;

		if(n%2)
		{
			   a=fib[0][0];
			   b=fib[1][0];
               fib[0][0]=(fib[0][0]+fib[0][1])%MOD;
		       fib[0][1]=a;
		       fib[1][0]=(fib[1][0]+fib[1][1])%MOD;
		       fib[1][1]=b;

		}
	}
}

main()
{
	long long int n;
	cin>>n;
	if(n==1) {
		cout << 0 << endl;
	}
	else {
		for(int i=0;i<n-1;i++) {
		    fib[0][0]=1;
		    fib[0][1]=1;
	        fib[1][0]=1;
			fib[1][1]=0;
	        a=1,b=1,c=1,d=0;
			calFib(i);
			cout<<fib[0][0]<<" ";
		}
	}
}
