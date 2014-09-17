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
#define MAX 10000009
pair<ll,pii> Q[MAX] ;
map<ll,pii> mapped ;
ll five=400000003, seven=142857144 ;
int a,b,c,d,digits;
ll P;
int cnt ;
long long int calPow(int q,int n)
{
	 long long int ans;
	 if(n==1)	return q;
	 if(n==0)	return 1;
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

void init() {
	ll val ;
	cnt = 0;
	ll mula=1,mulb=1 ;
	rep(i,2100) {
		int tempa = i ;
		mula = i ? (2*mula)%MOD : 1 ;
		rep(j,1400) {
			int tempb = j ;
			mulb = j ? (3*mulb)%MOD : 1 ;
			int tot = tempb / 2 + ( (tempb&1) ? (tempa+4)/3 : (tempa+2)/3 ) ;
			if(tot < 700) {
				val = ( mula * mulb ) % MOD ;
				Q[cnt++] = (mp(val,mp(tempa,tempb)));
			}
			else
				break;
		}
	}	
	sort(Q,Q+cnt) ;

}
vi powers(10) ;
int dig ;
void best (int a, int b, int c, int d,int digits) {
//	cout << (((calPow(2,a)*calPow(3,b))%MOD*calPow(5,c))%MOD*calPow(7,d))%MOD << endl;;
	vi temp(10) ;
	temp[9] = b/2, b%=2 ;
	temp[8] = a/3, a%=3 ;
	temp[7] = d;
	int tmp = min(a,b) ;
	temp[6] = tmp , a -= tmp, b -= tmp ;
	temp[5] = c ;
	temp[4] = a/2, a%=2;
	temp[3] = b ; 
	temp[2] = a ;
	bool flag = false ;
	if(dig > digits)
		dig = digits, flag = true ;
	else if(dig == digits) {
		repi(i,2,10)
			if(powers[i] < temp[i]) {
				flag = true ;
				break;
			}
			else if(powers[i] > temp[i]) {
				flag = false ;
				break;
			}			
	}
	if(flag == true)
		rep(i,10)
			powers[i] = temp[i] ;
}
void func() {
	ll mul = 0 ;
	ll mulc=1,muld=1;
	bool flag = false ;
	rep(i,700) {
		mulc = i ? (five*mulc)%MOD : 1 ;
		int tempc = i ;
		rep(j,700) {
			muld = j ? (seven*muld)%MOD : 1 ;
			flag = false ;
			int tempd = j ;
			if(tempc + tempd < 700) {
				mul = ( (mulc*muld) % MOD * P ) % MOD  ;
				int index = lower_bound (Q,Q+cnt,mp(mul,mp(0,0))) - Q ;
				if(Q[index].first == mul) {
					int p = Q[index].second.first , q = Q[index].second.second ;
					digits = q/2 + ( (q&1) ? (p+4)/3 : (p+2)/3 ) + tempc + tempd ;
					if( digits <= dig) {
						a = p, b = q, c = tempc, d = tempd ;
						best(a,b,c,d,digits) ;
					}
///					else	
//						break;
				}
			} 
			else
				break;
		}
	}
}

void number () {
	rep(i,10)
		powers[i] = 700;
	dig = 700 ;
	int temp ;
	func() ;
	
	char  str[dig]  ;
	repi(i,2,10) 
		while(powers[i]--)
			printf("%c",i+'0') ;
	printf("\n") ;
}

int main() {
	init() ;
	int t;
	scanf("%d",&t) ;
//	t = 15 ;
	while(t--) {
		scanf("%lld",&P) ;
//		P = 1000000006;
		if(P == 1)
			printf("1\n") ;
		else if(P == 0)
			printf("10\n") ;
		else
			number();
	}
}
