#include<bits/stdc++.h>
using namespace std;

#define MAX 1000009

bool isPrime[MAX];
vector<int> prime(MAX);

void sieve(int n) {

	int s=sqrt(n);
	int a;
	for(int i=2;i<=s;i++)
	{
		a=i;
		if(!isPrime[i])
    	for(int j=2*a;j<=n;j+=a)
			   isPrime[j]=1;
	}
}


int main() {
	sieve(MAX);
	int n ;
	cin >> n ;
	
	for(int i=4;i<=n-i;i++) {
		if(isPrime[i] && isPrime[n-i]) {
			cout << i << " "  << n-i << endl;
			return 0;
		}
	}
}
