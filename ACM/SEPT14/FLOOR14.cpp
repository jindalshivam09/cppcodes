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

ll MOD ;


#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
inline ll read_int()
{
int flag=1;
long long n = 0;
char c;
int sign=1;
while (1)
{
c=GETCHAR();
if(c=='-')	sign=-1;
else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
 }
return sign*n;
}

long long calPower(long long int a,long long int b)
{	
	long long x=1,y=a; 
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD; 
		b /= 2;
	}
	return x;
}

ll power4 ( ll a ) {
	ll val[5], rem[5] ;
	val[0] = ((a)/30) ;
	rem[0] = (a) % 30 ;
	repi(i,1,5) 
		val[i] = ((val[i-1]*(a))%MOD)%MOD , val[i] = (val[i]+(rem[i-1]*a)/30)%MOD ,  rem[i] = (rem[i-1]*a) % 30 ;


	ll result = (6*val[4] + 15*val[3] + 10*val[2] - a/30 ) ;
	ll remainder = (6*rem[4] + 15*rem[3] + 10*rem[2] - a%30 ) ;

//	cout << result << " " << remainder << endl;
	result += remainder/30 ; 
	return result%MOD;
}

ll summation ( ll a, ll b ) {
	return ( power4(b) - power4(a) + MOD ) % MOD ;
}

ll values ( ll n ) {
	ll ans = 0 ;
	for(ll i=1;i*i<=n;i++) {
		ans = ( ans + ( calPower(i,4) * (n/i) )  ) % MOD;
//		cout << ans << " " << calPower(i,4) << endl;
		if(i != (n/i)) {
			ll temp = (n/(i+1)) ;
			if(temp != n/i)
				ans = ( ans + ( summation(temp,n/i) * i ) ) % MOD;
			else
				ans = ( ans + ( calPower(temp,4) * (i) ) ) % MOD;
				
		}
//		cout  << ans << endl;
	}
	return ans ;
}

int main() {
//	ifstream cin("test.txt") ;
//	ofstream cout("3.txt") ;

	int t  ;
	t = read_int() ;
	while(t--) {
		ll n, m ;
//		cin >> n >> m;
	n = read_int() ;
	m = read_int() ;
		MOD = m ;
//		cout << values(n) << endl;
		printf("%lld\n",values(n)) ;
	}
}


