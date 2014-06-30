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
#define MAX 201
#define MOD 1000000007

ll n,k;
vb visited(MAX);
vll arr(MAX);
vll fact(MAX);
ll maximum ;
void init () {
	fact[1] = 1;
	fact[0] = 1;
	for(ll i=2;i<MAX;i++) {
		fact[i] =  ( i * fact[i-1])%  MOD ;
	}
}

ll memo[MAX][MAX][MAX];
ll dp(ll m=0 , ll i=0 , ll exc = 0) {
	cout << i-1 << " " << m << " " << exc << endl;
	if (memo[i][m][exc])
		return memo[i][m][exc];
	if ( i == n )
		if (exc <= k)
			return 1;
		else
			return 0;
	if (exc == k) {
		if ( m == maximum)
			return fact[n-i];
		else if ( m < maximum )
			return 0;
	}
	else if ( exc < k && m == maximum)
		return fact[n-i];

	ll ans = 0;
	for (vll::iterator itr = arr.begin() ; itr != arr.end() ; itr ++) {
		int j = *itr;
		arr.erase(itr);
//			cout << arr[j] << " " << j << endl;
			visited[j] = true;
			if (j > m)
				ans = (ans + dp (j, i+1, exc+1) )%MOD;
			else
				ans = (ans + dp (m, i+1, exc))%MOD;
		arr.push_back(j);	
	}
	return memo[i][m][exc] = ans ;
}

int main() {
	init();
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		arr.resize(n,0);
		maximum = 0  ;
		rep(i,n) {
			scanf("%d",&arr[i]);	
			maximum = max ( maximum , arr[i]);
		}
//		sort(all(arr));
		ll ans = dp();
		printf("%d\n",ans);
		for(int i=0;i<MAX;i++) 
			for(int j=0;j<MAX;j++) 
				for(int k=0;k<MAX;k++) 
					memo[i][j][k] = 0 ;
		for(int i=0;i<MAX;i++)
			visited[i] = false;
	}
}


