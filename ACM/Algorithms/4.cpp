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
	int j=2;

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
	prime[1] = 2;
	for(int i=3;i<=n;i+=2)
	if(!isPrime[i])
		prime[j++] = i;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		ll a,b,c,d ;
		vll A(MAX,0),B(MAX,0) ;
		cin >> a >> b >> c >> d ;
		int pa= 0, pc = 0;
		for(int i=2;i<MAX;i++ ) {
			int temp = i ;
			while(a % temp == 0) {
				a /= temp ;
				A[i] ++ ;
				pa ++ ;
			}
			while(c % temp == 0) {
				c /= temp ;
				B[i] ++ ;
				pc ++ ;
			}
			A[i] *= b ;
			B[i] *= d ;
		}
		bool flag = false ;
		rep(i,MAX) {
			if(B[i] > A[i]) {
				flag = true ;
				break;
			}
		}
		if( a != c && c!=1) 
			flag = true ;
		
		if(flag == false) 
			cout << "Divisible" << endl;
		else 
			cout << "Not divisible" << endl;
	
	}
}


