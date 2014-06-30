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

vi number ;
int digit; 
int memo[100][2][2][2] ;
int dp(int i,bool shorter,bool found, bool started) {
	if(i==number.size())
		return 0 ;
	if(memo[i][shorter][found][started] != -1)
		return 	memo[i][shorter][found][started] ;
	int ret = 0 ;
	bool nshorter = false, nfound = false , nstarted = false ;
	for(int j=0;j<=9;j++) {
		if(shorter && number[i]<=j)
			nshorter = true ;
		else break;
		if (started || (number[i]!=0) )
			nstarted = true ;
		if( nstarted && (found || (number[i] == digit)) )
			nfound = true ;
		ret += dp(i+1,nshorter,nfound, nstarted) ;
	}
	return memo[i][shorter][found][started] = ret ;
}

int main() {
	int t ;
	cin >> t ;
	while(t--) {
		ll n ,temp;
		cin >> n ;
		temp = n ;
		vi str ; 
		while(temp) {
			str.pb(temp%10) ;
			temp /= 10 ;
		}
		
		for(int i=str.size()-1;i>=0;i--) {
			number.pb(str[i]);
		}
		ll ans = 0, den = n*10 ;
		rep(i,10) {
			memset(memo,-1,sizeof(memo)) ;
			digit = i ;
			ans += dp(0,0,0,0) ;
		}
		ll div = __gcd(ans,den) ;
		cout << ans/div << "/" << den/div << endl;
	}
}


