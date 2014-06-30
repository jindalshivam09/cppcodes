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

vector<vector<int>  > memo(MAX,vector<int>(MAX)); 

int dp(vi &arr,int n,int m,int k,int i=0) {
	
//	cout << m << " " <<  k << endl;;
	if(i == n)
		return 0;
	if(memo[i][k])
		return memo[i][k];
	if(arr[i] == 1) {
		
		if(!m)
			return memo[i][k] = 1 + dp(arr,n,max(m-1,0),k,i+1);
		else
			return memo[i][k] = dp(arr,n,m-1,k,i+1);
	}
	else {
		
		if(!m && !k)
			return memo[i][k] = 1 + dp(arr,n,0,0,i+1);
		else if(!m)
			return memo[i][k] = dp(arr,n,0,max(0,k-1),i+1);
		else if(!k)
			return memo[i][k] = dp(arr,n,max(m-1,0),0,i+1);
		else
			return memo[i][k] = min(dp(arr,n,max(m-1,0),k,i+1),dp(arr,n,m,max(k-1,0),i+1));
	}
}

int main() {

	int n,m,k;
	cin >> n >> m >> k;
	vi arr(n);
	rep(i,n)
		cin >> arr[i];
		
	cout << dp(arr,n,m,k) << endl;
}


