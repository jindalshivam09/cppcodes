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
	cin >> n >> m ;
	vector<vi> arr(n,vi(m));
	rep(i,n)
		rep(j,m)
			cin >> arr[i][j];
			
	int l;
	cin >> l;
	vpii input(l);
	int a,b;
	rep(i,l) {
		cin >> a >> b;
		input[i] = mp(a,b);
	}
	ll e1 = 0 , e2 = 0;
	rep(i,l) {
		a = input[i].first;
		b = input[i].second;
		a--;
		b--;
		if(a < m && b < n && e1 != -1) {
				e1 += arr[a][b];
		}
		else
			e1 = -1;
			
		if(a < n && b < m && e2 != -1) {
				e2 += arr[b][a] ;
		}
		else
			e2 = -1;
	}		
	cout << max(e1,e2) << endl;	
}


