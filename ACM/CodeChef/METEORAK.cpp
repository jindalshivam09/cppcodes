#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
#include <limits>
#include <cstdio>
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
#define imax  			numeric_limits<ll>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
#define MAX 1009
ll m,n;
vector<vll> matrix(MAX,vll(MAX,1)) , height(MAX,vll(MAX)) ,area(MAX,vll(MAX,imin));

void cal_height () {
	for(ll i=0;i<n;i++) 
		height[m-1][i] = matrix[m-1][i] ;
	for(ll i=m-2;i>=0;i--) {
		for(ll j=0;j<n;j++ ) {
			if(matrix[i][j] == 0)
				height[i][j] = 0 ;
			else
				height[i][j] = 1 + height[i+1][j] ;
//			cout << height[i][j] << " " ;
		}
//		cout << endl;
	}
}

ll cal_area() {
	cal_height() ;
//	cout << "calculating areas ...\n" ;
	ll ans = imin , j;
	rep(i,m) {
		stack<ll> stk ;
		for(j=0;j<n;) {
			if(stk.empty() || height[i][stk.top()] <= height[i][j] ) 
				stk.push(j) , j ++;
			else {
				ll top = stk.top() ;
				stk.pop() ;
				ans = max ( ans , height[i][top]*(stk.empty() ? j : j-stk.top()-1) ) ;
				area[i][i+height[i][top]] = max ( area[i][i+height[i][top]] , height[i][top]*(stk.empty() ? j : j-stk.top()-1)) ;
//				cout << i << " " << height[i][top] <<" " << area[i][i+height[i][top]] << endl; ;
			}
		}
		while (stk.empty() == false) {
			ll top = stk.top() ;
			stk.pop() ;
			ans = max ( ans , height[i][top]*(stk.empty() ? j : j-stk.top()-1) ) ;			
			area[i][i+height[i][top]] = max ( area[i][i+height[i][top]] , height[i][top]*(stk.empty() ? j : j-stk.top()-1)) ;
//			cout << ans << " " ;
		}
//		cout << endl;
	}	
	for(ll i = 0 ; i < m ; i ++ ) {
//		cout << area[i][m] << " ";
		for(ll j=m-1;j>i;j--) {
			ll temp = area[i][j+1] / (j+1-i);
			area[i][j] = max ( area[i][j] , temp*(j-i)) ;
//			cout << area[i][j] << " ";
		}
//		cout << endl;
	}
	for(ll i=m-2;i>=0;i--) repi(j,i+1,m+1)
		area[i][j] = max ( max (area[i][j],area[i][j-1]) , area[i+1][j] ) ;
	
/*	for(ll i = 0 ; i < m ; i ++ ) {
	cout << area[i][m] << " ";
	for(ll j=m-1;j>i;j--) {
//		ll temp = area[i][j+1] / (j+1-i);
//		area[i][j] = max ( area[i][j] , temp*(j-i)) ;
		cout << area[i][j] << " ";
	}
	cout << endl;
}
*/
}
 
int main() {
//	freopen("input.txt","r",stdin) ;
//	freopen("output_meteorak.txt","w",stdout) ;
	ll k;
//	cin >> m >> n >>  k;
	scanf("%lld%lld%lld",&m,&n,&k) ;
	ll a,b ;
	rep(i,k) {
//		cin >> a >> b ;
		scanf("%lld%lld",&a,&b) ;
		a-- , b --;
		matrix[a][b] = 0 ;
	}
	cal_area() ;
	ll q ;
//	cin >> q; 
	scanf("%lld",&q) ;
	while(q--) {
//		cin >> a >> b ;
		scanf("%d%d",&a,&b) ;
		a-- , b-- ;
//		cout << area[a][b+1] << endl;
		printf("%lld\n",max(0LL,area[a][b+1])) ;
	}
}


