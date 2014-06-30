#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()

#define MAX 2000009
bool isPrime[MAX];
vector<int> prime(MAX);

void sieve(int n) {

	int s=sqrt(n);
	int a;
	for(int i=2;i<=s+1;i++)
	{
		a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=n;j+=i)
			   isPrime[j]=1;
	}
//	int j=2;
//	prime[1] = 2;
//	for(int i=3;i<=n;i+=2)
//	if(!isPrime[i])
//		cout << i << " " ;
}

#define MOD 1000000007
int main() {
	
	int n;
	cin >> n;
	sieve(2*n);
	
	long long ans = 0;
	for(long long i=2;i<2*n-1;i++) {
		
		if(!isPrime[i]) {
			
//			cout << i << " ";
			if(i < n) {
				
				ans += (i+1);
				ans %= MOD;
			}
			else {
				
//				long long temp = i-n+1;
				ans += (2*n-i-1);
				ans %= MOD ;
			}
		}
	}
	
	cout << ans%MOD << endl;
}


