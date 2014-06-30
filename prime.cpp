#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>

#define sq 100000
#define MAX 1000000009
using namespace std;

vector<bool> isPrime(MAX,1);

void sieve2(int n) {

	int s=sqrt(n);
	int a;
	
	for(int i=4;i<=sq;i+=2)
	isPrime[i] = 0;
	
	for(int i=2;i<=s;i++)
	{
		a=i;
		if(isPrime[i])
    	for(int j=a*a;j<=n;j+=2*i)
     	{
			   isPrime[j]=0;
	    }
	}
}

void sieve(int n,int m) {

	int s=sqrt(n);
	int a;
	for(int i=2;i<=s;i++)
	{
		a=i;
		if(isPrime[i]) {
		
			int j=m;
			while(j%i)	j++;
			
			for(int k=j;k<=n;k+=i)
			isPrime[k] = 0;
		}
	}
}

int main()
{
	
	sieve2(sq);
	
//	for(int i=0;i<100;i++)
//	if(isPrime[i])
//	cout << i << " ";
		
	int n;
	cin>>n;

	while(n--) {
	
		int a,b;
		cin >> a >> b;
		
		if(b > sq)
		sieve(b,a);
		
		for(int i=a;i<=b;i++)
		if(isPrime[i] && i != 1) 
		cout<<i<<endl;
		cout << endl;
	}
}
