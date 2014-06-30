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

int main() {
	int n,m;
	cin >> n >> m;
	int a,b;
	a = max(m,n);
	b = min(m,n);
	int ans = 0;
	int min = 0;
	bool flag = false;
	while(b) {
		
		ans += (a-min)/2;
		if((a-min)%2 && b>1) 
			flag = true , min = 1 ,ans = ans + 1;
		else
			flag = false , min = 0;
		b--;
	}
	cout << ans << endl;
}


