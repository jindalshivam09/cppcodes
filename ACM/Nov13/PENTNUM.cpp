#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;

#define MAX 1000000

vector<bool> isPrime(MAX);
vector<long long> prime(MAX);
long long tot_prime  = 0;


void sieve(long long n) {

	long long s=sqrt(n);
	long long a;
	isPrime[1] = 0;
	isPrime[0] = 1;
	for(long long i=2;i<=s;i++)
	{
		a=i;
		if(!isPrime[i])
    	for(long long j=a*a;j<=n;j+=i)
			   isPrime[j]=1;
	}
	long long j=2;
	prime[0] = 1;
	prime[1] = 2;
	for(long long i=3;i<=n;i++)
	if(!isPrime[i])
		prime[j++] = i;
	tot_prime = j;	
//	cout << j << endl;
//	for(int i=0;i<100;i++)
//	cout << prime[i] << " ";
}

vector<long long> divisors(MAX);

int main() {
	
//	float r = clock_t()/CLOCKS_PER_SEC;
	sieve(MAX);
	
	long long t;
	cin >> t;
	while(t--) {
		
		long long a,b;
		cin >> a >> b;
		
		divisors.clear();
		divisors.resize(MAX);
		
		for(long long i=1;i<tot_prime;i++) {
			
			long long p = prime[i];
			long long temp = a;
			if(a%p)
			temp = a - (a%p) + p;	
			long long temp2 = p;
				
			int power = 1;
			for(;;power++) {
				
				if(temp2 >= a)
					break;
					
				temp2 *= p;	
			}
					
//			if(!power)		power ++;
		
			long long count = power;
			
//			cout << power << " " << count << endl;
			long long last = temp2;
//			cout << temp << " "<< temp2 << endl;
			
			for(long long j = temp ; j <= b ; j += p) {
				 
//				cout << j << " " << p << " " << last << endl;
				if(j==last && !(j%p)) {

					divisors[j-a] += count ;
					count ++;
					last *= p;
				}
				else if (!(j%p))		
					divisors[j-a] = -1 ;
//				cin.get();
			}
//			cin.get();
		}
		
		long long count = 0;
		
		for(long long i = 0 ; i <= b-a ; i ++) {
			
//			cout << a+i << " "<< divisors[i] << endl;
			if(!isPrime[divisors[i] + 1] && divisors[i] != -1) {
				
//				cout << a+i << " "<< divisors[i] << endl;
				count ++;
			}
//			cin.get();
		}
		
		if(a==1)		count--;
		cout << count << endl;
	}
	return 0;
}
