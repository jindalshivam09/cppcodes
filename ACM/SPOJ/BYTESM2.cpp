
#include<iostream>
#include<vector>
#include<list>
#include<utility>
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
#define MAX 109		
int h,w ;
vector<vi> tiles(MAX,vi(MAX)),memo(MAX,vi(MAX));
int dp(int i,int j) {
//	cout << i << " "<< j << endl;
	if(i<0 || i>=h || j<0 || j>=w)
		return 0;
	if(memo[i][j]>-1)
		return memo[i][j];
	int temp = dp(i+1,j-1);
	temp = max(temp,dp(i+1,j));
	temp = max(temp,dp(i+1,j+1));
	return memo[i][j]=temp+tiles[i][j];
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> h >> w ;
		rep(i,h)
			rep(j,w)
				cin >> tiles[i][j] , memo[i][j]=-1;
			
		int ans = 0;
		rep(i,w)	
			ans = max(ans,dp(0,i));
		cout << ans << endl;
	}
}


