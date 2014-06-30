#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<ll,ll> 	pii;
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
#define MAX 1000009
vi tree(MAX);
ll n;
int cal_cum_freq(int idx) {

	int sum = 0;
	while(idx>0) {
		sum += tree[idx];
		idx -= (idx&-idx);
	}
	return sum;
} 

void change_freq(int idx,int freq) {

	while(idx <= n) {
		
		tree[idx] += freq;
		idx += (idx&-idx);
	}
}


int main() {
	cin >> n ;
	map<ll,ll> left;
	vpii pairs(n) ;
	vi female(n);
	ll a,b;
	rep(i,n) {
		cin >> a >> b;
		pairs[i] = mp(a,b);
		female[i] = b ;
	}  
	sort(all(female)) ;
	int ans = 0 ;
	int index = 1;
	rep(i,n) {
		left[female[i]] = index ;
		index ++ ;
	}	
	rep(i,n) {
		int temp = pairs[i].second ;
		int val = left[temp] ;
		ans += i-cal_cum_freq(val) ;
		change_freq (val,1) ;
	}
	cout << ans << endl ; 
}


