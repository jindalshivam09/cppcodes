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
#define MAX 50001
int n;
vi arr(MAX);
map<pii,int> memo; 

int dp( int i=0 , int count=0 , int cost=0 ) {

//	cout << i << " " << count << " " << cost << endl;
	if( memo[mp(i,count)] )
		return memo[mp(i,count)];
	if( i == n )
		return -1*cost; 
		
	int share = imin;		
	share = dp(i+1,count,cost);
	share = max( share , dp(i+1,count+1,cost+arr[i]) );
	share = max( share , count*arr[i] - cost + dp(i+1,0,0) );

	return memo[mp(i,count)] = share;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		
		cin >> n;
		rep(i,n)
			cin >> arr[i];
			
		cout << dp() << endl;
		memo.clear();
	}
}


