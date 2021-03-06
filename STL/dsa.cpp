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
	int n;
	cin >> n;
	string str;
	int count = 0 ;
	map<string ,int> cities;
	rep(i,n)	{
		cin >> str;
		cities[str] = count ++;
	}
	vector<vi> cost(n,vi(n));
	rep(i,n)
		rep(j,n)
			cin >> cost[i][j];
	int p;
	cin >> p;
	ll ans = 0;
	int start=0,dest;
	rep(i,p) {
		cin >> str;
		int dest = cities[str];
		ans += cost[start][dest];
		start = dest;
	}
	cout << ans << endl;
}


