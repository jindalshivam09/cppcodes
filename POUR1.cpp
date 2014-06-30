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
int a,b,c;
map<pii,int> memo , repeat ;
int min_steps (int i=0,int j=0) {
//	cout << i << " " << j << endl;
	if ( i == c || j == c )
		return 0;
	if ( memo[mp(i,j)] )
		return memo[mp(i,j)] ;
	if ( repeat[mp(i,j)] )
		return -1 ;
	int ans = 0;
	repeat[mp(i,j)] = 1;
	if(!i && !j) {
		int ans1 = 1 + min_steps(0,b);
		int ans2 = 1 + min_steps(a,0);
		if(!ans1)		ans1 = imax ;
		if(!ans2)		ans2 = imax ;
		ans = min ( ans1 , ans2 ) ;
		if(ans == imax)
				ans = 0;
	}
	else {
		if (!i) {
			if ( j > a )
				ans = 1 + min_steps(a,j-a); 
			else
				ans = 1 + min_steps(j,0) ;
		}
		else if (!j)  {
				int ans1 = 1 + min_steps(i,b);
				int ans2 = 1 + min_steps(0,i);
				if(!ans1)		ans1 = imax ;
				if(!ans2)		ans2 = imax ;
				ans = min ( ans1 , ans2 ) ;				
				if(ans == imax)
				ans = 0;
		}
		else {
			int ans1 , ans2 ;
			if ( b-j >= i)
				ans1 = 1 + min_steps (0,j+i);
			else
				ans1 = 1 + min_steps (i-(b-j),b);
			if ( a-i >= j )
				ans2 = 1 + min_steps (i+j,0);
			else
				ans2 = 1 + min_steps (a,j-(a-i));
			if ( !ans1 )	ans1 = imax ;
			if ( !ans2 )	ans2 = imax ;
			ans = min ( ans1 , ans2 );
			if(ans == imax)
				ans = 0;
		}		
	}
	if ( ans )
		return memo[mp(i,j)] = ans;
	else
		return memo[mp(i,j)] = -1 ;
}
int main() {
	int t;
	cin >> t;
	int x,y;
	while(t--) {
		cin >> x >> y >> c ;
		a = min ( x , y ) ;
		b = max ( x , y ) ;
		cout << min_steps() << endl;
		memo.clear();
		repeat.clear();
	}
}
