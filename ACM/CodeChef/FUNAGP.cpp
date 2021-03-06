#include<bits/stdc++.h>
using namespace std;

#define MAX 100009
typedef long long ll;
ll N, Q, R, p1, p2 ;
vector<ll> arr(MAX), r1(MAX), r2(MAX);
vector<ll> inversePower(2) ;
typedef struct node {
	ll sum1,sum2;
	ll s1, s2, d1, d2, sz;
	bool isLazy ;
} node;

vector<node> segment(4*MAX) ;


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


long long int calPow(ll q,ll n,ll MOD)
{
	 long long int ans;
	 if(n==0)	return 1%MOD;
	 if(n==1)	return q%MOD;
	 else{
		ans=calPow(q,n/2,MOD)%MOD;
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
	r1[0] = 1%p1, r2[0] = 1%p2 ;
	for(int i=1;i<=N;i++) {
		r1[i] = (r1[i-1]*R)%p1;
		r2[i] = (r2[i-1]*R)%p2;
	}	
	inversePower[0]=calPow(((1-R)*(1-R))%p1,p1-2,p1);
	inversePower[1]=calPow(((1-R)*(1-R))%p2,p2-2,p2);
}

long long sumAGP(long long a,long long d,long long r,long long n,long long mod) {
	a %= mod;
	d %= mod;
	r %= mod;
	
	if(r==1)
	{
		long long ans1=(((a*n)%mod)+((((n*(n-1))/2)%mod)*d)%mod)%mod;
		return ans1;
	}
	else
	{
		long long ans1=a*(1-r);
		ans1%=mod;
		ans1+=mod;
		ans1%=mod;
		
		long long ans2;
		if(mod == p1)
			ans2 = (d*((r1[n]-r+mod)%mod))%mod;
		else
			ans2 = (d*((r2[n]-r+mod)%mod))%mod;
		ans2 += mod ;
		ans2 %= mod ;

		long long ans3 ;
		if(mod == p1)
			ans3 = (((a+(n-1)*d)%mod)*((r1[n]*(mod+1-r)%mod)%mod))%mod;
		else
			ans3 = (((a+(n-1)*d)%mod)*((r2[n]*(mod+1-r)%mod)%mod))%mod;
		ans1 -= (ans2+ans3)%mod;
		ans1 += mod ;
		ans1 %= mod ;
		
		ans1 *= inversePower[mod==p2] ;
		ans1 %= mod ;
		return ans1 ;
	}
}

void init_segment (int num, int a, int b) {
	if(a>b)
		return ;
	segment[num].s1 = segment[num].s2 = segment[num].d1 = segment[num].d2 = segment[num].sum1 = segment[num].sum2 = segment[num].sz = 0; 
	segment[num].isLazy = false ;
	if(a == b) {
		segment[num].sum1 = arr[a]%p1 ;
		segment[num].sum2 = arr[a]%p2 ;
		segment[num].sz = 1 ;
		return ;
	}
	int mid = (a+b)/2 ;
	init_segment(2*num,a,mid) ;
	init_segment(2*num+1,mid+1,b) ;
	segment[num].sum1 = (segment[2*num].sum1 + segment[2*num+1].sum1)%p1 ;
	segment[num].sum2 = (segment[2*num].sum2 + segment[2*num+1].sum2)%p2 ;
	segment[num].sz = segment[2*num].sz + segment[2*num+1].sz ;
	return ;
}

void push_lazy (int i, int j, int num) {
	if(segment[num].isLazy == true) {
		segment[num].sum1 = (segment[num].sum1 + sumAGP(segment[num].s1,segment[num].d1,R,segment[num].sz,p1)) % p1 ;
		if(i==j) 
			segment[num].sum2 = ( segment[num].sum2 + sumAGP(segment[num].s2,segment[num].d2,R,segment[num].sz,p2 )) % p2;
		else {
			int mid = (i+j)/2+1 ;
			segment[2*num].isLazy = segment[2*num+1].isLazy = true;

			segment[2*num].s1 = (segment[2*num].s1 + segment[num].s1) % p1 ; 
			segment[2*num].s2 = (segment[2*num].s2 + segment[num].s2) % p2 ; 
			segment[2*num].d1 = (segment[2*num].d1 + segment[num].d1) % p1 ; 
			segment[2*num].d2 = (segment[2*num].d2 + segment[num].d2) % p2 ;

			segment[2*num+1].s1 = (segment[2*num+1].s1 + ((segment[num].s1+(segment[num].d1*(mid-i)))%p1*(r1[mid-i]))%p1 ) % p1 ;
			segment[2*num+1].s2 = (segment[2*num+1].s2 + ((segment[num].s2+(segment[num].d2*(mid-i)))%p2*(r2[mid-i]))%p2 ) % p2 ;
			segment[2*num+1].d1 = (segment[2*num+1].d1 + (segment[num].d1*r1[mid-i])%p1) % p1 ; 
			segment[2*num+1].d2 = (segment[2*num+1].d2 + (segment[num].d2*r2[mid-i])%p2) % p2 ;
			
		}
		segment[num].s1 = segment[num].s2 = segment[num].d1 = segment[num].d2 = 0;
		segment[num].isLazy = false ;
	}
}

void update (int num, int i, int j, int a, int b, ll s, ll d) {
	push_lazy(i,j,num) ;
	if(j < a || i > b)
		return ;
	if(i >= a && j <= b) {
		segment[num].isLazy = true ;
		ll s1 = (((s + ((i-a)*d)))%p1*r1[i-a])%p1 ;
		ll s2 = (((s + ((i-a)*d)))%p2*r2[i-a])%p2 ;
		ll d1 = (d*r1[i-a])%p1 ;
		ll d2 = (d*r2[i-a])%p2 ;
		segment[num].s1 = (segment[num].s1 + s1)%p1 ;
		segment[num].s2 = (segment[num].s2 + s2)%p2 ;
		segment[num].d1 = (segment[num].d1 + d1)%p1 ;
		segment[num].d2 = (segment[num].d2 + d2)%p2 ;

		push_lazy(i,j,num) ;
		return ;
	}
	int mid = (i+j)/2 ;
	update(2*num,i,mid,a,b,s,d) ;
	update(2*num+1,mid+1,j,a,b,s,d) ;
	segment[num].sum1 = (segment[2*num].sum1 + segment[2*num+1].sum1) % p1;
	segment[num].sum2 = (segment[2*num].sum2 + segment[2*num+1].sum2) % p2;
	return ;
}

void point_update(int num, int i, int j, int a, ll g) {
	push_lazy(i,j,num) ;
	if(j<a || i>a)
		return ;
	if(i == j) {
		segment[num].sum2 = calPow(segment[num].sum2,g,p2) ;
		segment[num].sum1 = segment[num].sum2 % p1 ;
		return ;
	}
	int mid = (i+j)/2 ;
	point_update(2*num,i,mid,a,g) ;
	point_update(2*num+1,mid+1,j,a,g) ;
	segment[num].sum1 = (segment[2*num].sum1 + segment[2*num+1].sum1) % p1 ;
	segment[num].sum2 = (segment[2*num].sum2 + segment[2*num+1].sum2) % p2 ;
	return ;
}

ll retrieval (int num, int i, int j, int a, int b) {
	push_lazy(i,j,num) ;
	if(i > b || j < a)
		return 0ll ;
	if(i>=a && j<=b)
		return segment[num].sum1 ;
	int mid = (i+j)/2 ;
	return ( retrieval(2*num,i,mid,a,b) + retrieval(2*num+1,mid+1,j,a,b) ) % p1 ;
}

int main() {
	int t ;
	t = read_int() ;
	while(t--) {
		N = read_int() ;
		Q = read_int() ;
		R = read_int() ;	
		p1 = read_int() ;
		p2 = read_int() ;
		init() ;
		for(int i=1;i<=N;i++)
			arr[i] = read_int() ;
		init_segment(1,1,N) ;
		while(Q--) {
			ll type, S, D, X, Y, g ;
			type = read_int() ;
			if(type == 0) {
				S = read_int() ;
				D = read_int() ;
				X = read_int() ;
				Y = read_int() ;
				update(1,1,N,X,Y,S,D) ;
			}
			else if (type == 1) {
				X = read_int() ;
				g = read_int() ;
				point_update(1,1,N,X,g) ;
			}
			else {
				X = read_int() ;
				Y = read_int() ;
				printf("%lld\n",retrieval(1,1,N,X,Y));
			}
		}
	}
}
