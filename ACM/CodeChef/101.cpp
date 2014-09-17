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
#define MAX 100009

bool isPrime[MAX];
vector<int> prime(MAX);
int primecnt = 0 ;
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
	prime[1] = 2;
	for(int i=3;i<=n;i+=2)
	if(!isPrime[i])
		prime[j++] = i;
	primecnt = j ;
}



int main() {
	sieve(MAX) ;
	int t ;
	cin >> t ;
	while(t--) {
		int r,k ;
		cin >> r >> k ;
		int cnt = 0 ;
		for(int j=1;j<primecnt;j++) {
			int i = prime[j];
			if ( r % i == 0 ) {
				cout << i << " " << i%4 << endl;;
				if ( (r/i)%4 == 1 )
					cnt ++;
				if ( i%4 == 1  ) 
					cnt ++ ;
			}
		}
		if(cnt == 0 && r%4 == 1)
			cnt ++ ;
		cout << cnt << endl;
		if ( k > 4*cnt)
			cout << "impossible" << endl;
		else
			cout << "possible" << endl; 
	}
}


