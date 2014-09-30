/*
	Fib(n) = a*x^n + (1-a)*y^n 
	a = (3 + sqrt(5)) / (5 + sqrt(5))
	x = (1 + sqrt(5)) / 2
	y = (1 - sqrt(5)) / 2
*/

#include<bits/stdc++.h>
using namespace std;

#define SQRT5 383008016 
#define MOD5 146695140320256256
#define MOD 1000000009
#define MAX 300009
typedef long long ll;
int n,q ;
vector<int> arr(MAX);
vector<ll> x(MAX), y(MAX) ;
ll A  , X , Y, xmod, ymod ;
ll trans = 276601605 ;

long long int calPow(ll q,ll n)
{
	 long long int ans;
	 if(n==0)	return 1;
	 if(n==1)	return q%MOD;
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
//	A = ((3 + SQRT5) * calPow(5+SQRT5,MOD-2))%MOD ;
//	X = ((1 + SQRT5) * calPow(2,MOD-2))%MOD;
//	Y = ((1 - SQRT5 + MOD)%MOD * calPow(2,MOD-2))%MOD;
//	cout << A << " " << X << " " << Y << endl;
	A = 138300803, X = 691504013, Y = 308495997 ;
	xmod = calPow(X-1,MOD-2), ymod = calPow(Y-1,MOD-2) ;
	x[0] = y[0] = 1 ;
	for(int i=1;i<MAX;i++) 
		x[i] = (x[i-1]*X)%MOD, y[i] = (y[i-1]*Y)%MOD ;
/*	for(int i=0;i<20;i++) {
		ll fib = ((A*calPow(X,i)%MOD)%MOD + ((1-A+MOD)%MOD * calPow(Y,i))%MOD)%MOD ;
		cout << (fib)%MOD << endl;
	}
*/
}

ll sumGP(ll a, ll r, ll n) {
	ll temp ;
	if(r==X) {
		temp = (x[n] - 1 + MOD ) % MOD;
		temp = (temp * xmod) % MOD;
	}
	else {
		temp = (y[n] - 1 + MOD ) % MOD;
		temp = (temp * ymod) % MOD;		
	}
	return (a*temp)%MOD ;
}

typedef struct node {
	ll sum;
	ll a1, a2 ;
	bool lazy ;
}node ;
vector<node> segment(4*MAX) ;

void init_segment(int num, int i, int j) {
	if(i == j) {
		segment[num].sum = arr[i] ;
		segment[num].lazy = false ;
		segment[num].a1 = 0 ;
		segment[num].a2 = 0 ;
		return ;
	}
	int mid = (i+j)/2 ;
	init_segment(2*num,i,mid) ;
	init_segment(2*num+1,mid+1,j) ;
	segment[num].sum = (segment[2*num].sum + segment[2*num+1].sum) % MOD;
}

void push_lazy(int i, int j, int num) {
	if(segment[num].lazy == true) {
		segment[num].sum = ( segment[num].sum + (sumGP(segment[num].a1,X,j-i+1) + sumGP(segment[num].a2,Y,j-i+1) ) % MOD ) % MOD ;
		if(i != j) {
			int mid = (i+j)/2 + 1;
			segment[2*num].lazy = segment[2*num+1].lazy = true ;
			segment[2*num].a1 = (segment[2*num].a1 + segment[num].a1) % MOD;
			segment[2*num].a2 = (segment[2*num].a2 + segment[num].a2) % MOD;
			segment[2*num+1].a1 = (segment[2*num+1].a1 + (segment[num].a1*x[mid-i])%MOD)%MOD ;
			segment[2*num+1].a2 = (segment[2*num+1].a2 + (segment[num].a2*y[mid-i])%MOD)%MOD ;
		}
		segment[num].a1 = segment[num].a2 = 0 ;
		segment[num].lazy = false ;
	}
}

void update(int num, int i, int j, int a, int b) {
	push_lazy(i,j,num) ;
	if(i>b || j<a)
		return;
	if(i>=a && j<=b) {
		segment[num].lazy = true ;
		segment[num].a1 = (segment[num].a1 + (A*x[i-a])%MOD)%MOD;
		segment[num].a2 = (segment[num].a2 + ((1-A+MOD)%MOD*y[i-a])%MOD)%MOD;
		push_lazy(i,j,num) ;
		return ;
	}
	int mid = (i+j)/2 ;
	update(2*num,i,mid,a,b);
	update(2*num+1,mid+1,j,a,b) ;
	segment[num].sum = (segment[2*num].sum + segment[2*num+1].sum) % MOD ;
}

ll retrieval(int num, int i, int j, int a, int b) {
	push_lazy(i,j,num) ;
	if(i>b || j<a)
		return 0ll;
	if(i>=a && j<=b)
		return segment[num].sum ;
	int mid = (i+j)/2 ;
	return (retrieval(2*num,i,mid,a,b) + retrieval(2*num+1,mid+1,j,a,b)) % MOD;
}

int main() {
	init() ;
//	cin >> n >> q;
	scanf("%d%d",&n,&q) ;
	for(int i=1;i<=n;i++)
//		cin >> arr[i] ;
		scanf("%d",&arr[i]) ;
	init_segment(1,1,n) ;
	while(q--) {
		int type,l,r ;
//		cin >> type >> l >> r ;
		scanf("%d%d%d",&type,&l,&r) ;
		if(type == 1) {
			update(1,1,n,l,r) ;
		}
		else {
			cout << retrieval(1,1,n,l,r) << endl;
		}
	}	
}
