#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
#define MAX 1000000000

bool isPrime[MAX];
	
void sieve(int n){

	int s=sqrt(n);
	int a;
	for(int i=2;i<=s;i++)
	{
		 a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=n;j+=2*i)
     	{
			   isPrime[j]=1;
	    }
	}

}

int main() {

//	sieve(1000000000);
	double ans=0;
	int n;
//	cin >> n;
	int t = clock();

	for(int i=0;i<100000000;i++) {
	
//		if (!isPrime[i])
//		ans += (double)n/i;
	}
		int q = clock();
	cout << (q-t)/CLOCKS_PER_SEC;

	
	cout << ans;
}
