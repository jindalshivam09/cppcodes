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

#define MAX 51
#define MAX2 61

vi chef1(MAX), chef2(MAX) ;
int n1,n2 ; 
int memo[MAX][MAX][MAX2];

int dp ( int i, int j, int diff) {
	if(diff >= MAX2)
		return imax ;
	if(i==n1&&j==n2)
		return diff ;
	if(memo[i][j][diff])
		return memo[i][j][diff] ;
	int ret = imax ;
	if(i<n1) {
		ret = min (ret,dp(i+1,j,max(chef1[i]-diff,0))+diff) ;
		ret = min (ret,dp(i+1,j,diff+chef1[i])) ;
	}
	if(j<n2) {
		ret = min (ret,dp(i,j+1,max(chef2[j]-diff,0))+diff) ;
		ret = min (ret,dp(i,j+1,diff+chef2[j])) ;
	}
	return memo[i][j][diff] = ret;
}

int main() {
	cin >> n1 >> n2 ;
	rep(i,n1)
		cin >> chef1[i] ;
	rep(i,n2)
		cin >> chef2[i] ;	
	cout << dp(0,0,0);
}


