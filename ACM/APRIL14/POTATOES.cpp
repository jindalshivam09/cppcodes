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

#define MAX 10000009
bool isPrime[MAX];
vector<int> prime;

void sieve(int n) {

	int s=sqrt(n);
	int a;
	for(int i=2;i<=s;i++)
	{
		a=i;
		if(!isPrime[i])
    	for(int j=a*a;j<=n;j+=2*i)
			   isPrime[j]=1;
	}
	int j=2;
	prime.pb(2);
	for(int i=3;i<=n;i+=2)
	if(!isPrime[i])
		prime.pb(i) ;
}

int main() {
	sieve(MAX) ;
	int t;
	cin >> t ;
	while(t--) {
		int x,y;
		cin >> x >> y ;
		int num = lower_bound(all(prime),x+y+1) - prime.begin() ;
//		cout << prime[num] << endl; 
		cout << prime[num] - x - y << endl;
	}
}


