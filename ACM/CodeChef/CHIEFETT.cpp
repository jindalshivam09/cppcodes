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

#define MAX 1009
vi price , discount ;
int n,k;
vector<vi> memo(MAX,vi(MAX));

ll nCr (int n,int k ) {
	ll ans = 1;
	if ( k > n/2)
		k = n - k ;
	for(int i=1;i<=k;i++) 
		ans = (ans*(n+1-i))/i;
//	cout << ans << endl;
	return ans;
}

ll dp ( int i=0,int j=0 ) {
	if ( n-i < k-j)
		return 0;
	if(i==n || j==k)
		return 0 ;
	if(memo[i][j])
		return memo[i][j];
	ll ans = 0 ;
	for(int l=i;l<n;l++) {
		if ( n-l >= k-j ) {
//			cout << l << " " << j << endl;
			ans += (price[l]*discount[j]*nCr(n-l-1,k-j-1)) + dp(l+1,j+1);
		}
		else	
			break;
	}
	return memo[i][j] = ans ;
} 

int main() {
	int t;
	cin >> t;
	while(t--) {
//		cin >> n >> k ;
		n = 1000 , k = 1000 ;
		price.resize(n,0);
		discount.resize(k,0);
		rep(i,n)	
			price[i] = i+3 ;;
		rep(i,k)
			discount[i] = i+3;
		ll ans = dp();
		printf("%.3f\n",(double)ans/(nCr(n,k)*100));
		rep(i,MAX)
			rep(j,MAX)
				memo[i][j] = 0;
		
	}
}
