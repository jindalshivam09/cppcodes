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
#define MAX 300
#define MOD 1000000007
ll n,k;
vll freq(MAX);
vll arr(MAX);
set<ll> uni;
vll fact(MAX);
vector<vll> C(MAX+1,vll(MAX+1));
long long mulmod(long long a,long long b,long long c){    
	long long x = 0,y=a%c;   
	while(b > 0){        
		if(b%2 == 1){    
		    x = (x+y)%c;        
		}        
		y = (y*2)%c;        
		b /= 2;   
	}    
	return x%c; 
}

void binomialCoeff(ll n, ll k)
{
    ll i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = ( C[i-1][j-1] + C[i-1][j] )%MOD;
        }
    }
}

void init () {
	binomialCoeff(MAX,MAX);
	fact[1] = 1;
	fact[0] = 1;
	for(ll i=2;i<MAX;i++) {
		fact[i] =  mulmod( i , fact[i-1] ,  MOD) ;
	}
}
ll memo[MAX][MAX][MAX];
ll dp(ll m =-1, ll i=0 , ll exc = 0) {
	cout << i-1 << " " << m << " " << exc << endl;
	if (memo[i][m][exc])
		return memo[i][m][exc];
	if (exc == k) {
		if ( m == arr[n-1])
			return fact[n-i];
		else if ( m < arr[n-1] )
			return 0;
	}
	else if ( exc < k && m == arr[n-1])
		return fact[n-i];
	ll ans = 0;
	for(set<ll>::iterator itr = uni.begin() ; itr != uni.end() ; itr ++) {
		ll j = *itr;
		ll temp = freq[j];
		ll count = 0;
		while (freq[j]>0) {
			freq[j]-- ;
			count++ ;
			cout << "(" << j << " " << freq[j] <<  ")";
			if ( j > m )
				ans = (ans + mulmod((C[temp][count] ) , dp (j, i+temp - freq[j] , exc+1) , MOD ))%MOD ;
			else
				ans = (ans + mulmod((C[temp][count] ) , dp (m, i+temp - freq[j] , exc) , MOD ))%MOD ;
		}				
		freq[j] = temp;
	}
	cout << ans << endl;
	return memo[i][m][exc] = ans ;
}
int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		arr.resize(n,0);
		rep(i,n) {
			cin >> arr[i];
			uni.insert(arr[i]);
			freq[arr[i]] ++;
		}
		sort(all(arr));
		ll ans = 0;
		for(int i=0;i<n;i++) {
			freq[arr[i]] --;
			ans = (ans + dp(arr[i]))%MOD;
//			cout << dp(arr[i]) << " ";
			freq[arr[i]] ++ ;
			cin.get();
		}
		cout << ans << endl ;
		for(int i=0;i<MAX;i++) 
		for(int j=0;j<MAX;j++) 
		for(int k=0;k<MAX;k++) 
		memo[i][j][k] = 0 ;
		for(int i=0;i<MAX;i++) 
		freq[i] = 0;
		uni.clear();
//		freq.clear();
	}
}


