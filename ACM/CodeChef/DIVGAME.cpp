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
#define TEST 3
#define TEN 1000000000
unsigned long long mulMod(unsigned long long a,unsigned long long b,unsigned long long n) {
	unsigned long long	a_low = a % TEN;
	 unsigned long long	a_high = a / TEN;
	 
	unsigned long long 	b_low = b % TEN;
	unsigned long long  	b_high = b / TEN;
	  
	  unsigned long long	result = (a_high * b_high) % n;
	 
	 for(int i=0;i<9;i++)
	     result = (result * 10) % n;
	 result = (result + a_low*b_high + b_low*a_high) % n;
	 for(int i=0;i<9;i++)
	    result = (result * 10) % n;
	 result = (result + a_low*b_low) % n;
	 return result;
}
unsigned long long  calPow(unsigned long long q,unsigned long long n,unsigned long long MOD) {
	 long long int ans;
	 if(n==1)
			return q;
	else	{
		ans=calPow(q,n/2,MOD)%MOD;
		ans=mulMod(ans,ans,MOD);
		ans%=MOD;
		if(n%2)	{
				  ans=mulMod(ans,q,MOD);
				  ans%=MOD;
		}
	}
	return ans;
}

bool isPrime(unsigned long long n) {
	unsigned long long  a;
	if(n==2 || n==3)
	return true;
	if(!(n%2))
	return false;
	int i=0,t=TEST;
	unsigned long long first;
	unsigned long long temp = n-1;
	while(!(temp&1)) {
		temp = temp>>1;
		i++;
	}
	while(t--) {
		bool flag= false;
		a = rand()%(n-1)+1;
		first = calPow(a,temp,n);
		if(first == 1)
		continue;
		else {
			if(first == n-1)
			continue;
			for(int j=1;j<i;j++) {
				first =mulMod(first,first,n)%n;
				if(first == n-1){
					flag = true;
					break;
				}
			}
			if(!flag)
			return false;
			flag=false;
		}
	}
	return true; 
}

bool win (ll n) {
	if ( n == 2 || n == 17)
		return true ;
	if ( n == 16 || n == 34 || n == 289 )
		return false;
	if ( isPrime(n)) 
		return false ;
	return true ;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n ;
		scanf("%d",&n);
		if (win(n))
			printf("Mike\n");
		else
			printf("Tom\n");
	}	
}


