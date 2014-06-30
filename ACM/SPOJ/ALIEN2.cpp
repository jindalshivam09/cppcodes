#include <iostream>
#include <vector>
#include <list>
#include <limits>
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
#define MAX 10009
vi A(MAX),B(MAX);
int n,k;
int count;
vector<vi> memo(MAX,vi(2));
int dp(int i,bool flag) {
	int ans = imax;
	if(memo[i][flag])
		return memo[i][flag];
	if(i==n)
		return 0;
	else if(flag) {
		if(!i) {
			memo[i][flag] = A[i]+dp(i+1,flag);
			memo[i][false] = B[i]+dp(i+1,false);
			return 0;
		}
		else
			ans = min(A[i]+dp(i+1,flag) , A[i]+B[i]+dp(i+1,false) );
	}
	else {
		ans = min(B[i]+dp(i+1,flag) , A[i]+B[i]+dp(i+1,true) );
	}
	return	memo[i][flag] = ans;
}
int main() {
	cin >> n >> k;
	rep(i,n)
		cin >> A[i];
	rep(i,n)
		cin >> B[i];
	dp(0,true);	
	int flag = true;
	int ans = imax,pos;
	for(int i=0;i<n;i++) {
		cout << memo[i][flag] << " " << n-i << endl;
		if(!i && memo[0][flag]<=k) {
			pos = n-i;
			ans = memo[0][flag];
			break;
		}
		else if(i && memo[0][flag]-memo[i][flag]<=k) {
			pos = n-i;
			ans = memo[0][flag]-memo[i][flag];
//			break;		
		}
		else if(i)
			break;
	}
	cout << endl << ans << endl;;
	flag = false;
	for(int i=0;i<n;i++) {
		cout << memo[i][flag] << " " << n-i << endl;
		if(!i && memo[0][flag]<=k && ans >= memo[0][flag]) {
			if(ans==memo[0][flag])
				pos = max(n-i,pos);
			else
				pos = n-i;			
			ans = memo[0][flag];
			break;
		}
		else if(i && memo[0][flag]-memo[i][flag]<=k && ans >= memo[0][flag]-memo[i][flag]) {
			if(ans==memo[0][flag]-memo[i][flag])
				pos = max(n-i,pos);
			else
				pos = n-i;
			ans = memo[0][flag]-memo[i][flag];
			
//			break;		
		}
		else if(i)
			break;
	}
	cout << pos <<  " " << ans << endl;
}


