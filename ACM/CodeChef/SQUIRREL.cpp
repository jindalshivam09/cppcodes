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
vi T , P ;
int n,m,k;
int maxtime ;

bool greater_nuts(int t) {
	ll count = 0 ;
	vi temp(m);
	rep(i,m) {
		if ( t >= T[i] )
			temp[i] = (t-T[i])/P[i] + 1;
		else
			temp[i] = 0;
	}
	sort(all(temp),greater<int>());
	rep(i,min(n,m))
		count += temp[i] ;
	return count >= k ;
}

int time()  {
	int a = 1 , b = maxtime ;
	while( a < b ) {
		int mid = (a+b)/2;
		if ( greater_nuts(mid) )
			b = mid ;
		else
			a = mid + 1;
	}
	return a ;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&m,&n,&k);
		T.resize(m) ;
		P.resize(m);
		rep(i,m)
			scanf("%d",&T[i]);
		rep(i,m)
			scanf("%d",&P[i]);
		maxtime = imax ;
		rep(i,m)
			maxtime = min ( maxtime , k*P[i]+T[i]) ;
		printf("%d\n",time());
	}
}
