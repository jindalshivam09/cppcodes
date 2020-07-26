#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#define MAX 1000009
using namespace std;


bool isPrime[MAX];
vector<int> prime(MAX);

void sieve(int n) {

	int s=sqrt(n);
	int a;
	for(int i=2;i<=s;i++)
	{
		a=i;
		if(!isPrime[i]) {
			for(int j=a*a;j<=n;j+=2*i)
			   isPrime[j]=1;
		}
	}
	
	int j=2;
	prime[1] = 2;
	for(int i=3;i<=n;i+=2) {
		if(!isPrime[i])	 prime[j++] = i;
	}
}

main()
{
	sieve(MAX);
	int n;
	cin>>n;
	cout << prime[n] << endl;
	while(1);

}
