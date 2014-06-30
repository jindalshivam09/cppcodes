#include<iostream>
#include<vector>

using namespace std;


bool isPrime[MAX];
vector<int> prime(MAX);

void sieve(int n,int m) {

	int s=sqrt(m);
	int a;
	for(int i=2;i<=s;i++)
	{
		a = n - n%i;
		if(!isPrime[i])
		for(int j = a ; j <= m ; j += 2*i )
			 isPrime[j]=1;
	}
	int j=0;
	prime[1] = 2;
	for(int i=n;i<=m;i++)
	if(!isPrime[i] && i%2)
		j++;
}


int main() {

	int t;
	cin >> t;
	while(t--) {

		int n,m;
		cin >> n >> m;
		cout << sieve(n,m);	
	}
}
