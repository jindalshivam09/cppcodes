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
#define MAX 2009
vector<vi> memo(MAX,vi(MAX));
int dp (const string &A, const string &B , int i = 0 , int j = 0,int count = 0) {
	if ( j == B.size() && i == A.size())
		return 0;
	else if ( j == B.size() && i < A.size())
		return A.size()-i;
	else if ( i == A.size() && j < B.size())
		return B.size()-j;
	else if (memo[i][j])
		return memo[i][j];
	int ans = 1 + min ( dp (A,B,i+1,j,count) , dp (A,B,i,j+1,count) );
	int temp = dp(A,B,i+1,j+1,count+1);
	ans = min (ans , temp + (A[i] != B[j]) ) ; 
	return memo[i][j] = ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string A,B;
		cin >> A >> B;
		cout << dp (A,B) << endl;
		for (int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				memo[i][j] = 0;
	}
}


