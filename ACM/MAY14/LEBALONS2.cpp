#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<ll,ll> 	pll;
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
#define MAX 45
int n,m ;
vector<vll> adj ;
vi arr;
map<pll,pair<ll,ll> > memo ;
vector<vi > visited(MAX,vi(MAX)) ;
vll sum ;
int dis;
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

pair<ll,ll> dp(int i,int color) {
//	cout << i << " " << color << endl;
	if(dis-i < color)
		return mp(0,0) ;
	if(i==dis)
		return mp(1,0) ;
	if(visited[i][color])
		return memo[mp(i,color)] ;
	if(color == 0) {
		ll tot = 0 , size = 0 ;
		repi(j,i,dis) {
			int temp = arr[j];
			tot += sum[temp] , size += adj[temp].size() ;
		}
		return mp( p(2,size) , tot*p(2,size-1) ) ;
	}
	int temp = arr[i] ;
	ll ans = sum[temp]*(p(2,(adj[temp].size()-1)) ) ;
	ll cnt = (  p(2,adj[temp].size() ) - 1 ) ;
//	cout << cnt << endl;
	pair<ll,ll> ret = dp ( i+1 , color-1 ) ;
//	cout << i << " " << ret.first << " " << ret.second << endl;
	if( ret.first ) {
		ret.second = ans*ret.first + cnt*ret.second ;
		ret.first *= cnt ;
	}
//	cout << i << " " << ret.first << " "<< ret.second << endl;
	pair<ll,ll> ret2 = dp(i+1,color) ;
	if ( ret2.first ) 
		ret.second += ret2.second , ret.first += ret2.first ; 
//	cout << i << " " << ret.first << " "<< ret.second << endl;
	visited[i][color] = 1 ;
	return memo[mp(i,color)] = ret ;
}

int main() {
//	ifstream cin("output.txt") ;
//	freopen("lebalon.txt","w",stdout);
	int t;
	cin >> t ;
	while(t--) {
		cin >> n >> m ;
		adj.resize(45) ;
		sum.resize(45) ;
		int a,b ;
		map<int,int> put ;
		rep(i,n) {
			cin >> a >> b ;
			adj[a].pb(b) ;
			sum[a] += b ;
			if(put[a]==0) {
				put[a] = 1 ;
				arr.pb(a) ;
			}
		}		
		dis = put.size() ;
		pair<ll,ll> ans = dp(0,m) ;
		printf("%0.6f\n",(double)ans.second / ans.first) ;
//		cout << ans.second << " " << ans.first <<endl;
		for(map<pair<ll,ll>,pair<ll,ll> >::iterator itr = memo.begin() ; itr != memo.end() ; itr ++ )
			cout << (itr->second).first << " " << (itr->second).second << endl;

		adj.clear() ;
		memo.clear(); 
		sum.clear();
		put.clear ();
		arr.clear();
		rep(i,n+1)
			rep(j,n+1)
				visited[i][j] = 0 , sum[j] = 0;
	}
}
