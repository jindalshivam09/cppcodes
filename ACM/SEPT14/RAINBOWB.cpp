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

#define MOD 1000000007
long long int calPow(int q,int n)
{
	 long long int ans;
	 if(n==1)	return q;
	 else{
		ans=calPow(q,n/2)%MOD;
 		ans*=ans;
		ans%=MOD;
		if(n%2)	{
				  ans*=q;
				  ans%=MOD;
		}
	}
	return ans;
}


int main() {
	int n ;
	cin >> n ;
	if(n<13) {
		cout << 0 << endl;
		return 0;
	}
	if(n==13 || n==14) {
		cout << 1 << endl;
		return 0 ;
	}
	vll fact(n+1) ;
	fact[0] = fact[1] = 1 ;
	repi(i,2,n+1) {
		fact[i] = (i*fact[i-1]) % MOD ;
	}
	if(n%2)		n -= 13 ;
	else		n -= 14 ;
	n /= 2 ;
	
	cout << (((fact[n+6]*calPow(fact[6],MOD-2))%MOD ) * calPow(fact[n],MOD-2))%MOD ;
}


