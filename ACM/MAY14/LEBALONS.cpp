// wrong code -----------------------------

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

vi C, P ;
int n, m;
ll cnt;
map<int,int> used ;
vector<vector<pair<bool,ll>> >  memo ;
vll sum ;
ll p(int q,ll n)
{
	 ll ans;
	 if(n==0)
	 	return 1;
	 if(n==1)
       		return q;
	else {
		ans=p(q,n/2);
		ans*=ans;
		if(n%2)
		{
				  ans*=q;
		}
	}
	return ans;
}

pair<ll,ll> dp (int i, int colors) {
//	cout << i << " " << colors << endl;
	if(m-colors > n-i)
		return mp(0,0);
	if(i==n) {
		if(colors>=m) {
			cnt ++ ;
			return mp(1,0) ;
		}
		return mp(0,0) ;
	}
	
	if(colors >= m) {	
		ll temp2 = ( i ? sum[i-1] : 0 );
		ll temp = (sum[n-1] - temp2)*p(2,n-i-1) ;
//		cout << "in colors == m .." << temp2 << " "<< temp << endl;
		cnt = p(2,n-i) ;
		return  mp(cnt,temp);
	}
	
	if (memo[mp(i,colors)].first)
		return memo[mp(i,colors)] ;
		
	pair<bool,ll> ans(mp(false,0)) ;
	int clr = C[i] ;

	if ( used[clr] ) {
		ll temp = cnt ;
		pair<ll,ll> ret = dp(i+1,colors) ; 
		if(ret.first) 
			ans = mp(true,P[i]*(cnt-temp)+2*(ret.second)) ;
	}
	else {
		used[clr] = 1 ;
		int temp = cnt ;
		pair<bool,ll> ret = dp(i+1,colors+1) ; 
		if(ret.first == true) 
			ans = mp(true,P[i]*(cnt-temp)+ret.second) ;
		used[clr] = 0 ;
		ret = dp(i+1,colors) ; 
		if(ret.first == true) 
			ans = mp(true,ans.second+ret.second) ;
	}
	return memo[mp(i,colors)] = ans ;
}

int main() {
//	ifstream cin("output.txt") ;
	int t;
	cin >> t; 
	while(t--) {
		cin >> n >> m;
		C.resize(n) ;
		P.resize(n) ;
		sum.resize(n) ;
		cnt = 0;
		used.clear() ;
		memo.clear() ;
		rep(i,n)  {
			cin >> C[i] >> P[i] ;
			sum[i] = P[i] + (i ? sum[i-1] : 0) ;
//			cout << sum[i] << " ";
		}
		pair<bool,ll> ans = dp(0,0) ;
//		cout << "values -> " << ans.second << " " << cnt << endl;
		printf("%0.9f\n",double(ans.second)/cnt) ;
	}
}


