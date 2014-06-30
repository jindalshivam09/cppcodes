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
#define MAX 40009
char str[MAX];
ll LCM ( int a,int b) {
	ll lcm = a*b ;
	if ( a > b )
		a^=b^=a^=b; 
	return lcm/__gcd(a,b);
}
int main() {
	int t;
	cin >> t;
	while(t--) {
//		scanf("%s",str);
		int m,n,len;
//		len = strlen(str);
		cin >> m >> n ;
		ll lcm = LCM(m,n);
		cout << lcm << " " ;
	}
}


